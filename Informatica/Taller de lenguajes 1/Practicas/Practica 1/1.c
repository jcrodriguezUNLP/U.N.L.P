// Al  compilar  un  programa  en  C,  el  compilador  puede  notificar  errores  y  avisos  (warnings).

// ¿Qué diferencia  existe  entre  ellos?
//    - ERRORES:
//        Son problemas críticos que impiden la compilación
//        Ejemplos: sintaxis incorrecta, variables no declaradas, funciones inexistentes, etc.
//    - WARNINGS:
//        Son avisos sobre posibles problemas o malas prácticas.
//        Ejemplos: variables no usadas, conversiones implícitas, etc.

// ¿puede  un  programa  compilar  con  errores? ¿y  con  warnings? 
//    El código NO puede compilar con errores.
//    El código SÍ puede compilar con warnings.

// Compile los siguientes programas  e identifique errores y warnings.

// Luego, corríjalos para que el código compile correctamente.

#include <stdio.h>
int main(){ 
    // a
        // double pi = 3.14 ;
        // int     y = 5

        // printf( "pi = %d\n" , pi ) ;

        // -----------------------------------------------------------------------------------//
        // ERRORES:
        //   - Falta punto y coma (;) después de "int y = 5"
        //   - Especificador incorrecto: usa %d para double (debería ser %f)
        //      Esto produce un resultado incorrecto al imprimir el valor
        // WARNINGS:
        //   - Variable 'y' declarada pero no utilizada
        //   - Falta de 'return 0;' en main puede generar un warning en algunos compiladores
        // ------------------------------------------------------------------------------------//

    // b
        // int x = 10 ;

        // if( x = 5 ) 
        //     printf( "x = 5\n" ) ;
        
        // return( 0 ) ;
        
        // -------------------------------------------------------------------------------//
        // ERRORES:
        //   - Asignación (=) en lugar de comparación (==) en la condición if
        // WARNINGS:
        //   - Warning sobre asignación en condición if (sugiere usar == en lugar de =) 
        // -------------------------------------------------------------------------------//
    
    // a corregido
        double pi = 3.14 ;

        printf( "pi = %f\n" , pi ) ;

        return( 0 ) ;

    // b corregido
        // int x = 10 ;

        // if( x == 5 ){
        //     printf( "x = 5\n" ) ;
        // }
        
        // return( 0 ) ;
}