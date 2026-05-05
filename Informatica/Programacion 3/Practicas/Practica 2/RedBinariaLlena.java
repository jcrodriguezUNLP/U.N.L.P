// ==========================================================================
// EJERCICIO 4: Cálculo de Retardo (RedBinariaLlena)
// ==========================================================================
//   CLASE: RedBinariaLlena
//     estado (Atributos):
//       - arbol: BinaryTree< Integer >.
//     comportamiento (Métodos):
//       - retardoReenvio(): int.
// ==========================================================================

public class RedBinariaLlena {
    
    private BinaryTree< Integer > arbol ;
    
    // constructores
        public RedBinariaLlena( BinaryTree< Integer > arbol ) {
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
        public int retardoReenvio() {
            if ( arbol.isEmpty() ) { return( 0 ) ; }

            return( maxRetardo( arbol ) ) ;
        }

        private int maxRetardo( BinaryTree< Integer > nodo ) {
            int retardoIzq = 0 ;
            int retardoDer = 0 ;

            if ( nodo.hasLeftChild() ) {
                retardoIzq = maxRetardo( nodo.getLeftChild() ) ;
            }
            
            if ( nodo.hasRightChild() ) {
                retardoDer = maxRetardo( nodo.getRightChild() ) ;
            }

            int max = Math.max( retardoIzq , retardoDer ) ;

            max += nodo.getData() ;

            return( max ) ;
        }
    //
}
