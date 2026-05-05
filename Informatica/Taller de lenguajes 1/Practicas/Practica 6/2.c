// Escriba un programa que calcule e imprima el promedio de 4 números que se pasan como argumentos a la función main.
// En caso de no pasar la cantidad necesaria de parámetros, informar al usuario. 

#include <stdio.h>
#include <stdlib.h> // Necesaria para atof()

int main( int argc , char* argv[] ) {
    
    // 1. VALIDACIÓN
    // Necesitamos 5 argumentos en total:
    // argv[0] -> Nombre del programa
    // argv[1], argv[2], argv[3], argv[4] -> Los 4 números
    if( argc != 5 ){
        printf( "Error: Se requieren exactamente 4 numeros.\n"             ) ;
        printf( "Uso correcto: %s <num1> <num2> <num3> <num4>\n" , argv[0] ) ;

        return( 1 ) ; // Retornamos 1 para indicar error
    }

    double suma = 0.0 ;

    // 2. PROCESAMIENTO
    // Empezamos el bucle en i=1 para saltar el nombre del programa
    for( int i = 1 ; i < argc ; i++ ){
        // atof convierte el string (char*) a double
        suma += atof( argv[i] ) ;
    }

    // 3. CALCULO Y SALIDA
    // Sabemos que son 4 números, así que dividimos por 4.0
    double promedio = ( suma / 4.0 ) ;

    printf( "Promedio: %.2f\n" , promedio ) ;

    return( 0 ) ;
}