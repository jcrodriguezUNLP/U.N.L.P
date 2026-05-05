# ==============================================================================
# ESTÁNDAR DE DESARROLLO Y ARQUITECTURA: JAVA (CORE UNIFICADO)
# ==============================================================================

Este documento define la filosofía de trabajo, arquitectura universal y reglas 
innegociables para el desarrollo de software en Java. Unifica el estándar 
estructural core con las particularidades de la Programación Orientada a Objetos 
y la Máquina Virtual de Java (JVM).

# ==============================================================================
# 1. INGENIERÍA DE REQUISITOS (EXTRACCIÓN DE CONSIGNAS)
# ==============================================================================
Queda estrictamente prohibido trabajar sobre el texto crudo de la cátedra. Toda 
consigna debe traducirse a requerimientos técnicos atómicos antes de codear.

[A] PARA CLASES DE DOMINIO (Entidades):
// ==============================================================================
// CLASE: [NombreDeLaClase] - [Responsabilidad única de la entidad]
// ==============================================================================
//   estado (Atributos):
//     - [Propiedades que definen al objeto, ej: String nombre, int legajo]
//   comportamiento (Métodos):
//     - [Acciones que puede realizar o mensajes que responde]
//   restricciones:
//     - [Validaciones de estado, ej: legajo > 0, nombre no nulo]
// ==============================================================================

[B] PARA LA CLASE PRINCIPAL (Ejecutora / Main):
// ==============================================================================
// MAIN: [Contexto o Título del Ejercicio]
// ==============================================================================
//   orquesta:
//     - [Instanciación de objetos, Scanner y configuración inicial]
//   flujo:
//     - [Interacción del usuario y paso de mensajes entre objetos/métodos]
//   salida:
//     - [Reportes finales o estado resultante impreso por consola]
// ==============================================================================

[C] PARA MÓDULOS AISLADOS (Métodos estáticos / Algoritmos):
// ==============================================================================
// MÓDULO: [NombreDelModulo] - [Propósito único]
// ==============================================================================
//   recibe:
//     - [Parámetros de entrada estables]
//   modifica (Efectos Secundarios Controlados):
//     - [Objetos o arreglos alterados por referencia]
//   retorna:
//     - [Valor de salida al evaluar el módulo, si aplica]
// ==============================================================================

# ==============================================================================
# 2. ESQUELETO DE CLASE Y ORDEN ESTRUCTURAL (INNEGOCIABLE)
# ==============================================================================
Toda clase en Java debe respetar el siguiente orden de miembros y bloques 
delimitados por comentarios. El "Plegado Visual" (indentación extra de 4 espacios) 
es obligatorio dentro de cada bloque.

public class NombreDeLaClase {
    
    private int    dato        ;
    private String descripcion ;

    // constructores
        public NombreDeLaClase() {
        }

        public NombreDeLaClase( int dato , String descripcion ) {
            this.dato        = dato        ;
            this.descripcion = descripcion ;
        }
    //
    
    // getters
        public int    getDato()        { return( dato        ) ; }
        public String getDescripcion() { return( descripcion ) ; }
    //

    // setters
        public void setDato( int dato ) {
            this.dato = dato ;
        }

        public void setDescripcion( String descripcion ) {
            this.descripcion = descripcion ;
        }
    //

    // metodos
        public void procesarAlgoritmo( int parametro ) {
            // --- 1. INICIALIZACIÓN ---
            // --- 2. PROCESAMIENTO ---
            // --- 3. SALIDA ---
        }
    //
}

# ==============================================================================
# 3. REGLA MATEMÁTICA DE LECTURA (CONDICIONES YODA)
# ==============================================================================
* ESTRICTAMENTE PROHIBIDO: El uso de los operadores de desigualdad `>` y `>=`.
* OBLIGATORIO: Utilizar exclusivamente `<` y `<=` invirtiendo los operandos.
* OBJETIVO: Todo condicional (`if`) o bucle (`for`, `while`) debe leerse como un 
  intervalo en la recta numérica matemática (de izquierda a derecha).

# ==============================================================================
# 4. TOLERANCIA CERO, ENCAPSULAMIENTO Y USO DE 'THIS.'
# ==============================================================================
* ZERO WARNINGS: El código debe compilar sin advertencias.
* ENCAPSULAMIENTO ESTRICTO: Los atributos de una clase NUNCA son `public`. Siempre 
  `private` (o `protected`). Mutación solo vía métodos.
* USO DE 'this.': OBLIGATORIO ÚNICAMENTE para desambiguar cuando una variable local 
  o parámetro tiene el mismo nombre que un atributo de instancia (ej: en 
  constructores o setters). En el resto de los casos, se prefiere la llamada 
  directa para mayor claridad.
* ESTADO GLOBAL PROHIBIDO: Todo estado debe viajar mediante parámetros explícitos 
  o pertenecer a la instancia instanciada.
* CONSTANTES: Si un valor es un límite inmutable, debe declararse `final`.

# ==============================================================================
# 5. TIPOGRAFÍA Y ESTILO VISUAL JAVA (ESTRICTO)
# ==============================================================================
* NOMENCLATURA:
  - Clases e Interfaces: `PascalCase` (ej: `CalculadoraEstadistica`).
  - Métodos y Variables: `camelCase` (ej: `calcularPromedio`).
  - Constantes (`final`): `UPPER_SNAKE_CASE` (ej: `LIMITE_MAXIMO`).
* RESPIRACIÓN DEL CÓDIGO: Espacios obligatorios en `( condicion )`, `[ indice ]` 
  y antes de comas y el punto y coma final ` ;`.
* GETTERS: Deben escribirse obligatoriamente en UNA SOLA LÍNEA.
* BLOQUES Y LLAVES: Llave de apertura `{` al final de la misma línea.
* PLEGADO VISUAL: Todo bloque dentro de `// nombre` y `//` debe indentarse un 
  nivel extra (4 espacios / Tab) hacia la derecha.
* ALINEACIÓN VERTICAL: Alinear tabularmente operadores `=` y comentarios inline. 
  Extender la alineación a las variables y operadores en condiciones simétricas.

# ==============================================================================
# 6. ENTORNO, MEMORIA Y BUGS CONOCIDOS JAVA
# ==============================================================================
* MEMORIA JVM: Entender la diferencia entre Tipos Primitivos (pasan por valor) y 
  Objetos/Referencias (pasan por referencia al valor real). No hay `free()` manual.
* BUG DEL '==': ESTRICTAMENTE PROHIBIDO usar `==` para comparar el contenido de 
  dos objetos (especialmente `String`). Obligatorio usar `.equals()`.
* BUG DEL SCANNER (HIGIENE DE BUFFER): Leer un número deja un `\n` residual. 
  Solución obligatoria: Consumir el salto extra con `scanner.nextLine() ;`, o 
  leer como `String` y usar `Integer.parseInt( scanner.nextLine() )`.

# ==============================================================================
# 7. GESTIÓN DEL CONOCIMIENTO Y RESÚMENES (DRY & TRACEABILITY)
# ==============================================================================
Los archivos `.java` deben mantenerse desprovistos de explicaciones teóricas 
extensas. La teoría (Polimorfismo, API Collections, Memoria) va a Markdown.
