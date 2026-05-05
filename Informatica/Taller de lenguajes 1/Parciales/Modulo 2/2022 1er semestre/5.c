// Se desea implementar un programa que recorra un archivo de texto y obtenga todas las posiciones en donde se encuentran todas las ocurrencias de un determinado caracter.
// Dichas posiciones se deben almacenar en un archivo binario.
// Los nombres de los archivos y el caracter se leen de teclado

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definición de variables y punteros a archivo
    FILE *archTexto   ;
    FILE *archBinario ;
    
    char nombreTxt[100]  ;
    char nombreBin[100]  ;
    char caracterBuscado ;
    char caracterLeido   ;
    long posicion = 0    ; // Usamos long para las posiciones (indices)
    
    // ---------------------------------------------------------
    // 1. Lectura de datos por teclado
    // ---------------------------------------------------------
    printf("Ingrese el nombre del archivo de TEXTO (origen): ");
    scanf("%s", nombreTxt);

    printf("Ingrese el nombre del archivo BINARIO (destino): ");
    scanf("%s", nombreBin);

    printf("Ingrese el caracter a buscar: ");
    // El espacio antes de %c limpia el buffer del salto de línea anterior
    scanf(" %c", &caracterBuscado) ; 

    // ---------------------------------------------------------
    // 2. Apertura de Archivos
    // ---------------------------------------------------------
    
    // Abrimos el archivo de texto en modo "r" (lectura) 
    // Fuente: 08_Archivos de texto en C.pdf [cite: 220, 496]
    archTexto = fopen( nombreTxt, "r" );

    if (archTexto == NULL) {
        printf("Error: No se pudo abrir el archivo de texto '%s'.\n", nombreTxt);
        return 1;
    }

    // Abrimos el archivo binario en modo "wb" (escritura binaria)
    // "wb": Crea un archivo binario; si existe, descarta el contenido.
    // Fuente: 09Archivos-Binarios-en-C.pdf 
    archBinario = fopen(nombreBin, "wb");

    if (archBinario == NULL) {
        printf("Error: No se pudo crear el archivo binario '%s'.\n", nombreBin);
        fclose(archTexto); // Cerramos el que sí se abrió
        return 1;
    }

    // ---------------------------------------------------------
    // 3. Procesamiento (Recorrido y Escritura)
    // ---------------------------------------------------------
    
    // Leemos el primer carácter usando fgetc
    // Fuente: 08_Archivos de texto en C.pdf 
    caracterLeido = fgetc(archTexto);

    // Usamos feof para controlar el final del archivo
    // Fuente: 08_Archivos de texto en C.pdf [cite: 559, 620]
    while (!feof(archTexto)) {
        
        if (caracterLeido == caracterBuscado) {
            // Si encontramos el caracter, guardamos la 'posicion' en el binario.
            // Usamos fwrite para escribir la variable 'posicion' directamente.
            // Sintaxis: fwrite(&dato, tamaño, cantidad, archivo)
            // Fuente: 09Archivos-Binarios-en-C.pdf [cite: 39, 45, 50]
            fwrite(&posicion, sizeof(long), 1, archBinario);
        }

        // Avanzamos el contador de posición y leemos el siguiente carácter
        posicion++;
        caracterLeido = fgetc(archTexto); // [cite: 631]
    }

    // ---------------------------------------------------------
    // 4. Cierre de archivos
    // ---------------------------------------------------------
    printf("\nProceso finalizado. Se guardaron las posiciones en '%s'.\n", nombreBin);

    // Cerramos ambos archivos usando fclose
    // Fuente: 08_Archivos de texto en C.pdf [cite: 215, 227]
    fclose(archTexto);
    fclose(archBinario);

    return 0;
}