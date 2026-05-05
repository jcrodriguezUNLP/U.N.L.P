// ==============================================================================
// TEORÍA 4: CATEGORÍAS DE OPERADORES
// ==============================================================================
//
// Investigue y Tarea:
//     - Enumere y describa los operadores de C según las siguientes categorías:
//         1. Aritméticos
//         2. Relacionales
//         3. Lógicos
//         4. De bits
//         5. Asignación
//         6. Condicional
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. RESPUESTAS TEÓRICAS: REFERENCIA DE OPERADORES ---
    //
    // 1. Operadores Aritméticos (Matemática básica):
    //    +  : Suma.
    //    -  : Resta.
    //    * : Multiplicación.
    //    /  : División (OJO: si ambos son enteros, trunca los decimales).
    //    %  : Módulo (Retorna el resto de una división entera).
    //    ++ : Incremento (Suma 1 a la variable de forma atómica).
    //    -- : Decremento (Resta 1 a la variable de forma atómica).
    //
    // 2. Operadores Relacionales (Comparación, retornan 1/True o 0/False):
    //    == : Igual a (Cuidado: no confundir con el '=' de asignación).
    //    != : Distinto de.
    //    >  : Mayor que.
    //    <  : Menor que.
    //    >= : Mayor o igual que.
    //    <= : Menor o igual que.
    //
    // 3. Operadores Lógicos (Álgebra de Boole, conectan condiciones):
    //    && : AND (Y). Verdadero SOLO si ambas condiciones son verdaderas.
    //    || : OR (O). Verdadero si al menos UNA condición es verdadera.
    //    !  : NOT (Negación). Invierte el valor de verdad (Ej: !1 es 0).
    //
    // 4. Operadores de Bits (Manipulación a nivel binario, se ven en Arqui):
    //    &  : AND a nivel de bits.
    //    |  : OR a nivel de bits.
    //    ^  : XOR (OR Exclusivo). Verdadero solo si los bits son distintos.
    //    ~  : NOT (Complemento a 1). Invierte todos los bits de la variable.
    //    << : Desplazamiento a la izquierda (Multiplica por potencias de 2).
    //    >> : Desplazamiento a la derecha (Divide por potencias de 2).
    //
    // 5. Operadores de Asignación (Guardan o actualizan valores en memoria):
    //    =  : Asignación simple (Ej: x = 5).
    //    += : Suma y asigna (Ej: x += 2 es exactamente igual a x = x + 2).
    //    -= : Resta y asigna.
    //    *= : Multiplica y asigna.
    //    /= : Divide y asigna.
    //    %= : Calcula el módulo y lo asigna.
    //    (También existen versiones para bits: &=, |=, ^=, <<=, >>=)
    //
    // 6. Operador Condicional (El único operador ternario de C):
    //    ? :  -> Sintaxis: (condición) ? valor_si_verdadero : valor_si_falso
    //            Es una forma matemáticamente compacta de escribir un if/else.

    return( 0 ) ;
}