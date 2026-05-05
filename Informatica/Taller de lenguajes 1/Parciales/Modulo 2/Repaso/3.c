// 3. (1 punto) Defina la macro nPares que dados dos valores permita determinar cuántos son pares.

#include <stdio.h>

#define nPares(VAL1, VAL2) \
    ( ((VAL1 % 2) == 0) + ((VAL2 % 2) == 0) )

int main() {
    int a = 12 ;
    int b =  7 ;
    int c = 10 ;
    
    printf( "--- Test de Macro nPares ---\n");
    printf( "Valores ( 12 ,  7 ): %d pares ( Esperado: 1 )\n", nPares( a , b ) ) ;
    printf( "Valores (  7 ,  5 ): %d pares ( Esperado: 0 )\n", nPares( b , 5 ) ) ;
    printf( "Valores ( 10 , 12 ): %d pares ( Esperado: 2 )\n", nPares( c , a ) ) ;
    
    return( 0 ) ;
}