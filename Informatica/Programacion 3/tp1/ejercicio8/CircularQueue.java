package tp1.ejercicio8;

public class CircularQueue<T> extends Queue<T> {

    // Rota los elementos de la cola, haciéndola circular
    public T shift() {
        if (isEmpty()) {
            throw new IllegalStateException("La cola está vacía");
        }
        T front = dequeue();
        enqueue(front);
        return front;
    }
}