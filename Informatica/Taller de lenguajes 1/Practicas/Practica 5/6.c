/*
 * 6) Un archivo csu (Comma Separated Values) contiene información separada por comas. Cada renglón
 * (fila) contiene un registro de información. Cada columna contiene un campo particular de
 * información. La primera fila es especial ya que contiene los nombres de los campos.
 * Se desea obtener información a partir del archivo llamado vinos.csv (el cual se encuentra en la
 * Sección "Ing. Gral. y Contenidos" del curso de la cátedra en WebUNLP).
 * El programa debe generar un archivo de texto con un resumen que indique el valor máximo, mínimo y promedio para cada
 * uno de los campos del archivo.
 * Este archivo debe llamarse reporte_vinos.txt y debe guardarse en la
 * misma ruta que el archivo vinos.csv.
 * El formato del archivo debe ser similar al del siguiente ejemplo:
 * [Ejemplo de formato de reporte_vinos.txt]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> // Para DBL_MAX, DBL_MIN

#define INPUT_FILENAME "vinos.csv"
#define OUTPUT_FILENAME "reporte_vinos.txt"
#define MAX_LINE_LEN 512
#define MAX_FIELDS 11 // Estimado por el ejemplo (Acidez Fija, Acidez Volatil, etc.)

// Estructura para almacenar las estadisticas de cada campo
typedef struct {
    char nombre[MAX_LINE_LEN];
    double suma;
    double max;
    double min;
    int count;
} Stats;

// --- MODULO DE PROCESAMIENTO ---

/**
 * @brief Inicializa las estadisticas para todos los campos.
 */
void inicializar_stats(Stats stats[], int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        stats[i].suma = 0.0;
        stats[i].max = -DBL_MAX; // Empezar con el valor mas pequeño
        stats[i].min = DBL_MAX;  // Empezar con el valor mas grande
        stats[i].count = 0;
        stats[i].nombre[0] = '\0';
    }
}

/**
 * @brief Procesa el archivo CSV, extrayendo nombres de campos y calculando estadisticas.
 * Nota: Esta implementacion asume que todos los campos son numericos flotantes.
 */
int procesar_csv(Stats stats[], int max_fields) {
    FILE *f_in = fopen(INPUT_FILENAME, "r");
    if (f_in == NULL) {
        perror("Error al abrir el archivo de entrada (vinos.csv)");
        return 0;
    }

    char line[MAX_LINE_LEN];
    int num_fields = 0;
    int row_count = 0;

    // 1. Leer la cabecera (nombres de los campos)
    if (fgets(line, MAX_LINE_LEN, f_in) != NULL) {
        char *token;
        char *rest = line;
        num_fields = 0;
        
        // Reemplazar el salto de linea por terminador nulo si existe
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        // Tokenizar por coma (',') para obtener los nombres
        while ((token = strtok_r(rest, ",", &rest))) {
            if (num_fields < max_fields) {
                strncpy(stats[num_fields].nombre, token, MAX_LINE_LEN - 1);
                stats[num_fields].nombre[MAX_LINE_LEN - 1] = '\0';
                num_fields++;
            }
        }
    } else {
        fclose(f_in);
        return 0; // Archivo vacio
    }

    // Si no hay campos, cerramos y salimos
    if (num_fields == 0) {
        fclose(f_in);
        return 0;
    }

    // 2. Procesar el resto de las filas (datos)
    while (fgets(line, MAX_LINE_LEN, f_in) != NULL) {
        // Reemplazar el salto de linea por terminador nulo si existe
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        char *token;
        char *rest = line;
        int field_index = 0;

        // Tokenizar por coma (',') para obtener los valores
        while ((token = strtok_r(rest, ",", &rest))) {
            if (field_index < num_fields) {
                // Convertir el token a double
                double valor = atof(token); 
                
                // Actualizar estadisticas
                stats[field_index].suma += valor;
                if (valor > stats[field_index].max) {
                    stats[field_index].max = valor;
                }
                if (valor < stats[field_index].min) {
                    stats[field_index].min = valor;
                }
                // Contar solo una vez por fila/campo
                if (row_count == 0) {
                    stats[field_index].count++; 
                }
            }
            field_index++;
        }
        row_count++;
    }
    
    // Ajustar el contador para todas las filas procesadas
    for (int i = 0; i < num_fields; i++) {
        stats[i].count = row_count;
    }

    fclose(f_in);
    return num_fields;
}

// --- MODULO DE REPORTE ---

/**
 * @brief Genera el archivo de reporte en formato de tabla.
 */
void generar_reporte(Stats stats[], int num_fields) {
    FILE *f_out = fopen(OUTPUT_FILENAME, "w");
    if (f_out == NULL) {
        perror("Error al crear el archivo de reporte");
        return;
    }

    // Escribir el encabezado del reporte
    fprintf(f_out, "Atributo          | Promedio | Minimo | Maximo\n");
    fprintf(f_out, "------------------+----------+--------+--------\n");

    // Escribir los datos de cada campo
    for (int i = 0; i < num_fields; i++) {
        double promedio = (stats[i].count > 0) ? (stats[i].suma / stats[i].count) : 0.0;
        
        // Imprimir el nombre del atributo alineado (max 17 caracteres)
        fprintf(f_out, "%-17.17s |", stats[i].nombre); 
        
        // Imprimir las estadisticas (usando ',' como separador decimal para el ejemplo)
        fprintf(f_out, " %8.2lf |", promedio);
        fprintf(f_out, " %6.2lf |", stats[i].min);
        fprintf(f_out, " %6.2lf\n", stats[i].max);
    }

    fclose(f_out);
    printf("\nReporte generado exitosamente en '%s'.\n", OUTPUT_FILENAME);
}

// --- FUNCION PRINCIPAL ---

int main() {
    Stats campo_stats[MAX_FIELDS];
    int num_fields;

    inicializar_stats(campo_stats, MAX_FIELDS);
    
    // NOTA: Para probar, se necesita el archivo 'vinos.csv' con formato:
    // Acidez Fija,Acidez Volatil,Acido Citrico,Azucares Residuales,PH,Sulfatos,Alcohol,Calidad
    // 7.4,0.70,0.00,1.9,3.51,0.56,9.4,5
    // 7.8,0.88,0.00,2.6,3.20,0.68,9.8,5

    printf("Programa de analisis de archivos CSV.\n");
    num_fields = procesar_csv(campo_stats, MAX_FIELDS);

    if (num_fields > 0) {
        generar_reporte(campo_stats, num_fields);
    } else {
        printf("Error: No se pudo procesar el archivo o no se encontraron campos.\n");
    }

    return 0;
}