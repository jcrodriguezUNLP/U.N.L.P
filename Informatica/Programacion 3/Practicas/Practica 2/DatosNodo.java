// ==============================================================================
// CLASE: DatosNodo - DTO para resultados de suma y diferencia de un nodo
// ==============================================================================
//   estado (Atributos):
//     - int suma: Resultado de la suma acumulada.
//     - int diferencia: Resultado de la diferencia calculada.
//   comportamiento (Métodos):
//     - getters para los atributos.
//   restricciones:
//     - Ninguna.
// ==============================================================================

public class DatosNodo {
    
    private int suma       ;
    private int diferencia ;

    // constructores
        public DatosNodo( int suma , int diferencia ) {
            this.suma       = suma       ;
            this.diferencia = diferencia ;
        }
    //

    // getters
        public int getSuma()       { return( suma       ) ; }
        public int getDiferencia() { return( diferencia ) ; }
    //

    // setters
    //

    // metodos
    //
}
