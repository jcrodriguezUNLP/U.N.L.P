/*
 * RESUMEN DE ARCHIVOS BINARIOS EN C
 * Basado en el PDF: 09Archivos-Binarios-en-C.pdf
 *
 * Temas incluidos:
 * 1. Apertura en modos binarios ("wb", "rb")
 * 2. Escritura por bloques (fwrite)
 * 3. Lectura por bloques (fread)
 * 4. Acceso Directo / Posicionamiento (fseek)
 */

#include <stdio.h>

int main() {
    FILE *arch;
    char nombreArchivo[] = "datos.bin";
    
    // Datos de prueba: Un arreglo de enteros
    int valores[] = {10, 20, 30, 40, 50}; 
    int leidos[5];
    int unValor;
    int cantidad = 5;

    // ================================================================
    // PARTE 1: ESCRITURA BINARIA (fwrite)
    // Modo "wb": Crea archivo binario para escritura 
    // ================================================================
    printf("--- 1. ESCRITURA DE ARREGLO EN BINARIO ---\n");

    arch = fopen(nombreArchivo, "wb"); 
    
    if (arch != NULL) {
        // fwrite(puntero_datos, tamaño_tipo, cantidad, archivo) [cite: 50]
        // Escribimos todo el arreglo de una sola vez
        int escritos = fwrite(valores, sizeof(int), cantidad, arch);
        
        printf("Se escribieron %d elementos enteros.\n", escritos); // [cite: 76]
        fclose(arch);
    } else {
        printf("Error al crear el archivo.\n");
        return 1;
    }


    // ================================================================
    // PARTE 2: LECTURA BINARIA COMPLETA (fread)
    // Modo "rb": Abre archivo binario para lectura 
    // ================================================================
    printf("\n--- 2. LECTURA COMPLETA DEL ARCHIVO ---\n");

    arch = fopen(nombreArchivo, "rb");

    if (arch != NULL) {
        // fread(puntero_destino, tamaño_tipo, cantidad, archivo) [cite: 91]
        // Leemos todo el bloque de bytes directamente al arreglo 'leidos'
        int recuperados = fread(leidos, sizeof(int), cantidad, arch);

        printf("Datos recuperados: ");
        for(int i = 0; i < recuperados; i++) {
            printf("%d ", leidos[i]); // [cite: 121]
        }
        printf("\n");
        fclose(arch);
    }


    // ================================================================
    // PARTE 3: ACCESO DIRECTO (fseek)
    // Saltamos directamente a un dato especifico sin leer los anteriores.
    // Esto es posible porque los registros tienen tamaño fijo 
    // ================================================================
    printf("\n--- 3. ACCESO DIRECTO (fseek) ---\n");
    
    arch = fopen(nombreArchivo, "rb");

    if (arch != NULL) {
        // Queremos leer el 4to elemento (indice 3 -> valor 40)
        // Usamos fseek para mover el puntero 
        // Desplazamiento = 3 * tamaño de int
        // Origen = SEEK_SET (desde el principio) 
        
        fseek(arch, 3 * sizeof(int), SEEK_SET); // [cite: 151]

        // Ahora leemos solo 1 entero en esa posición
        fread(&unValor, sizeof(int), 1, arch); // [cite: 152]

        printf("El 4to valor del archivo es: %d\n", unValor);
        
        fclose(arch);
    }

    return 0;
}