/*
 * 8) Escriba un programa que lea desde teclado números enteros de una cifra (del 0 al 9) y que cree dos
 * archivos, los cuales almacenen los números leídos.
 * El primer archivo debe llamarse "numeros.txt" y contener en formato texto todos los números leídos en forma consecutiva.
 * El segundo archivo debe llamarse "numeros.dat" y contener todos los números leídos en formato binario.
 * Una vez ejecutado el programa, utilice un editor de texto (como por ejemplo: el Bloc de notas
 * en MS Windows, o Gedit en GNU/Linux) para abrir el archivo de texto y corroborar que la
 * información almacenada sea la correcta.
 * Usando el mismo editor, intente abrir el archivo binario. ¿Es posible visualizar los números?
 * ¿Por qué cree que no es posible?
 * Compare los tamaños que ocupan cada archivo. ¿Cuál es más grande?
 * ¿En qué ocasiones cree usted que sería mejor utilizar cada tipo de archivos?
 */

#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE "numeros.txt"
#define BIN_FILE "numeros.dat"

/**
 * @brief Escribe un numero leido en formato texto y en formato binario.
 * @param f_txt Descriptor de archivo de texto.
 * @param f_bin Descriptor de archivo binario.
 * @param num Numero a escribir.
 */
void escribir_archivos(FILE *f_txt, FILE *f_bin, int num) {
    // 1. Escritura en formato TEXTO (numeros.txt)
    // fprintf convierte el entero 'num' a su representacion ASCII/caracter (ej: 5 -> '5').
    fprintf(f_txt, "%d", num); 

    // 2. Escritura en formato BINARIO (numeros.dat)
    // fwrite escribe los BYTES brutos que componen la representacion interna del entero.
    fwrite(&num, sizeof(int), 1, f_bin);
}

// --- ANALISIS DE PREGUNTAS ---
void imprimir_analisis() {
    printf("\n\n--- ANALISIS DE ARCHIVOS ---\n");
    
    // Pregunta: ¿Es posible visualizar los números en el archivo binario (numeros.dat) usando un editor de texto? ¿Por qué?
    printf("1. Visualizacion Binaria:\n");
    printf("   No es posible visualizar los numeros enteros directamente en el editor de texto.\n");
    printf("   Razon: El editor solo lee caracteres (ASCII). El archivo binario contiene los 4 (o 8) bytes\n");
    printf("          que el sistema usa para representar el entero (ej: el numero 5 se guarda como 0x00000005).\n");
    printf("          El editor interpreta estos bytes como caracteres de control o simbolos incomprensibles.\n");

    // Pregunta: Compare los tamaños. ¿Cuál es más grande?
    printf("\n2. Comparacion de Tamanos (Asumiendo 4 bytes/int):\n");
    printf("   Si se leen 10 numeros de 1 cifra (ej: '1234567890'):\n");
    printf("   - numeros.txt (Texto): Ocupa 10 bytes (1 byte por caracter/cifra).\n");
    printf("   - numeros.dat (Binario): Ocupa 40 bytes (10 enteros * 4 bytes/entero).\n");
    printf("   CONCLUSION: El archivo de texto sera MAS PEQUENO en este caso (numeros de una cifra).\n");
    printf("   *Excepcion*: Si los numeros fueran muy grandes (ej: 123456789), el archivo binario seria mas pequeno, ya que siempre ocupa 4 bytes.\n");

    // Pregunta: ¿En qué ocasiones cree usted que sería mejor utilizar cada tipo de archivos?
    printf("\n3. Usos Preferidos:\n");
    printf("   - Archivos de TEXTO (.txt): Preferible cuando la legibilidad humana es clave, o para configuraciones y logs.\n");
    printf("     Tienen mayor portabilidad entre sistemas operativos y arquitecturas.\n");
    printf("   - Archivos BINARIOS (.dat): Preferible para estructuras de datos complejas (structs), grandes volumenes de datos numericos, o cuando la velocidad y el tamano compacto son criticos.\n");
    printf("     Son mas rapidos de leer/escribir porque no requieren conversion ASCII.\n");
}


// --- FUNCION PRINCIPAL ---

int main() {
    FILE *f_txt = fopen(TEXT_FILE, "w");
    FILE *f_bin = fopen(BIN_FILE, "wb");
    int num;

    if (!f_txt || !f_bin) {
        perror("Error al abrir o crear los archivos");
        if (f_txt) fclose(f_txt);
        if (f_bin) fclose(f_bin);
        return 1;
    }

    printf("Programa de creacion de archivos (Texto y Binario).\n");
    printf("Ingrese numeros de una cifra (0-9). Ingrese -1 para finalizar.\n");
    
    while (1) {
        printf("Numero: ");
        if (scanf("%d", &num) != 1) {
            // Manejo de entrada invalida
            while (getchar() != '\n');
            printf("Entrada invalida. Finalizando.\n");
            break;
        }

        if (num == -1) {
            break; // Condicion de salida
        }

        if (num >= 0 && num <= 9) {
            escribir_archivos(f_txt, f_bin, num);
        } else {
            printf("Solo se aceptan numeros de una cifra (0-9).\n");
        }
    }

    fclose(f_txt);
    fclose(f_bin);
    printf("\nArchivos '%s' y '%s' creados exitosamente.\n", TEXT_FILE, BIN_FILE);
    
    imprimir_analisis();

    return 0;
}