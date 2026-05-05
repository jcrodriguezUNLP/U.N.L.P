/*
 * RESUMEN DE MANEJO DE ARCHIVOS DE TEXTO EN C
 * Basado en el PDF proporcionado.
 * * Temas incluidos:
 * 1. Declaración de FILE* y fopen (Modos "w", "r", "a")
 * 2. Escritura: fprintf, fputs, fputc
 * 3. Lectura: fgets, fgetc, fscanf
 * 4. Control de EOF (feof)
 * 5. Desplazamiento: fseek, ftell, SEEK_END
 */

#include <stdio.h>

int main() {
    FILE *archivo                               ;
    char nombreArchivo[] = "prueba_resumen.txt" ;
    char buffer[100]                            ;
    char caracter                               ;
    
    // ================================================================
    // PARTE 1: ESCRITURA (Modo "w")
    // Crea el archivo o borra el contenido si ya existe.
    // ================================================================
    printf("--- 1. ESCRITURA EN ARCHIVO ---\n");
    
    archivo = fopen(nombreArchivo, "w"); [cite_start] // [cite: 38]
    
    if (archivo == NULL) {
        printf("Error: No se pudo crear el archivo.\n");
        return 1;
    }

    [cite_start]// Uso de fprintf (Formato como printf) [cite: 147]
    fprintf(archivo, "Nombre: %s\n", "Juan Perez");
    fprintf(archivo, "Edad: %d\n", 30);
    
    [cite_start]// Uso de fputs (Cadenas directas) [cite: 479]
    fputs("Esta linea fue escrita con fputs.\n", archivo);
    
    [cite_start]// Uso de fputc (Caracter por caracter) [cite: 454]
    fputc('A', archivo);
    fputc('\n', archivo); // Salto de linea manual

    printf("Archivo '%s' creado y datos escritos correctamente.\n\n", nombreArchivo);
    
    fclose(archivo); [cite_start]// Importante cerrar para guardar cambios [cite: 44]


    // ================================================================
    // PARTE 2: ANEXAR DATOS (Modo "a")
    // Escribe al final sin borrar lo anterior.
    // ================================================================
    printf("--- 2. AGREGANDO DATOS AL FINAL (APPEND) ---\n");
    
    archivo = fopen(nombreArchivo, "a"); [cite_start]// [cite: 314]
    
    if (archivo != NULL) {
        fprintf(archivo, "--- FIN DEL REPORTE ---\n");
        printf("Se agrego una linea al final del archivo.\n\n");
        fclose(archivo);
    }


    // ================================================================
    // PARTE 3: LECTURA COMPLETA (Modo "r")
    // Lee el archivo linea por linea usando fgets.
    // ================================================================
    printf("--- 3. LECTURA DEL ARCHIVO (fgets) ---\n");
    
    archivo = fopen(nombreArchivo, "r"); [cite_start]// [cite: 314]
    
    if (archivo == NULL) {
        printf("Error al abrir para lectura.\n");
        return 1;
    }

    [cite_start]// fgets lee hasta encontrar un salto de linea o llenar el buffer [cite: 471]
    while (fgets(buffer, 100, archivo) != NULL) {
        printf("%s", buffer); // Muestra en pantalla lo leido
    }
    
    fclose(archivo);
    printf("\n");


    // ================================================================
    // PARTE 4: LECTURA CARACTER POR CARACTER (fgetc + feof)
    // ================================================================
    printf("--- 4. LECTURA CARACTER POR CARACTER ---\n");
    
    archivo = fopen(nombreArchivo, "r");
    
    if (archivo != NULL) {
        // Leemos el primer caracter antes del ciclo
        caracter = fgetc(archivo); [cite_start]// [cite: 445]
        
        [cite_start]// feof devuelve verdadero si se intento leer mas alla del final [cite: 378]
        while (!feof(archivo)) { 
            printf("%c-", caracter); // Imprimimos con un guion para diferenciar
            caracter = fgetc(archivo); // Leemos el siguiente
        }
        fclose(archivo);
    }
    printf("\n\n");


    // ================================================================
    // PARTE 5: MANEJO DEL CURSOR (fseek y ftell)
    // Calculando el tamaño del archivo.
    // ================================================================
    printf("--- 5. TAMANO DEL ARCHIVO (fseek / ftell) ---\n");
    
    archivo = fopen(nombreArchivo, "r");
    
    if (archivo != NULL) {
        // Mover el cursor al final del archivo
        fseek(archivo, 0, SEEK_END); [cite_start]// [cite: 560]
        
        // Obtener la posicion actual (que ahora es el final = tamaño total)
        long tamano = ftell(archivo); [cite_start]// [cite: 555]
        
        printf("El archivo pesa: %ld bytes.\n", tamano);
        
        // Volver al principio si quisieramos seguir leyendo
        fseek(archivo, 0, SEEK_SET); [cite_start]// [cite: 563]
        
        fclose(archivo);
    }

    return 0;
}