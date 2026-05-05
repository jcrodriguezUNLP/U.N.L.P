// ==============================================================================
//   [A] CLASE: Queue<T>
//    estado (Atributos Privados / Encapsulamiento Estricto):
//      - data: List<T>.
//    comportamiento (Métodos):
//      - Constructor Queue(): Inicializa la lista subyacente.
//      - enqueue(dato: T): Inserta al final.
//      - dequeue(): Elimina del frente y retorna.
//      - head(): Retorna elemento del frente sin eliminar.
//      - size(): int.
//      - isEmpty(): boolean.
//      - toString(): String.
//    restricciones:
//      - Atributos 'protected' para permitir herencia controlada.
//      - Lanzar error si dequeue/head operan sobre estructura vacía.
// ==============================================================================

import java.util.ArrayList ;
import java.util.List ;

public class Queue<T> {
    protected List<T> data ;

    // Constructor
        public Queue() {
            this.data = new ArrayList<T>() ;
        }
    //

    // Metodos
        public void enqueue( T dato ) {
            data.add( dato ) ;
        }

        public T dequeue() {
            if ( this.isEmpty() ) {
                throw( new RuntimeException( "Error: La cola esta vacia." ) ) ;
            }

            return( data.remove( 0 ) ) ;
        }

        public T head() {
            if ( this.isEmpty() ) {
                throw( new RuntimeException( "Error: La cola esta vacia." ) ) ;
            }

            return( data.get( 0 ) ) ;
        }

        public int size() {
            return( data.size() ) ;
        }

        public boolean isEmpty() {
            return( data.isEmpty() ) ;
        }
    //

    // Representación
        @Override
        public String toString() {
            String str = "" ;

            str += "[ " ;

            for ( T elemento : data ) {
                str += ( elemento + " " ) ;
            }

            str += "]" ;

            return( str ) ;
        }
    //
}