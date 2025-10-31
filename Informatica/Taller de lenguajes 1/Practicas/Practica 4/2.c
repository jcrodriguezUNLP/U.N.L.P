#include <stdio.h> 
#include <stdlib.h> 
 
// Declaración de la función f, que recibe un puntero a int
void f( int * p ) ; 
 
int main(){ 
 
    int * ptr = NULL; // Se declara un puntero a int y se inicializa en NULL
    f(ptr);           // Se llama a la función f pasando ptr como argumento
 
    // Se verifica si ptr sigue siendo NULL
    if (ptr == NULL) 
        printf("ptr es NULL\n");      // Si ptr es NULL, imprime este mensaje
    else 
        printf("ptr no es NULL\n");  // Si ptr no es NULL, imprime este mensaje
 
    return 0; // Fin del programa
} 
 
// Definición de la función f
void f( int * p ) { 
    // Se reserva memoria para 10 enteros y se asigna a p
    // Pero p es una copia local del puntero, no afecta a ptr en main
    p = (int *) malloc( 10*sizeof(int) ) ; 
}