#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura según el enunciado
typedef struct {
    char titulo[30];
    char link[120];
    int reproducciones;
} Video;

// --- A) Función para generar el reporte ---
// Recibe: Puntero al binario abierto, nombre del txt a crear, cantidad N
void generarReporteLinks(FILE* ptrBin, const char* nombreTxt, int N) {
    // Abrimos el archivo de texto para escritura ("w")
    FILE* ptrTxt = fopen(nombreTxt, "w");
    
    if (ptrTxt == NULL) {
        printf("Error al crear el archivo de texto.\n");
        return;
    }

    Video v;
    
    // Nos aseguramos de empezar desde el inicio del binario
    rewind(ptrBin);

    // Leemos registro por registro
    while (fread(&v, sizeof(Video), 1, ptrBin)) {
        // Si supera las reproducciones N, escribimos el link
        if (v.reproducciones > N) {
            fprintf(ptrTxt, "%s\n", v.link);
        }
    }

    fclose(ptrTxt);
}

// --- B) Programa Principal ---
int main() {
    FILE *archBin;
    char nombreBin[50], nombreTxt[50];
    int N;

    // 1. Lectura de datos por teclado
    printf("Ingrese nombre del archivo binario: ");
    scanf("%s", nombreBin);
    printf("Ingrese nombre del archivo de texto a generar: ");
    scanf("%s", nombreTxt);
    printf("Ingrese cantidad de reproducciones N: ");
    scanf("%d", &N);

    // 2. Abrir archivo binario (Debe existir previamente)
    archBin = fopen(nombreBin, "rb");
    if (archBin == NULL) {
        printf("Error: No se pudo abrir el archivo binario.\n");
        return 1;
    }

    // 3. Llamada a la función del punto A
    generarReporteLinks(archBin, nombreTxt, N);

    // 4. Verificar si el archivo quedó vacío
    FILE *testTxt = fopen(nombreTxt, "r"); // Abrimos para leer
    if (testTxt != NULL) {
        // Intentamos leer el primer caracter
        fseek(testTxt, 0, SEEK_END); // Vamos al final
        long tamano = ftell(testTxt); // Vemos el tamaño

        if (tamano == 0) {
            printf("SIN INFORMACION\n");
        } else {
            printf("Reporte generado con exito en %s\n", nombreTxt);
        }
        fclose(testTxt);
    }

    fclose(archBin);
    return 0;
}