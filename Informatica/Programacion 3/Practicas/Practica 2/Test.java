public class Test {
    public static void main( String[] args ) {
        
        System.out.println( "=== INICIANDO BATERIA DE PRUEBAS: BinaryTree ===" ) ;

        // --- TEST 1: Árbol Vacío ---
        System.out.println( "\n[1] TEST: Arbol Vacio" ) ;
        BinaryTree< Integer > raiz = new BinaryTree< Integer >() ; // Reemplazamos T por Integer
        
        System.out.println( "arbol.toString() (Debe ser null): " + raiz.toString() ) ;
        System.out.println( "arbol.isEmpty()  (Debe ser true): " + raiz.isEmpty() ) ;
        System.out.println( "arbol.isLeaf()   (Debe ser true): " + raiz.isLeaf() ) ;


        // --- TEST 2: Inserción de Datos ---
        System.out.println( "\n[2] TEST: Mutacion de Datos (setData)" ) ;
        raiz.setData( 10 ) ;
        
        System.out.println( "arbol.getData()  (Debe ser 10)  : " + raiz.getData() ) ;
        System.out.println( "arbol.isEmpty()  (Debe ser false): " + raiz.isEmpty() ) ;
        System.out.println( "arbol.isLeaf()   (Debe ser true) : " + raiz.isLeaf() ) ;


        // --- TEST 3: Agregar Hijos ---
        System.out.println( "\n[3] TEST: Ensamblaje de Hijos (add)" ) ;
        BinaryTree< Integer > hijoIzq = new BinaryTree< Integer >( 5 ) ;
        BinaryTree< Integer > hijoDer = new BinaryTree< Integer >( 15 ) ;

        raiz.addLeftChild( hijoIzq ) ;
        raiz.addRightChild( hijoDer ) ;

        System.out.println( "hasLeftChild()   (Debe ser true) : " + raiz.hasLeftChild() ) ;
        System.out.println( "hasRightChild()  (Debe ser true) : " + raiz.hasRightChild() ) ;
        System.out.println( "arbol.isLeaf()   (Debe ser false): " + raiz.isLeaf() ) ;


        // --- TEST 4: Navegar Punteros ---
        System.out.println( "\n[4] TEST: Navegacion de Estructura (get)" ) ;
        System.out.println( "Hijo Izquierdo (Debe ser 5)   : " + raiz.getLeftChild().getData() ) ;
        System.out.println( "Hijo Derecho   (Debe ser 15)  : " + raiz.getRightChild().getData() ) ;


        // --- TEST 5: Remover Hijos ---
        System.out.println( "\n[5] TEST: Desconexion de Nodos (remove)" ) ;
        raiz.removeLeftChild() ;
        raiz.removeRightChild() ;

        System.out.println( "hasLeftChild()   (Debe ser false): " + raiz.hasLeftChild() ) ;
        System.out.println( "hasRightChild()  (Debe ser false): " + raiz.hasRightChild() ) ;
        System.out.println( "arbol.isLeaf()   (Debe ser true) : " + raiz.isLeaf() ) ;


        System.out.println( "\n=== PRUEBAS FINALIZADAS CON EXITO ===" ) ;
    }
}