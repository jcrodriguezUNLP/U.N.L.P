// El  objetivo  del  siguiente  código  es  leer  dos  caracteres  de  teclado  e  imprimirlos  en  pantalla.
// ¿El código cumple con su cometido?
// En caso negativo, corríjalo para que lo haga. 
 
#include <stdio.h> 

int main() { 
    char a ;
    char b ;

    printf( "Ingrese el primer caracter:\n" ) ; 
    scanf ( " %c" , &a                      ) ; // Note el espacio antes de %c, para ignorar espacios en blanco previos
    printf( "Se leyo el caracter: %c\n" , a ) ; 
    
    printf( "Ingrese el segundo caracter:\n" ) ; 
    scanf ( " %c" , &b                       ) ; 
    printf( "Se leyo el caracter: %c\n" , b  ) ; 
    
    return( 0 ) ; 
}