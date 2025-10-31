// Escriba un programa  que, a partir de  un número  flotante leído desde teclado
// el cual representa una distancia en kilómetros, imprima su equivalente en millas.   
// Nota: 1,61 Km ≈ 1 milla.

#include <stdio.h>

int main() {
    float km     ;
    float millas ;

    printf( "Ingrese la distancia en kilómetros: " ) ;
    // importante el & antes de km, ya que scanf necesita la dirección de memoria
    scanf( "%f", &km ) ;
    
    millas = ( km / 1.61 ) ;

    printf( "La distancia en millas es: %.2f\n", millas ) ;

    return( 0 ) ;
}