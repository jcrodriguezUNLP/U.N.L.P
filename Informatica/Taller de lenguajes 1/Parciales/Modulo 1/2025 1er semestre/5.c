// A)
//      defina un enumerativo que permita representar generos musicales
//          pop
//          rock
//          jazz
//          electronica
//          hip-hop
//          clasica
//          reggaeton
//          salsa

// B)
//     implemente una funcion que reciba un genero e imprima en pantalla el valor correspondiente

#include <stdio.h>

typedef enum {
    pop = 1     ,
    rock        ,
    jazz        ,
    electronica ,
    hipHop      ,
    clasica     ,
    reggaeton   ,
    salsa       ,

} TGenerosMusicales ;

void imprimirGeneroMusical( TGenerosMusicales generoMusical ) {
    printf( "%d" , generoMusical ) ;
}