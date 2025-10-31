// Escriba un programa que reserve en forma dinámica un arreglo de 100 caracteres. A continuación, lea 
// 10  oraciones  utilizando  la  función  gets  e  informe  para  cada  una  de  ellas  la  cantidad  de  letras 
// minúsculas y de letras mayúsculas que la componen. Utilice el arreglo creado como variable temporal 
// para procesar cada oración. Por último, libere la memoria reservada dinámicamente.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Ingrese una oracion (%d/10): ", i + 1);
        fgets(buffer, 100, stdin);

        int mayus = 0, minus = 0;
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (isupper((unsigned char)buffer[j]))
                mayus++;
            else if (islower((unsigned char)buffer[j]))
                minus++;
        }
        printf("Mayusculas: %d, Minusculas: %d\n", mayus, minus);
    }

    free( buffer ) ;
    return 0 ;
}