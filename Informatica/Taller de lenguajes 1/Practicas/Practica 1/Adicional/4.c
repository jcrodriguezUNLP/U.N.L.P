#include <stdio.h>

int main() {
    int n ;
    
    printf( "\ningrese un numero: " ) ;
    scanf ( "%d" , &n               ) ;
    
    printf( "\n%d" , n ) ;

    while( 10 <= n ){
        int suma = 0 ;

        while( n != 0 ){
            suma += ( n % 10 ) ;

            n /= 10 ;
        }

        printf( " ---> %d", suma ) ;

        n = suma ;
    }

    return( 0 ) ;
}