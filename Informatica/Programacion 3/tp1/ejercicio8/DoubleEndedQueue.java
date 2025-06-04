package tp1.ejercicio8;

import java.util.LinkedList;

public class DoubleEndedQueue<T> extends Queue<T> {
    private LinkedList<T> elements;

    // Constructor
    public DoubleEndedQueue() {
        elements = new LinkedList<>();
    }

    // Inserta un elemento al inicio de la cola
    public void enqueueFirst(T dato) {
        elements.addFirst(dato);
    }

    // Sobrescribe el método enqueue para agregar al final
    @Override
    public void enqueue(T dato) {
        elements.addLast(dato);
    }

    // Sobrescribe el método dequeue para eliminar del frente
    @Override
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("La cola está vacía");
        }
        return elements.removeFirst();
    }

    // Retorna el elemento del frente de la cola
    @Override
    public T head() {
        if (isEmpty()) {
            throw new IllegalStateException("La cola está vacía");
        }
        return elements.getFirst();
    }

    // Retorna verdadero si la cola está vacía
    @Override
    public boolean isEmpty() {
        return elements.isEmpty();
    }

    // Retorna la cantidad de elementos en la cola
    @Override
    public int size() {
        return elements.size();
    }

    // Retorna los elementos de la cola como un String
    @Override
    public String toString() {
        return elements.toString();
    }
}