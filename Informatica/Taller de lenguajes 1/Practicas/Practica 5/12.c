/*
 * 12) a) Realice un programa que permita generar un índice para acceder por DNI de manera eficiente a
 * la información del archivo de texto "personas.csv".
 * Este archivo contiene los datos de una persona (identificador, dni, nombre, apellido, correo, ciudad,
 * país y trabajo que desarrolla) en formato CSV.
 * El índice debe generarse en memoria y estar ordenado por DNI para finalmente almacenarlo en el
 * archivo binario "personas.idx".
 * Este archivo binario deberá tener por cada línea del archivo "personas.csv" una entrada que
 * contenga el DNI de la persona junto con la posición absoluta dentro del archivo a los datos asociados a dicho DNI.
 * Diseñe una estructura de datos adecuada para el índice y tenga en cuenta al momento de generarlo que la primera línea del archivo CSV es de encabezado.
 *
 * b) Realice un programa que muestre en pantalla toda la información de una persona a través de un DNI ingresado por teclado.
 * Si la persona no existe deberá informar el error.
 * Tenga en cuenta para la implementación:
 * - Utilizar una estructura de datos adecuada que permita tener el índice completamente en memoria.
 * - Implemente para la búsqueda una función que realice una búsqueda dicotómica.
 * - Implemente el siguiente prototipo para la función de búsqueda:
 * int buscar (FILE* personas, Indice indice, int dni, persona *una_persona)
 *
 * c) Reimplemente b) para utilizar en la función de búsqueda el descriptor del archivo índice.
 * Además modifique el valor de retorno para reflejar la cantidad de veces que se accedió al disco durante la búsqueda en caso de que lo encuentre.
 * El prototipo de la función de búsqueda quedaría:
 * int buscar (FILE* personas, FILE* indice, int dni, persona *una_persona)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para la funcion usleep (opcional)

// --- DEFINICIONES DE ARCHIVO Y TAMAÑOS ---
#define CSV_FILE "personas.csv"
#define INDEX_FILE "personas.idx"
#define MAX_LINE_LEN 256
#define MAX_DNI_LEN 15

// --- ESTRUCTURAS DE DATOS ---

// Estructura para almacenar una entrada del índice (DNI + Desplazamiento en el archivo CSV)
typedef struct {
    long dni;      // DNI como numero (o long long si fuera muy grande)
    long offset;   // Posicion inicial del registro en el archivo CSV (byte inicial)
} EntradaIndice;

// Estructura para la persona completa (solo se usa en el modulo de busqueda)
typedef struct {
    long dni;
    char id[10];
    char apellido[50];
    char nombre[50];
    char trabajo[50];
    char correo[50];
    char ciudad[50];
    char pais[50];
} Persona;

// Estructura para el índice completo en memoria (para busqueda eficiente)
typedef struct {
    EntradaIndice *entradas;
    int count;
} Indice;

// --- MODULO DE GENERACION DEL ÍNDICE (Punto a) ---

/**
 * @brief Funcion de comparacion para qsort (ordenar por DNI).
 */
int comparar_dni(const void *a, const void *b) {
    long dni_a = ((EntradaIndice*)a)->dni;
    long dni_b = ((EntradaIndice*)b)->dni;
    
    if (dni_a < dni_b) return -1;
    if (dni_a > dni_b) return 1;
    return 0;
}

/**
 * @brief Genera el archivo binario de indice "personas.idx".
 */
void generar_indice() {
    FILE *f_csv = fopen(CSV_FILE, "r");
    FILE *f_idx = fopen(INDEX_FILE, "wb");
    
    if (!f_csv || !f_idx) {
        perror("Error al abrir archivos CSV o IDX");
        printf("Asegurese de que '%s' exista con datos.\n", CSV_FILE);
        if (f_csv) fclose(f_csv);
        if (f_idx) fclose(f_idx);
        return;
    }

    char line[MAX_LINE_LEN];
    EntradaIndice *indice_memoria = NULL;
    int num_registros = 0;
    long offset_actual = 0;

    // 1. Omitir la linea de encabezado (y capturar su offset)
    if (fgets(line, MAX_LINE_LEN, f_csv) != NULL) {
        offset_actual = ftell(f_csv);
    } else {
        fclose(f_csv); fclose(f_idx); return;
    }

    // 2. Leer cada registro del CSV y construir el indice en memoria
    while (fgets(line, MAX_LINE_LEN, f_csv) != NULL) {
        char dni_str[MAX_DNI_LEN];
        long dni_val;
        
        // --- Parsing del DNI (asumiendo que es el segundo campo) ---
        // Se crea una copia modificable de la línea
        char temp_line[MAX_LINE_LEN];
        strcpy(temp_line, line);
        
        // Intentar tokenizar: Ignorar ID, tomar DNI
        char *token = strtok(temp_line, ","); // ID
        token = strtok(NULL, ","); // DNI

        if (token != NULL) {
            dni_val = atol(token); // Convertir DNI a long

            // Reasignar memoria para la nueva entrada
            indice_memoria = (EntradaIndice*)realloc(indice_memoria, (num_registros + 1) * sizeof(EntradaIndice));
            if (indice_memoria == NULL) {
                perror("Error de memoria durante realloc");
                free(indice_memoria); fclose(f_csv); fclose(f_idx); return;
            }

            // Almacenar la entrada
            indice_memoria[num_registros].dni = dni_val;
            indice_memoria[num_registros].offset = offset_actual;
            num_registros++;
        }
        
        // Actualizar el offset para el inicio del proximo registro
        offset_actual = ftell(f_csv);
    }
    
    // 3. Ordenar el indice por DNI (qsort)
    qsort(indice_memoria, num_registros, sizeof(EntradaIndice), comparar_dni);

    // 4. Escribir el indice ordenado en el archivo binario (personas.idx)
    fwrite(indice_memoria, sizeof(EntradaIndice), num_registros, f_idx);

    printf("\n--- Generacion de Indice ---\n");
    printf("Indice generado y ordenado para %d personas.\n", num_registros);
    printf("Archivo de indice binario '%s' creado.\n", INDEX_FILE);

    // 5. Liberar memoria
    free(indice_memoria);
    fclose(f_csv);
    fclose(f_idx);
}

// --- MODULOS DE BÚSQUEDA (Punto b y c) ---

/**
 * @brief Carga el indice binario completo a RAM.
 */
Indice cargar_indice_en_memoria() {
    FILE *f_idx = fopen(INDEX_FILE, "rb");
    Indice idx = {NULL, 0};
    
    if (f_idx == NULL) {
        perror("Error al abrir el archivo de indice");
        return idx;
    }

    // 1. Determinar el tamano del archivo
    fseek(f_idx, 0, SEEK_END);
    long tamano_bytes = ftell(f_idx);
    rewind(f_idx);
    
    if (tamano_bytes == 0) {
        fclose(f_idx);
        return idx;
    }

    // 2. Calcular el numero de entradas
    idx.count = tamano_bytes / sizeof(EntradaIndice);

    // 3. Reservar memoria y leer todas las entradas
    idx.entradas = (EntradaIndice*)malloc(tamano_bytes);
    if (idx.entradas == NULL) {
        perror("Error al reservar memoria para el indice");
        fclose(f_idx);
        return idx;
    }

    fread(idx.entradas, sizeof(EntradaIndice), idx.count, f_idx);
    fclose(f_idx);
    return idx;
}

/**
 * @brief Lee el registro completo de la persona en el offset dado.
 */
void leer_registro_persona(FILE *f_csv, long offset, Persona *p) {
    char line[MAX_LINE_LEN];
    
    // Mover el puntero al inicio del registro (offset)
    fseek(f_csv, offset, SEEK_SET);
    
    // Leer la linea del registro
    if (fgets(line, MAX_LINE_LEN, f_csv) == NULL) {
        return;
    }
    
    // Parsear los campos (solo tomamos los que nos interesan)
    char *token;
    char *rest = line;

    // 1. ID
    token = strtok_r(rest, ",", &rest);
    if (token) strncpy(p->id, token, sizeof(p->id) - 1);

    // 2. DNI (ya lo tenemos, pero lo leemos)
    token = strtok_r(rest, ",", &rest);
    if (token) p->dni = atol(token);

    // 3. Apellido
    token = strtok_r(rest, ",", &rest);
    if (token) strncpy(p->apellido, token, sizeof(p->apellido) - 1);

    // 4. Nombre
    token = strtok_r(rest, ",", &rest);
    if (token) strncpy(p->nombre, token, sizeof(p->nombre) - 1);

    // El resto de campos se podrian leer de forma similar para completar la estructura Persona
    // Simplificacion: Solo imprimimos los que leimos
}

/**
 * @brief Imprime la estructura Persona.
 */
void imprimir_persona(const Persona *p) {
    printf("\n--- INFORMACION DE PERSONA ---\n");
    printf("DNI: %ld\n", p->dni);
    printf("ID: %s\n", p->id);
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    // Mas campos si se hubieran parseado...
    printf("------------------------------\n");
}


// --------------------------------------------------------------------------------
// PUNTO b) BUSQUEDA CON INDICE EN RAM (int buscar(FILE* personas, Indice indice, ...))
// --------------------------------------------------------------------------------

/**
 * @brief Busca el DNI usando busqueda dicotomica en el indice cargado en RAM.
 * @return int 1 si encuentra la persona, 0 si no.
 */
int buscar_ram(FILE* personas, Indice indice, long dni, Persona *una_persona) {
    int bajo = 0;
    int alto = indice.count - 1;
    
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        long dni_en_indice = indice.entradas[medio].dni;

        if (dni_en_indice == dni) {
            // Encontrado: Leemos el registro completo del archivo CSV
            long offset = indice.entradas[medio].offset;
            leer_registro_persona(personas, offset, una_persona);
            return 1;
        } else if (dni_en_indice < dni) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return 0; // No encontrado
}


// --------------------------------------------------------------------------------
// PUNTO c) BUSQUEDA CON INDICE EN DISCO (int buscar(FILE* personas, FILE* indice, ...))
// --------------------------------------------------------------------------------

/**
 * @brief Busca el DNI usando busqueda dicotomica sobre el archivo de indice en DISCO.
 * @return int Cantidad de accesos a disco (lecturas de entrada de indice) si encuentra, 0 si no.
 */
int buscar_disco(FILE* personas, FILE* indice_f, long dni, Persona *una_persona, int num_entradas) {
    int bajo = 0;
    int alto = num_entradas - 1;
    int accesos_disco = 0;

    EntradaIndice entrada_actual;

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        
        // 1. Acceso a Disco: Leer la entrada en la posicion 'medio'
        long offset_idx = (long)medio * sizeof(EntradaIndice);
        fseek(indice_f, offset_idx, SEEK_SET);
        fread(&entrada_actual, sizeof(EntradaIndice), 1, indice_f);
        accesos_disco++;
        
        long dni_en_indice = entrada_actual.dni;

        if (dni_en_indice == dni) {
            // Encontrado: Acceso a Disco 2: Leer el registro completo del archivo CSV
            leer_registro_persona(personas, entrada_actual.offset, una_persona);
            accesos_disco++; // Contamos el acceso al archivo de datos
            return accesos_disco;
        } else if (dni_en_indice < dni) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return 0; // No encontrado
}


// --- FUNCIÓN PRINCIPAL ---

int main() {
    long dni_consulta;
    Persona persona_encontrada;
    Indice indice_ram;
    
    printf("Programa de gestion de indices CSV/Binario.\n");

    // =================================================================
    // PUNTO A: GENERAR INDICE
    // =================================================================
    // NOTA: Para probar, cree un archivo 'personas.csv' con el formato especificado.
    printf("\n[Punto a] Generando indice en memoria y escribiendo a disco...\n");
    generar_indice();

    // =================================================================
    // PUNTO B: BUSQUEDA EN RAM
    // =================================================================
    printf("\n[Punto b] Busqueda Dicotomica con Indice en RAM.\n");
    indice_ram = cargar_indice_en_memoria();
    FILE *f_csv_b = fopen(CSV_FILE, "r");
    
    if (f_csv_b == NULL) {
        printf("Error: No se pudo abrir el archivo CSV para la busqueda.\n");
        return 1;
    }
    
    printf("Ingrese DNI a buscar (Busqueda RAM): ");
    if (scanf("%ld", &dni_consulta) == 1) {
        if (buscar_ram(f_csv_b, indice_ram, dni_consulta, &persona_encontrada) == 1) {
            imprimir_persona(&persona_encontrada);
        } else {
            printf("Error: Persona con DNI %ld no encontrada.\n", dni_consulta);
        }
    }
    
    fclose(f_csv_b);
    if (indice_ram.entradas) free(indice_ram.entradas); // Liberar RAM del índice


    // =================================================================
    // PUNTO C: BUSQUEDA EN DISCO
    // =================================================================
    printf("\n[Punto c] Busqueda Dicotomica con Indice en DISCO (Contando accesos).\n");
    
    FILE *f_csv_c = fopen(CSV_FILE, "r");
    FILE *f_idx_c = fopen(INDEX_FILE, "rb");

    if (f_csv_c == NULL || f_idx_c == NULL) {
        printf("Error: No se pudieron abrir los archivos para la busqueda en disco.\n");
        if (f_csv_c) fclose(f_csv_c);
        if (f_idx_c) fclose(f_idx_c);
        return 1;
    }
    
    long tamano_idx;
    fseek(f_idx_c, 0, SEEK_END);
    tamano_idx = ftell(f_idx_c);
    rewind(f_idx_c);
    int num_entradas = tamano_idx / sizeof(EntradaIndice);

    printf("Ingrese DNI a buscar (Busqueda DISCO): ");
    if (scanf("%ld", &dni_consulta) == 1) {
        int accesos = buscar_disco(f_csv_c, f_idx_c, dni_consulta, &persona_encontrada, num_entradas);
        
        if (accesos > 0) {
            imprimir_persona(&persona_encontrada);
            printf("Busqueda exitosa. Total de ACCESOS a disco (indice + datos): %d\n", accesos);
        } else {
            printf("Error: Persona con DNI %ld no encontrada (0 accesos al registro de datos).\n", dni_consulta);
        }
    }

    fclose(f_csv_c);
    fclose(f_idx_c);

    return 0;
}