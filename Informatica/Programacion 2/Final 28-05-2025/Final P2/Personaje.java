public class Personaje {
    private String nombre ;
    private int nivel ;
    private int puntosDeVida_Maximos ;
    private int puntosDeVida_Actuales ;
    private String estado ;

    // Constructores
        public Personaje() {}

        public Personaje( String nombre , int nivel , int puntosDeVida_Maximos , int puntosDeVida_Actuales ) {
            this.nombre = nombre ;
            this.nivel = nivel ;
            this.puntosDeVida_Maximos = puntosDeVida_Maximos ;
            this.puntosDeVida_Actuales = puntosDeVida_Actuales ;

            if( 3 < this.puntosDeVida_Actuales ){
                this.estado = "normal" ;
            } else if( 0 < this.puntosDeVida_Actuales ){
                this.estado = "envenenado" ;
            } else {
                this.estado = "derrotado" ;
            }
        }
    //

    // Getters
        public String getNombre() { return( nombre ) ; }

        public int getNivel() { return( nivel ) ; }

        public int getPuntosDeVida_Maximos() { return( puntosDeVida_Maximos ) ; }

        public int getPuntosDeVida_Actuales() { return( puntosDeVida_Actuales ) ; }

        public String getEstado() { return( estado ) ; }
    //

    // Setters
        public void setNombre( String nombre ) { this.nombre = nombre ; }

        public void setNivel( int nivel ) { this.nivel = nivel ; }

        public void setPuntosDeVida_Maximos( int puntosDeVida_Maximos ) { this.puntosDeVida_Maximos = puntosDeVida_Maximos ; }

        public void setPuntosDeVida_Actuales( int puntosDeVida_Actuales ) { this.puntosDeVida_Actuales = puntosDeVida_Actuales ; }

        public void setEstado( String estado ) { this.estado = estado ; }
    //

    // Métodos
        public void subirDeNivel(){
            this.nivel++ ;

            this.puntosDeVida_Maximos  += 10 ;
            this.puntosDeVida_Actuales += 10 ;
        } ;

        public void recibirDanio( int danio ){
            int danioTotal = danio + efectoDelEstado() ;

            int nuevosPuntosDeVida = ( this.puntosDeVida_Actuales - danioTotal ) ;

            if( 0 < nuevosPuntosDeVida ){
                if( nuevosPuntosDeVida <= 3 ){
                    this.estado = "envenenado" ;
                }
                
                this.puntosDeVida_Actuales = nuevosPuntosDeVida ;
            } else {
                this.puntosDeVida_Actuales = 0 ;

                this.estado = "derrotado" ;
            }
        } ;

        public int efectoDelEstado(){
            int danioEfecto = ( this.estado.equals("envenenado") ) ? 5 : 0 ;
            
            return( danioEfecto ) ;
        } ;

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + Sangria.sangria( 1 ) + "nombre: " + this.nombre ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "nivel: " + this.nivel ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "puntosDeVida_Maximos: " + this.puntosDeVida_Maximos ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "puntosDeVida_Actuales: " + this.puntosDeVida_Actuales ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "estado: " + this.estado ) ;

            return( texto ) ;
        }
    //
}