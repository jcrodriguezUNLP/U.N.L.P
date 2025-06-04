#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string más \0

// leer un string
void leerPalabra(char str[], int maxLength) {
    printf("\nIngrese una palabra (o 'XXX' para terminar): ");
    scanf("%s", str); // Leer un string
}

int cantPalabrasTerminanConO() {
    char str[STRING_SIZE] = "";
    int contador = 0;
    int notFin;

    do {
        leerPalabra(str, STRING_SIZE); // Leer una palabra

        // Comparar la palabra con "XXX"
        notFin = strcmp(str, "XXX") == 0 ? 0 : 1;

        if (notFin) {
            // Verificar si la palabra termina con 'o'
            int len = strlen(str);
            if( (0 < len) && (str[ (len - 1) ] == 'o') ) {
                contador++;
            }
        }
    } while (notFin);

    return( contador ) ; // Retornar la cantidad de palabras que terminan con 'o'
}

int main() {
    printf("\nCantidad de palabras que terminan con 'o': %d", cantPalabrasTerminanConO());

    printf("\n");

    return 0;
}