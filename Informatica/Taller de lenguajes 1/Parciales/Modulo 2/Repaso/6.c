/*
 * 6. (1 punto) Escriba un programa que reciba una secuencia de palabras como argumentos a la función main e imprima una única frase conformada por la concatenación de todas ellas separándolas entre sí por un blanco. 
 * En caso de que el programa no reciba ninguna palabra se debe imprimir un mensaje de error.
 * * --- SOLUCION ---
 * Se utiliza el bucle 'for' desde el índice 1 (el primer argumento después del nombre del programa) 
 * hasta 'argc - 1', y se imprime un espacio solo si no es la última palabra.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * argc: Argument Count (Número de argumentos, incluyendo el nombre del programa)
 * argv: Argument Vector (Array de cadenas de argumentos)
 */
int main(int argc, char *argv[]) {
    
    // Verificacion de argumentos: Si argc == 1, solo se ejecuto el nombre del programa.
    if (argc == 1) {
        printf("Error: El programa no recibio ninguna palabra como argumento.\n");
        printf("Uso: ./programa palabra1 palabra2 ...\n");
        return 1;
    }

    printf("Frase concatenada: \"");

    // Iteramos desde el primer argumento de palabra (i=1) hasta el ultimo (argc - 1).
    for (int i = 1; i < argc; i++) {
        
        // Imprimir la palabra actual
        printf("%s", argv[i]);
        
        // Imprimir un espacio separador, SÓLO si quedan más palabras.
        if (i < argc - 1) {
            printf(" ");
        }
    }

    printf("\"\n");

    return 0;
}