/*
    a.
        ¿En qué se diferencia la función malloc de la función calloc?
            malloc reserva memoria sin inicializar, mientras que calloc reserva memoria e inicializa todos los bytes a cero.

        ¿y de la función realloc?
            realloc cambia el tamaño de un bloque de memoria previamente reservado con malloc/calloc, pudiendo moverlo si es necesario.
    b.
        ¿Puede utilizarse la función realloc en lugar de la función malloc?
            Sí, si se pasa un puntero NULL a realloc, actúa como malloc.

        ¿Se requiere alguna condición?
            El puntero debe ser NULL para que realloc funcione como malloc.

        ¿Qué sucede si realloc se invoca con el valor 0 como parámetro?
            Si el tamaño es 0, realloc libera la memoria y devuelve NULL.
    c.
        ¿Qué utilidad tiene el operador sizeof a la hora de reservar memoria dinámicamente?
            sizeof permite calcular el tamaño exacto de un tipo de dato, asegurando que se reserve la cantidad correcta de memoria.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr  ;
    int n = 5 ;

    // Reservar memoria para un arreglo de 5 enteros
    arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf( "Error al reservar memoria.\n" ) ;

        return( 1 ) ;
    }

    // Inicializar y mostrar los valores
    for( int i = 0 ; i < n ; i++ ) {
        arr[i] = i * 2 ;
        printf( "arr[%d] = %d\n", i, arr[i] ) ;
    }

    // Liberar la memoria reservada
    free( arr ) ;

    return( 0 ) ;
}

/*
Resumen:
- malloc: Reserva un bloque de memoria de tamaño especificado en bytes, pero no inicializa su contenido (puede contener basura).
- calloc: Reserva memoria para un número de elementos de un tamaño dado y además inicializa toda la memoria a cero.
- realloc: Cambia el tamaño de un bloque de memoria previamente reservado. Si es necesario, puede mover el bloque a una nueva ubicación y copiar el contenido existente. Si el nuevo tamaño es mayor, el contenido adicional no está inicializado.
*/