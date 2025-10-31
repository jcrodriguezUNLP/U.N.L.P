#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOMBRE_ARCHIVO "numeros.bin"  // nombre del archivo binario

// -------------------------------------------------------
// Función que genera números aleatorios y los guarda en un archivo binario
// -------------------------------------------------------
void grabar() {
    FILE* f = fopen(NOMBRE_ARCHIVO, "wb"); // abrir en modo escritura binaria

    if (f == NULL) {
        perror("Error al crear el archivo");
        return;
    }

    int n;
    printf("Ingrese la cantidad de números a generar: ");
    scanf("%d", &n);

    srand(time(NULL)); // inicializar generador aleatorio

    for (int i = 0; i < n; i++) {
        int num = rand() % 1000; // número entre 0 y 999
        fwrite(&num, sizeof(int), 1, f); // grabar número en archivo binario
    }

    fclose(f);
    printf("\n Se grabaron %d números correctamente en '%s'.\n\n", n, NOMBRE_ARCHIVO);
}

// -------------------------------------------------------
// Función que lee y muestra todos los números del archivo binario
// -------------------------------------------------------
// -------------------------------------------------------
// Función que lee y muestra todos los números del archivo binario
// -------------------------------------------------------
void mostrar() {
    FILE* f = fopen(NOMBRE_ARCHIVO, "rb"); // abrir en modo lectura binaria

    // 👇 MODIFICACIÓN AQUÍ 👇
    if (f == NULL) {
        // Usa perror, pero muestra el mensaje específico de "no encontrado"
        perror("Error al abrir el archivo para lectura");

        // Mensaje adicional informativo para el usuario
        printf("\n🚫 Archivo '%s' no encontrado.\n", NOMBRE_ARCHIVO);
        printf("👉 **Para crearlo, ingrese la opción 1 en el menú principal.**\n");
        return;
    }
    // 👆 FIN DE MODIFICACIÓN 👆

    int num;
    int contador = 0;

    printf("=== Contenido del archivo '%s' ===\n", NOMBRE_ARCHIVO);
    while (fread(&num, sizeof(int), 1, f) == 1) {
        printf("%d ", num);
        contador++;
    }

    printf("\n\nTotal de números leídos: %d\n", contador);
    fclose(f);
}

// -------------------------------------------------------
// Programa principal
// -------------------------------------------------------
int main() {
    int opcion;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Grabar números en el archivo\n");
        printf("2. Mostrar contenido del archivo\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            grabar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida.\n");
        }
    } while (opcion != 3);

    return 0;
}
