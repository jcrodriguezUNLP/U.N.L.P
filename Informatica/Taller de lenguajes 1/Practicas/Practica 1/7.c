// ==============================================================================
// ANÁLISIS 7: LECTURA E IMPRESIÓN DE CARACTERES
// ==============================================================================
// Contexto:
//     - El código busca leer dos caracteres del teclado e imprimirlos.
//
// Tarea:
//     1. ¿El código cumple con su cometido original?
//     2. En caso negativo, corríjalo para que lo haga.
// ==============================================================================

// --- 1. RESPUESTA TEÓRICA ---
// ¿El código cumple con su cometido original?
//     NO. Falla al leer el segundo carácter porque el primer 'scanf' deja el 
//     salto de línea ('\n') en el buffer del teclado. El segundo 'scanf' 
//     consume ese '\n' automáticamente en lugar de esperar la entrada del usuario.

#include <stdio.h>

int main() {
    // --- 2. INICIALIZACIÓN ---
    char a ;
    char b ;

    // --- 3. PROCESAMIENTO Y SALIDA ---
    printf( "Ingrese el primer caracter: " ) ;
    
    // Lectura normal del primer carácter
    scanf( "%c" , &a ) ;
    printf( "Se leyo el caracter: %c\n\n" , a ) ;

    printf( "Ingrese el segundo caracter: " ) ;
    
    // CORRECCIÓN CORE: Se añade un espacio antes de %c. 
    // Esto obliga a scanf a ignorar los espacios en blanco y saltos de línea
    // ('\n', '\t', ' ') que hayan quedado residuales en el buffer estándar (stdin).
    scanf( " %c" , &b ) ;
    printf( "Se leyo el caracter: %c\n" , b ) ;

    return( 0 ) ;
}