public abstract class Visita {
    private int numDeVisita ;
    private String fecha ;
    private boolean egreso ;

    // Constructores
        public Visita() {}

        public Visita( int numDeVisita , String fecha , boolean egreso ) {
            this.numDeVisita = numDeVisita ;
            this.fecha = fecha ;
            this.egreso = egreso ;
        }
    //

    // Getters
        public int getNumDeVisita() { return( numDeVisita ) ; }

        public String getFecha() { return( fecha ) ; }

        public boolean getEgreso() { return( egreso ) ; }
    //

    // Setters
        public void setNumDeVisita( int numDeVisita ) { this.numDeVisita = numDeVisita ; }

        public void setFecha( String fecha ) { this.fecha = fecha ; }

        public void setEgreso( boolean egreso ) { this.egreso = egreso ; }
    //

    // Métodos
        abstract public double costoVisita() ;

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + "numDeVisita: " + numDeVisita ) ;
            texto += ( "\n" + "fecha: " + fecha ) ;
            texto += ( "\n" + "egreso: " + egreso ) ;

            return( texto ) ;
        }
    //
}