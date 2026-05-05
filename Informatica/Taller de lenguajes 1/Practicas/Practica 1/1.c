// ==============================================================================
// ANÁLISIS 1: ERRORES Y WARNINGS DE COMPILACIÓN
// ==============================================================================
//
// Contexto:
//     - Compilación utilizando el flag -Wall.
//
// Tarea:
//     1. ¿Qué diferencia existe entre errores y warnings?
//     2. ¿Puede un programa compilar con errores? ¿Y con warnings?
//     3. Compile, identifique y corrija los errores/warnings en los códigos.
// ==============================================================================

// --- 1. RESPUESTAS TEÓRICAS ---
//
// 1. Diferencia:
//    - ERRORES: Son problemas críticos (ej. sintaxis inválida) que impiden que 
//      el compilador traduzca el código. 
//    - WARNINGS: Son avisos. El código es sintácticamente válido, pero tiene 
//      malas prácticas o comportamientos ambiguos (ej. conversiones implícitas, 
//      variables declaradas que nunca se usan).
//
// 2. Compilación:
//    - Con errores: NO compila. No se genera el archivo ejecutable.
//    - Con warnings: SÍ compila. El ejecutable se genera, pero puede fallar o 
//      comportarse de forma errática en tiempo de ejecución.

#include <stdio.h>

int main() {
    
    // --- 2. CORRECCIÓN PARTE A ---
    // Errores originales: faltaban punto y coma (;). Falta de return.
    // Warnings originales (-Wall): variable 'y' sin uso, formato %d para double.
    
    double pi = 3.14 ;
    int    y  = 5    ; // CORRECCIÓN: Se agregó el ';'

    // CORRECCIÓN: Se cambió '%d' por '%f' para imprimir un double correctamente
    printf( "pi = %f\n" , pi ) ;

    // CORRECCIÓN: Se imprime 'y' para eliminar el warning de "variable unused"
    printf( "y  = %d\n" , y ) ;

    printf( "------------------------------\n" ) ;


    // --- 3. CORRECCIÓN PARTE B ---
    // Errores originales: uso de asignación (=) en lugar de comparación (==).
    
    int x = 10 ;

    // CORRECCIÓN: Se reemplazó '=' por '=='
    if( x == 5 ) {
        printf( "x = 5\n" ) ;
    } else {
        printf( "x no es 5 (es %d)\n" , x ) ;
    }

    // CORRECCIÓN: Se agregó el retorno esperado por la firma 'int main'
    return( 0 ) ;
}