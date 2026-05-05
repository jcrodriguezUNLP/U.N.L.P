// ==============================================================================
// CLASE: BinaryTree - Estructura de datos recursiva de árbol binario
// ==============================================================================
//   estado (Atributos):
//     - T data: El valor contenido en el nodo.
//     - BinaryTree< T > leftChild: Referencia al hijo izquierdo.
//     - BinaryTree< T > rightChild: Referencia al hijo derecho.
//   comportamiento (Métodos):
//     - getters/setters para los atributos.
//     - hasLeftChild/hasRightChild: Verificación de existencia de hijos.
//     - isLeaf: Determina si el nodo es hoja.
//     - contarHojas: Retorna el total de hojas en el subárbol.
//     - espejo: Retorna una nueva estructura espejada.
//     - entreNiveles: Imprime los datos entre dos niveles dados.
//   restricciones:
//     - Ninguna específica sobre el tipo T.
// ==============================================================================

public class BinaryTree< T > {
    private T data ;

    private BinaryTree< T > leftChild  ; 
    private BinaryTree< T > rightChild ; 

    // Constructores
        public BinaryTree() {}

        public BinaryTree( T data ) {
            this.data = data ;
        }
    //

    // Getters
        public T getData() { return( data ) ; }

        public BinaryTree< T > getLeftChild()  { return( leftChild  ) ; }
        public BinaryTree< T > getRightChild() { return( rightChild ) ; }
    //

    // Setters
        public void setData( T data ) {
            this.data = data ;
        }
        
        public void addLeftChild( BinaryTree< T > child ) {
            leftChild = child ;
        }
        
        public void addRightChild( BinaryTree< T > child ) {
            rightChild = child ;
        }

        public void removeLeftChild() {
            leftChild = null ;
        }

        public void removeRightChild() {
            rightChild = null ;
        }
    //

    // Metodos
        public boolean hasLeftChild() {
            return( (leftChild != null) ) ;
        }
        
        public boolean hasRightChild() {
            return( (rightChild != null) ) ;
        }

        public boolean isLeaf() {
            return( !hasLeftChild() && !hasRightChild() ) ;
        }

        public boolean isEmpty() {
            return( (data == null) && isLeaf() ) ;
        }

        public int contarHojas() {
            if( isEmpty() ) { return( 0 ) ; }
            if( isLeaf()  ) { return( 1 ) ; }

            int hojas = 0 ;

            if( hasLeftChild() ) {
                hojas += leftChild.contarHojas() ;
            }
            
            if( hasRightChild() ) {
                hojas += rightChild.contarHojas() ;
            }

            return( hojas ) ;
        }

        public BinaryTree< T > espejo() {
            BinaryTree< T > arbolEspejo = new BinaryTree<>( data ) ;

            if( hasLeftChild() ) {
                arbolEspejo.addRightChild( leftChild.espejo() ) ;
            }

            if( hasRightChild() ) {
                arbolEspejo.addLeftChild( rightChild.espejo() ) ;
            }
            
            return( arbolEspejo ) ;
        }

        public void entreNiveles( int n , int m ) {
            if( isEmpty() || (n < 0) || (m < n) ) {
                return ;
            }

            Queue< BinaryTree<T> > cola = new Queue<>() ;

            int nivelActual = 0 ;

            // encolo la raiz
            cola.enqueue( this ) ;

            // encolo null por cambiar de nivel
            cola.enqueue( null ) ;

            while ( !cola.isEmpty() && ( nivelActual <= m ) ) {
                BinaryTree< T > nodo = cola.dequeue() ;

                if( nodo != null ) {
                    if( n <= nivelActual ) {
                        System.out.print( nodo.getData() + " " ) ;
                    }

                    if( nodo.hasLeftChild() ) {
                        cola.enqueue( nodo.getLeftChild() ) ;
                    }

                    if( nodo.hasRightChild() ) {
                        cola.enqueue( nodo.getRightChild() ) ;
                    }
                } else if( !cola.isEmpty() ) {
                    if( n <= nivelActual ) {
                        System.out.println() ;
                    }
                    
                    nivelActual++ ;
                    cola.enqueue( null ) ;
                }
            }    
        }

        @Override
        public String toString() {
            return( data.toString() ) ;
        }
    //
}
