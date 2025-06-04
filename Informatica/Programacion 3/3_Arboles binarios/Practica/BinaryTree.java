import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<T> {
    private T data ;
    private BinaryTree<T> leftChild ;
    private BinaryTree<T> rightChild ;
    
    // Constructores
        public BinaryTree() {
            super() ;
        }
        
        public BinaryTree(T data) {
            this.data = data ;
        }
    //
    
    // Getters
        public T getData() { return( data ) ; }
        
        public BinaryTree<T> getLeftChild() { return( leftChild ) ; }
        
        public BinaryTree<T> getRightChild() { return( rightChild ) ; }
    //
    
    // Setters
        public void setData(T data) { this.data = data ; }
        
        public void addLeftChild(BinaryTree<T> child) { this.leftChild = child ; }
        
        public void addRightChild(BinaryTree<T> child) { this.rightChild = child ; }
        
        public void removeLeftChild() { this.leftChild = null ; }
        
        public void removeRightChild() { this.rightChild = null ; }
    //
    
    // Métodos
        public boolean isEmpty() { return( this.isLeaf() && (this.getData() == null) ) ; }
        
        public boolean isLeaf() { return( !this.hasLeftChild() && !this.hasRightChild() ) ; }
        
        public boolean hasLeftChild() { return( this.leftChild != null ) ; }
        
        public boolean hasRightChild() { return( this.rightChild != null ) ; }
        
        // ejers
            public int contarHojas() {
                int hojas = 0 ;
                
                if( !this.isEmpty() ){
                    if( this.isLeaf() ) {
                        hojas = 1 ;
                    } else {
                        hojas += this.hasLeftChild() ? this.getLeftChild().contarHojas() : 0 ;
                        hojas += this.hasRightChild() ? this.getRightChild().contarHojas() : 0 ;
                    }
                }
                
                return( hojas ) ;
            }
            
            public BinaryTree<T> espejo() {
                BinaryTree<T> espejo = new BinaryTree<>() ;

                if( !this.isEmpty() ){
                    espejo.setData( this.getData() ) ;

                    if ( this.hasLeftChild() ) {
                        espejo.addRightChild( this.getLeftChild().espejo() ) ;
                    }
                    
                    if (this.hasRightChild()) {
                        espejo.addLeftChild( this.getRightChild().espejo() ) ;
                    }
                }
                
                return( espejo ) ;
            }
            
            public void entreNiveles( int n , int m ) {
                if( (m < n) || (n < 0) ) {
                    System.out.println("Rango de niveles inválido.");
                } else {                
                    Queue<BinaryTree<T>> cola = new LinkedList<>();
                    Queue<Integer> niveles = new LinkedList<>();
                    cola.add( this );
                    niveles.add(0);

                    while ( !cola.isEmpty() ) {
                        BinaryTree<T> actual = cola.poll();
                        int nivelActual = niveles.poll();

                        if ( (n <= nivelActual) && (nivelActual <= m) ) {
                            System.out.println( actual.getData() );
                        }

                        if (nivelActual < m) {
                            if (actual.hasLeftChild()) {
                                cola.add(actual.getLeftChild());
                                niveles.add(nivelActual + 1);
                            }
                            if (actual.hasRightChild()) {
                                cola.add(actual.getRightChild());
                                niveles.add(nivelActual + 1);
                            }
                        }
                    }
                }
            }
        //

        // MIOS AL PEDO
            public void graficarArbol( int espacio , int nivel , int[] nivelAnt ) {
                if ( this.isEmpty() ) {
                    System.out.println("El árbol está vacío.");
                } else {
                    if( nivelAnt == null ) {
                        nivelAnt = new int[1] ;
                        nivelAnt[0] = 0 ;
                    } else if( nivel <= nivelAnt[0] ) {
                        separador(2);

                        for (int i = 1; i < espacio; i++) {
                            System.out.print("-");
                        }

                        System.out.print(" ^");

                        separador(1);

                        for (int i = 1; i <= espacio; i++) {
                            System.out.print(" ");
                        }

                        System.out.print("|");

                        separador(2);

                        nivelAnt[0] = nivel - 1;
                    }

                    System.out.print("Nivel: " + nivel);

                    for (int i = 1; i < espacio - 7; i++) {
                        System.out.print(" ");
                    }

                    System.out.println( this.data );

                    for (int i = 1; i < espacio; i++) {
                        System.out.print(" ");
                    }

                    System.out.println("/ \\");

                    nivel++;
                    nivelAnt[0]++;

                    if (this.hasLeftChild()) {
                        this.leftChild.graficarArbol(espacio - 2, nivel, nivelAnt);
                    }
                    if (this.hasRightChild()) {
                        this.rightChild.graficarArbol(espacio + 2, nivel, nivelAnt);
                    }
                }
            }

            // auxiliar para graficarArbol
                private void separador(int cantidad) {
                    for (int i = 0; i < cantidad; i++) {
                        System.out.print("\n");
                    }
                }
            //

            public void insert( T data ) {
                if (data == null) {
                    throw new IllegalArgumentException("Cannot insert null data into the binary tree.");
                }

                if( this.isEmpty() ) {
                    this.data = data ;
                } else {
                    boolean fin = false ;
                    BinaryTree<T> tree_aux ;
                    Queue<BinaryTree<T>> cola = new LinkedList<>() ;
                    
                    cola.add( this ) ;
                
                    do{
                        tree_aux = cola.poll() ;
                        if ( !tree_aux.hasLeftChild() ) {
                            tree_aux.addLeftChild( new BinaryTree<T>( data ) ) ;
                            fin = true ;
                        } else if ( !tree_aux.hasRightChild() ) {
                            tree_aux.addRightChild( new BinaryTree<T>( data ) ) ;
                            fin = true ;
                        } else {
                            if( tree_aux.hasLeftChild() ) {
                                cola.add( tree_aux.getLeftChild() ) ;
                            }
                            
                            if( tree_aux.hasRightChild() ) {
                                cola.add( tree_aux.getRightChild() ) ;
                            }
                        }
                    } while( !fin ) ;
                }
            }

            public void remove(T data) {
                if (this.isEmpty()) {
                    System.out.println("El árbol está vacío.");
                } else {
                    Queue<BinaryTree<T>> cola = new LinkedList<>();
                    cola.add(this);
                    
                    BinaryTree<T> nodoAEliminar = null;
                    BinaryTree<T> ultimoNodo = null;
                    BinaryTree<T> padreUltimoNodo = null;
                    
                    while (!cola.isEmpty()) {
                        BinaryTree<T> actual = cola.poll();
                        
                        // Buscamos el nodo que tiene el dato a eliminar
                        if (actual.getData().equals(data)) {
                            nodoAEliminar = actual;
                        }
                        
                        // Seguimos agregando hijos para encontrar el último nodo
                        if (actual.hasLeftChild()) {
                            cola.add(actual.getLeftChild());
                            padreUltimoNodo = actual;
                            ultimoNodo = actual.getLeftChild();
                        }
                        
                        if (actual.hasRightChild()) {
                            cola.add(actual.getRightChild());
                            padreUltimoNodo = actual;
                            ultimoNodo = actual.getRightChild();
                        }
                    }
                    
                    if (nodoAEliminar != null) {
                        // Reemplazamos el dato del nodo a eliminar por el dato del último nodo
                        nodoAEliminar.setData(ultimoNodo.getData());
                        
                        // Ahora eliminamos el último nodo
                        if (padreUltimoNodo.getRightChild() == ultimoNodo) {
                            padreUltimoNodo.removeRightChild();
                        } else {
                            padreUltimoNodo.removeLeftChild();
                        }
                    } else {
                        System.out.println("El valor no está en el árbol.");
                    }
                }
            }


            public BinaryTree<T> search( T data ) {
                BinaryTree<T> nodo = null ;

                if( !this.isEmpty() ){
                    if( this.data == data ){
                        nodo = this ;
                    } else {
                        if( this.hasLeftChild() ) {
                            nodo = this.getLeftChild().search( data ) ;
                        }

                        if( (nodo == null) && this.hasRightChild() ) {
                            nodo = this.getRightChild().search( data ) ;
                        }
                    }
                }

                return( nodo ) ;
            }

            private int cantNiveles(){
                int niveles = 0 ;

                Queue<BinaryTree<T>> cola = new LinkedList<>() ;
                Queue<Integer> nivelesCola = new LinkedList<>() ;

                cola.add( this ) ;
                nivelesCola.add(0) ;

                while( !cola.isEmpty() ) {
                    BinaryTree<T> tree_aux = cola.poll() ;
                    int nivelActual = nivelesCola.poll() ;

                    if( niveles < nivelActual ) {
                        niveles = nivelActual ;
                    }

                    if( tree_aux.hasLeftChild() ) {
                        cola.add( tree_aux.getLeftChild() ) ;
                        nivelesCola.add( nivelActual + 1 ) ;
                    }

                    if( tree_aux.hasRightChild() ) {
                        cola.add( tree_aux.getRightChild() ) ;
                        nivelesCola.add( nivelActual + 1 ) ;
                    }
                }

                return( niveles ) ;
            }
        
            public void graficarArbol_Por_Nivel() {
                if( this.isEmpty() ) {
                    System.out.println( "El árbol está vacío." ) ;
                } else {
                    int nivelMax = this.cantNiveles() ; // Número de niveles del árbol
                    Queue<BinaryTree<T>> cola = new LinkedList<>() ;
                    cola.add( this ) ;

                    for( int nivel = 0 ; nivel <= nivelMax ; nivel++ ) {
                        int nivelInvertido      = nivelMax - nivel ;
                        int espaciosIniciales   = (int) Math.pow( 2 , (nivelInvertido + 1) ) - 2 ;
                        int cantidadNodosXNivel = (int) Math.pow( 2 , nivel                )     ;
                        int espaciosEntreNodos  = (int) Math.pow( 2 , (nivelInvertido + 2) ) - 1 ;
                        
                        // Imprimir nodos del nivel actual
                        System.out.print( "Nivel " + nivel + ": "       ) ;
                        System.out.print( " ".repeat(espaciosIniciales) ) ;
                        
                        for( int i = 0 ; i < cantidadNodosXNivel ; i++ ) {
                            BinaryTree<T> nodo = cola.poll() ;

                            if( nodo != null ) {
                                System.out.print( nodo.getData() ) ;

                                cola.add( nodo.getLeftChild()  ) ;
                                cola.add( nodo.getRightChild() ) ;
                            } else {
                                System.out.print(" ");
                                
                                cola.add(null);
                                cola.add(null);
                            }

                            if( i < (cantidadNodosXNivel - 1) ) {
                                System.out.print( " ".repeat(espaciosEntreNodos) ) ;
                            }
                        }
                        System.out.println() ; // Salto de línea después de los nodos
                        
                        // Imprimir conexiones entre nodos (barras)
                        if( nivel < nivelMax ) {
                            int espaciosAntesBarras  = calcularEspaciosAntesBarras( nivelInvertido ) ;
                            int espaciosDentroBarras = (int) Math.pow( 2 , nivelInvertido ) - 1    ;
                            int espaciosEntreBarras  = calcularEspaciosEntreBarras( nivelInvertido ) ;
                            
                            System.out.print( " ".repeat(9) ) ; // Espaciado inicial para "Nivel n:"
                            System.out.print( " ".repeat(espaciosAntesBarras) ) ;
                            
                            for( int i = 0 ; i < cantidadNodosXNivel ; i++ ) {
                                System.out.print( "/" ) ;
                                System.out.print( " ".repeat(espaciosDentroBarras) ) ;
                                System.out.print( "\\" ) ;

                                if( i < (cantidadNodosXNivel - 1) ) {
                                    System.out.print( " ".repeat(espaciosEntreBarras) ) ;
                                }
                            }
                            System.out.println() ; // Salto de línea después de las barras
                        }
                    }
                }
            }

            // auxiliares para graficarArbol_Por_Nivel
                private int calcularEspaciosEntreBarras(int nivelInvertido) {
                    if (nivelInvertido == 0) return 0;
                    if (nivelInvertido == 1) return 5;

                    int resultado = 5;
                    for (int i = 2; i <= nivelInvertido; i++) {
                        resultado = resultado * 2 + 1;
                    }
                    return resultado;
                }

                private int calcularEspaciosAntesBarras(int nivelInvertido) {
                    if (nivelInvertido == 0) return 0;
                    return 3 * ((int) Math.pow(2, nivelInvertido - 1) - 1) + 1;
                }
            //

            public void insertarAleatorio(T dato) {
                insertarAleatorio(this, dato, 0);
            }

            // Método auxiliar para insertar un nodo aleatorio en el árbol
                private void insertarAleatorio(BinaryTree<T> nodo, T dato, int nivel) {
                    if (nivel >= 4) {
                        // Ya llegamos al máximo nivel permitido, no insertamos más abajo
                        return;
                    }

                    // Si el hijo izquierdo está vacío, hay posibilidad de insertar
                    if (nodo.getLeftChild() == null && nodo.getRightChild() == null) {
                        if (Math.random() < 0.5) {
                            nodo.addLeftChild(new BinaryTree<>(dato));
                        } else {
                            nodo.addRightChild(new BinaryTree<>(dato));
                        }
                    } else if (nodo.getLeftChild() == null) {
                        nodo.addLeftChild(new BinaryTree<>(dato));
                    } else if (nodo.getRightChild() == null) {
                        nodo.addRightChild(new BinaryTree<>(dato));
                    } else {
                        // Ambos hijos existen, elegimos uno al azar para seguir bajando
                        if (Math.random() < 0.5) {
                            insertarAleatorio(nodo.getLeftChild(), dato, nivel + 1);
                        } else {
                            insertarAleatorio(nodo.getRightChild(), dato, nivel + 1);
                        }
                    }
                }
            //

        //

        @Override
        public String toString() {
            String texto = "" ;

            if( this.isEmpty() ) {
                texto += "El arbol esta vacio" ;
            } else {
                texto += this.data ;
            }

            return( texto ) ;
        }
    //
}