// Analice el siguiente código e indique cuál es la opción correcta:

#include <stdio.h>

int main() {
    int a , cant = 0 ;              // ----> | int a ;
                                    //       | int cant = 0 ;

    scanf( "%d" , &a ) ;            // leer a 

    while( a % 3 ) {                // entra si a no es multiplo de 3
        ++cant ;                    // incrementa la calidad

        scanf( "%d" , &a ) ;        // vuelve a leer para continuar el bucle
    }

    return( 0 ) ;
}
// ____
// |  | El programa almacena en cant la cantidad de números leídos hasta ingresar el 3. 
// ----
// _____
// | x | El programa almacena en cant la cantidad de números leídos consecutivamente que no son múltiplos de 3. 
// -----
// ____
// |  | El programa almacena en cant la cantidad de números leídos consecutivamente que son múltiplos de 3. 
// ----
// ____
// |  | El programa no compila
// ----