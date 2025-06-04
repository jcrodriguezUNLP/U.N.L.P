#include <stdio.h>
#include <string.h>

// a. Convierte todas las letras de una cadena a mayúsculas
void upperStr( char* str ) {
    while( *str ) {
        if( ('a' <= *str) && (*str <= 'z') ) {
            *str = ( *str - 32 ) ; // Convierte a mayúscula restando 32 al valor ASCII
        }
        str++ ;
    }
}

// b. Convierte todas las letras de una cadena a minúsculas
void lowerStr( char* str ) {
    while( *str ) {
        if( ('A' <= *str) && (*str <= 'Z') ) {
            *str = *str + 32 ; // Convierte a minúscula sumando 32 al valor ASCII
        }
        str++ ;
    }
}

// c. Convierte un número entero a una cadena de caracteres
void numToStr( int num, char* str ) {
    int len = 0 ;

    strcpy( str , "" ) ; // Inicializa la cadena como vacía

    // Maneja números negativos
    if( num < 0 ) {
        num = -num; // Convierte el número a positivo
        str[ len ] = '-' ; // Agrega el signo negativo al inicio de la cadena
        len++ ; // Incrementa la longitud de la cadena
    }

    // Convierte el número a caracteres (en orden inverso)
    do {
        int digito = ( num % 10 ) ; // Obtiene el último dígito del número
        str[ len ] = ( '0' + digito ) ; // Convierte el dígito a carácter
        num  = ( num / 10 ) ; // Elimina el último dígito del número
        len++ ; // Incrementa la longitud de la cadena
    } while( num != 0 ) ;

    str[ len ] = '\0' ; // Agrega el terminador nulo al final de la cadena

    // Invierte la cadena para que quede en el orden correcto
    for( int i = 0 ; i < (len / 2) ; i++ ) {
        char temp = str[ i ] ; // Guarda el carácter actual en una variable temporal
        str[ i ] = str[ (len - 1) - i ] ; // Intercambia el carácter actual con su opuesto
        str[ (len - 1) - i ] = temp ; // Coloca el carácter temporal en su nueva posición
    }
}

// d. Convierte un número (0-99) a su representación en texto
void numToText( int num, char* str ) {
    const char* unidades[] = { "cero" , "uno" , "dos" , "tres" , "cuatro" , "cinco" , "seis" , "siete" , "ocho" , "nueve" } ;
    const char* especiales[] = { "diez" , "once" , "doce" , "trece" , "catorce" , "quince" , "dieciséis" , "diecisiete" , "dieciocho" , "diecinueve" } ;
    const char* decenas[] = { "" , "" , "veinte" , "treinta" , "cuarenta" , "cincuenta" , "sesenta" , "setenta" , "ochenta" , "noventa" } ;

    if ( num < 10 ) {
        strcpy( str , unidades[ num ] ) ; // Copia la unidad correspondiente
    } else if ( num < 20 ) {
        strcpy( str , especiales[ num - 10 ] ) ; // Copia el número especial correspondiente
    } else {
        int dec = ( num / 10 ) ; // Obtiene la decena
        int uni = ( num % 10 ) ; // Obtiene la unidad

        strcpy( str , decenas[ dec ] ) ; // Copia la decena al inicio de la cadena

        if ( uni != 0 ) {
            strcat( str , " y " ) ; // Agrega " y " si hay unidades
            strcat( str , unidades[ uni ] ) ; // Agrega la unidad correspondiente
        }
    }
}

int main( ) {
    char str [ 100 ] = "" ;

    // Prueba de upperStr
    strcpy( str , "hola mundo" ) ;
    upperStr( str ) ;
    printf( "upperStr: %s\n" , str ) ;

    // Prueba de lowerStr
    strcpy( str , "HOLA MUNDO" ) ;
    lowerStr( str ) ;
    printf( "lowerStr: %s\n" , str ) ;

    // Prueba de numToStr
    int num = 124 ;
    numToStr( num, str ) ;
    printf( "numToStr: %s\n" , str ) ;

    // Prueba de numToText
    num = 35 ;
    numToText( num, str ) ;
    printf( "numToText: %s\n" , str ) ;

    return( 0 ) ;
}