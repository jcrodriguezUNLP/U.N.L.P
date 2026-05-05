// ==============================================================================
// ANÁLISIS 21: TRUNCAMIENTO, ESTADO ESTÁTICO Y TERNARIOS
// ==============================================================================
// Contexto:
//     - Analice el siguiente programa e indique qué imprime.
// ==============================================================================

#include <stdio.h>

// --- 1. PROTOTIPO ---
// La función exige recibir un entero (int).
int incremento( int N ) ;

int main() {
    // --- 2. INICIALIZACIÓN ---
    // 'i' se declara como flotante, lo que permite cálculos con decimales.
    float i ;

    printf( "--- Analisis de Traza en Ejecucion ---\n\n" ) ;

    // --- 3. PROCESAMIENTO Y SALIDA ---
    // El bucle reduce 'i' a la mitad: 6.0 -> 3.0 -> 1.5 -> 0.75
    // Condición Yoda aplicada: 0.5 < i
    for( i = 6.0f ; 0.5 < i ; i /= 2.0f ) {
        
        // ANÁLISIS DEL PRINTF Y LA LLAMADA A LA FUNCIÓN:
        // 1. %5.1f : Imprime el float reservando 5 espacios y 1 decimal.
        //    TRAMPA: En la última vuelta válida (0.75), printf lo redondea a 0.8.
        // 2. incremento( i ) : Al pasar 'i' (float) a un parámetro (int), ocurre un 
        //    TRUNCAMIENTO IMPLÍCITO. Los decimales se eliminan directamente de la RAM:
        //    - 6.0  entra como 6
        //    - 3.0  entra como 3
        //    - 1.5  entra como 1  <-- Pierde el .5
        //    - 0.75 entra como 0  <-- Pierde el .75
        printf( "i = %5.1f   j = %5d\n" , i , incremento( i ) ) ;
    }

    return( 0 ) ;
}

// --- 4. IMPLEMENTACIÓN CORE ---
int incremento( int N ) {
    // 'static' modifica el ciclo de vida. Nace con 0 y luego conserva su valor.
    static int j = 0 ;

    // Su estado por vuelta en la memoria será: 1 -> 2 -> 3 -> 4
    j++ ;

    // OPERADOR TERNARIO: ( condición ) ? valor_si_verdadero : valor_si_falso
    // 
    // La condición (N % 2) evalúa si N tiene resto al dividirse por 2.
    // - Si N es IMPAR: da 1 (Verdadero) -> Retorna N intacto.
    // - Si N es PAR o 0: da 0 (Falso)   -> Retorna la suma de (N + j).
    return( (N % 2) ? N : (N + j) ) ;
}