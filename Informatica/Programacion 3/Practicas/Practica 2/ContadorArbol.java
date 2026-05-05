// ==========================================================================
// EJERCICIO 3: Filtrado de Nodos (ContadorArbol)
// ==========================================================================
//   CLASE: ContadorArbol
//     estado (Atributos):
//       - arbol: BinaryTree< Integer >.
//     comportamiento (Métodos):
//       - numerosParesInOrden(): List< Integer >.
//       - numerosParesPostOrden(): List< Integer >.
// ==========================================================================

import java.util.LinkedList ;
import java.util.List ;

public class ContadorArbol {
    
    private BinaryTree< Integer > arbol ;

    // constructores
        public ContadorArbol( BinaryTree< Integer > arbol ) {
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
        public List< Integer > numerosParesInOrden() {
            List< Integer > pares = new LinkedList<>() ;
            
            if ( !arbol.isEmpty() ) {
                recolectarInOrden( arbol , pares ) ;
            }
            
            return( pares ) ;
        }

        private void recolectarInOrden( BinaryTree< Integer > nodo , List< Integer > lista ) {
            if ( nodo.hasLeftChild() ) {
                recolectarInOrden( nodo.getLeftChild() , lista ) ;
            }
            
            if ( ( nodo.getData() % 2 ) == 0 ) {
                lista.add( nodo.getData() ) ;
            }
            
            if ( nodo.hasRightChild() ) {
                recolectarInOrden( nodo.getRightChild() , lista ) ;
            }
        }

        public List< Integer > numerosParesPostOrden() {
            List< Integer > pares = new LinkedList<>() ;
            
            if ( !arbol.isEmpty() ) {
                recolectarPostOrden( arbol , pares ) ;
            }
            
            return( pares ) ;
        }

        private void recolectarPostOrden( BinaryTree< Integer > nodo , List< Integer > lista ) {
            if ( nodo.hasLeftChild() ) {
                recolectarPostOrden( nodo.getLeftChild() , lista ) ;
            }
            
            if ( nodo.hasRightChild() ) {
                recolectarPostOrden( nodo.getRightChild() , lista ) ;
            }

            if ( ( nodo.getData() % 2 ) == 0 ) {
                lista.add( nodo.getData() ) ;
            }
        }
    //
}
