/* imath.c - Implementación de la lógica */
#include "imath.h"

// a. Eleva x a la y
int potencia( int x , int y ){
    int res = 1 ;

    for( int k = 0 ; k < y ; k++ ) {
        res *= x ;
    }

    return( res ) ;
}

// b. Eleva al cuadrado (reutilizamos potencia o multiplicamos directo)
int cuadrado( int x ){
    return( x * x ) ;
}

// c. Eleva al cubo
int cubo( int x ){
    return( x * x * x ) ;
}

// d. Valor absoluto (si es negativo, lo hace positivo)
int absoluto( int i ){
    if( i < 0 ){
        i = -i ;
    }        

    return( i ) ;
}

// e. Factorial (ej: 5! = 5*4*3*2*1)
int factorial( int i ){
    int res = 1 ;

    if( i < 0 ){
        res = 0 ;
    } else { 
        for( int k = 1 ; k <= i ; k++ ){
            res *= k ;
        }
    }

    return( res ) ;
}

// f. Sumatoria de 0 hasta i
int sumatoria( int i ){
    int suma = 0 ;

    for( int k = 0 ; k <= i ; k++ ){
        suma += k ;
    }

    return( suma ) ;
}

// g. Retorna 1 si y es divisor de x (x % y == 0)
int multiplo( int x , int y ){
    int res ;

    if( y == 0 ){
        res = 0 ;
    }

    if( (x % y) == 0 ){
        res = 1 ;
    }

    return( res ) ;
}

// h. Retorna 1 si y es múltiplo de x (y % x == 0)
int divisor( int x , int y ){
    int res ;

    if( x == 0 ){
        res = 0 ;
    }

    if( (y % x) == 0 ){
        res = 1 ;
    }

    return( res ) ;
}

// i. Retorna 1 si es par
int par( int i ){
    return( (i % 2) == 0 ) ;
}

// j. Retorna 1 si es impar
int impar( int i ){
    return( (i % 2) != 0 ) ;
}