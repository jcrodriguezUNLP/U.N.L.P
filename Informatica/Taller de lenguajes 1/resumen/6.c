#include <stdio.h>
#include <string.h> // Necesario para sprintf

/**
 * Función que comprime una cadena usando RLE.
 * Condición: Solo escribe el conteo si es mayor a 1.
 * param s: Puntero constante a la cadena de entrada.
 * param salida: Puntero al buffer de salida (DEBE ser lo suficientemente grande).
 */
void comprimir_rle(const char *s, char *salida) {
    char *p_salida = salida; // Puntero auxiliar para escribir en la salida
    char countStr[12];       // Buffer temporal para sprintf (maneja conteos grandes)

    // Bucle principal: mientras no lleguemos al final de la cadena de entrada
    while (*s != '\0') {
        char caracter_actual = *s;
        int cantRepeticiones = 0;
        
        // 1. Bucle INTERNO: Cuenta todas las repeticiones del caracter_actual
        while( (*s != '\0') && (*s == caracter_actual) ){
            cantRepeticiones++;
            s++; // Avanza el puntero de lectura 's' para contar
        }

        // 2. Escribir el CARÁCTER en la salida
        *p_salida++ = caracter_actual;
        
        // 3. Escribir el CONTEO: SOLO si es mayor a 1
        if( 1 < cantRepeticiones ){
            // **CORRECCIÓN CRÍTICA:** Usar sprintf para convertir el entero a cadena.
            int len = sprintf( countStr, "%d", cantRepeticiones ) ; 
            
            // Copia la cadena del conteo (ej. "10") al buffer de salida
            strcpy( p_salida, countStr ) ;
            
            // Avanza el puntero de salida por la longitud del número copiado
            p_salida += len ; 
        }
        
        // Al salir del bucle interno, 's' ya apunta al siguiente carácter diferente (o a '\0')
    }

    // 4. Terminar la cadena de salida con el nulo
    *p_salida = '\0'; 
}

int main() {
    const char *cadenaOriginal1 = "aaabbbbcaa";
    const char *cadenaOriginal2 = "aaaaaaaaaabbc"; // Caso crítico: conteo > 9
    char salidaComprimida1[100]; 
    char salidaComprimida2[100]; 

    comprimir_rle(cadenaOriginal1, salidaComprimida1);
    comprimir_rle(cadenaOriginal2, salidaComprimida2);

    printf("Cadena original (1): %s\n", cadenaOriginal1);
    printf("Cadena comprimida (1): %s\n", salidaComprimida1); // Esperado: a3b4ca2

    printf("\nCadena original (2): %s\n", cadenaOriginal2);
    printf("Cadena comprimida (2): %s\n", salidaComprimida2); // Esperado: a10bc

    return 0;
}