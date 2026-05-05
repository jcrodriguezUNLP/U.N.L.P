#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cambioSTR(char *);
int main()
{
    char* linea = malloc(100);

    strcpy(linea, "Caso posible");
    printf("Linea = %s\n", linea+5);

    printf("ptr a linea --> %p\n", linea);

    cambioSTR(linea);

    printf("ptr a linea --> %p\n", linea);

    strcpy(linea+8, linea+11);
    printf("Linea = %s\n", linea);

    return 0;
}

void cambioSTR(char * L){
    char * aux;

    L = NULL;

    printf("ptr L en la funcion --> %p\n", L);

    L = malloc(200);

    printf("ptr L en la funcion --> %p\n", L);

    strcpy(L, "Nuevo ");
    strcat(L, "texto");

    printf("L = %s\n", L);
}
