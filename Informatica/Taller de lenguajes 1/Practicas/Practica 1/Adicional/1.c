#include <stdio.h>

int main() {
    int numPaises = 14 ;
    int cantEspecies ;
    int min1 = 0 ;
    int min2 = 0 ;
    int idx1 = 0 ;
    int idx2 = 0 ;
    int contador_mayor_40 = 0 ;

    // Leer datos de los paises
    for ( int i = 1 ; i <= numPaises ; i++ ) {
        printf( "Ingrese la cantidad de especies de aves del pais %d: " , i ) ;
        scanf( "%d" , &cantEspecies ) ;

        // actualizar los 2 paises con menor cantidad de especies
        if ( (cantEspecies < min1) | (i == 1) ) {
            min2 = min1 ;
            idx2 = idx1 ;
            min1 = cantEspecies ;
            idx1 = i ;
        } else if ( (cantEspecies < min2) | (i == 2) ) {
            min2 = cantEspecies ;
            idx2 = i ;
        }

        // actualizar paises con mas de 40 especies
        (40 < cantEspecies) ? contador_mayor_40++ : 0 ;
    }

    // Calcular el porcentaje
    float porcentaje = ( (contador_mayor_40 * 100.0) / numPaises ) ;

    // Mostrar resultados
    printf( "\nLos paises con menor cantidad de especies son:" ) ;
    printf( "\n    Pais %d: %d especies" , idx1 , min1 ) ;
    printf( "\n    Pais %d: %d especies" , idx2 , min2 ) ;

    printf( "\n\nPorcentaje de paises con mas de 40 especies: %.2f%%\n" , porcentaje ) ;

    return( 0 ) ;
}