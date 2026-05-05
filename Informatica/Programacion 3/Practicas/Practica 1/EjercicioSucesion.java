// ==========================================================================
//   [C] MÓDULO AISLADO: calcularSucesion (Inciso G - Sucesión de Collatz)
//     recibe:
//       - int n.
//     modifica:
//       - Ninguno.
//     retorna:
//       - List< Integer > con la sucesión recursiva.
//     restricciones:
//       - Firma exacta: public List< Integer > calcularSucesion( int n ).
//       - Debe implementarse obligatoriamente de forma recursiva.
// ==========================================================================

import java.util.ArrayList ;
import java.util.List      ;

public class EjercicioSucesion {

    // metodos
        public List< Integer > calcularSucesion( int n ) {
            List< Integer > listaFinal ;

            if( n == 1 ) {
                // Caso Base: llegamos a 1. Inicializamos la lista de retorno.
                listaFinal = new ArrayList<>() ;
                listaFinal.add( 1 ) ;
            } else {
                // Llamada Recursiva según paridad de n
                if( ( n % 2 ) == 0 ) {
                    listaFinal = calcularSucesion( n / 2 ) ;
                } else {
                    listaFinal = calcularSucesion( ( n * 3 ) + 1 ) ;
                }
                
                // En el rebote recursivo, insertamos el 'n' actual al principio
                listaFinal.add( 0 , n ) ;
            }

            return( listaFinal ) ;
        }
    //
}
