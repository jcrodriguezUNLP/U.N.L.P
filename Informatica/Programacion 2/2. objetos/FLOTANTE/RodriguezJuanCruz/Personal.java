public class Personal extends Visita {
    private boolean extranjera ;

    // Constructores
        public Personal() {}

        public Personal( int numDeVisita , String fecha , boolean egreso , boolean extranjera ) {
            super( numDeVisita , fecha , egreso ) ;
            this.extranjera = extranjera ;
        }
    //

    // Getters
        public boolean getExtranjera() { return( extranjera ) ; }
    //

    // Setters
        public void setExtranjera( boolean extranjera ) { this.extranjera = extranjera ; }
    //

    // Métodos
        public double costoVisita() {
            double costo = 0 ;
            
            boolean egreso = super.getEgreso() ;
            String fecha = super.getFecha() ;
            
            if ( extranjera ) {
                if ( egreso ) {
                    costo += 10000 ;
                } else {
                    costo += 15000 ;
                }
            } else {
                if ( egreso ) {
                    costo += 7000 ;
                }
            }
            
            if ( fecha.equals( "11 de Octubre de 2024" ) | fecha.equals( "18 de Noviembre de 2024" ) ) {
                costo *= 1.10 ;
            }
            
            return( costo ) ;
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( super.toString() ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "extranjera: " + extranjera ) ;

            return( texto ) ;
        }
    //
}