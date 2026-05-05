/*
 * 3) Se desea leer y procesar información de precipitaciones del mes de enero.
 * Para ello se dispone de un archivo de texto (llamado precipitaciones.txt) con el siguiente formato:
 * 0-2-0-0-7-22-11-0-... -0-
 * Por cada de los 31 días se tiene un número entero indicando los milímetros llovidos, seguido de un
 * guión medio (-) como delimitador.
 * Escriba un programa que lea la información del archivo y derermine el día con mayor precipitación.
 * Para evaluar el programa, genere un archivo con el formato establecido utilizando un editor de texto plano
 * (por ejemplo: Bloc de notas o Notepad++).
 * Nota: puede utilizar la función fscanf para procesar cada valor de precipitación.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "precipitaciones.txt"
#define DIAS_ENERO 31

/**
 * @brief Procesa el archivo de precipitaciones para encontrar el dia con mayor lluvia.
 */
void buscar_mayor_precipitacion() {
    FILE *f = fopen(FILENAME, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo de precipitaciones");
        printf("Asegurese de que '%s' exista con 31 valores separados por '-'.\n", FILENAME);
        return;
    }

    int precipitacion_actual;
    int max_precipitacion = -1;
    int dia_max = -1;
    int dia_actual = 1;
    
    // El formato esperado es: valor-valor-valor-...-valor-
    // Usamos "%d-" para leer el entero seguido del delimitador '-'.
    // El ultimo valor no tiene el guion a su derecha.
    
    // Leemos los 31 dias de Enero
    while (dia_actual <= DIAS_ENERO) {
        
        // Intentamos leer el entero (%d) y el delimitador ('-')
        int resultado_fscanf = fscanf(f, "%d-", &precipitacion_actual);

        // Si es el ultimo dia, la lectura es solo el entero (%d)
        if (dia_actual == DIAS_ENERO) {
             // Retrocedemos al inicio del ultimo numero leido
             fseek(f, -2, SEEK_CUR); // Ajuste heuristico
             resultado_fscanf = fscanf(f, "%d", &precipitacion_actual);
        }


        if (resultado_fscanf < 1) {
            // Si fscanf no lee el entero (puede ser el final del archivo
            // antes de llegar al dia 31, o un error de formato).
            if (resultado_fscanf == EOF && dia_actual <= DIAS_ENERO) {
                 printf("\nADVERTENCIA: Archivo incompleto. Solo se encontraron datos hasta el dia %d.\n", dia_actual - 1);
            } else if (resultado_fscanf == 0) {
                 // Si se lee algo que no es un entero, pero no es EOF
                 printf("\nERROR DE FORMATO: Dato invalido o delimitador faltante despues del dia %d.\n", dia_actual - 1);
            }
            break;
        }

        if (precipitacion_actual > max_precipitacion) {
            max_precipitacion = precipitacion_actual;
            dia_max = dia_actual;
        }

        dia_actual++;
    }

    fclose(f);

    printf("\n--- Analisis de Precipitaciones ---\n");
    if (dia_max != -1) {
        printf("El dia con mayor precipitacion fue el %d de enero.\n", dia_max);
        printf("Milimetros llovidos: %d mm.\n", max_precipitacion);
    } else {
        printf("No se encontraron datos de precipitacion validos.\n");
    }
}

int main() {
    printf("Programa de analisis de precipitaciones.\n");
    // NOTA: Para probar, cree un archivo 'precipitaciones.txt' con 31 valores, por ejemplo:
    // 0-0-0-10-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-5-
    buscar_mayor_precipitacion();
    return 0;
}