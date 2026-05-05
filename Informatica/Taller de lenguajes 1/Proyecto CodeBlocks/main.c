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

// a.
#include <stdio.h>

int main(){
    double pi = 3.14 ;              // CORRECTO
    int     y = 5   ;                // ERROR: falta ; al final -> int y = 5 ;

    printf( "pi = %d\n" , pi ) ;    //  WARNING: %D deberia ser %lf

    // WARNING: variable 'y' no utilizada

    // ERROR: falta return( 0 ) -> no tira error PREGUNTAR
}

// // b.
// #include <stdio.h>

// int main(){
//     int x = 10 ;                    // CORRECTO

//     if( x = 5 )                     // INCORRECTO: se usa '==' para comparar -> if( x == 5 )
//         printf( "x = 5\n" ) ;       // CORRECTO

//     return( 0 ) ;                   //CORRECTO
// }
