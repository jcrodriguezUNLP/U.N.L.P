// Indique qué imprime el siguiente código: 
 
#include <stdio.h>

int main() {
    int i , a = 0 ;                         // --> | int i ;
                                            //     | int a = 0 ;

    for( i = 0 ; i == 100 ; i++ ) {         // for mientras q a sea = a 100. a = a != 100 por lo tanto no entra
        a += 3 ;                            // incrementa a en 3
    }

    printf( "El valor de a es %d" , a ) ;    // error, deberia 

    return( 0 ) ;
}

// a. El valor de a es 300.  
// b. El valor de a es 0.       verdadero
// c. El valor de a es 100. 
// d. El valor de a es 303. 
// e. No imprime nada dado que el código presenta  errores  en  la  sintaxis  del  for  al compilar. 
// f. No  imprime  nada  dado  que  queda  en  un bucle infinito