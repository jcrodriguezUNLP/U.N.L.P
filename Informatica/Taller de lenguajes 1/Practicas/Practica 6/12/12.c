// Implemente una biblioteca diccionario.h que permita manejar un diccionario de palabras.
// Determine las estructuras de datos necesarias para implementar la biblioteca.
// Las operaciones que debe implementar son las siguientes: 

// a) Crear un diccionario: inicializa la estructura del diccionario. 
// b) Agregar palabra: agrega una nueva palabra al diccionario siempre y cuando no exista. Retorna si la agregó o no. 
// c) Existe palabra: determina si una palabra está en el diccionario o no. 
// d) Eliminar palabra: elimina una palabra del diccionario. Retorna si la palabra fue eliminada o no. 
// e) Cargar desde un archivo: carga un diccionario desde un archivo de texto. 
// f) Guardar a un archivo: guarda un diccionario en un archivo de texto. 
// g) Destruir el diccionario: libera los recursos del diccionario. 

// Una vez implementadas todas las funciones de biblioteca, escriba un programa que permita probarlas. 

#include <stdio.h>
#include "diccionario.h"

int main() {
    printf("=== TEST DICCIONARIO ===\n");

    // 1. Crear
    Diccionario* miDic = dic_crear();

    // 2. Agregar palabras
    printf("Agregando 'Hola': %d\n", dic_agregar(miDic, "Hola"));
    printf("Agregando 'Mundo': %d\n", dic_agregar(miDic, "Mundo"));
    printf("Agregando 'C': %d\n", dic_agregar(miDic, "C"));
    printf("Agregando 'Hola' (duplicado): %d\n", dic_agregar(miDic, "Hola")); // Debería dar 0

    dic_imprimir(miDic);

    // 3. Verificar existencia
    printf("Existe 'Mundo'? %s\n", dic_existe(miDic, "Mundo") ? "SI" : "NO");
    printf("Existe 'Java'? %s\n", dic_existe(miDic, "Java") ? "SI" : "NO");

    // 4. Eliminar
    printf("Eliminando 'Mundo': %d\n", dic_eliminar(miDic, "Mundo"));
    printf("Eliminando 'Java' (no existe): %d\n", dic_eliminar(miDic, "Java"));

    dic_imprimir(miDic);

    // 5. Guardar en archivo
    if (dic_guardar(miDic, "mis_palabras.txt")) {
        printf("Diccionario guardado en 'mis_palabras.txt'.\n");
    } else {
        printf("Error al guardar.\n");
    }

    // 6. Destruir (Limpiar memoria)
    dic_destruir(miDic);
    printf("Diccionario destruido.\n");

    // ---------------------------------------------------------
    // 7. Prueba de carga (Recuperar datos)
    printf("\n=== PRUEBA DE CARGA DESDE ARCHIVO ===\n");
    
    Diccionario* nuevoDic = dic_crear();
    int cant = dic_cargar(nuevoDic, "mis_palabras.txt");
    
    printf("Se cargaron %d palabras desde el archivo.\n", cant);
    
    // Agregamos una más para probar mezcla
    dic_agregar(nuevoDic, "Recuperado");
    
    dic_imprimir(nuevoDic);

    dic_destruir(nuevoDic);

    return 0;
}