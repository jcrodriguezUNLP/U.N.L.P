/*
    5. (1.5 puntos) El archivo de texto "Habitantes.txt" contiene información de la cantidad de habitantes de ciertas localidades argentinas.
    En cada línea del archivo se encuentra: el código de provincia, el código de Localidad, el nombre de localidad y la cantidad de habitantes. 
    Estos cuatro valores se encuentran separados por un único blanco tal como se observa en el cuadro que aparece a derecha. 
    Escriba un programa que lea la información del archivo "Habitantes.txt" y la utilice para generar el archivo binario "Habitantes.dat" con la siguiente estructura: 
    struct destino { 
    int codProv;
    int codLoc;
    char nomLoc [30];
    int nHab;
    };
    Al finalizar la carga del archivo binario, deberá calcular y mostrar el código y el nombre de localidad con mayor cantidad de habitantes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_FILE "Habitantes.txt"
#define BIN_FILE "Habitantes.dat"

// Estructura de destino para el archivo binario
struct destino {
    int  codProv    ;
    int  codLoc     ;
    char nomLoc[30] ;
    int  nHab       ;
};

// Funcion para generar el archivo binario
void generar_archivo_binario(const char *text_file, const char *bin_file) {
    FILE *f_txt = fopen(text_file, "r");
    FILE *f_bin = fopen(bin_file, "wb");
    struct destino d;
    
    if (f_txt == NULL || f_bin == NULL) {
        perror("Error al abrir archivos");
        printf("Asegurese de crear %s con el formato: codProv codLoc nomLoc nHab\n", text_file);
        if (f_txt) fclose(f_txt);
        if (f_bin) fclose(f_bin);
        return;
    }
    
    printf("--- Generando archivo binario %s ---\n", bin_file);
    
    // El formato esperado es: %d %d %s %d (separados por espacios)
    while (fscanf(f_txt, "%d %d %29s %d", 
                  &d.codProv, &d.codLoc, d.nomLoc, &d.nHab) == 4) {
        
        if (fwrite(&d, sizeof(struct destino), 1, f_bin) != 1) {
            printf("Error de escritura binaria.\n");
            break;
        }
    }
    
    fclose(f_txt);
    fclose(f_bin);
}

// Funcion para procesar el archivo binario y encontrar la localidad con más habitantes
void encontrar_mayor_habitante(const char *bin_file) {
    FILE *f_bin = fopen(bin_file, "rb");
    if (f_bin == NULL) {
        perror("Error al abrir archivo binario para lectura");
        return;
    }

    struct destino d_actual;
    struct destino d_mayor_hab = {0, 0, "", -1}; 

    printf("\n--- Buscando Localidad con Mayor Habitante ---\n");

    while (fread(&d_actual, sizeof(struct destino), 1, f_bin) == 1) {
        if (d_actual.nHab > d_mayor_hab.nHab) {
            d_mayor_hab = d_actual;
        }
    }

    fclose(f_bin);

    if (d_mayor_hab.nHab > -1) {
        printf("Localidad con mayor cantidad de habitantes:\n");
        printf("  Codigo de Localidad: %d\n", d_mayor_hab.codLoc);
        printf("  Nombre de Localidad: %s\n", d_mayor_hab.nomLoc);
        printf("  Cantidad de Habitantes: %d\n", d_mayor_hab.nHab);
    } else {
        printf("El archivo binario esta vacio o no se encontraron datos validos.\n");
    }
}

int main() {
    // Para probar, se debe crear un archivo 'Habitantes.txt' con datos de ejemplo
    // Ejemplo: 2 5 Peñaloza 10868
    
    generar_archivo_binario(TEXT_FILE, BIN_FILE);
    encontrar_mayor_habitante(BIN_FILE);

    return 0;
}