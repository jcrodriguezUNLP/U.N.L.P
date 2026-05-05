// ==============================================================================
// TEORÍA 2: TIPOS DE DATOS Y OPERADORES
// ==============================================================================
// Investigue:
//     - El operador sizeof.
//
// Responda:
//     1. ¿Qué ocurre al asignar un char a un int y viceversa?
//     2. ¿Qué diferencia existe entre float y double? ¿Se pueden asignar entre sí?
//     3. ¿Qué sucede cuando intervienen operadores diferentes? (ej: x=2*32+10/2-1)
//     4. ¿Para qué sirve sizeof? Verifique el tamaño de los tipos en su máquina.
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. RESPUESTAS TEÓRICAS ---
    //
    // 1. Asignación char <-> int:
    //    - char a int: Promoción implícita. El valor numérico (ASCII) del 
    //      carácter se guarda en el entero. No hay pérdida de datos porque un 
    //      int (4 bytes) tiene espacio de sobra para un char (1 byte).
    //    - int a char: Truncamiento. El entero se recorta para encajar en 1 byte. 
    //      Si el entero supera el rango de 8 bits (-128 a 127), se pierde 
    //      información (los bytes más significativos se descartan).
    //
    // 2. Diferencia entre float y double:
    //    - float: Precisión simple (4 bytes). Guarda aprox. 7 dígitos decimales.
    //    - double: Precisión doble (8 bytes). Guarda aprox. 15 dígitos decimales.
    //    - Asignación: Asignar un double a un float es peligroso (pérdida de 
    //      precisión) y puede tirar un warning. Asignar un float a un double es 
    //      100% seguro (promoción).
    //
    // 3. Operadores diferentes (Precedencia y Asociatividad):
    //    - C evalúa la expresión siguiendo sus reglas internas matemáticas.
    //    - Ejemplo: x = 2 * 32 + 10 / 2 - 1 
    //      Primero se resuelve (* y /): x = 64 + 5 - 1
    //      Luego se resuelve (+ y -) de izquierda a derecha: x = 68
    //
    // 4. Operador sizeof:
    //    - Es un operador que actúa en TIEMPO DE COMPILACIÓN (no de ejecución). 
    //    - Retorna la cantidad de bytes que ocupa un tipo de dato o variable en 
    //      la RAM de la arquitectura actual.


    // --- 2. PROCESAMIENTO Y SALIDA: ANÁLISIS DE CÓDIGO (Parte 1) ---
    printf( "--- Analisis de Asignacion char/int ---\n" ) ;
    
    char c = 'a' ; // En código ASCII, la 'a' minúscula equivale al entero 97
    int  x = 64  ; // En código ASCII, el 64 equivale al carácter '@'

    // El formato del printf (%d o %c) le dice al compilador cómo debe 
    // interpretar la memoria cruda.
    printf( "La variable char 'c' ('a') leida como int (%cd) es : %d\n" , '%' , c ) ; 
    printf( "La variable int  'x' (64 ) leida como char (%cc) es: %c\n"  , '%' , x ) ; 
    
    
    // --- 3. PROCESAMIENTO Y SALIDA: SIZEOF (Parte 4) ---
    printf( "\n--- Tamaños en memoria (Arquitectura 64-bits WSL/Linux) ---\n" ) ;
    
    // NOTA TÉCNICA: El operador sizeof retorna un dato de tipo 'size_t'.
    // Para que el flag -Wall no tire un warning por "type mismatch", 
    // es obligatorio imprimirlo usando el modificador '%zu', no '%d'.
    
    printf( "Tamaño de char   : %zu bytes\n" , sizeof( char ) ) ;
    printf( "Tamaño de int    : %zu bytes\n" , sizeof( int ) ) ;
    printf( "Tamaño de float  : %zu bytes\n" , sizeof( float ) ) ;
    printf( "Tamaño de double : %zu bytes\n" , sizeof( double ) ) ;

    return( 0 ) ;
}