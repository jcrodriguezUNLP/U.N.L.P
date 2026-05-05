#ifndef ISTACK_H
    #define ISTACK_H

    // Estructura para cada elemento (nodo) de la pila
    typedef struct node {
        int          data ;
        struct node* next ;
    } node_t ;

    // Estructura de control de la Pila
    typedef struct stack {
        node_t* top   ;  // Puntero al elemento superior
        int     count ;    // Contador de elementos (para s_length)
    } Stack ;

    // --- Prototipos ---

    // a. Crea una nueva pila vacía
    Stack* s_create() ;

    // b. Apila n en s. Retorna n.
    int s_push( Stack* s , int n );

    // c. Desapila y retorna el elemento.
    int s_pop( Stack* s ) ;

    // d. Retorna el próximo elemento sin desapilar (tope).
    int s_top( Stack* s ) ;

    // e. Retorna 1 si está vacía, 0 si no.
    int s_empty( Stack* s ) ;

    // f. Retorna la cantidad de elementos.
    int s_length( Stack* s ) ;
#endif