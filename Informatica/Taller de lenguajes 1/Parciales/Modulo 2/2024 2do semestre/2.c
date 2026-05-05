// defina una macro que dados cinco caracteres retorne:
//      "SI" cuando la mayoria sean letras minusculas
//      "NO" en caso contrario

// luego escriba un programa que utilice la macro para imprimir lo siguiente
//      { 'e' , 's' , ';' , '-' , '+' } --> "NO"
//      { '-' , 'w' , '+' , 't' , 'z' } --> "SI"
//      { 'f' , '@' , '(' , '}' , '?' } --> "NO"

#define ES_MINUSCULA(c) ( ('a' <= (c)) && ((c) <= 'z') )

#define MAYORIA_MINUSCULAS(a,b,c,d,e) ( 3 <= ( ES_MINUSCULA(a) + ES_MINUSCULA(b) + ES_MINUSCULA(c) + ES_MINUSCULA(d) + ES_MINUSCULA(e) )? "SI" : "NO" )

#include <stdio.h>

int main() {
    printf( "{ 'e' , 's' , ';' , '-' , '+' } --> %s\n", MAYORIA_MINUSCULAS('e', 's', ';', '-', '+') ) ;
    printf( "{ '-' , 'w' , '+' , 't' , 'z' } --> %s\n", MAYORIA_MINUSCULAS('-', 'w', '+', 't', 'z') ) ;
    printf( "{ 'f' , '@' , '(' , '}' , '?' } --> %s\n", MAYORIA_MINUSCULAS('f', '@', '(', '}', '?') ) ;

    return( 0 ) ;
}