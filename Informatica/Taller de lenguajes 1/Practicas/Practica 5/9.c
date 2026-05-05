/*
 * 9) Escriba un programa que lea información de 20 jugadores de tenis.
 * De cada jugador se lee nombre y apellido, edad, cantidad de títulos, ranking actual y fortuna acumulada.
 * Defina una estructura de datos adecuada para la información y almacene la misma en un archivo binario.
 * Finalizada la lectura, procese los datos almacenados en el archivo e informe:
 * a) Nombre y apellido del jugador con mejor ranking.
 * b) Nombre y apellido del jugador que más títulos ha ganado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "jugadores.dat"
#define MAX_JUGADORES 20
#define MAX_NAME_LEN 50

// Estructura de datos adecuada para almacenar la informacion
typedef struct {
    char nombre_apellido[MAX_NAME_LEN];
    int edad;
    int titulos;
    int ranking; // Menor numero = Mejor ranking
    double fortuna;
} Jugador;

// --- MODULO DE GESTION DE ARCHIVO ---

/**
 * @brief Escribe los datos de los jugadores en un archivo binario.
 */
void escribir_archivo_binario(const Jugador jugadores[], int count) {
    FILE *f = fopen(FILENAME, "wb");
    if (f == NULL) {
        perror("Error al crear el archivo binario");
        return;
    }
    
    // Escribe el arreglo completo en un solo bloque
    fwrite(jugadores, sizeof(Jugador), count, f);
    
    fclose(f);
    printf("\nDatos de %d jugadores escritos en '%s'.\n", count, FILENAME);
}

/**
 * @brief Procesa el archivo binario e informa el mejor ranking y mas titulos.
 */
void procesar_archivo_binario() {
    FILE *f = fopen(FILENAME, "rb");
    if (f == NULL) {
        perror("Error al abrir el archivo binario para lectura");
        return;
    }

    Jugador actual, mejor_ranking, mas_titulos;
    long num_leidos;
    
    // Inicializacion con valores extremos
    mejor_ranking.ranking = 999999;
    mas_titulos.titulos = -1;
    
    printf("\n--- Procesando archivo binario ---\n");

    // Recorremos el archivo leyendo la estructura Jugador una por una
    while ((num_leidos = fread(&actual, sizeof(Jugador), 1, f)) == 1) {
        
        // a) Mejor Ranking (menor ranking number)
        if (actual.ranking < mejor_ranking.ranking) {
            mejor_ranking = actual;
        }
        
        // b) Mas Títulos
        if (actual.titulos > mas_titulos.titulos) {
            mas_titulos = actual;
        }
    }
    
    fclose(f);

    printf("\n--- Resultados del Analisis ---\n");
    printf("a) Jugador con Mejor Ranking (%d): %s\n", mejor_ranking.ranking, mejor_ranking.nombre_apellido);
    printf("b) Jugador con Mas Titulos (%d): %s\n", mas_titulos.titulos, mas_titulos.nombre_apellido);
}

// --- FUNCION PRINCIPAL ---

int main() {
    Jugador jugadores[MAX_JUGADORES];
    
    printf("Programa de gestion de datos de jugadores de tenis.\n");

    // --- Lectura de datos simulada (para no ingresar 20 veces) ---
    printf("\n--- Lectura simulada de %d jugadores ---\n", MAX_JUGADORES);
    
    // Ejemplo de inicializacion:
    strcpy(jugadores[0].nombre_apellido, "Rafael Nadal"); 
    jugadores[0].ranking = 5; jugadores[0].titulos = 92;
    
    strcpy(jugadores[1].nombre_apellido, "Novak Djokovic"); 
    jugadores[1].ranking = 1; jugadores[1].titulos = 98;
    
    strcpy(jugadores[2].nombre_apellido, "Roger Federer"); 
    jugadores[2].ranking = 500; jugadores[2].titulos = 103;
    
    for (int i = 3; i < MAX_JUGADORES; i++) {
        sprintf(jugadores[i].nombre_apellido, "Jugador %d", i);
        jugadores[i].ranking = i * 10;
        jugadores[i].titulos = i;
        jugadores[i].edad = 20 + (i % 10);
        jugadores[i].fortuna = 100000.0 * i;
    }
    
    // 1. Almacenar la informacion en el archivo binario
    escribir_archivo_binario(jugadores, MAX_JUGADORES);
    
    // 2. Procesar los datos del archivo
    procesar_archivo_binario();

    return 0;
}