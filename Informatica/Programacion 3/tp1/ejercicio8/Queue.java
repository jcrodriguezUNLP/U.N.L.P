package tp1.ejercicio8;

import java.util.LinkedList;

public class Queue<T> {
    private LinkedList<T> elements;

    // Constructor
    public Queue() {
        elements = new LinkedList<>();
    }

    // Inserta un elemento al final de la cola
    public void enqueue(T dato) {
        elements.addLast(dato);
    }

    // Elimina y retorna el elemento del frente de la cola
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("La cola está vacía");
        }
        return elements.removeFirst();
    }

    // Retorna el elemento del frente de la cola sin eliminarlo
    public T head() {
        if (isEmpty()) {
            throw new IllegalStateException("La cola está vacía");
        }
        return elements.getFirst();
    }

    // Retorna verdadero si la cola está vacía
    public boolean isEmpty() {
        return elements.isEmpty();
    }

    // Retorna la cantidad de elementos en la cola
    public int size() {
        return elements.size();
    }

    // Retorna los elementos de la cola como un String
    @Override
    public String toString() {
        return elements.toString();
    }
}