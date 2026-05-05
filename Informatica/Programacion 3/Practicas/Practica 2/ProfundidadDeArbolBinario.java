// ==========================================================================
// EJERCICIO 5: Suma Transversal (ProfundidadDeArbolBinario)
// ==========================================================================
//   CLASE: ProfundidadDeArbolBinario
//     estado (Atributos):
//       - arbol: BinaryTree< Integer >.
//     comportamiento (Métodos):
//       - sumaElementosProfundidad( int p ): int.
// ==========================================================================

import java.util.Queue ;

public class ProfundidadDeArbolBinario {
    
    private BinaryTree< Integer > arbol ;

    // constructores
        public ProfundidadDeArbolBinario( BinaryTree< Integer > arbol ) {
            this.arbol = arbol ;
        }
    //

    // getters
        public BinaryTree< Integer > getArbol() { return( arbol ) ; }
    //

    // setters
        public void setArbol( BinaryTree< Integer > arbol ) {
            this.arbol = arbol ;
        }
    //

    // metodos
        public int sumaElementosProfundidad( int p ) {
            if ( arbol.isEmpty() ) { return( 0 ) ; }

            int suma  = 0 ;
            int nivel = 0 ;

            Queue< BinaryTree< Integer > > cola = new Queue<>() ;

            cola.enqueue( arbol ) ;
            cola.enqueue( null ) ;

            while ( ( !cola.isEmpty() ) && ( nivel <= p ) ) {
                BinaryTree< Integer > nodo = cola.dequeue() ;

                if ( nodo != null ) {
                    if ( nivel == p ) {
                        suma += nodo.getData() ;

                    } else {
                        if ( nodo.hasLeftChild() ) {
                            cola.enqueue( nodo.getLeftChild() ) ;
                        }

                        if ( nodo.hasRightChild() ) {
                            cola.enqueue( nodo.getRightChild() ) ;
                        }
                    }

                } else if ( !cola.isEmpty() ) {
                    nivel++ ;

                    cola.enqueue( null ) ;
                }
            }

            return( suma ) ;
        }
    //
}
