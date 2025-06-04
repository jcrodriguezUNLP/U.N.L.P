public class Guerrero extends Personaje {
    private int fuerza ;

    // Constructores
        public Guerrero() {}

        public Guerrero( String nombre , int nivel , int puntosDeVida_Maximos , int puntosDeVida_Actuales , int fuerza ) {
            super( nombre , nivel , puntosDeVida_Maximos , puntosDeVida_Actuales ) ;

            this.fuerza = fuerza ;
        }
    //

    // Getters
        public int getFuerza() { return( fuerza ) ; }
    //

    // Setters
        public void setFuerza( int fuerza ) { this.fuerza = fuerza ; }
    //

    // Métodos
        public int golpeConHacha() {
            int danio = ( fuerza * 2 ) ;

            return( danio ) ;
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( super.toString() ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "fuerza: " + fuerza ) ;

            return( texto ) ;
        }
    //
}