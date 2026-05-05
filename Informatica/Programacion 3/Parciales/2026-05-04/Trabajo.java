public class Trabajo {
    private String id    ;
    private double costo ;

    // Constructores
        public Nodo( String id , double costo ) {
            this.id    = id    ;
            this.costo = costo ;
        }
    //

    // Getters
        public String getId()    { return( id    ) ; }
        public double getCosto() { return( costo ) ; }
    //

    // Metodos
        public void actualizarCosto( double nuevoCosto ) {
            costo = nuevoCosto ;
        }
    //
}
