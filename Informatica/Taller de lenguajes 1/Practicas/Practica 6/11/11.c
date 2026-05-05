// a.
//     Implemente la biblioteca istack.h
//     debe contener tipos y operaciones necesarias para manipular una estructura de datos pila que almacene números enteros.
//     Una pila es una estructura de datos homogénea y dinámica.
//     El acceso a la misma se dice que es de tipo LIFO (Last In First Out), lo que quiere decir que los elementos se recuperan en el orden inverso en que fueron insertados.
    
//     Implemente al menos las siguientes funciones: 
//     a. Stack* s_create (                 ) Retorna una nueva pila.Se debe invocar antes de manipular cualquiera de ellas.
//     b. int    s_push   (stack* s , int n ) Apila n en s.Retorna el elemento apilado.
//     c. int    s_pop    (stack* s         ) Desapila un elemento de s.
//     d. int    s_top    (stack  s         ) Retorna el próximo elemento que será desapilado.
//     e. int    s_empty  (stack  s         ) Retorna 1 si s está vacía, 0 en caso contrario.
//     f. int    s_length (stack  s         ) Retorna la cantidad de elementos apilados en s.
 
// b.
//     Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros y los inserte en una pila.
//     A continuación, desapile los elementos para verificar si funciona correctamente.
//     La lectura finaliza con el ingreso del 0.

// c.
//     Manteniendo la misma interfaz, modifique el tipo de datos stack y reimplemente la biblioteca para que la función s_length retorne la cantidad de elementos sin recorrer la pila.

#include <stdio.h>
#include "istack.h"

int main() {
    // 1. Crear la pila
    Stack* miPila = s_create();

    // 2. Apilar números (Push)
    printf("Apilando: %d\n", s_push(miPila, 10));
    printf("Apilando: %d\n", s_push(miPila, 20));
    printf("Apilando: %d\n", s_push(miPila, 30));

    printf("--- Estado actual ---\n");
    printf("La pila tiene %d elementos.\n", s_length(miPila));
    printf("El tope es: %d\n", s_top(miPila));
    printf("---------------------\n");

    // 3. Desapilar (Pop) - LIFO (El último en entrar es el primero en salir)
    while (!s_empty(miPila)) {
        printf("Desapilando: %d\n", s_pop(miPila));
    }

    // Verificar si quedó vacía
    if (s_empty(miPila)) {
        printf("La pila ha quedado vacia.\n");
    }

    return 0;
}