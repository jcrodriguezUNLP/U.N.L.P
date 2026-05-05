#include <stdio.h>
#include <stdlib.h>

// Definimos las constantes según el enunciado
#define CLIENTES 100
#define SERVICIOS 5

// --- 1. Módulo de Reserva de Memoria ---
int** reservarMatriz(int filas, int cols) {
    // Paso 1: Reservar el array de punteros (filas)
    int** mat = (int**)malloc(filas * sizeof(int*));
    
    // Paso 2: Reservar las columnas para cada fila
    for (int i = 0; i < filas; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
    }
    return mat;
}

// --- 2. Inciso A: Cargar Opiniones ---
void cargarOpiniones(int** mat, int filas, int cols) {
    printf("\n--- CARGA DE OPINIONES ---\n");
    
    for (int i = 0; i < filas; i++) {
        printf(">> Cliente %d:\n", i + 1);
        
        for (int j = 0; j < cols; j++) {
            int nota;
            do {
                printf("   Calificacion Servicio %d (0-5): ", j + 1);
                scanf("%d", &nota);
                if (nota < 0 || nota > 5) {
                    printf("   Error: La nota debe estar entre 0 y 5.\n");
                }
            } while (nota < 0 || nota > 5);
            
            mat[i][j] = nota;
        }
    }
}

// --- 3. Inciso B: Calcular Promedios ---
// Retorna un vector dinámico de float con el promedio de cada servicio
float* calcularPromedios(int** mat, int filas, int cols) {
    // Reservamos memoria para el vector de resultados (uno por servicio)
    float* promedios = (float*)malloc(cols * sizeof(float));
    
    // Recorremos por COLUMNA (Servicios) primero
    for (int j = 0; j < cols; j++) {
        int suma = 0;
        // Sumamos las opiniones de todos los clientes para este servicio j
        for (int i = 0; i < filas; i++) {
            suma += mat[i][j];
        }
        // Calculamos promedio
        promedios[j] = (float)suma / filas;
    }
    
    return promedios;
}

// --- 4. Módulo de Liberación de Memoria ---
void liberarMatriz(int** mat, int filas) {
    // Primero liberamos cada fila
    for (int i = 0; i < filas; i++) {
        free(mat[i]);
    }
    // Finalmente liberamos el contenedor de punteros
    free(mat);
}

// --- 5. Inciso C: Programa Principal ---
int main() {
    int** opiniones;
    float* vectorPromedios;
    
    // Nombres de servicios para mostrar lindo el resultado
    const char* nombresServicios[] = {
        "Atencion al cliente", "Soporte tecnico", 
        "Entrega a domicilio", "Calidad del producto", "Postventa"
    };

    printf("Iniciando sistema de encuestas...\n");

    // 1. Reservar memoria
    opiniones = reservarMatriz(CLIENTES, SERVICIOS);
    if (opiniones == NULL) {
        printf("Error de memoria.\n");
        return 1;
    }

    // 2. Cargar datos (Inciso A)
    // NOTA: Cargar 100 clientes a mano es eterno. 
    // Para probar, cambia el #define CLIENTES a 2 o 3 arriba.
    cargarOpiniones(opiniones, CLIENTES, SERVICIOS);

    // 3. Procesar datos (Inciso B)
    vectorPromedios = calcularPromedios(opiniones, CLIENTES, SERVICIOS);

    // 4. Mostrar resultados
    printf("\n--- RESULTADOS PROMEDIO POR SERVICIO ---\n");
    for (int j = 0; j < SERVICIOS; j++) {
        printf("Servicio %d (%s): %.2f\n", 
               j + 1, nombresServicios[j], vectorPromedios[j]);
    }

    // 5. Liberar recursos
    liberarMatriz(opiniones, CLIENTES); // Matriz
    free(vectorPromedios);              // Vector de promedios

    return 0;
}