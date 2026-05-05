// ==============================================================================
// PROBLEMA 8: API de Colas (Jerarquía POO)
// ==============================================================================
//   [A] CLASE: Queue<T>
//     estado (Atributos Privados / Encapsulamiento Estricto):
//       - data: List<T>.
//     comportamiento (Métodos):
//       - Constructor Queue(): Inicializa la lista subyacente.
//       - enqueue( dato: T ): Inserta al final.
//       - dequeue(): Elimina del frente y retorna.
//       - head(): Retorna elemento del frente.
//       - size(): int.
//       - isEmpty(): boolean.
//       - toString(): String.
//     restricciones:
//       - Atributos 'private' y mutación exclusiva por métodos.
//       - Error si dequeue opera sobre vacía.
//       - Error si head opera sobre vacía.
//
//   [A] CLASE: CircularQueue<T>
//     comportamiento (Métodos):
//       - shift(): Rota elementos de forma circular y retorna.
//
//   [A] CLASE: DoubleEndedQueue<T>
//     comportamiento (Métodos):
//       - enqueueFirst( data: T ): Permite encolar al inicio.
// ==============================================================================

import ar.edu.unlp.info.prog3.practica1.Queue             ;
import ar.edu.unlp.info.prog3.practica1.CircularQueue     ;
import ar.edu.unlp.info.prog3.practica1.DoubleEndedQueue ;

public class Ejercicio8 {

    // metodos
        public static void main( String[ ] args ) {
            
            System.out.println( "=== TEST 1: QUEUE ESTÁNDAR (FIFO) ===" ) ;
            Queue< Integer > colaNormal = new Queue<>() ;

            colaNormal.enqueue( 10 ) ;
            colaNormal.enqueue( 20 ) ;
            colaNormal.enqueue( 30 ) ;

            System.out.println( "Cola inicial: " + colaNormal )           ;
            System.out.println( "Dequeue: "      + colaNormal.dequeue() ) ;
            System.out.println( "Estado final: " + colaNormal )           ;
            System.out.println() ;


            System.out.println( "=== TEST 2: CIRCULAR QUEUE (ROTACIÓN) ===" ) ;
            CircularQueue< String > colaC = new CircularQueue<>() ;

            colaC.enqueue( "A" ) ;
            colaC.enqueue( "B" ) ;
            colaC.enqueue( "C" ) ;
            
            System.out.println( "Cola antes del shift: " + colaC ) ;
            colaC.shift() ;
            System.out.println( "Cola despues (1 rot): " + colaC ) ;
            colaC.shift() ;
            System.out.println( "Cola despues (2 rot): " + colaC ) ;
            System.out.println() ;


            System.out.println( "=== TEST 3: DOUBLE ENDED (BI-COLA) ===" ) ;
            DoubleEndedQueue< Double > colaD = new DoubleEndedQueue<>() ;

            colaD.enqueue( 1.5 ) ;
            colaD.enqueue( 2.5 ) ;
            
            System.out.println( "Cola inicial: "          + colaD ) ;
            colaD.enqueueFirst( 0.5 ) ;
            System.out.println( "Luego de enqueueFirst: " + colaD ) ;
            System.out.println( "Dequeue normal: "        + colaD.dequeue() ) ;
            System.out.println( "Estado final: "          + colaD ) ;
        }
    //
}
