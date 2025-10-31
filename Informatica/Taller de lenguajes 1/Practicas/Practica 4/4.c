// Escriba  un  programa  que  lea  un  número  entero  n  desde  teclado  y  luego  reserve  memoria  en  forma 
// dinámica  para  un  arreglo  de  n  float.  Inicialícelo  con  valores  ingresados  por  teclado  y  a  continuación 
// calcule e imprima el promedio de todos ellos. Por último, libere la memoria reservada dinámicamente.  
// Nota: Modularice la reserva de memoria, la inicialización y el cálculo del promedio.

#include <stdio.h>
#include <stdlib.h>

// Reserva memoria para un arreglo de n floats
float* reservar_memoria(int n) {
    return (float*)malloc(n * sizeof(float));
}

// Inicializa el arreglo con valores ingresados por teclado
void inicializar_arreglo(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}

// Calcula el promedio de los elementos del arreglo
float calcular_promedio(float* arr, int n) {
    float suma = 0.0f;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma / n;
}

int main() {
    int n;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    float* arreglo = reservar_memoria(n);
    if (arreglo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    inicializar_arreglo(arreglo, n);

    float promedio = calcular_promedio(arreglo, n);
    printf("El promedio es: %.2f\n", promedio);

    free(arreglo);
    return 0;
}