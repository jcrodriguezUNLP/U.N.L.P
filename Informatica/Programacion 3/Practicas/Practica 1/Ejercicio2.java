// ==============================================================================
// MAIN: Generación de Múltiplos
// ==============================================================================
//   orquesta:
//     - Instanciación de Scanner para entrada de datos.
//     - Lectura de valor n desde consola.
//   flujo:
//     - Invocación de generarVectorMultiplos.
//   salida:
//     - Impresión del arreglo de múltiplos.
// ==============================================================================

import java.util.Scanner ;

public class Ejercicio2 {

    // metodos
        public static void main( String[ ] args ) {
            Scanner in        = new Scanner( System.in ) ;
            int     n                                    ;
            int[ ]  multiplos                            ;

            System.out.print( "Ingrese un numero entero n: " ) ;
            
            // Solución obligatoria para el bug del Scanner
            n         = Integer.parseInt( in.nextLine() ) ;
            multiplos = generarVectorMultiplos( n )       ;

            System.out.println( "\nLos " + n + " primeros multiplos son:" ) ;
            
            for( int i = 0 ; i < n ; i++ ) {
                System.out.println( multiplos[ i ] ) ;
            }

            in.close() ;
        }

        public static int[ ] generarVectorMultiplos( int n ) {
            int[ ] multiplos = new int[ n ] ;

            for( int i = 0 ; i < n ; i++ ) {
                multiplos[ i ] = ( ( i + 1 ) * n ) ;
            }

            return( multiplos ) ;
        }
    //
}
