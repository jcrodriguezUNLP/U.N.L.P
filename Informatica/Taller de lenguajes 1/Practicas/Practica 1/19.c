// ==============================================================================
// PROBLEMA 19: SIMULADOR DE EVALUACIÓN MATEMÁTICA
// ==============================================================================
// Escriba un programa que:
//     imprima:
//         4 operaciones matemáticas de suma.
//     lea:
//         el resultado ingresado por el alumno para cada operación.
//     imprima:
//         el puntaje total y la nota cualitativa (4=A, 3=B, 2=C, 1=D, 0=E).
//     condiciones:
//         - Los operandos deben generarse aleatoriamente en el rango [0, 100].
//         - Cada respuesta correcta suma 1 punto.
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // --- 1. INICIALIZACIÓN ---
    int op1 ;
    int op2 ;
    int respuesta ;
    int resultadoCorrecto ;
    int puntaje = 0 ;

    // Inyección de entropía al sistema para garantizar escenarios únicos
    srand( time( NULL ) ) ;

    printf( "--- Evaluacion de Matematicas ---\n\n" ) ;

    // --- 2. PROCESAMIENTO: MOTOR DE EVALUACIÓN ---
    // Ejecuta un ciclo estricto de 4 iteraciones usando operador '<='
    for( int i = 1 ; i <= 4 ; i++ ) {
        
        // Genera operandos acotados al rango [0, 100] usando reducción por módulo
        // La fórmula es rand() % (N + 1)
        op1 = ( rand() % 101 ) ;
        op2 = ( rand() % 101 ) ;
        
        // Calcula el estado válido en memoria antes de preguntar
        resultadoCorrecto = ( op1 + op2 ) ;

        printf( "Operacion %d: %d + %d = " , i , op1 , op2 ) ;
        scanf( "%d" , &respuesta ) ;

        // Validación y actualización del estado del acumulador
        if( respuesta == resultadoCorrecto ) {
            printf( "    -> ¡Correcto!\n\n" ) ;
            puntaje++ ;
        } else {
            printf( "    -> Incorrecto. El resultado era: %d\n\n" , resultadoCorrecto ) ;
        }
    }

    // --- 3. SALIDA: RESOLUCIÓN Y MAPEO ---
    printf( "--- Resultado Final ---\n" ) ;
    printf( "Puntaje total: %d/4\n" , puntaje ) ;
    printf( "Nota cualitativa: " ) ;

    // Convierte el valor cuantitativo (0 a 4) en una calificación cualitativa (A a E)
    switch( puntaje ) {
        case 4:
            printf( "A\n" ) ;
            break ;
        case 3:
            printf( "B\n" ) ;
            break ;
        case 2:
            printf( "C\n" ) ;
            break ;
        case 1:
            printf( "D\n" ) ;
            break ;
        case 0:
            printf( "E\n" ) ;
            break ;
        default:
            // Práctica de código defensivo
            printf( "Error critico en el calculo del puntaje.\n" ) ; 
            break ;
    }

    return( 0 ) ;
}