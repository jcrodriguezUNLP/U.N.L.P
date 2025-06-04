#include <stdio.h>

#define CANT_DATOS 10

// Función 1
void opcion1(int datos[]) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        datos[i] = datos[i] * 0.5;
    }
}

/*
Explicación:
- Tarea: Recorre el array `datos` usando índices y multiplica cada elemento por `0.5`.
- Diferencias:
  - Usa notación de índices (`datos[i]`).
  - Es clara y fácil de entender.
- Advertencias: No genera advertencias.
*/

// Función 2
void opcion2(int *datos) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        (*datos++) = (*datos) / 2;
    }
}

/*
Explicación:
- Tarea: Recorre el array usando un puntero y divide cada elemento por `2`.
- Diferencias:
  - Usa aritmética de punteros (`*datos` y `datos++`).
  - Modifica el puntero `datos` al avanzar.
- Advertencias: Puede generar la advertencia "operation on 'datos' may be undefined" porque `datos++` se evalúa dos veces en la misma línea, lo que puede causar un comportamiento indefinido.
*/

// Función 3
void opcion3(int *datos) {
    int i;
    for (i = 0; i < CANT_DATOS; i++, datos++) {
        *datos = *datos * 0.5;
    }
}

/*
Explicación:
- Tarea: Recorre el array usando un puntero y multiplica cada elemento por `0.5`.
- Diferencias:
  - Usa aritmética de punteros (`*datos`).
  - El puntero `datos` avanza con `datos++` en el encabezado del `for`.
- Advertencias: No genera advertencias.
*/

// Función 4
void opcion4(int datos[]) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        *datos++ = *datos / 2;
    }
}

/*
Explicación:
- Tarea: Recorre el array usando un puntero y divide cada elemento por `2`.
- Diferencias:
  - Usa aritmética de punteros (`*datos` y `datos++`).
  - Modifica el puntero `datos` al avanzar.
- Advertencias: Puede generar la advertencia "operation on 'datos' may be undefined" porque `datos++` se evalúa dos veces en la misma línea, lo que puede causar un comportamiento indefinido.
*/

// Función 5
void opcion5(int datos[]) {
    int i;
    for (i = 0; i < CANT_DATOS; i++, datos--) {
        *datos++ = *datos++ * 0.5;
    }
}

/*
Explicación:
- Tarea: Intenta recorrer el array y multiplicar cada elemento por `0.5`.
- Diferencias:
  - Usa aritmética de punteros (`*datos` y `datos++`).
  - Modifica el puntero `datos` de forma inconsistente (`datos--` en el encabezado y `datos++` en el cuerpo).
- Advertencias: Genera "operation on 'datos' may be undefined" porque `datos++` se evalúa dos veces en la misma línea, lo que causa un comportamiento indefinido.
*/

// Función 6
void opcion6(int *datos) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        *datos = *datos++ * 0.5;
    }
}

/*
Explicación:
- Tarea: Intenta recorrer el array y multiplicar cada elemento por `0.5`.
- Diferencias:
  - Usa aritmética de punteros (`*datos` y `datos++`).
  - Modifica el puntero `datos` al avanzar.
- Advertencias: Genera "operation on 'datos' may be undefined" porque `datos++` se evalúa dos veces en la misma línea, lo que causa un comportamiento indefinido.
*/

// Función 7
void opcion7(int datos[]) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        datos[i] = *(datos + i) * 0.5;
    }
}

/*
Explicación:
- Tarea: Recorre el array usando índices y multiplica cada elemento por `0.5`.
- Diferencias:
  - Usa una combinación de notación de índices (`datos[i]`) y aritmética de punteros (`*(datos + i)`).
  - Es redundante porque `datos[i]` ya es equivalente a `*(datos + i)`.
- Advertencias: No genera advertencias.
*/

// Función 8
void opcion8(int *datos) {
    int i;
    for (i = 0; i < CANT_DATOS; i++) {
        *(datos + i) = datos[i] / 2;
    }
}

/*
Explicación:
- Tarea: Recorre el array usando aritmética de punteros y divide cada elemento por `2`.
- Diferencias:
  - Usa una combinación de notación de índices (`datos[i]`) y aritmética de punteros (`*(datos + i)`).
  - Es redundante porque `*(datos + i)` ya es equivalente a `datos[i]`.
- Advertencias: No genera advertencias.
*/