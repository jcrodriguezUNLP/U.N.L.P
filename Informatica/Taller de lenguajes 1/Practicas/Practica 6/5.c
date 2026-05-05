// Analice y ejecute el siguiente código:

#include <stdio.h> 
#include <stdlib.h> 
 
// #define size 25  --> error 
#define SIZE 25     // corrección
 
void imprimir( int* v , int size ){ 
    for( int i = 0 ; i < size ; i++ ){ 
        printf( "v[%d] = %d\n" , i , v[i] ) ; 
    } 
} 
 
int main(){ 
    // int v[ size ] ;  --> error
    int v[ SIZE ] ;     // corrección

    // faltaria inicializar el arreglo v antes de imprimir
    // no da error pero imprime valores basura

    // imprimir( v , size ) ;  --> error
    imprimir( v , SIZE ) ;     // correccion

    return( 0 ) ; 
} 

// A)
//     El código compila?
//          No.
//     Lea detenidamente el primer error que se detecta
//     ¿Cómo se explica?
//          El error se debe a que la macro "size" no está definida correctamente.
//          En C, las macros deben estar en mayúsculas por convención para evitar conflictos con nombres de variables.
// B)
//     Identifique las etapas de precompilación y compilación
//     ¿Qué es lo que está ocurriendo en cada una?  
//          Durante la precompilación, el preprocesador reemplaza todas las ocurrencias de "size" con "25", pero dado que "size" no está definido como una macro, esto causa un error.
// C)
//     ¿Cómo podría solucionarse este problema? 
//          Definiendo la macro correctamente como "SIZE" y utilizando "SIZE" en lugar de "size" en el código.