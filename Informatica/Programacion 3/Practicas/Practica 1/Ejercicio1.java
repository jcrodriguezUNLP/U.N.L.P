// ==============================================================================
// MAIN: Impresión de Rangos Numéricos (Iteración y Recursión)
// ==============================================================================
//   orquesta:
//     - Inicialización de variables enteras a y b.
//     - Swap de valores para asegurar que a sea el límite inferior.
//   flujo:
//     - Invocación de métodos imprimirFor, imprimirWhile e imprimirRecursivo.
//   salida:
//     - Impresión por consola de los rangos de números.
// ==============================================================================

public class Ejercicio1 {

    // metodos
        public static void main( String[ ] args ) {
            int a   = 12 ;
            int b   = 8  ;
            int aux      ;

            // Swap para garantizar lectura de izquierda a derecha en la recta numérica
            if( b < a ) {
                aux = a   ;
                a   = b   ;
                b   = aux ;
            }

            System.out.println( "a = " + a ) ;
            System.out.println( "b = " + b ) ;
            System.out.println() ;

            System.out.println( "--- Ejecucion con FOR ---" ) ;
            imprimirFor( a , b ) ;

            System.out.println( "\n--- Ejecucion con WHILE ---" ) ;
            imprimirWhile( a , b ) ;

            System.out.println( "\n--- Ejecucion con RECURSION ---" ) ;
            imprimirRecursivo( a , b ) ;
        }

        public static void imprimirFor( int a , int b ) {
            for( int i = a ; i <= b ; i++ ) {
                System.out.println( i ) ;
            }
        }

        public static void imprimirWhile( int a , int b ) {
            while( a <= b ) {
                System.out.println( a ) ;
                
                a++ ;
            }
        }

        public static void imprimirRecursivo( int a , int b ) {
            if( a <= b ) {
                System.out.println( a ) ;
                
                imprimirRecursivo( a + 1 , b ) ;
            }
        }
    //
}
