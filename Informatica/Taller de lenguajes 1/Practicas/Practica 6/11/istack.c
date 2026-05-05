#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

// a. Crear pila
Stack* s_create() {
    Stack* s = ( Stack* )malloc( sizeof(Stack) ) ;
    
    if( s != NULL ){
        s->top   = NULL ;   // Inicialmente no apunta a nada
        s->count = 0    ;   // Tamaño 0
    }

    return( s ) ;
}

// b. Push (Apilar)
int s_push( Stack* s , int n ){
    // 1. Crear el nuevo nodo
    node_t* new_node = ( node_t* )malloc( sizeof(node_t) ) ;
    
    if( new_node == NULL ){
        return( -1 ) ; // Error de memoria
    }

    // 2. Cargar datos
    new_node -> data = n ;

    // 3. Conectar: El nuevo apunta al antiguo tope
    new_node -> next = s -> top ;

    // 4. Actualizar tope: El nuevo nodo es ahora el tope
    s -> top = new_node ;
    s -> count++ ;

    return( n ) ;
}

// c. Pop (Desapilar)
int s_pop( Stack* s ){
    if( s_empty(s) ){
        printf( "Error: Pila vacia.\n" ) ;

        return( 0 ) ; // O manejar error según necesidad
    }

    // 1. Identificar el nodo a eliminar (el tope actual)
    node_t* aux  = s   -> top  ;
    int     data = aux -> data ; // Guardamos el dato para retornarlo

    // 2. Mover el tope al siguiente nodo
    s -> top = aux -> next ;

    // 3. Liberar la memoria del nodo eliminado
    free(aux);
    s -> count-- ;

    return( data ) ;
}

// d. Top (Ver tope)
int s_top( Stack* s ) {
    if( s_empty(s) ){
        // En C no hay excepciones, retornamos un valor dummy o error
        return( 0 ) ; 
    }

    return( s -> top -> data ) ;
}

// e. Empty (Vacia)
int s_empty( Stack* s ) {
    // Si top es NULL, la pila está vacía
    if (s -> top == NULL ){
        return 1 ;
    }
    
    return 0;
}

// f. Length (Longitud)
int s_length( Stack* s ) {
    return( s -> count ) ;
}