// ==============================================================================
// TODO MAESTRO: PRÁCTICA 2 - ARREGLOS, PUNTEROS Y STRINGS
// ==============================================================================

// ==============================================================================
// SECCIÓN B: PUNTEROS
// ==============================================================================

// ==============================================================================
// ANÁLISIS 3: DIRECCIONES Y VALORES
// ==============================================================================
// Contexto:
//     - Fragmento de código que interactúa con un arreglo y un puntero.
// Tarea / Responda:
//     1. ¿Puede explicar qué significado tienen los valores impresos?
//     2. ¿Qué ocurre cuando se incrementa en uno el puntero "p"?
//
// Código original a analizar:
/*
    int x[5] = {1, 2, 3, 4, 5};
    int *p = x;
    printf("La direccion memoria de p es %p \n", &p);
    printf("La direccion a la que apunta p es %p \n", p);
    printf("El valor al que apunta p es %d \n", *p);
    p++;
    printf("La direccion memoria de p ahora es %p \n", &p);
    printf("La direccion a la que apunta p ahora es %p \n", p);
    printf("El valor al que apunta p ahora es %d \n", *p);
*/
// ==============================================================================

// ==============================================================================
// ANÁLISIS 4: ARITMÉTICA DE PUNTEROS EN BUCLES
// ==============================================================================
// Contexto:
//     - Bucle for que modifica un vector mediante aritmética de punteros.
// Tarea / Responda:
//     a) ¿Qué imprime el programa?
//     b) ¿Por qué razón se ve modificada la variable vector? ¿Es correcto realizar esto?
//     c) ¿Qué ocurre si en la línea 7 se cambia *p por vector[i]?
//     d) Cambie la línea 8 por p+=1. ¿Qué sucede?
//     e) Cambie la línea 8 por p+=2. ¿Qué sucede?
//
// Código original a analizar:
/*
    int vector[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i;
    int *p = vector;
    for (i=0; i<10; i++) {
        *p += 3;
        p++;
    }
    printf("vector[%d] = %d \n", i, *p);
*/
// ==============================================================================

// ==============================================================================
// PROBLEMA 5: INVERSIÓN DE ARREGLO (CON SWAP)
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un arreglo unidimensional.
//     modifique:
//         el arreglo invirtiendo el orden de sus valores físicos.
//     condición / nota:
//         utilice obligatoriamente la función swap(int *a, int *b) definida en la Práctica 1.
// ==============================================================================


// ==============================================================================
// SECCIÓN C: STRINGS (VECTORES DE CARACTERES)
// ==============================================================================

// ==============================================================================
// PROBLEMA 1: FILTRO DE CADENAS POR LONGITUD
// ==============================================================================
// Escriba un programa que:
//     lea:
//         palabras desde el teclado.
//     condición de corte:
//         hasta leer exactamente la palabra "ZZZ".
//     imprima:
//         la cantidad total de palabras leídas que tengan exactamente longitud 5.
// ==============================================================================

// ==============================================================================
// PROBLEMA 2: FILTRO DE CADENAS POR TERMINACIÓN
// ==============================================================================
// Escriba un programa que:
//     lea:
//         palabras desde el teclado.
//     condición de corte:
//         hasta leer exactamente la palabra "XXX".
//     imprima:
//         la cantidad de palabras ingresadas que terminan con la letra minúscula 'o'.
// ==============================================================================

// ==============================================================================
// PROBLEMA 3: REEMPLAZO DE CARACTERES
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un puntero a una cadena de caracteres y dos caracteres individuales.
//     modifique:
//         la cadena, reemplazando todas las ocurrencias del primer carácter por el segundo.
//     retorne:
//         la cadena modificada.
//
// Tarea / Responda:
//     - ¿Retornar la cadena tiene alguna utilidad o no tiene sentido en C?
// ==============================================================================

// ==============================================================================
// PROBLEMA 4: IMPLEMENTACIÓN MANUAL DE STRLEN
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un puntero a una cadena de caracteres.
//     retorne:
//         su longitud (sin incluir el carácter nulo '\0').
//     condición / nota:
//         implemente su propia versión de la función 'strlen'. No use la original.
// ==============================================================================

// ==============================================================================
// PROBLEMA 5: IMPLEMENTACIÓN MANUAL DE STRCPY
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         dos punteros a cadenas de caracteres (destino y origen).
//     modifique:
//         la cadena destino, copiando el contenido de la cadena origen (incluyendo '\0').
//     retorne:
//         el puntero a la cadena destino.
//     condición / nota:
//         - implemente su propia versión de la función 'strcpy'.
//         - asuma que la cadena destino tiene espacio suficiente para la segunda.
// ==============================================================================

// ==============================================================================
// PROBLEMA 6: FRECUENCIA DE LETRAS EN STRING
// ==============================================================================
// Escriba un programa que:
//     lea:
//         una palabra desde teclado.
//     imprima:
//         la cantidad de veces que aparece cada letra contenida en la palabra.
//     condición / nota:
//         asuma que la palabra está formada sólo por letras minúsculas.
// ==============================================================================

// ==============================================================================
// PROBLEMA 7: DETECTOR DE PALÍNDROMOS
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un puntero a una secuencia de caracteres (string).
//     retorne:
//         1 en caso de que la palabra sea palíndroma, 0 en caso contrario.
//     condición / nota:
//         realizar dos implementaciones independientes de esta función:
//         a. Utilizando índices numéricos tradicionales.
//         b. Utilizando estrictamente aritmética de punteros.
// ==============================================================================