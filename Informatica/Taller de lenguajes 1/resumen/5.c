// 5. (1 Punto)
// Consigna:

// a. Defina una enumerativa que permita representar géneros musicales: Pop, Rock, Jazz, Electrónica, Hip-Hop, Clásica, Reggaetón y Salsa.

// b. Implemente una función que reciba un género e imprima un texto en pantalla con el valor correspondiente.

#include <stdio.h>

enum GeneroMusical {
    POP,
    ROCK,
    JAZZ,
    ELECTRONICA,
    HIP_HOP,
    CLASICA,
    REGGAETON,
    SALSA
};

void imprimir_genero(enum GeneroMusical genero) {

    printf( "El genero musical seleccionado es: " );
    switch (genero) {
        case POP:
            printf("Pop\n");
        break;
        case ROCK:
            printf("Rock\n");
        break;
        case JAZZ:
            printf("Jazz\n");
        break;
        case ELECTRONICA:
            printf("Electrónica\n");
        break;
        case HIP_HOP:
            printf("Hip-Hop\n");
        break;
        case CLASICA:
            printf("Clásica\n");
        break;
        case REGGAETON:
            printf("Reggaetón\n");
        break;
        case SALSA:
            printf("Salsa\n");
        break;
        default:
            printf("Género desconocido\n");
        break;
    }
}