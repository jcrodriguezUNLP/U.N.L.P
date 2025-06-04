#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string más \0

// leer un string
void leerPalabra(char str[], int maxLength) {
    printf("\nIngrese una palabra: ");
    scanf("%s", str); // Leer un string
}

// Función para reemplazar todas las ocurrencias de un carácter por otro
char* reemplazarCaracter(char* str, char original, char reemplazo) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == original) {
            str[i] = reemplazo;
        }
    }
    return str; // Retornar la cadena modificada
}

int main() {
    char str[STRING_SIZE] = "" ; // Cadena de caracteres

    // Leer una palabra
    leerPalabra(str, STRING_SIZE);

    // Caracteres a reemplazar
    char original, reemplazo;
    printf("\nIngrese el carácter a reemplazar: ");
    scanf(" %c", &original); // Leer un carácter
    printf("Ingrese el carácter de reemplazo: ");
    scanf(" %c", &reemplazo); // Leer un carácter

    // Reemplazar caracteres en la cadena
    char retornada[STRING_SIZE] = reemplazarCaracter(str, original, reemplazo);

    // Imprimir la cadena modificada
    printf("\nCadena modificada: %s\n", str);

    return 0;
}