// ==============================================================================
//   [A] CLASE: DoubleEndedQueue<T>
//    comportamiento (Métodos):
//      - enqueueFirst(dato: T): Inserta el elemento al inicio de la cola.
//    restricciones:
//      - Hereda de Queue<T>.
//      - Permite comportamiento de Bi-cola (entrada por ambos extremos).
// ==============================================================================

public class DoubleEndedQueue<T> extends Queue<T> {

    // Constructor
        public DoubleEndedQueue() {
            super() ;
        }
    //

    // Métodos específicos
        public void enqueueFirst( T dato ) {
            // Usamos el método add(indice, elemento) de List
            this.data.add( 0 , dato ) ;
        }
    //
}