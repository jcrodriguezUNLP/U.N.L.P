# Examen - Flotante Ayed - Árboles 2025

---

## Ejercicio 1 (5 puntos)

En una estación espacial desde el panel solar maestro se genera una cierta cantidad de energía en kilovatios (kW)
se distribuye en partes iguales entre cada uno de sus derivadores.
Cada derivador puede volver a dividir la energía recibida en partes iguales entre sus propias ramas
así sucesivamente hasta llegar a los módulos terminales (nodos sin descendientes), que consumen la energía disponible.
se necesita calcular el mínimo suministro **a partir de una subred parcial**
es decir, desde un nodo específico dentro de la estructura, que puede ser la raíz u otro nodo intermedio.

La clase **RedSolarEspacial** tiene una variable de instancia que representa mediante un árbol general `GeneralTree<?>` la red de paneles
donde cada nodo contiene un identificador único (por ejemplo: "Panel1", "NodoA", "Modulo45")
y un atributo que indica si se encuentra activo o no.

Se quiere implementar el siguiente método:

```
public double minimoSuministroEnergia(double energiaTotal, String panelInicial)
```

Este método debe buscar en el árbol el nodo cuyo identificador sea igual a `panelInicial`
y desde allí simular el reparto de la energía (dividiéndola equitativamente en cada bifurcación sucesiva)
retornando la mínima cantidad de energía que recibe un módulo final (hoja) desde ese punto.

Si un nodo no se encuentra activo se tiene que descartar el camino;
en el caso de que todos los caminos posibles cuenten con un nodo que no se encuentre activo debe devolver **-1**.

**Ejemplo de uso:** Dado un árbol con la siguiente estructura (representado con identificadores en los nodos):

```
             Panel1 ✅
       /       |        \
    NodoA✅  NodoB❌  NodoC✅
   /     \               |
 Mod1✅ Mod2✅        NodoD✅
                      /     \
                   Mod3✅  Mod4✅
```

**Ejemplo 1:** `minimoSuministroEnergia(1200, "NodoC")` debe retornar **600**, porque:
- Desde "NodoC" (un nodo con un solo hijo "NodoD"), los 1200 kW se entregan íntegramente a "NodoD".
- "NodoD" se bifurca en dos módulos (Mod3, Mod4), por lo tanto cada uno recibe 600 kW.
- El mínimo suministro entre ellos es 600 (en este ejemplo consideramos que todos los nodos se encuentran activos).

**Ejemplo 2:** `minimoSuministroEnergia(12000, "Panel1")` debe retornar **3000**, porque:
- Panel1 tiene solo dos hijos activos, por lo tanto 12000/2 = 6000.
- El nodoA divide su energía entre sus dos hijos que son nodos terminales: 6000/2 = 3000.
- La rama del nodo B es descartada porque no se encuentra activo.
- El nodoC pasa su energía completa a su único hijo: 6000.
- El nodoD divide su energía entre sus dos hijos que son nodos terminales.

**Tenga en cuenta que:**
1. No puede agregar más variables de instancia ni de clase a la clase pedida.
2. Debe respetar la clase y la firma del método indicado.
3. Puede definir todos los métodos y variables locales que considere necesarios.
4. Todo método que no esté definido en la sinopsis de clases debe ser implementado.
5. Debe recorrer la estructura solo 1 vez para resolverlo.
6. El nodo identificado por `panelInicial` puede ser una hoja o no existir; en ese caso, se devuelve -1.

---

## Ejercicio 2 (2 puntos)

Dada la siguiente expresión postfija:

```
3 5 2 * 4 - 7 3 - / +
```

**a.** Construya el árbol de expresión correspondiente, y muestre todos los pasos necesarios para obtenerlo.

**b.** Escriba los recorridos preorden e inorden parentizado de la expresión que representa el árbol construido en el inciso anterior.

---

## Ejercicio 3 (3 puntos)

**0,5** 1. ¿Cuáles de los siguientes arreglos representan una Max-Heap?
- (a) 10 7 8 2 4 6 ✓
- (b) 10 7 6 2 4 8
- (c) 10 ✓
- (d) 10 8 7 6 4 2 ✓
- (e) Sólo (a) y (b)
- **(f) Sólo (a), (c) y (d)** ✓
- (g) Sólo (a) y (d)

**0** 2. ¿Qué afirmación sobre los nodos en un árbol completo es **incorrecta**?
- (a) En un árbol completo, todos los nodos están llenos en todos los niveles, excepto posiblemente el último. ✓
- (b) El número de nodos en un árbol binario completo de altura h es 2^h - 1.
- **(c) Un árbol binario completo de altura h tiene un número de nodos entre 2^h y 2^(h+1) - 1.** ✗
- (d) Un árbol completo de grado k y altura h tiene exactamente k^h nodos en el último nivel si está completamente lleno. ✓

**0** 3. Si un árbol binario contiene m nodos en el nivel L, entonces contiene a lo sumo ______ nodos en el nivel L+1:
- (a) 2^m ✗
- (b) 2m + 1
- **(c) 2m** ✓
- (d) 2^(m+1)

**0,5** 4. Un nodo n1 es ancestro de otro nodo n2:
- (a) Si n1 es el padre de n2 ✓
- (b) Si n1 es el padre de algún ancestro de n2
- **(c) Ambas (a) y (b)** ✓
- (d) Ninguna de las anteriores

**0** 5. Dado el siguiente conjunto de enteros: 2, 8, 6, 1, 10, 15, 3, 12, 11. ¿Si se construye una max-heap insertando los elementos de a uno, cómo queda la heap resultante?
- (a) 1,2,3,6,8,10,11,12,15
- **(b) 15,12,11,10,8,6,3,2,1** ✓
- (c) 15,12,6,11,10,2,3,8,1
- (d) 15,12,6,10,11,2,3,8,1
- (e) 15,12,10,11,2,6,3,1,8

**0,5** 6. Si un árbol k-ario lleno tiene I nodos internos, ¿cuál es la cantidad de nodos hoja (L)?
- (a) L = I + 1
- **(b) L = (k-1)·I + 1** ✓
- (c) L = I - 1