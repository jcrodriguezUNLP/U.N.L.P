// ==============================================================================
// ANÁLISIS 8: DEBUGGING BÁSICO
// ==============================================================================
// Contexto:
//     - Cuatro fragmentos de código con errores de sintaxis o lógica.
//
// Tarea:
//     - Identifique y corrija los errores en cada bloque.
// ==============================================================================

#include <stdio.h>

int main() {
    
    // ==========================================================================
    // BLOQUE A
    // ==========================================================================
    printf( "--- Bloque A ---\n" ) ;
    {
        // ERROR 1: 'edad' declarada pero no inicializada (basura en memoria).
        int edad = 45 ; 
        
        // ERROR 2: Punto y coma (;) erróneo después de la condición del if.
        if( 40 <= edad ) {
            // ERROR 3: Uso de '&40'. No se puede obtener la dirección de memoria 
            // de un literal. Se pasa el valor directo.
            printf( "Tiene 40 años o mas\n" ) ; 
        } else {
            printf( "Tiene menos de 40 años\n" ) ;
        }
    }

    // ==========================================================================
    // BLOQUE B
    // ==========================================================================
    printf( "\n--- Bloque B ---\n" ) ;
    {
        // ERROR 1: 'total' no estaba inicializada en 0.
        int total = 0 ;
        int x = 1 ;

        // ERROR 2: Se abría el bloque con '(' en lugar de '{'.
        while( x <= 10 ) {
            total += x ;
            ++x ;
        }
        
        // ERROR 3: Se usaba '%f' (float) para imprimir una variable 'int'.
        printf( "Total = %d\n" , total ) ;
    }

    // ==========================================================================
    // BLOQUE C
    // ==========================================================================
    printf( "\n--- Bloque C ---\n" ) ;
    {
        int valor = 4 ; // Forzado a 4 para testear sin detener la ejecución
        
        // ERROR 1: Caracteres '(' y '}' mal ubicados rompiendo la sintaxis.
        switch( valor % 2 ) {
            case 0: 
                printf( "El valor es par\n" ) ;
                // ERROR 2: Falta de 'break' provocaría "fall-through" al case 1.
                break ; 
            case 1: 
                printf( "El valor es impar\n" ) ;
                break ;
        }
    }

    // ==========================================================================
    // BLOQUE D
    // ==========================================================================
    printf( "\n--- Bloque D ---\n" ) ;
    {
        // ERROR 1: Variable separada por coma pero terminada en 'i' (yi) en vez de ';'.
        int x = 5  ; 
        int y = 10 ; 
        
        // ERROR 2: scanf no tenía los ampersand '&' para pasar por referencia.
        // Simulamos la lectura directamente asignando los valores arriba.
        // scanf( "%d" , &x ) ;
        // scanf( "%d" , &y ) ;
        
        // ERROR 3: El printf original no tenía el especificador de formato '%d'.
        printf( "x + y = %d\n" , (x + y) ) ;
    }

    return( 0 ) ;
}