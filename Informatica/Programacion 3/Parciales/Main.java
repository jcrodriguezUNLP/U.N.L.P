public class Main {
    public static void main( String[] args ) {

        // Creamos los nodos hoja (módulos terminales)
        RedSolarEspacial mod1  = new RedSolarEspacial( "Mod1"  , true ) ;
        RedSolarEspacial mod2  = new RedSolarEspacial( "Mod2"  , true ) ;
        RedSolarEspacial mod3  = new RedSolarEspacial( "Mod3"  , true ) ;
        RedSolarEspacial mod4  = new RedSolarEspacial( "Mod4"  , true ) ;

        // Creamos nodos intermedios
        RedSolarEspacial nodoA = new RedSolarEspacial( "NodoA" , true  ) ;
        RedSolarEspacial nodoB = new RedSolarEspacial( "NodoB" , false ) ;
        RedSolarEspacial nodoC = new RedSolarEspacial( "NodoC" , true  ) ;
        RedSolarEspacial nodoD = new RedSolarEspacial( "NodoD" , true  ) ;

        // Creamos la raíz
        RedSolarEspacial panel1 = new RedSolarEspacial( "Panel1" , true ) ;

        // Armamos el árbol
        // NodoA -> Mod1, Mod2
        nodoA.getDerivadores().addChild( new GeneralTree<>( mod1 ) ) ;
        nodoA.getDerivadores().addChild( new GeneralTree<>( mod2 ) ) ;

        // NodoD -> Mod3, Mod4
        nodoD.getDerivadores().addChild( new GeneralTree<>( mod3 ) ) ;
        nodoD.getDerivadores().addChild( new GeneralTree<>( mod4 ) ) ;

        // NodoC -> NodoD
        nodoC.getDerivadores().addChild( new GeneralTree<>( nodoD ) ) ;

        // Panel1 -> NodoA, NodoB, NodoC
        panel1.getDerivadores().addChild( new GeneralTree<>( nodoA ) ) ;
        panel1.getDerivadores().addChild( new GeneralTree<>( nodoB ) ) ;
        panel1.getDerivadores().addChild( new GeneralTree<>( nodoC ) ) ;

        // Imprimimos para verificar
        System.out.println( "Raíz: " + panel1.getId() ) ;
        
        for( GeneralTree<RedSolarEspacial> hijo : panel1.getDerivadores().getChildren() ) {
            System.out.println( "  Hijo: " + hijo.getData().getId() + " activo: " + hijo.getData().getActive() ) ;
        }
    }
}