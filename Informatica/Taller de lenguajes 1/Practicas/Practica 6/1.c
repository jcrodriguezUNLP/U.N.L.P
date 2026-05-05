// Analice, compile y ejecute el siguiente código:

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char* argv[] ){
    printf( "\nargc = %d" , argc ) ;            // imprime el número de argumentos

    printf( "\nargv[0] => %s" , argv[0] ) ;     // imprime el primer argumento (nombre del programa)
                                                // ya que argv es un arreglo de cadenas (arreglo de punteros a char)
                                                // argv[0] es el nombre del programa
                                                // argv[n] 0 < n es el n argumento pasado al programa
}