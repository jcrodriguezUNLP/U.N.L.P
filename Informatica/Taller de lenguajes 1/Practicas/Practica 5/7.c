/*
 * 7) Escriba un programa que copie el contenido de un archivo de texto en otro nuevo.
 * a) Utilizando las funciones fgetc y fputc.
 * b) Utilizando las funciones fgets y fputs.
 * c) Utilizando las funciones fread y fwrite.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_FILE "origen.txt"
#define DEST_FILE_A "destino_a.txt"
#define DEST_FILE_B "destino_b.txt"
#define DEST_FILE_C "destino_c.txt"
#define BUFFER_SIZE 256 // Tamano del buffer para fgets/fputs y fread/fwrite

/**
 * @brief Copia un archivo caracter por caracter (fgetc/fputc).
 */
void copiar_fgetc_fputc(const char *src, const char *dest) {
    FILE *f_in = fopen(src, "r");
    FILE *f_out = fopen(dest, "w");
    int c;

    if (!f_in || !f_out) {
        perror("Error al abrir archivos para fgetc/fputc");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    // a) Copia caracter por caracter
    while ((c = fgetc(f_in)) != EOF) {
        fputc(c, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    printf("a) Copia (fgetc/fputc) completada en '%s'.\n", dest);
}

/**
 * @brief Copia un archivo linea por linea (fgets/fputs).
 */
void copiar_fgets_fputs(const char *src, const char *dest) {
    FILE *f_in = fopen(src, "r");
    FILE *f_out = fopen(dest, "w");
    char buffer[BUFFER_SIZE];

    if (!f_in || !f_out) {
        perror("Error al abrir archivos para fgets/fputs");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    // b) Copia linea por linea
    while (fgets(buffer, BUFFER_SIZE, f_in) != NULL) {
        fputs(buffer, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    printf("b) Copia (fgets/fputs) completada en '%s'.\n", dest);
}

/**
 * @brief Copia un archivo usando bloques binarios (fread/fwrite).
 */
void copiar_fread_fwrite(const char *src, const char *dest) {
    // Abrir en modo binario para la copia mas eficiente (aunque sea texto)
    FILE *f_in = fopen(src, "rb");
    FILE *f_out = fopen(dest, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes_leidos;

    if (!f_in || !f_out) {
        perror("Error al abrir archivos para fread/fwrite");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    // c) Copia por bloques binarios
    while ((bytes_leidos = fread(buffer, 1, BUFFER_SIZE, f_in)) > 0) {
        fwrite(buffer, 1, bytes_leidos, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    printf("c) Copia (fread/fwrite) completada en '%s'.\n", dest);
}

int main() {
    printf("Programa de copia de archivos (3 metodos).\n");
    
    // NOTA: Cree un archivo 'origen.txt' con varias lineas de texto antes de ejecutar.
    
    // Verificacion: Si el archivo origen no existe
    FILE *f_check = fopen(SRC_FILE, "r");
    if (f_check == NULL) {
        printf("\nERROR: Archivo fuente '%s' no encontrado. Cree el archivo y ejecute de nuevo.\n", SRC_FILE);
        return 1;
    }
    fclose(f_check);

    copiar_fgetc_fputc(SRC_FILE, DEST_FILE_A);
    copiar_fgets_fputs(SRC_FILE, DEST_FILE_B);
    copiar_fread_fwrite(SRC_FILE, DEST_FILE_C);

    return 0;
}