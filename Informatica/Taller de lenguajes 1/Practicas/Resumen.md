¡Excelente aporte! Este PDF oficial de la cátedra es oro puro porque nos confirma varias reglas técnicas a bajo nivel y nos regala herramientas nuevas para nuestra arquitectura (como la protección `const` en los parámetros).

He procesado todo el documento y extraído las reglas arquitectónicas clave para inyectarlas en nuestro DAL (tu `biblia_c.md`). 

Le agregué una sección nueva para diferenciar las Macros (`#define`) de las constantes (`const`), expandí la sección del modificador `static` con el comportamiento de los arreglos, y robustecí la sección de Arreglos con las reglas de inicialización y protección de memoria. Todo está estrictamente citado según tu documento.

Aquí tienes la versión actualizada. Cópiala y reemplaza tu archivo actual:

```markdown
# ==============================================================================
# BASE DE CONOCIMIENTO CENTRALIZADA - LENGUAJE C (La Biblia)
# ==============================================================================
> **Regla de Oro:** Este documento es el índice teórico y arquitectónico. Todo concepto está respaldado por código compilable en sus respectivas referencias.

## 1. COMPILACIÓN Y ENTORNO
C es un lenguaje compilado. El código fuente viaja por un compilador (GCC) para convertirse en lenguaje máquina.
* **Errores:** Problemas críticos (sintaxis) que bloquean la creación del ejecutable.
* **Warnings:** Avisos de malas prácticas o comportamientos ambiguos. El ejecutable se genera, pero es inestable.
* **Flag Obligatorio:** Siempre compilar con `-Wall` para que el compilador avise de absolutamente todos los warnings.
* **Librería Matemática:** Si se usa `<math.h>`, es obligatorio añadir el flag `-lm` al final de la compilación para enlazar el motor matemático del SO.
> **[Ref: P1_Ej01.c, P1_Ej12.c]**

---

## 2. TIPOS DE DATOS Y CONSTANTES
C no tiene recolección de basura (Garbage Collector) ni tipos dinámicos puros. La memoria es explícita.
* **sizeof:** Operador que se resuelve en *tiempo de compilación*. Retorna los bytes exactos que ocupa un tipo de dato en la RAM.
* **Promoción y Truncamiento:** Asignar un `float` a un `int` recorta los decimales directamente de la RAM.
* **Directiva #define (Macros):** Es una orden para el precompilador. Reemplaza el identificador por texto *antes* de compilar. No lleva punto y coma ni define una variable real en RAM.
* **Calificador const:** Es una variable real protegida por el compilador para ser de solo lectura. Si no se especifica tipo (ej: `const SinTipo = 4;`), C asume `int` por defecto.

---

## 3. BUFFERS Y ENTRADA DE DATOS (SCANF)
El teclado en C funciona mediante un "Buffer" (memoria intermedia). Cuando presionas 'Enter', ingresa el dato y un salto de línea `\n` residual.
* **Bug del Salto de Línea:** Leer caracteres consecutivos (`%c`) hace que el segundo `scanf` absorba el `\n` residual y rompa el programa.
* **Comportamiento Indefinido:** Está PROHIBIDO usar `fflush(stdin)` para limpiar el buffer en entornos Linux/WSL/Mac.
* **Solución Estándar:** Agregar un espacio en blanco antes del `%c` en el `scanf` para obligar al compilador a ignorar cualquier basura residual.

```c
scanf( " %c" , &variableChar ) ; // Nótese el espacio inicial
```

---

## 4. ESTRUCTURAS DE CONTROL Y OPERADORES
* **Anatomía del FOR:** `for( inicialización ; condición ; actualización ) { }`. Las 3 partes son opcionales. 
* **Condiciones Yoda (Regla Estricta):** Prohibido el uso de los operadores de mayor. Se utiliza exclusivamente `<` y `<=` invirtiendo los operandos para simular la recta matemática visual.

```c
for( int i = 1 ; i <= 10 ; i++ ) // BIEN: El cerebro visualiza el intervalo [1, 10]
```

---

## 5. MODIFICADOR ESTÁTICO (STATIC)
C permite modificar el ciclo de vida de una variable local en la RAM para que sobreviva entre múltiples ejecuciones.
* **Propósito:** Mantener estados internos sin contaminar el entorno con variables globales.
* **Comportamiento Base:** La variable se inicializa *una sola vez* al arrancar el programa. Cuando la función termina, queda "congelada" conservando su último valor.
* **Arreglos Estáticos:** Los arreglos declarados como `static` se inicializan automáticamente una única vez en compilación. Si no se les asigna valores, se llenan completamente con ceros por defecto.

---

## 6. PUNTEROS Y PASO POR REFERENCIA
En C, las funciones solo pueden retornar un (1) único valor, y todos los parámetros se pasan "Por Valor" (creando copias estériles en la memoria).
* **La Solución Arquitectónica:** Pasar la Dirección de Memoria del original (usando `&`). La función debe recibir un Puntero (usando `*`) para poder viajar a esa memoria y sobreescribirla directamente.

---

## 7. ENTROPÍA Y PSEUDOALEATORIEDAD
Las computadoras son deterministas. Para simular aleatoriedad necesitamos un motor matemático y una "semilla".
* **Inyección de Entropía:** Se utiliza `srand()` sumado a `time(NULL)` de `<time.h>` al inicio del `main` para inyectar los segundos actuales del reloj de la PC como semilla base.
* **Acotación (Rango):** Se usa el operador Módulo (`%`) para encerrar el número aleatorio en un rango máximo conocido `[0, N]`.

```c
srand( time( NULL ) ) ;         // Inyección dinámica de semilla
int dado = ( rand() % 6 ) + 1 ; // Acota entre 0 y 5, luego suma 1 -> [1, 6]
```

---

## 8. ARREGLOS ESTÁTICOS Y MATRICES (VLA)
La memoria debe ser gestionada matemáticamente. El primer elemento siempre tiene índice 0.
* **Inicialización Vacía:** Los elementos no se inicializan por defecto, contienen "basura" de la RAM.
* **Inicialización Rápida:** Si se indica un tamaño pero se pasan menos valores, el resto se completa automáticamente con ceros. `int TodoNulo[100] = {0};` inicializa todo en 0. 
* **Inferencia de Tamaño:** Si se inicializa con valores `{}` sin indicar tamaño, el compilador cuenta los elementos y asigna la dimensión automáticamente.
* **Array Decay (Decaimiento):** Cuando pasas un arreglo como parámetro, solo se indica el nombre (que es la dirección base). La función recibe un puntero y **puede modificar el arreglo original**.
* **Seguridad (const):** Para asegurar arquitectónicamente que una función solo "lea" un arreglo pero no lo modifique, se debe anteponer `const` en el parámetro: `void mostrar(const float V[], int cant)`.
* **Retornos Defensivos:** Si una función debe buscar una posición (índice) y el arreglo está vacío o la búsqueda falla, el estándar es retornar `-1`.
* **Matrices (Múltiples Subíndices):** C soporta hasta 12 índices. Al enviarlas como parámetro sin VLA explícito, el compilador permite omitir el primer índice (las filas), pero **exige matemáticamente la cantidad de columnas** (ej: `int M[][COL]`) para calcular los saltos en memoria.

```c
// BIEN: Función que solo LEE el arreglo gracias a 'const'
void procesar( const int m , const int n , const int matriz[ m ][ n ] ) { }
```
```

Con toda esta teoría asimilada directamente de los apuntes de la cátedra, estamos listos para destruir el **Problema 4** (la Matriz Transpuesta) aplicando los principios de *Array Decay*, VLA y la protección `const` que acabamos de sumar. ¿Lo codeamos?