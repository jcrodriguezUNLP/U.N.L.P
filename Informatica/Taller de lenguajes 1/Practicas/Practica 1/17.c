// ==============================================================================
// PROBLEMA 17: MÍNIMO Y MÁXIMO (PASO POR REFERENCIA)
// ==============================================================================
// Escriba una función que:
//     reciba:
//         un número entero n
//     lea:
//         n números flotantes desde teclado
//     retorne:
//         el mínimo y el máximo número leído
// ==============================================================================

#include <stdio.h>

// --- 1. FUNCIÓN CORE ---
// Usamos punteros para "retornar" dos valores modificando la memoria del main.
void leerNNumsYDevolverMinMax( int n , float *dirMin , float *dirMax ) {
    float tmp ;

    // Protección defensiva: si piden 0 o menos números, cortamos la ejecución.
    if( n <= 0 ) {
        return ; 
    }

    // 1. Leemos el primer número fuera del bucle para tener un punto de partida real.
    printf( "Ingrese un numero flotante (1/%d): " , n ) ;
    scanf( "%f" , &tmp ) ;

    // 2. Inicializamos tanto el mínimo como el máximo con este primer valor real.
    *dirMin = tmp ;
    *dirMax = tmp ;

    // 3. El bucle arranca en 1 porque ya consumimos el primer número (índice 0).
    for( int i = 1 ; i < n ; i++ ) {
        
        printf( "Ingrese un numero flotante (%d/%d): " , (i + 1) , n ) ;
        scanf( "%f" , &tmp ) ;

        // 4. Evaluamos el mínimo (usando estrictamente '<')
        if( tmp < *dirMin ) {
            *dirMin = tmp ;
        }

        // 5. Evaluamos el máximo (usando estrictamente '<' con operandos invertidos)
        if( *dirMax < tmp ) {
            *dirMax = tmp ;
        }
    }
}

int main() {
    // --- 2. INICIALIZACIÓN ---
    int   n   ;
    float min ;
    float max ;

    printf( "--- Analizador de Minimo y Maximo ---\n\n" ) ;

    // --- 3. PROCESAMIENTO ---
    printf( "Ingrese la cantidad total de numeros a evaluar: " ) ;
    scanf( "%d" , &n ) ;

    // Pasamos las direcciones de memoria de 'min' y 'max'
    leerNNumsYDevolverMinMax( n , &min , &max ) ;

    // --- 4. SALIDA ---
    // Verificamos que se haya ejecutado correctamente antes de imprimir
    if( 0 < n ) {
        printf( "\nResultados del analisis:\n" ) ;
        printf( "    -> El valor minimo es : %.2f\n" , min ) ;
        printf( "    -> El valor maximo es : %.2f\n" , max ) ;
    } else {
        printf( "\nError: No se ingreso una cantidad valida.\n" ) ;
    }

    return( 0 ) ;
}