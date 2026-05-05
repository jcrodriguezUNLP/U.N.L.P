import java.util.LinkedList;
import java.util.Queue;

public class BinaryTreeInteger extends BinaryTree<Integer> {
    // Constructores
        public BinaryTreeInteger() {
            super();
        }

        public BinaryTreeInteger( Integer data ) {
            super( data ) ;
        }
    //
    
    // getters
        public Integer getData() { return( super.getData() ) ; }

        public BinaryTreeInteger getLeftChild() { return( (BinaryTreeInteger) super.getLeftChild() ) ; }

        public BinaryTreeInteger getRightChild() { return( (BinaryTreeInteger) super.getRightChild() ) ; }
    //

    // setters
        public void setData( Integer data ) { super.setData(data) ; }

        public void addLeftChild( BinaryTreeInteger child ) { super.addLeftChild(child) ; }

        public void addRightChild( BinaryTreeInteger child ) { super.addRightChild(child) ; }

        public void removeLeftChild() { super.removeLeftChild() ; }

        public void removeRightChild() { super.removeRightChild() ; }
    //

    // metodos 
        public LinkedList<Integer> numerosPares_InOrden() {
            LinkedList<Integer> numerosPares = new LinkedList<Integer>() ;

            if( !this.isEmpty() ) {
                if( this.isLeaf() ) {
                    if( (this.getData() % 2) == 0 ) {
                        numerosPares.add( this.getData() ) ;
                    }
                } else {
                    if( this.hasLeftChild() ) {
                        numerosPares.addAll( this.getLeftChild().numerosPares_InOrden() ) ;
                    }

                    if( (this.getData() % 2) == 0 ) {
                        numerosPares.add( this.getData() ) ;
                    }

                    if( this.hasRightChild() ) {
                        numerosPares.addAll( this.getRightChild().numerosPares_InOrden() ) ;
                    }
                }
            }

            return( numerosPares ) ;
        }

        public LinkedList<Integer> numerosPares_PostOrden() {
            LinkedList<Integer> numerosPares = new LinkedList<Integer>() ;

            if( !this.isEmpty() ) {
                if( this.isLeaf() ) {
                    if( this.getData() % 2 == 0 ) {
                        numerosPares.add( this.getData() ) ;
                    }
                } else {
                    if( this.hasLeftChild() ) {
                        numerosPares.addAll( this.getLeftChild().numerosPares_PostOrden() ) ;
                    }

                    if( this.hasRightChild() ) {
                        numerosPares.addAll( this.getRightChild().numerosPares_PostOrden() ) ;
                    }
                    
                    if( this.getData() % 2 == 0 ) {
                        numerosPares.add( this.getData() ) ;
                    }
                }
            }

            return( numerosPares ) ;
        }

        // maximo retardo
            public int maximoRetardo() {
                return maximoRetardoRecursivo( this ) ;
            }

            // Método auxiliar recursivo para calcular el máximo retardo
            private int maximoRetardoRecursivo( BinaryTreeInteger nodo ) {
                int retardo ;

                if( nodo != null ) {
                    retardo = nodo.getData() ;

                    // Suma de la rama izquierda
                    int sumaIzquierda = maximoRetardoRecursivo(nodo.getLeftChild());
        
                    // Suma de la rama derecha
                    int sumaDerecha = maximoRetardoRecursivo(nodo.getRightChild());

                    retardo += ( sumaIzquierda < sumaDerecha ) ? sumaDerecha : sumaIzquierda ;

                } else {
                    retardo = 0 ;
                }

                // Retornar la suma más grande entre las dos ramas, incluyendo el valor del nodo actual
                return( retardo );
            }
        //

        // suma de elementos en una profundidad específica
            public int sumaElementosProfundidad(int p) {
                return sumaElementosProfundidadRecursivo(this, p, 0);
            }

            // Método auxiliar recursivo para calcular la suma de elementos en una profundidad específica
            private int sumaElementosProfundidadRecursivo(BinaryTreeInteger nodo, int profundidadObjetivo, int profundidadActual) {
                int suma = 0 ;

                if( nodo != null ) {
                    if (profundidadActual == profundidadObjetivo) {
                        suma = nodo.getData(); // Si estamos en la profundidad deseada, sumamos el valor del nodo
                    } else {
                        // Sumar recursivamente los valores de los hijos izquierdo y derecho
                        suma += sumaElementosProfundidadRecursivo(nodo.getLeftChild(), profundidadObjetivo, profundidadActual + 1)  ;
                        suma += sumaElementosProfundidadRecursivo(nodo.getRightChild(), profundidadObjetivo, profundidadActual + 1) ;
                    }
                }

                return( suma );
            }
        //
        
        // transformar el árbol
            public void Transformacion() {
                transformar(this); // Llama al método auxiliar para transformar el árbol
            }
            // Método auxiliar recursivo para transformar el árbol
            private int transformar(BinaryTreeInteger nodo) {
            int suma = 0; // Inicializar la suma en 0

            if (nodo != null) {
                if (nodo.isLeaf()) {
                    // Transformar el nodo hoja a su valor original (sin modificarlo)
                    suma = nodo.getData(); // Retornar el valor de la hoja

                    nodo.setData(0); // Cambiar el valor del nodo hoja a 0
                } else {
                    // Si el nodo no es hoja, sumar los valores de los hijos
                    if (nodo.hasLeftChild()) {
                        suma += transformar(nodo.getLeftChild()); // Llamada recursiva al hijo izquierdo
                    }

                    if (nodo.hasRightChild()) {
                        suma += transformar(nodo.getRightChild()); // Llamada recursiva al hijo derecho
                    }

                    nodo.setData(suma + nodo.getData()); // Actualizar el valor del nodo actual con la suma de los hijos y su valor original
                }
            }

            return suma; // Retornar la suma acumulada
        }
        //

        // comparar el número de hijos únicos
            public boolean compararUnicosHijos(int num) {
                boolean resultado = false; // Inicializar el resultado como false
                BinaryTreeInteger nodo = buscarNodo(this, num);

                if (nodo != null) {
                    int unicosIzquierda = contarUnicosHijos(nodo.getLeftChild());
                    int unicosDerecha = contarUnicosHijos(nodo.getRightChild());

                    // Considerar -1 si una rama no existe
                    if (!nodo.hasLeftChild()) {
                        unicosIzquierda = -1;
                    }
                    if (!nodo.hasRightChild()) {
                        unicosDerecha = -1;
                    }

                    resultado = unicosIzquierda > unicosDerecha;
                }

                return resultado;
            }

            // Método auxiliar para contar árboles con un único hijo
            private int contarUnicosHijos(BinaryTreeInteger nodo) {
                int count = 0;

                if (nodo != null) {
                    if ((nodo.hasLeftChild() && !nodo.hasRightChild()) || (!nodo.hasLeftChild() && nodo.hasRightChild())) {
                        count = 1; // Nodo con un único hijo
                    }

                    count += contarUnicosHijos(nodo.getLeftChild());
                    count += contarUnicosHijos(nodo.getRightChild());
                }

                return count;
            }
        //

        private BinaryTreeInteger buscarNodo(BinaryTreeInteger nodo, int num) {
            BinaryTreeInteger encontrado = null;

            if (nodo != null) {
                if (nodo.getData() == num) {
                    encontrado = nodo;
                } else {
                    encontrado = buscarNodo(nodo.getLeftChild(), num);
                    if (encontrado == null) {
                        encontrado = buscarNodo(nodo.getRightChild(), num);
                    }
                }
            }

            return encontrado;
        }

        @Override
        public void insert(Integer data) {
            if (data == null) {
                throw new IllegalArgumentException("Cannot insert null data into the binary tree.");
            }

            if (this.isEmpty()) {
                this.setData(data);
            } else {
                boolean fin = false;
                BinaryTreeInteger treeAux;
                Queue<BinaryTreeInteger> cola = new LinkedList<>();

                cola.add(this);

                do {
                    treeAux = cola.poll();
                    if (!treeAux.hasLeftChild()) {
                        treeAux.addLeftChild(new BinaryTreeInteger(data)); // Aseguramos que el nodo sea de tipo BinaryTreeInteger
                        fin = true;
                    } else if (!treeAux.hasRightChild()) {
                        treeAux.addRightChild(new BinaryTreeInteger(data)); // Aseguramos que el nodo sea de tipo BinaryTreeInteger
                        fin = true;
                    } else {
                        if (treeAux.hasLeftChild()) {
                            cola.add(treeAux.getLeftChild());
                        }

                        if (treeAux.hasRightChild()) {
                            cola.add(treeAux.getRightChild());
                        }
                    }
                } while (!fin);
            }
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += super.toString() ;
            texto += this.getData() ;

            return( texto ) ;
        }
    //
}