# ==============================================================================
# ESTÁNDAR DE LENGUAJE: C (Extensión del Estándar Base)
# ==============================================================================
> **NOTA:** Este documento extiende `estandar_base.md`. Se asumen como sabidas 
> las reglas de arquitectura de 3 fases, condiciones Yoda, y la prohibición 
> del estado global.

# 1. PLANTILLAS DE CONSIGNAS (SNIPPETS C)
Utilizar estas estructuras para la traducción de consignas:

[A] PARA PROGRAMAS COMPLETOS:
// ==============================================================================
// PROBLEMA X: [TÍTULO]
// ==============================================================================
// main que:
//   lea: [datos por teclado con scanf]
//   imprima: [resultados con printf]
//   restricción: [ej: no usar arreglos, límite de memoria]
// ==============================================================================

[B] PARA FUNCIONES AISLADAS:
// ==============================================================================
// FUNCIÓN: [Nombre]
// ==============================================================================
//   recibe: [parámetros por valor, ej: int n]
//   modifica: [memoria original vía punteros, ej: int *resultado]
//   retorna: [tipo de dato, ej: 1 éxito, 0 error]
// ==============================================================================

# 2. ESQUELETO BASE (.c)
Todo archivo principal debe estructurarse estrictamente de la siguiente manera:

#include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

int main() {
    // --- 1. INICIALIZACIÓN ---
    
    // --- 2. PROCESAMIENTO ---
    
    // --- 3. SALIDA ---
    
    return( 0 ) ;
}

# 3. ENTORNO, COMPILACIÓN Y MEMORIA (REGLAS C)

* BANDERAS DE COMPILACIÓN (GCC): 
  - Uso obligatorio de `-Wall` para generar el ejecutable.
  - Si se incluye `<math.h>`, es obligatorio enlazar la librería matemática 
    añadiendo el flag `-lm` al final del comando de compilación.

* HIGIENE DE BUFFER (EL BUG DEL SCANF): 
  - Estrictamente PROHIBIDO el uso de `fflush(stdin)` (genera Undefined Behavior 
    en entornos Linux).
  - Para leer caracteres (`%c`) y limpiar el salto de línea residual (`\n`) 
    del buffer, es obligatorio dejar un espacio en blanco antes del formato:
    `scanf( " %c" , &variable ) ;`

* ESTADO PERSISTENTE LOCAL: 
  - Dado que las variables globales están prohibidas (ver Estándar Base), si 
    una función requiere "recordar" un estado entre múltiples llamadas, se debe 
    utilizar el modificador `static` en la declaración local de la variable.

* MUTABILIDAD Y MÚLTIPLES RETORNOS (PUNTEROS): 
  - Dado que C pasa los argumentos por valor (copia) y solo retorna un dato, 
    cualquier modificación requerida sobre las variables del entorno llamador 
    debe hacerse recibiendo la dirección de memoria (`*` en el parámetro) y 
    enviando la referencia (`&` en el argumento).

# 4. SISTEMA DE RESÚMENES (C-SPECIFIC)
* Todo concepto teórico sobre C, peculiaridades de GCC, o snippets de algoritmos 
  clásicos (ej: intercambios, búsquedas) deben ir al archivo `resumen.md` de 
  la práctica correspondiente, citando la línea y archivo `.c` donde se aplicó,
  cumpliendo con la directiva de No Repetición (DRY).