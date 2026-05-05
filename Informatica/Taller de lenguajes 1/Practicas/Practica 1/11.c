// ==============================================================================
// ANÁLISIS 11: COMPORTAMIENTO DEL FOR
// ==============================================================================
// Contexto:
//     - Diferentes configuraciones de la estructura for.
//
// Tarea:
//     - Indique qué valores de la variable de control 'i' se imprimen.
//     - Ejecute y analice por qué ocurre cada caso.
// ==============================================================================

#include <stdio.h>

int main() {
    int i ;

    // --- CASO A ---
    // Imprime: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // Por qué: Comienza en 0 y avanza de a 1. Al usar el operador estricto '<', 
    // el bucle se rompe exactamente cuando 'i' llega a 11, sin imprimirlo.
    printf( "--- Caso A ---\n" ) ;
    for( i = 0 ; i < 11 ; i++ ) {
        printf( "%d " , i ) ;
    }
    
    // --- CASO B ---
    // Imprime: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    // Por qué: Es idéntico al A, pero al usar '<=' (menor o igual), el 11 
    // pasa la condición y se imprime. Nota: '++i' y 'i++' como instrucción 
    // aislada en el for tienen el mismo efecto práctico aquí.
    printf( "\n\n--- Caso B ---\n" ) ;
    for( i = 0 ; i <= 11 ; ++i ) {
        printf( "%d " , i ) ;
    }

    // --- CASO C ---
    // Imprime: 2, 4, 6, 8, 10
    // Por qué: Inicia en 2. El salto es de a 2 en cada iteración (i += 2). 
    // Termina en 10 porque el siguiente valor sería 12, que falla el 'i < 11'.
    printf( "\n\n--- Caso C ---\n" ) ;
    for( i = 2 ; i < 11 ; i += 2 ) {
        printf( "%d " , i ) ;
    }

    // --- CASO D ---
    // Imprime: 1, 2, 4, 8
    // Por qué: El salto es multiplicativo (i *= 2). Los valores en memoria 
    // evolucionan así: 1 -> 2 -> 4 -> 8 -> 16. El 16 rompe el 'i <= 11'.
    printf( "\n\n--- Caso D ---\n" ) ;
    for( i = 1 ; i <= 11 ; i *= 2 ) {
        printf( "%d " , i ) ;
    }

    // --- CASO E ---
    // Imprime: 11, 9, 7, 5, 3, 1
    // Por qué: Es un bucle regresivo. Arranca en 11, la condición exige que 
    // 'i' sea mayor o igual a 1, y en cada vuelta resta 2 (i -= 2).
    printf( "\n\n--- Caso E ---\n" ) ;
    for( i = 11 ; 1 <= i ; i -= 2 ) {
        printf( "%d " , i ) ;
    }

    // --- CASO F (¡TRAMPA DE SINTAXIS!) ---
    // Imprime: 11
    // Por qué: 'i =+ 1' NO ES UN INCREMENTO. El compilador lo lee como una 
    // asignación de un valor positivo: 'i = (+1)'. 
    // Traza de la CPU: 
    // 1. i vale 11. Imprime 11.
    // 2. Ejecuta actualización: i pasa a valer 1 exacto.
    // 3. Evalúa condición: ¿1 > 1? Falso. El bucle termina abruptamente.
    printf( "\n\n--- Caso F ---\n" ) ;
    for( i = 11 ; 1 < i; i =+ 1 ) {
        printf( "%d " , i ) ;
    }

    printf( "\n" ) ;

    return( 0 ) ;
}