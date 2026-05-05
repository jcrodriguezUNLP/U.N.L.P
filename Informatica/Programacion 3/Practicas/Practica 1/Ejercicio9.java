// ==============================================================================
// PROBLEMA 9: Validación de String Balanceado
// ==============================================================================
//   [B] MAIN: TestBalanceo
//     orquesta:
//       - Selección de estructura de datos a justificar.
//     flujo:
//       - El String a verificar es parámetro de entrada.
//       - Validar anidado de: (,).
//       - Validar anidado de: [,].
//       - Validar anidado de: {.}.
//     salida:
//       - Determinar si está balanceado.
// ==============================================================================

import ar.edu.unlp.info.prog3.practica1.TestBalanceo ;

public class Ejercicio9 {

    // metodos
        public static void main( String[ ] args ) {
            
            if( args.length == 0 ) {
                System.out.println( "ERROR: Debe ingresar un String como parametro." ) ;
                
                return ;
            }

            String  expresion  = args[ 0 ] ;
            boolean balanceado             ;

            // Se asume que esBalanceado es un método estático de TestBalanceo
            balanceado = TestBalanceo.esBalanceado( expresion ) ;

            if( balanceado ) {
                System.out.println( "RESULTADO: El String '" + expresion + "' esta BALANCEADO." ) ;
            } else {
                System.out.println( "RESULTADO: El String '" + expresion + "' esta DESBALANCEADO." ) ;
            }
        }
    //
}
