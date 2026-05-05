// ==============================================================================
// TEORÍA 10: ESTRUCTURA FOR
// ==============================================================================
// Responda:
//     1. Indique detalladamente la estructura de control for en C.
//     2. ¿Cuál es la finalidad de cada parte?
//     3. ¿Qué partes son opcionales y cuáles obligatorias?
//     4. ¿En qué parte del bloque se ejecuta/evalúa cada una?
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. RESPUESTAS TEÓRICAS: ANATOMÍA DEL FOR ---
    //
    // 1. Estructura general:
    //    for ( inicialización ; condición ; actualización ) {
    //        // bloque de instrucciones (cuerpo)
    //    }
    //
    // 2. Finalidad de cada parte:
    //    - Inicialización : Se usa para configurar el estado inicial o declarar la 
    //                       variable de control (ej. int i = 0).
    //    - Condición      : Expresión booleana que determina si el bucle debe 
    //                       continuar o romperse (ej. i < 10).
    //    - Actualización  : Modifica la variable de control para que el algoritmo 
    //                       avance hacia la condición de corte (ej. i++ o i += 2).
    //
    // 3. Opcional vs Obligatorio:
    //    - Las TRES partes (inicialización, condición y actualización) son OPCIONALES.
    //    - Lo único estrictamente OBLIGATORIO por sintaxis son los dos puntos y coma (;). 
    //    - Escribir 'for( ; ; )' es perfectamente válido en C y genera un bucle infinito.
    //
    // 4. Ciclo de ejecución en la CPU (Orden exacto):
    //    [Paso 1] Inicialización -> Se ejecuta UNA SOLA VEZ, justo antes de arrancar.
    //    [Paso 2] Condición      -> Se evalúa ANTES de entrar al bloque.
    //                               Si es Verdadera (distinta de 0), avanza al Paso 3.
    //                               Si es Falsa (0), el bucle se destruye y termina.
    //    [Paso 3] Cuerpo         -> Se ejecutan todas las instrucciones dentro de { }.
    //    [Paso 4] Actualización  -> Se ejecuta al FINALIZAR la iteración, después de 
    //                               la última línea del cuerpo. Luego, salta al Paso 2.

    return( 0 ) ;
}