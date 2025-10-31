// Escriba  un  programa  que  lea  un  número  entero  n  desde  teclado  y  luego  reserve  memoria  en  forma 
// dinámica  para  un  arreglo  de  n  enteros.  Inicialícelo  con  valores  aleatorios  y  a  continuación  calcule  e 
// imprima  el  máximo  número  almacenado.  Por  último,  libere  la  memoria  reservada  dinámicamente. 
// Nota: Modularice la reserva de memoria, la inicialización y el cálculo del máximo. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para reservar memoria para un arreglo de n enteros
int* reservar_memoria(int n) {
    return (int*)malloc( n * sizeof(int) ) ;
}

// Función para inicializar el arreglo con valores aleatorios entre 0 y 99
void inicializar_arreglo(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Función para calcular el máximo valor en el arreglo
int calcular_maximo(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int n;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    // Reservar memoria
    int* arreglo = reservar_memoria(n);
    if (arreglo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    // Inicializar arreglo
    srand(time(NULL));
    inicializar_arreglo(arreglo, n);

    // Calcular e imprimir el máximo
    int maximo = calcular_maximo(arreglo, n);
    printf("El valor máximo es: %d\n", maximo);

    // Liberar memoria
    free(arreglo);

    return 0;
}