public class Jugadores{
    private Jugador[] jugadores     ;
    private int       cantJugadores ;
    private int       MAX_JUGADORES ;

    // constructores
        public Jugadores() {
            this.cantJugadores = 0                            ;
            this.MAX_JUGADORES = 50                           ;
            this.jugadores     = new Jugador[ MAX_JUGADORES ] ;
        }
    //

    // getters
        public int getCantJugadores () { return cantJugadores ; }
    //

    // setters
        public void setCantJugadores ( int cantJugadores ) { this.cantJugadores = cantJugadores ; }
    //

    // metodos
        public void agregarJugador( Jugador jugador ) {
            if( cantJugadores < MAX_JUGADORES ) {
                jugadores[ cantJugadores ] = jugador ;
                
                cantJugadores++ ;
            } else {
                System.out.println( "No se pueden agregar más jugadores" ) ;
            }
        }

        public Jugador getJugador( int posicion ) {
            if ( (0 <= posicion) && (posicion < cantJugadores) ) {
                return jugadores[ posicion ] ;
            }

            return null ;
        }

        public void eliminarJugador( int posicion ) {
            if ( (0 <= posicion) && (posicion < cantJugadores) ) {
                for( int i = posicion ; i < (cantJugadores - 1) ; i++ ) {
                    jugadores[ i ] = jugadores[ i + 1 ] ;
                }

                jugadores[ cantJugadores - 1 ] = null ;

                cantJugadores-- ;

                System.out.println( "Jugador eliminado en la posicion " + posicion ) ;
            } else {
                System.out.println( "No se puede eliminar el jugador en la posicion " + posicion ) ;
            }
        }

        public int cantJugadoresMas100Partidos() {
            int contador = 0 ;

            for( int i = 0 ; i < cantJugadores ; i++ ) {
                if ( 100 < jugadores[ i ].getNumPartidosJugados() ) {
                    contador++ ;
                }
            }

            return contador ;
        }
    //
}