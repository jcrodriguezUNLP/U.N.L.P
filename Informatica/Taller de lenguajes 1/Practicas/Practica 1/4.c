// Investigue los operadores del lenguaje C.
// Enumérelos y descríbalos según las siguientes categorías: 
//  - aritméticos
//  - relacionales
//  - lógicos
//  - de bits
//  - asignación
//  - condicional

// ARITMÉTICOS:
//  +  : Suma
//  -  : Resta
//  *  : Multiplicación
//  /  : División
//  %  : Módulo (solo para enteros)
//  ++ : Incremento (pre/post: ++a vs a++)
//  -- : Decremento (pre/post: --a vs a--)
//  -  : Negación (unario)
//  +  : Identidad (unario)
//  Precedencia alta: *, /, % antes que +, -

// RELACIONALES:
//  == : Igualdad
//  != : Desigualdad
//  >  : Mayor que
//  <  : Menor que
//  >= : Mayor o igual que
//  <= : Menor o igual que
//  Devuelven 1 (verdadero) o 0 (falso). Precedencia menor que aritméticos.
//  Cuidado: No confundir = (asignación) con == (comparación).
//  Para strings usar strcmp(), no == directamente.

// LÓGICOS:
//  && : AND lógico (evaluación corta: si primer operando es falso, no evalúa el segundo)
//  || : OR lógico (evaluación corta: si primer operando es verdadero, no evalúa el segundo)
//  !  : NOT lógico
//  Operan con "verdadero" (≠0) y "falso" (=0). Precedencia: ! > && > ||
//  Ejemplo: (a > 0) && (b < 10) - solo evalúa b si a > 0 es verdadero.

// DE BITS:
//  &  : AND a nivel de bits
//  |  : OR a nivel de bits
//  ^  : XOR a nivel de bits
//  ~  : NOT a nivel de bits (complemento)
//  << : Desplazamiento a la izquierda (multiplica por 2^n)
//  >> : Desplazamiento a la derecha (divide por 2^n)
//  Solo para tipos enteros. Útiles para manipulación de flags y optimización.
//  Ejemplo: x << 2 equivale a x * 4, x >> 1 equivale a x / 2.

// DE ASIGNACIÓN:
//  =   : Asignación simple (evalúa de derecha a izquierda)
//  +=  : Suma y asigna (a += b equivale a a = a + b)
//  -=  : Resta y asigna
//  *=  : Multiplica y asigna
//  /=  : Divide y asigna
//  %=  : Módulo y asigna
//  &=  : AND de bits y asigna
//  |=  : OR de bits y asigna
//  ^=  : XOR de bits y asigna
//  <<= : Desplaza izq. y asigna
//  >>= : Desplaza der. y asigna
//  Precedencia más baja que casi todos los demás operadores.

// CONDICIONAL:
//  ?: : Operador ternario
//  Sintaxis: condición ? valor_si_verdadero : valor_si_falso
//  Ejemplo: int max = (a > b) ? a : b;
//  Evalúa de derecha a izquierda. Puede anidarse pero afecta legibilidad.
//  Útil para asignaciones condicionales simples.