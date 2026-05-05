/*
17.  Dado el siguiente código:
    Se crea y retorna un "tensor" 3D dinámico de tamaño t x t x t usando punteros.
    Este archivo fue modificado para:
    - Comprobar errores de asignación
    - Añadir una función para liberar la memoria
    - Hacer que el fichero sea compilable y demostrable

    Analice el código y realice un diagrama de cómo se reserva memoria para la variable a y cómo queda
    la variable e luego del llamado al módulo. ¿Por qué es necesario que la variable a sea de tipo int***?
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

int*** crearTensor(int t){
    if (t <= 0) return NULL;
    int i, j, ii, jj;
    int*** a = (int***) calloc(t, sizeof(int**));
    if (!a) return NULL;

    for (i = 0; i < t; i++){
        a[i] = (int**) calloc(t, sizeof(int*));
        if (!a[i]){
            /* liberar lo asignado hasta ahora */
            for (ii = 0; ii < i; ii++){
                if (a[ii]){
                    for (jj = 0; jj < t; jj++) free(a[ii][jj]);
                    free(a[ii]);
                }
            }
            free(a);
            return NULL;
        }

        for (j = 0; j < t; j++){
            a[i][j] = (int*) calloc(t, sizeof(int));
            if (!a[i][j]){
                /* liberar lo asignado en la fila i y en filas anteriores */
                for (jj = 0; jj < j; jj++) free(a[i][jj]);
                free(a[i]);
                for (ii = 0; ii < i; ii++){
                    if (a[ii]){
                        for (jj = 0; jj < t; jj++) free(a[ii][jj]);
                        free(a[ii]);
                    }
                }
                free(a);
                return NULL;
            }
        }
    }
    return a;
}

/*
 * liberarTensor: libera toda la memoria asignada por crearTensor
 * a: puntero al tensor
 * t: dimensión usada para crear el tensor
 */
void liberarTensor(int*** a, int t){
    if (!a) return;
    int i, j;
    for (i = 0; i < t; ++i){
        if (a[i]){
            for (j = 0; j < t; ++j){
                free(a[i][j]);
            }
            free(a[i]);
        }
    }
    free(a);
}

int main(void)
{
    int*** e = crearTensor(N);
    if (e == NULL){
        fprintf(stderr, "Error: fallo en la asignación del tensor\n");
        return 1;
    }

    /* prueba rápida: asignar y leer un valor */
    e[0][0][0] = 42;
    printf("e[0][0][0] = %d\n", e[0][0][0]);

    liberarTensor(e, N);
    return 0;
}

