// ==============================================================================
// PROBLEMA 9: Validación de String Balanceado
// ==============================================================================
//   [A] CLASE: TestBalanceo
//     comportamiento (Métodos):
//       - esBalanceado( s: String ): boolean.
//       - sonPareja( apertura: char , cierre: char ): boolean.
//     restricciones:
//       - Uso de Stack< Character > para el control de anidamiento.
// ==============================================================================

import java.util.Stack ;

public class TestBalanceo {

    // metodos
        private static boolean sonPareja( char apertura , char cierre ) {
            if ( ( apertura == '(' ) && ( cierre == ')' ) ) { return( true ) ; }
            if ( ( apertura == '[' ) && ( cierre == ']' ) ) { return( true ) ; }
            if ( ( apertura == '{' ) && ( cierre == '}' ) ) { return( true ) ; }
            return( false ) ;
        }

        public static boolean esBalanceado( String s ) {
            Stack< Character > pila = new Stack<>() ;
            char actual ;
            char tope   ;

            if ( s.isEmpty() ) { return( true ) ; }

            for ( int i = 0 ; ( i < s.length() ) ; i++ ) {
                actual = s.charAt( i ) ;

                if ( ( actual == '(' ) || ( actual == '[' ) || ( actual == '{' ) ) {
                    pila.push( actual ) ;
                } 
                else if ( ( actual == ')' ) || ( actual == ']' ) || ( actual == '}' ) ) {
                    
                    if ( pila.isEmpty() ) { return( false ) ; }

                    tope = pila.pop() ;

                    if ( !sonPareja( tope , actual ) ) {
                        return( false ) ;
                    }
                }
            }

            return( pila.isEmpty() ) ;
        }
    //
}
