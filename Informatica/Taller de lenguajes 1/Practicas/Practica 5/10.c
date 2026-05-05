/*
 * 10) Utilizando el archivo binario generado en el ejercicio anterior:
 * a) escriba una función que permita actualizar el ranking de un jugador.
 * Dicha función recibe como parámetros nombre, apellido y nuevo ranking del jugador y retorna 1 
 * si pudo realizar la modificación y 0 en caso contrario.
 * b) escriba un programa que lea desde teclado el nombre y apellido de jugadores y sus nuevos
 * rankings hasta ingresar "ZZZ" y actualice el ranking de cada jugador o muestre un mensaje de
 * error en caso de no existir el jugador.
 * Por último, imprima el contenido del archivo modificado, para verificar que la actualización se haya
 * aplicado correctamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "jugadores.dat"
#define MAX_NAME_LEN 50
#define TOKEN_FIN "ZZZ"

// Estructura de datos (la misma que en el Ejercicio 9)
typedef struct {
    char nombre_apellido[MAX_NAME_LEN];
    int edad;
    int titulos;
    int ranking; 
    double fortuna;
} Jugador;

// --- MODULO DE ACTUALIZACIÓN ---

/**
 * @brief Actualiza el ranking de un jugador en el archivo binario.
 * * @param nombre_apellido Nombre y apellido a buscar.
 * @param nuevo_ranking El nuevo valor del ranking.
 * @return int 1 si la modificacion se realizo, 0 en caso contrario.
 */
int actualizar_ranking(const char *nombre_apellido, int nuevo_ranking) {
    // Abrir el archivo en modo lectura/escritura binaria
    FILE *f = fopen(FILENAME, "r+b"); 
    if (f == NULL) {
        perror("Error al abrir el archivo binario para actualizacion");
        return 0;
    }

    Jugador actual;
    long posicion_actual = 0;
    int encontrado = 0;
    
    // Recorremos el archivo registro por registro
    while (fread(&actual, sizeof(Jugador), 1, f) == 1) {
        
        // Comparamos el nombre y apellido
        if (strcmp(actual.nombre_apellido, nombre_apellido) == 0) {
            
            // 1. Modificar el campo en la estructura
            actual.ranking = nuevo_ranking;
            
            // 2. Retroceder el puntero del archivo al inicio del registro actual
            // ftell nos da la posicion actual (final del registro leido)
            // Retrocedemos el tamano de un registro (sizeof(Jugador))
            posicion_actual = ftell(f) - sizeof(Jugador);
            fseek(f, posicion_actual, SEEK_SET);
            
            // 3. Escribir el registro modificado en el mismo lugar
            fwrite(&actual, sizeof(Jugador), 1, f);
            
            encontrado = 1;
            break; // Salimos del bucle una vez actualizado
        }
        // Avanzamos 'posicion_actual' para llevar control (aunque ftell es mas preciso)
        // posicion_actual = ftell(f);
    }
    
    fclose(f);
    return encontrado;
}

// --- MODULO DE VERIFICACIÓN ---

/**
 * @brief Imprime todo el contenido del archivo para verificar la actualizacion.
 */
void imprimir_archivo_modificado() {
    FILE *f = fopen(FILENAME, "rb");
    if (f == NULL) {
        perror("Error al abrir el archivo para verificacion");
        return;
    }

    Jugador j;
    printf("\n--- CONTENIDO DEL ARCHIVO (VERIFICACION) ---\n");
    printf("Ranking | Titulos | Nombre y Apellido\n");
    printf("--------|---------|--------------------------------------------------\n");
    
    while (fread(&j, sizeof(Jugador), 1, f) == 1) {
        printf("%7d | %7d | %s\n", j.ranking, j.titulos, j.nombre_apellido);
    }
    
    fclose(f);
}

// --- FUNCION PRINCIPAL ---

int main() {
    char nombre_input[MAX_NAME_LEN];
    int nuevo_ranking;
    int resultado;
    
    // NOTA: Asumimos que el archivo 'jugadores.dat' del Ejercicio 9 ya existe.
    printf("Programa de actualizacion de ranking de jugadores.\n");

    // b) Lectura desde teclado y actualizacion
    while (1) {
        printf("\nJugador (Nombre y Apellido) o ingrese '%s' para salir: ", TOKEN_FIN);
        // Lee la linea completa (nombre + apellido)
        if (fgets(nombre_input, MAX_NAME_LEN, stdin) == NULL) break;
        
        // Eliminar el salto de linea y limpiar el string
        nombre_input[strcspn(nombre_input, "\n")] = 0;
        
        if (strcmp(nombre_input, TOKEN_FIN) == 0) {
            break;
        }

        printf("Nuevo Ranking para %s: ", nombre_input);
        if (scanf("%d", &nuevo_ranking) != 1) {
            printf("Error: Ingrese un ranking numerico valido.\n");
            // Limpiar buffer de entrada
            while (getchar() != '\n'); 
            continue;
        }
        // Consumir el salto de linea que deja scanf
        while (getchar() != '\n');
        
        // Llamada a la funcion de actualizacion (a)
        resultado = actualizar_ranking(nombre_input, nuevo_ranking);
        
        if (resultado == 1) {
            printf("-> Exito: Ranking de %s actualizado a %d.\n", nombre_input, nuevo_ranking);
        } else {
            printf("-> Error: Jugador '%s' no encontrado o fallo al actualizar.\n", nombre_input);
        }
    }

    // Ultimo paso: Imprimir el contenido modificado para verificar
    imprimir_archivo_modificado();

    return 0;
}