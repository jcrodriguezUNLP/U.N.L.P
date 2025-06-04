#include <stdio.h>
#include <math.h>

int main() {
    double error = 0.0000001 ;
    double pi    = 3.141592  ;
    double miPi  = 3.0       ;
    int    i     = 0         ;
    
    while( error < fabs(miPi - pi) ){
        i++ ;

        int n = ( i * 2 ) ;

        double calc = ( 4.0 / (n * (n + 1) * (n + 2)) ) ;

        if( (i % 2) == 0 ){
            miPi -= calc ;
        } else {
            miPi += calc ;
        }
    }

    printf( "\nmi pi: %f" , miPi ) ;
    printf( "\npi: %f"    , pi   ) ;

    printf( "\ncant de terminos: %d" , i ) ;

    return( 0 ) ;
}