// Implemente la biblioteca imath.h, la cual contiene funciones matemáticas para enteros.
// La misma debe contener las siguientes funciones: 
//     a. int potencia(int x, int y) Eleva x a la y-ésima potencia. 
//     b. int cuadrado(int x) Eleva x al cuadrado. 
//     c. int cubo(int x) Eleva x al cubo. 
//     d. int absoluto(int i) Retorna el valor absoluto entero de i. 
//     e. int factorial (int i) Retorna el factorial de i. 
//     f. int sumatoria (int i) Retorna la sumatoria de 0 hasta i. 
//     g. int multiplo (int x, int y) Retorna 1 si y es divisor de x, 0 en otro caso. 
//     h. int divisor (int x, int y) Retorna 1 si y es múltiplo de x, 0 en otro caso. 
//     i. int par (int i) Retorna 1 si i es par, 0 en otro caso. 
//     j. int impar (int i) Retorna 1 si i es impar, 0 en otro caso. 

// Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e imprima:
//     numeros pares:    
//         el cuadrado y el cubo
//     numeros impares:
//         el factorial
// La lectura finaliza con el ingreso del 0. 

#include <stdio.h>
#include "imath.h" // Incluimos nuestra biblioteca con comillas ""

int main() {
    int num;

    printf( "Ingrese numeros enteros (0 para terminar):\n" ) ;
    scanf( "%d" , &num ) ;

    while( num != 0 ){
        
        // Verificamos si es PAR usando nuestra biblioteca
        if( par(num) ){
            printf( " -> Es PAR.\n"                      ) ;
            printf( "    Cuadrado: %d\n" , cuadrado(num) ) ;
            printf( "    Cubo:     %d\n" , cubo(num)     ) ;
        }
        
        // Verificamos si es IMPAR
        if( impar(num) ){
            printf( " -> Es IMPAR.\n" ) ;
            // Nota: Factorial crece muy rápido, números > 13 darán error en int
            if( num > 0){ 
                printf( "    Factorial: %d\n" , factorial(num) ) ;
            } else {
                printf( "    No se calcula factorial de negativos.\n" ) ;
            }
        }

        printf( "\nIngrese otro numero: " ) ;
        scanf( "%d" , &num ) ;
    }

    printf( "Fin del programa.\n" ) ;
    
    return( 0 ) ;
}