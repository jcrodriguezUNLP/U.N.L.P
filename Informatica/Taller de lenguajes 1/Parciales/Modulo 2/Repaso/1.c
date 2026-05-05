// 1. (1 punto) Indique qué imprime el siguiente código y corríjalo.

#include <stdio.h>
#include <string.h>

void cambioSTR( char * ) ;                      // Declaración de la función 'cambioSTR' que toma un puntero a char.

int main() {
    char* linea = malloc( 100 ) ;               // Reserva 100 bytes de memoria dinámica para almacenar una cadena de caracteres.
    
    strcpy( linea, "Caso posible" ) ;           // Copia la cadena "Caso posible" en la memoria apuntada por 'linea'.
    
    printf( "Linea: %s\n", (linea + 5) ) ;      // Imprime la subcadena comenzando desde el índice 5 de 'linea', que es "posible". 
    
    cambioSTR( linea ) ;                        // Llama a la función 'cambioSTR', pasando 'linea' como argumento.
    
    strcpy( (linea + 8), (linea + 11 ) ) ;      // Intenta copiar la subcadena desde el índice 11 de 'linea' a partir del índice 8. 
    
    printf( "Linea = %s\n", linea ) ;           // Imprime el contenido de 'linea' después de las modificaciones.
    
    return 0 ;
}

void cambioSTR( char* L ) {                     // Definición de la función 'cambioSTR' que toma un puntero a char.
    free( L ) ;                                 // Libera la memoria apuntada por 'L'.
    
    L = malloc( 200 ) ;                         // Reserva 200 bytes de memoria dinámica y asigna la dirección a 'L'.
    
    strcpy( L, "Nuevo " ) ;                     // Copia la cadena "Nuevo " en la memoria apuntada por 'L'.
    strcat( L, "texto"  ) ;                     // Concatena la cadena "texto" al final de la cadena en 'L'.
    
    printf( "L = %s\n", L ) ;                   // Imprime el contenido de 'L'.
}


//  * * --- ANÁLISIS ---
//  * 1. Salida Inicial:
//          printf( "Linea %s\n", (linea + 5) ) ;   ->   "posible\n" ( linea[5] en adelante ).
//                                                  "Caso posible\n"
//                                                        ^
//                                                        |
//                                                   012345678901

//  * 2. Error Critico:
//          Dentro de cambioSTR, 'free(L)' libera la memoria apuntada por 'linea' en main.

//  * Luego 'L = malloc(200)' reasigna SOLO la copia local del puntero 'L' a un nuevo bloque.
//  * La variable 'linea' en main queda como un PUNTERO COLGANTE (dangling pointer).
//  * 3. Fallo: La linea 'strcpy (linea+8, linea+11);' intenta escribir en memoria liberada, 
//  * resultando en COMPORTAMIENTO INDEFINIDO, que probablemente cause un fallo de segmentación.
//  * * IMPRESIÓN TEÓRICA ANTES DE FALLO:
//  * Linea posible
//  * L = Nuevo texto
//  * (Y luego un fallo/segmentation fault)
//  * * --- CORRECCIÓN ---
//  * Para reasignar el puntero 'linea' en main, la función debe recibir su DIRECCIÓN (char**).

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// La funcion ahora recibe un DOBLE PUNTERO (char**)
void cambioSTR(char** L) { 
    // Liberar la memoria antigua a traves del puntero original (*L)
    if (*L != NULL) {
        free(*L);
    }
    
    // Reasignar el puntero original (*L) a la nueva memoria
    *L = (char*)malloc(200); 
    if (*L == NULL) return;
    
    strcpy (*L, "Nuevo "); 
    strcat(*L, "texto");
    
    printf("L = %s\n", *L); 
}

int main() {
    char *linea = (char*)malloc(100);
    if (linea == NULL) return 1;
    
    strcpy(linea, "Caso posible");
    
    // 1. Imprime la subcadena
    printf("Linea %s\n", linea+5); 
    
    // 2. Llama a la funcion, pasando la DIRECCIÓN de 'linea'
    cambioSTR(&linea); 
    
    // 3. Esta linea NO tiene sentido si 'linea' ahora es "Nuevo texto", pero la incluimos
    //    como estaba en la consigna.
    //    En el caso de "Nuevo texto", linea+8 es 'x', linea+11 es '\0'
    //    Esto solo moveria el terminador nulo a linea[8].
    if (strlen(linea) > 11) {
        strcpy (linea+8, linea+11); 
    }
    
    // 4. Imprime el contenido reasignado
    printf("Linea = %s\n", linea);
    
    // 5. Liberar la nueva memoria antes de salir.
    free(linea); 
    return 0;
}