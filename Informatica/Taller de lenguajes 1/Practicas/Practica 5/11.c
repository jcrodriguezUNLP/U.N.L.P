/*
 * 11) Escriba un programa que abra el archivo binario del ejercicio anterior y que imprima en pantalla el
 * tamaño en bytes de dicho archivo.
 * ¿Por qué cree Ud. que tiene ese tamaño?
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "jugadores.dat"
#define MAX_JUGADORES 20 // De acuerdo con el Ejercicio 9

// Estructura de datos (la misma que en el Ejercicio 9)
typedef struct {
    char nombre_apellido[50];
    int edad;
    int titulos;
    int ranking; 
    double fortuna;
} Jugador;

/**
 * @brief Calcula e imprime el tamano en bytes del archivo binario.
 */
void calcular_tamano_archivo() {
    FILE *f = fopen(FILENAME, "rb");
    if (f == NULL) {
        perror("Error al abrir el archivo binario");
        printf("Asegurese de ejecutar el Ejercicio 9 primero para crear '%s'.\n", FILENAME);
        return;
    }

    long tamano_bytes;
    
    // 1. Mover el puntero al final del archivo
    fseek(f, 0, SEEK_END); 
    
    // 2. Obtener la posicion actual (que es el tamano del archivo en bytes)
    tamano_bytes = ftell(f);
    
    // 3. Cerrar el archivo
    fclose(f);

    printf("\n--- Tamano del Archivo Binario ---\n");
    printf("El archivo '%s' tiene un tamano de: %ld bytes.\n", FILENAME, tamano_bytes);

    // --- Analisis de la pregunta ---
    printf("\n--- Analisis de la Pregunta: ¿Por que tiene ese tamano? ---\n");
    printf("El tamano se debe a que el archivo almacena la informacion de %d jugadores\n", MAX_JUGADORES);
    printf("en formato binario, sin separadores ni conversiones de texto.\n");
    
    // Calculo teorico:
    size_t tamano_jugador = sizeof(Jugador);
    long tamano_teorico = (long)tamano_jugador * MAX_JUGADORES;
    
    printf("\nCalculo Teorico:\n");
    printf("* Tamano de la estructura Jugador: %zu bytes (debido a la alineacion interna de la CPU).\n", tamano_jugador);
    printf("* Jugadores almacenados: %d.\n", MAX_JUGADORES);
    printf("* Tamano Esperado: %d Jugadores * %zu bytes/jugador = %ld bytes.\n", MAX_JUGADORES, tamano_jugador, tamano_teorico);
    printf("El tamano leido (%ld bytes) debe coincidir con este calculo teorico.\n", tamano_bytes);
}

int main() {
    printf("Programa para calcular el tamano en bytes de un archivo binario.\n");
    calcular_tamano_archivo();
    return 0;
}