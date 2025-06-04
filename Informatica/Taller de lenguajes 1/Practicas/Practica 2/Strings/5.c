#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string mas \0

// leer un string
void leerPalabra( char str[] , int maxLength ){
    printf("\nIngrese una palabra (o 'ZZZ' para terminar): ");
    scanf("%s", str); // Leer un string
}

// Implementación propia de la función strlen
void my_strcpy(char* dest, const char* src) {
    while( *src ) {
        *dest = *src ; // Copiar el caracter
        
        dest++ ; // Avanzar al siguiente caracter
        src ++ ; // Avanzar al siguiente caracter
    }
}

int main() {
    char str[ STRING_SIZE ] = "" ;

    leerPalabra( str , STRING_SIZE ) ; // Leer una palabra

    char strCopy1[STRING_SIZE] = "dado";
    char strCopy2[STRING_SIZE] = "mio";

    // Usar strcpy
    strcpy(strCopy1, str);
    printf("Resultado usando strcpy: %s\n", strCopy1);

    // Usar my_strcpy
    my_strcpy(strCopy2, str);
    printf("Resultado usando my_strcpy: %s\n", strCopy2);

    printf("\n");

    return 0;
}