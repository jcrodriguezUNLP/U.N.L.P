#include <stdio.h>

/*
Cuadro Resumen: Estructuras de Control

| Estructura | Uso principal                                                                                | Garantiza al menos una ejecución |
|------------|----------------------------------------------------------------------------------------------|----------------------------------|
| for        | Cuando se conoce el número exacto de iteraciones.                                            | No                               |
| while      | Cuando no se conoce el número exacto de iteraciones, pero se tiene una condición inicial.    | No                               |
| do-while   | Cuando se necesita ejecutar el bloque al menos una vez, independientemente de la condición.  | Sí                               |

Sintaxis general:
    for:
        inicializa la variable de control
        evalua la condición
            si es verdadera
                ejecuta el bloque de código
                incremento/decremento // Modifica la variable de control
            si es falsa
                termina el bucle
        
        for( inicialización ; condición ; incremento/decremento ){
            código
        }
    
    while:
        evalua la condición
            si es verdadera
                ejecuta el bloque de código
                incremento/decremento // Modifica la variable de control
            si es falsa
                termina el bucle

        while( condición ){
            código
        }

    do-while:
        ejecuta el bloque de código
            incremento/decremento // Modifica la variable de control
            evalua la condición
                si es verdadera
                    repite el bloque de código
                si es falsa
                    termina el bucle

        do {
            código
        } while( condición ) ;

Errores comunes:
- No modificar la variable de control en un bucle `while` o `do-while` puede provocar un loop infinito por error.
- Usar una condición que siempre es verdadera sin un mecanismo para salir del bucle puede causar problemas.
- Los loops infinitos intencionales deben incluir una condición de salida, como `break`.
*/

int main() {
    // Explicación y ejemplo del ciclo for
        printf( "\nUsando for:\n" ) ;

        for( int i = 1 ; i <= 5 ; i++ ){
            printf( "%d " , i ) ;
        }

    // Explicación y ejemplo del ciclo while
        printf( "\nUsando while:\n" );

        int j = 1 ;

        while( j <= 5 ){
            printf( "%d " , j );

            j++; // Incremento
        }

    // Explicación y ejemplo del ciclo do-while
        printf( "\nUsando do-while:\n" );
        
        int k = 1 ;
        
        do {
            printf( "%d " , k ) ;

            k++; // Incremento

        } while( k <= 5 ) ;

    // Ejemplo de while infinito por error
        printf( "\nEjemplo de while infinito por error:\n" );

        int x = 1 ;

        while( x == 1 ){ // La condición siempre es verdadera
            printf( "Este es un loop infinito porque x no cambia.\n" );
            // Error: No se modifica x, por lo que el bucle nunca termina
        }

    // Ejemplo de do-while infinito por error
        printf( "\nEjemplo de do-while infinito por error:\n" );

        int y = 1 ;

        do {
            printf( "Este es un loop infinito porque y no cambia.\n" );
            // Error: No se modifica y, por lo que el bucle nunca termina
        } while( y == 1 ) ;

    // Ejemplo de while infinito intencional
        printf( "\nEjemplo de while infinito intencional:\n" );

        int contador = 0 ;

        while( 1 ){ // Condición siempre verdadera
            printf( "Iteración %d\n" , contador );
            contador++;

            if( contador == 5 ){ // Condición de salida
                printf( "Saliendo del loop infinito.\n" );
                break;
            }
        }

    // Ejemplo de do-while infinito intencional
        printf( "\nEjemplo de do-while infinito intencional:\n" );

        int z = 0 ;

        do {
            printf( "Iteración %d\n" , z );
            z++;

            if( z == 5 ){ // Condición de salida
                printf( "Saliendo del loop infinito.\n" );
                break;
            }
        } while( 1 ); // Condición siempre verdadera

    return( 0 ) ;
}