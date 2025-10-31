#include <stdio.h>
#include <string.h>

/*
 * =========================================================
 * ARCHIVO: estructura.c
 * CONCEPTO: struct (Estructura)
 * DESCRIPCIÓN:
 * Una 'struct' es un tipo de dato definido por el usuario que
 * agrupa un conjunto de variables de *diferentes tipos* bajo
 * un único nombre. Sirve para crear un registro o una entidad.
 * =========================================================
*/

// 1. Definición de la estructura 'Libro'
// Esta plantilla agrupa tres atributos para describir un libro.
struct Libro {
    char titulo[50]; // Miembro de tipo array de caracteres (cadena)
    char autor[50];  // Miembro de tipo array de caracteres (cadena)
    int anio_publicacion; // Miembro de tipo entero
};

int main() {
    // 2. Declaración de una variable de tipo 'struct Libro'
    // 'miLibro' es una instancia (objeto) de la estructura 'Libro'.
    struct Libro miLibro;

    // 3. Inicialización y asignación de valores a los miembros
    // Se usa el operador punto (.) para acceder a cada miembro.
    
    // Inicializar cadenas (se usa strcpy porque son arrays)
    strcpy(miLibro.titulo, "C Esencial");
    strcpy(miLibro.autor, "A. Programador");
    
    // Inicializar el entero
    miLibro.anio_publicacion = 2023;

    // 4. Acceso e impresión de los valores de la estructura
    printf("--- Uso de Estructuras (struct) ---\n");
    printf("Título: %s\n", miLibro.titulo);
    printf("Autor: %s\n", miLibro.autor);
    printf("Año: %d\n", miLibro.anio_publicacion);
    
    // 5. Demostración de asignación (copia de una struct)
    struct Libro otroLibro = miLibro;
    printf("\nCopia (otroLibro.anio_publicacion): %d\n", otroLibro.anio_publicacion);

    return 0;
}