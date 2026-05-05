// ==========================================================================
// EJERCICIO 6: Mutación de Estado (Transformacion)
// ==========================================================================
// Cree una clase Java llamada Transformacion que tenga como variable de instancia 
// un árbol binario de enteros[cite: 1195]. 
// Implemente el método: suma(): BinaryTree<Integer>
// Devuelve el árbol en el que se reemplazó el valor de cada nodo por la suma 
// de todos los elementos presentes en su subárbol izquierdo y derecho[cite: 1195].
// Asuma que los valores de los subárboles vacíos son ceros[cite: 1196].

public class Transformacion {
    private BinaryTree< Integer > arbol ;
    
    // Constructor
        public Transformacion( BinaryTree< Integer > arbol ) {
            this.arbol = arbol ;
        }
    //

    // Metodos
        public BinaryTree< Integer > suma() {
            if( !arbol.isEmpty() ){
                sumaRecursiva(arbol) ;
            }

            return( arbol ) ;
        }

        private int sumaRecursiva( BinaryTree< Integer > nodo ) {
            int valorOriginal = nodo.getData() ;
            int suma = 0 ;

            if( nodo.hasLeftChild() ) {
                suma += sumaRecursiva( nodo.getLeftChild() ) ;
            }

            if( nodo.hasRightChild() ) {
                suma += sumaRecursiva( nodo.getRightChild() ) ;
            }

            nodo.setData( suma ) ;

            suma += valorOriginal ;

            return( suma ) ;
        }
    //
}