/*
 * 2) Escriba un programa que procese un archivo de texto e informe la cantidad de caracteres
 * minúsculas, mayúsculas y dígitos que posee.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para islower, isupper, isdigit

#define FILENAME "datos.txt"

/**
 * @brief Procesa un archivo de texto y cuenta minusculas, mayusculas y digitos.
 */
void procesar_archivo() {
    FILE *f = fopen(FILENAME, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo de texto");
        printf("Asegurese de crear el archivo '%s' con contenido.\n", FILENAME);
        return;
    }

    int c;
    long minusculas = 0;
    long mayusculas = 0;
    long digitos = 0;

    // fgetc lee un solo caracter a la vez y avanza el puntero.
    while ((c = fgetc(f)) != EOF) {
        // c es un int para poder capturar el valor EOF (-1).
        
        if (islower(c)) {
            minusculas++;
        } else if (isupper(c)) {
            mayusculas++;
        } else if (isdigit(c)) {
            digitos++;
        }
        // Los demas caracteres (espacios, simbolos, saltos de linea) son ignorados.
    }

    fclose(f);

    printf("\n--- Resultados del analisis de '%s' ---\n", FILENAME);
    printf("Caracteres minusculas: %ld\n", minusculas);
    printf("Caracteres mayusculas: %ld\n", mayusculas);
    printf("Digitos (0-9):         %ld\n", digitos);
}

int main() {
    printf("Programa de conteo de caracteres en archivo.\n");
    procesar_archivo();
    return 0;
}