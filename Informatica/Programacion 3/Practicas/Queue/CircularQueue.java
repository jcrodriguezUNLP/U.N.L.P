// ==============================================================================
//   [A] CLASE: CircularQueue<T>
//    comportamiento (Métodos):
//      - shift(): Rota elementos de forma circular y retorna el elemento movido.
//    restricciones:
//      - Hereda de Queue<T>.
//      - Mantiene el tipo genérico T.
// ==============================================================================

public class CircularQueue<T> extends Queue<T> {

    // Constructor (Llama al constructor de la clase madre)
        public CircularQueue() {
            super() ;
        }
    //

    // Métodos específicos
        public T shift() {
            T elemento = null ;
            
            if( !this.isEmpty() ) {
                elemento = this.dequeue() ;
                
                this.enqueue( elemento ) ;
            }
            
            return( elemento ) ;
        }
    //
}