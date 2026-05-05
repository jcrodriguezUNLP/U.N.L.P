#include <stdio.h>
#define CALCULO( x ) x * 2 + 1

int main() {
    printf( "%d \n" , CALCULO( 6     )     ) ; // --> 6 * 2 + 1     = 13
    printf( "%d \n" , CALCULO( 4 + 2 )     ) ; // --> 4 + 2 * 2 + 1 = 9
    printf( "%d \n" , CALCULO( 3     ) * 2 ) ; // --> 3 * 2 + 1 * 2 = 8

    return( 0 ) ;
}