# 📚 Resumen Técnico: Programación 3 - Práctica 1
**Autor:** `jcrod` | **Materia:** Programación 3 (UNLP) | **Especialidad:** Computer Engineering / Java Backend

---

## 🛠️ I. Fundamentos de Java y Memoria

### 1. Gestión de Memoria: Stack vs Heap
* **Stack (Pila):** Almacena variables locales de tipos primitivos y las **referencias** (punteros) a objetos. Es de acceso ultra rápido y gestión automática (LIFO). Un exceso de llamadas recursivas sin caso base produce el `StackOverflowError`.
* **Heap (Montículo):** Región de memoria donde residen los objetos reales (`new`). Las instancias permanecen aquí mientras haya al menos una referencia activa en el Stack. El **Garbage Collector** libera la memoria de los objetos huérfanos.

### 2. Modificadores de Acceso
| Modificador | Clase | Paquete | Subclase | Mundo |
| :--- | :---: | :---: | :---: | :---: |
| **`private`** | ✅ | ❌ | ❌ | ❌ |
| **`protected`** | ✅ | ✅ | ✅ | ❌ |
| **`public`** | ✅ | ✅ | ✅ | ✅ |

> **Nota de Arquitectura:** En el Ejercicio 8, el atributo `data` se definió como `protected` para permitir que las subclases especializadas (`CircularQueue`, `DoubleEndedQueue`) manipulen la lista subyacente de forma atómica sin exponerla al cliente externo.

---

## 🏗️ II. Estructuras de Datos (TDAs)

### 1. Listas: ArrayList vs LinkedList
| Operación | ArrayList | LinkedList | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **get(i)** | $O(1)$ | $O(n)$ | Acceso indexado directo vs. Recorrido de nodos. |
| **add(0, x)** | $O(n)$ | $O(1)$ | Desplazamiento de memoria vs. Re-puntero de nodos. |
| **Uso ideal** | Lectura intensiva | Inserciones/Bajas frecuentes | Elección basada en la volatilidad de los datos. |

### 2. Pilas y Colas
* **Stack (LIFO):** *Last-In, First-Out*. Estructura fundamental para el parseo de expresiones y algoritmos de balanceo (Ejercicio 9).
* **Queue (FIFO):** *First-In, First-Out*. Base para la gestión de procesos por orden de llegada.

---

## 🔄 III. Recursión y Sucesiones

La recursión se fundamenta en la **Pila de Llamadas**. Para una implementación robusta se requiere:
1.  **Caso Base:** Detiene la ejecución (ej. `if (n == 1)`).
2.  **Caso Recursivo:** Reduce el problema hacia el caso base.

**Caso de Estudio: Sucesión de Collatz (Ej 7G)**
La implementación recursiva utiliza el **"rebote"** de la pila: se desciende hasta el 1 y, durante el retorno (desapilado), se reconstruye la lista insertando los elementos en el orden cronológico correcto.

---

## 📝 IV. Resoluciones Críticas de Diseño

### Mecanismos de Mutación y Retorno (Ejercicio 5)
1.  **Return Nativo:** Función pura que devuelve una nueva instancia. Mayor overhead de memoria pero máxima inmutabilidad.
2.  **Parámetro Wrapper (Inyectado):** Se pasa un objeto para ser mutado internamente. Aprovecha que Java pasa **objetos por valor de la referencia**, permitiendo "devolver" múltiples métricas sin crear nuevos objetos.
3.  **Estado Estático:** Mutación de variables `static`. Desaconsejado en entornos concurrentes por falta de thread-safety.

### Validación de Balanceo (Ejercicio 9)
Se resuelve mediante un **`Stack<Character>`**:
* Los símbolos de apertura `( { [` se apilan (**push**).
* Los símbolos de cierre `) } ]` disparan un **pop** para verificar coincidencia con el tope.
* Si al finalizar el recorrido la pila está vacía, el String es válido.

---

## 🏛️ V. Casos de Aplicación Real (Ejercicios 10 y 11)

### 1. Cola de Banco (Prioridades)
* **Estructura:** `DoubleEndedQueue<Persona>` (Bi-cola).
* **Justificación:** Mantiene el orden FIFO para el público general (`enqueue`), pero habilita el método `enqueueFirst()` para insertar ciudadanos con prioridad legal (embarazadas, 70+) directamente al inicio de la atención.

### 2. Transporte Público (Paradas Cíclicas)
* **Estructura:** `CircularQueue<Parada>`.
* **Justificación:** Modela un ciclo cerrado. Al procesar una parada, el método `shift()` la mueve automáticamente al final de la secuencia, permitiendo que el colectivo recorra la ruta de forma infinita durante la jornada operativa.