/*
 * 4) Se desea leer y procesar información de un listado de apuestas.
 * Para ello se dispone de un archivo de texto (llamado apuestas.txt) con el siguiente formato:
 * código_de_apuesta | monto_apostado; ; código_de_apuesta | monto_apostado;
 * Donde cada apuesta se compone de un número entero (código de apuesta) y un número flotante
 * (monto apostado).
 * Escriba un programa que procese la información del archivo e informe el monto
 * total apostado.
 * Ejemplo: 1|100.0;65|50.5;23|34.5; debe informar: "El monto total apostado es $185".
 * Nota: Intente resolver el problema leyendo cada tupla (código, monto) al mismo tiempo.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "apuestas.txt"

/**
 * @brief Procesa el archivo de apuestas y calcula el monto total apostado.
 */
void calcular_monto_total_apuestas() {
    FILE *f = fopen(FILENAME, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo de apuestas");
        printf("Asegurese de que '%s' exista con formato 'codigo|monto;'.\n", FILENAME);
        return;
    }

    int codigo_apuesta;
    float monto_apostado;
    double monto_total = 0.0;
    
    // Formato de lectura esperado: %d|%f;
    // "%d|%f;" indica a fscanf que lea:
    // 1. Un entero (%d) -> codigo_apuesta
    // 2. El caracter literal '|'
    // 3. Un flotante (%f) -> monto_apostado
    // 4. El caracter literal ';'
    
    printf("\n--- Procesando Apuestas ---\n");
    
    // Bucle: lee tuplas hasta que fscanf no pueda satisfacer el formato completo.
    while (fscanf(f, "%d|%f;", &codigo_apuesta, &monto_apostado) == 2) {
        // fscanf retorna el número de elementos leídos exitosamente (2 en este caso).
        
        //printf("DEBUG: Leida apuesta Codigo=%d, Monto=%.2f\n", codigo_apuesta, monto_apostado);
        monto_total += monto_apostado;
    }
    
    // Verificamos si hubo un error de formato antes de EOF
    if (!feof(f)) {
        printf("ADVERTENCIA: El archivo puede contener datos con formato incorrecto que no pudieron ser leidos.\n");
    }

    fclose(f);

    printf("\nResultado Final:\n");
    printf("El monto total apostado es $%.2lf\n", monto_total);
}

int main() {
    printf("Programa de calculo de monto total de apuestas.\n");
    // NOTA: Para probar, cree un archivo 'apuestas.txt' con contenido como:
    // 1|100.0;65|50.5;23|34.5;
    calcular_monto_total_apuestas();
    return 0;
}