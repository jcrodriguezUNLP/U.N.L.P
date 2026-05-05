// ==============================================================================
// TEORÍA 3: NÚMEROS NATURALES Y ENTEROS EN C
// ==============================================================================
//
// Responda:
//     1. ¿Qué tipos de datos pueden usarse para representar enteros en C?
//     2. ¿Qué modificadores pueden utilizarse con estos tipos?
//
// Tarea:
//     - Para cada combinación (tipo + modificador), indique:
//         a. Tamaño en bytes.
//         b. Sistema de representación binario.
//         c. Rango de valores.
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. RESPUESTAS TEÓRICAS ---
    //
    // 1. Tipos de datos base para enteros:
    //    - char : Aunque se usa para texto, internamente es un número entero de 8 bits.
    //    - int  : El entero estándar nativo de la arquitectura de la computadora.
    //
    // 2. Modificadores aplicables:
    //    - De longitud : short, long, long long.
    //    - De signo    : signed, unsigned.
    //
    // --- 2. TAREA: COMBINACIONES Y ARQUITECTURA (Compilador 32/64 bits) ---
    //
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | Tipo + Modificador   | Bytes | Representación Binaria | Rango de Valores                             |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | [signed] char        | 1     | Complemento a 2        | -128 a 127                                   |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | unsigned char        | 1     | Binario puro sin signo | 0 a 255                                      |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | short [int]          | 2     | Complemento a 2        | -32,768 a 32,767                             |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | unsigned short [int] | 2     | Binario puro sin signo | 0 a 65,535                                   |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | [signed] int         | 4     | Complemento a 2        | -2,147,483,648 a 2,147,483,647               |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | unsigned int         | 4     | Binario puro sin signo | 0 a 4,294,967,295                            |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | long long [int]      | 8     | Complemento a 2        | -9 trillones a +9 trillones (aprox)          |
    // |----------------------|-------|------------------------|----------------------------------------------|
    // | unsigned long long   | 8     | Binario puro sin signo | 0 a 18 trillones (aprox)                     |
    // |----------------------|-------|------------------------|----------------------------------------------|
    //
    // NOTAS ARQUITECTÓNICAS:
    // - Las palabras entre corchetes [] son implícitas. Escribir "short" es 
    //   exactamente lo mismo que escribir "signed short int" para el compilador.
    // - El "Complemento a 2" es el truco matemático que usan las CPU para 
    //   representar números negativos usando el primer bit de la izquierda.
    // - El tamaño del tipo "long" a secas depende del Sistema Operativo. 
    //   En Windows suele ser 4 bytes, pero en Linux/WSL suele ser 8 bytes.

    // Retorno estándar para que el archivo sea un programa C válido y compile.
    return( 0 ) ;
}