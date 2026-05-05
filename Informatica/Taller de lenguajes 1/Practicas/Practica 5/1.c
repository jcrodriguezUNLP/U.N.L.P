/*
 * 1) El siguiente código lee la información de un archivo de texto y la imprime en la pantalla.
 * Analice, compile y ejecute el programa. Utilice el archivo "prueba.txt" provisto por la cátedra.
 * ¿El código funciona correctamente? Si no es así, corríjalo para que lo haga.
 * Nota: Preste atención al formato del archivo. La función fgets() procesa hasta encontrar un salto de
 * línea (el cual es retenido). Si luego del último renglón no hubiese un salto de línea, el archivo no
 * tendría un formato válido para procesar.
 * * CÓDIGO ORIGINAL:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #define LONG 300
 * int main() {
 * FILE *f;
 * char linea [LONG];
 * // Abrir el archivo
 * f = fopen("prueba.txt", "r");
 * if (f == NULL) {
 * printf ("\nError al abrir archivo fuente\n");
 * return 1;
 * }
 * while (!feof(f)) {
 * // leer una linea del archivo
 * fgets (linea, LONG, f);
 * // imprimir la linea en la pantalla
 * puts (linea);
 * }
 * fclose(f);
 * return 0;
 * }
 */

#include <stdio.h> 
#include <stdlib.h> 
#define LONG 300 

int main() { 
    FILE *f; 
    char linea [LONG]; 
    
    printf("Programa de lectura de archivo (Corregido).\n");
    
    // Abrir el archivo
    f = fopen("prueba.txt", "r"); 
    if (f == NULL) { 
        printf ("\nError al abrir archivo fuente (Asegurese de que 'prueba.txt' exista)\n"); 
        return 1; 
    } 

    // --- CORRECCIÓN CLAVE ---
    // El codigo original funciona incorrectamente porque la funcion feof(f) solo 
    // retorna verdadero *despues* de que una lectura intento pasar el fin de archivo.
    // Esto hace que la ultima linea se procese DOS veces (o se procese una linea 
    // vacia adicional).
    // La forma correcta es verificar el exito de la lectura (fgets) directamente.
    
    printf("\nContenido de prueba.txt:\n");
    while (fgets(linea, LONG, f) != NULL) {
        // La funcion fgets() lee una linea (incluyendo '\n') o NULL si falla/llega al EOF.
        // imprimir la linea en la pantalla
        puts(linea); 
    } 

    fclose(f); 
    printf("\nArchivo cerrado exitosamente.\n");
    return 0; 
}