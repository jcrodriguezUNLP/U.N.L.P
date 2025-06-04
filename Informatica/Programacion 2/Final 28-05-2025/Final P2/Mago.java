public class Mago extends Personaje {
    private int poderMagico ;

    // Constructores
        public Mago() {}

        public Mago( String nombre , int nivel , int puntosDeVida_Maximos , int puntosDeVida_Actuales , int poderMagico ) {
            super( nombre , nivel , puntosDeVida_Maximos , puntosDeVida_Actuales ) ;

            this.poderMagico = poderMagico ;
        }
    //

    // Getters
        public int getPoderMagico() { return( poderMagico ) ; }
    //

    // Setters
        public void setPoderMagico( int poderMagico ) { this.poderMagico = poderMagico ; }
    //

    // Métodos
        public double rayoDeFuego(){
            double danio = ( this.poderMagico * 1.5 ) ;

            return( danio ) ;
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( super.toString() ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "poderMagico: " + poderMagico ) ;

            return( texto ) ;
        }
    //
}