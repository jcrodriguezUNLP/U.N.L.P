#include <stdio.h>

int main() {
    unsigned int k ;

    for( k = 13 ; k & 5 ; k >>= 1 ) {
        printf( "\nk = %d" , k ) ;
    }

    printf( "\n" ) ;

    char i ;

    for( i = 250 ; i ; ++i ){
        printf( "\ni = %d" , i ) ;
    }
    
    return( 0 ) ;
}