// ==============================================================================
// CLASE: ParcialArboles - Procesamiento y validación de árboles binarios
// ==============================================================================
//   estado (Atributos):
//     - BinaryTree< Integer > arbol: Árbol principal de la instancia.
//   comportamiento (Métodos):
//     - isLeftTree: Validación estructural basada en hijos únicos.
//     - esPrefijo: Comparación de igualdad topológica inicial.
//     - sumAndDif: Transformación a árbol de sumas y diferencias.
//   restricciones:
//     - Complejidad temporal O(n) (un solo recorrido).
// ==============================================================================

public class ParcialArboles {
    
    private BinaryTree< Integer > arbol ;

    // constructores
        public ParcialArboles( BinaryTree< Integer > arbol ) {
            this.arbol = arbol ;
        }
    //

    // getters
    //

    // setters
    //

    // metodos
        public boolean isLeftTree( int num ) {
            if ( arbol.isEmpty() ) { return( false ) ; }

            BinaryTree< Integer > nodoEncontrado = buscarNodo( arbol , num ) ;

            if ( nodoEncontrado == null ) { return( false ) ; }

            int cantLeftTrees  = -1 ;
            int cantRightTrees = -1 ;

            if ( nodoEncontrado.hasLeftChild() ) {
                cantLeftTrees = calcularSingleTrees( nodoEncontrado.getLeftChild() ) ; 
            }

            if ( nodoEncontrado.hasRightChild() ) {
                cantRightTrees = calcularSingleTrees( nodoEncontrado.getRightChild() ) ; 
            }

            return( cantRightTrees < cantLeftTrees ) ;
        }

        private BinaryTree< Integer > buscarNodo( BinaryTree< Integer > nodo , int num ) {
            if ( nodo.getData() == num ) { return( nodo ) ; }

            BinaryTree< Integer > result = null ;

            if ( nodo.hasLeftChild() ) {
                result = buscarNodo( nodo.getLeftChild() , num ) ;
            }
            
            if ( ( result == null ) && nodo.hasRightChild() ) {
                result = buscarNodo( nodo.getRightChild() , num ) ;
            }

            return( result ) ;
        }

        private int calcularSingleTrees( BinaryTree< Integer > nodo ) {
            int suma = 0 ;

            boolean tieneSoloIzquierdo =  nodo.hasLeftChild()  && !nodo.hasRightChild() ;
            boolean tieneSoloDerecho   = !nodo.hasLeftChild()  &&  nodo.hasRightChild() ;

            if ( tieneSoloIzquierdo || tieneSoloDerecho ) {
                suma++ ;
            }

            if ( nodo.hasLeftChild() ) {
                suma += calcularSingleTrees( nodo.getLeftChild() ) ;
            }
            
            if ( nodo.hasRightChild() ) {
                suma += calcularSingleTrees( nodo.getRightChild() ) ;
            }

            return( suma ) ;
        }

        public boolean esPrefijo( BinaryTree< Integer > arbol1 , BinaryTree< Integer > arbol2 ) {
            if ( arbol1.isEmpty() ) { return( true ) ; }

            if ( arbol2.isEmpty() ) { return( false ) ; }

            if ( !arbol1.getData().equals( arbol2.getData() ) ) {
                return( false ) ;
            }

            if ( arbol1.hasLeftChild()  && !arbol2.hasLeftChild()  ) { return( false ) ; }
            if ( arbol1.hasRightChild() && !arbol2.hasRightChild() ) { return( false ) ; }

            if ( arbol1.hasLeftChild() && arbol2.hasLeftChild() ) {
                if ( !esPrefijo( arbol1.getLeftChild() , arbol2.getLeftChild() ) ) {
                    return( false ) ; 
                }
            }

            if ( arbol1.hasRightChild() && arbol2.hasRightChild() ) {
                if ( !esPrefijo( arbol1.getRightChild() , arbol2.getRightChild() ) ) {
                    return( false ) ; 
                }
            }

            return( true ) ;
        }

        public BinaryTree< DatosNodo > sumAndDif( BinaryTree< Integer > arbol ) {
            if ( arbol.isEmpty() ) { return( new BinaryTree<>() ) ; }
            
            return( procesarSumAndDif( arbol , 0 , 0 ) ) ;
        }

        private BinaryTree< DatosNodo > procesarSumAndDif( BinaryTree< Integer > nodo , int sumaPadre , int valorPadre ) {
            int sumaActual = ( sumaPadre      + nodo.getData() ) ;
            int difActual  = ( nodo.getData() - valorPadre     ) ;
            
            DatosNodo               datos      = new DatosNodo( sumaActual , difActual ) ;
            BinaryTree< DatosNodo > nuevoNodo = new BinaryTree<>( datos ) ;
            
            if ( nodo.hasLeftChild() ) {
                nuevoNodo.addLeftChild( procesarSumAndDif( nodo.getLeftChild() , sumaActual , nodo.getData() ) ) ;
            }
            
            if ( nodo.hasRightChild() ) {
                nuevoNodo.addRightChild( procesarSumAndDif( nodo.getRightChild() , sumaActual , nodo.getData() ) ) ;
            }
            
            return( nuevoNodo ) ;
        }
    //
}
