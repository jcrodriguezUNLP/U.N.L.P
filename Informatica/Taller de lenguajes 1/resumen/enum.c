#include <stdio.h>

/*
 * =========================================================
 * ARCHIVO: enumeracion.c
 * CONCEPTO: enum (Enumeración)
 * DESCRIPCIÓN:
 * Un 'enum' define un conjunto de constantes enteras con nombre
 * (identificadores). Esto mejora la legibilidad del código al
 * permitirnos usar nombres en lugar de números 'mágicos'.
 * =========================================================
*/

// 1. Definición de la enumeración 'EstadoConexion'
// Por defecto, NO_CONECTADO es 0, CONECTADO es 1, ERROR_RED es 2.
enum EstadoConexion {
    NO_CONECTADO, // Valor por defecto: 0
    CONECTADO,    // Valor por defecto: 1
    ERROR_RED,    // Valor por defecto: 2
    EN_MANTENIMIENTO = 5 // Se puede asignar un valor explícitamente
};

// 2. Definición de otra enumeración 'Mes' con valores iniciales
enum Mes {
    ENERO = 1, // Se fuerza a que el primer valor comience en 1
    FEBRERO,   // Automáticamente toma el valor 2
    MARZO,     // Automáticamente toma el valor 3
    ABRIL
    // ... y así sucesivamente
};

int main() {
    // 3. Declaración de variables de tipo 'enum'
    enum EstadoConexion estadoActual = CONECTADO;
    enum Mes mesActual = MARZO;
    
    printf("--- Uso de Enumeraciones (enum) ---\n");

    // 4. Uso de la enumeración en una estructura de control (switch)
    printf("Estado de la conexión: ");
    switch (estadoActual) {
        case NO_CONECTADO:
            printf("Desconectado (%d)\n", NO_CONECTADO);
            break;
        case CONECTADO:
            printf("Establecida (%d)\n", CONECTADO);
            break;
        case ERROR_RED:
            printf("Error de red (%d)\n", ERROR_RED);
            break;
        case EN_MANTENIMIENTO:
            printf("Mantenimiento (%d)\n", EN_MANTENIMIENTO);
            break;
    }
    
    // 5. Imprimiendo el valor subyacente de la constante
    printf("El mes actual es Marzo, que tiene el valor entero: %d\n", mesActual);

    return 0;
}