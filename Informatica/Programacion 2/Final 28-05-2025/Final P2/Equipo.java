public class Equipo {
    private Personaje[] aventureros ;

    private int cantAventureros ;
    
    private int MAX_AVENTUREROS ;

    // Constructores
        public Equipo() {
            cantAventureros = 0 ;

            MAX_AVENTUREROS = 5 ;

            // lpmqlrp
            aventureros = new Personaje[ MAX_AVENTUREROS ] ;
        }
    //

    // Getters
        public Personaje[] getAventureros() { return( aventureros ) ; }

        public int getCantAventureros() { return( cantAventureros ) ; }

        public int getMAX_AVENTUREROS() { return( MAX_AVENTUREROS ) ; }
    //

    // Setters
        public void setAventureros( Personaje[] aventureros ) { this.aventureros = aventureros ; }

        public void setCantAventureros( int cantAventureros ) { this.cantAventureros = cantAventureros ; }

        public void setMAX_AVENTUREROS( int MAX_AVENTUREROS ) { this.MAX_AVENTUREROS = MAX_AVENTUREROS ; }
    //

    // Métodos
        public void agregarAventurero( Personaje aventurero ){
            if( this.cantAventureros < this.MAX_AVENTUREROS ){
                this.aventureros[ this.cantAventureros ] = aventurero ;

                this.cantAventureros++ ;
            } else {
                System.out.println( "No se pueden agregar más aventureros" ) ;
            }
        }

        public void quitarAventurero( int numAventurero ){
            if( numAventurero <= this.cantAventureros ){
                int posAventurero = ( numAventurero - 1 ) ;

                for( int i = posAventurero ; i < (this.MAX_AVENTUREROS - 1) ; i++ ){
                    this.aventureros[ i ] = this.aventureros[ i+1 ] ;
                }

                this.aventureros[ this.MAX_AVENTUREROS - 1 ] = null ;
                //lrpmqtrp
                this.cantAventureros-- ;
            } else {
                System.out.println( "no se encuentra el aventurero" );
            }
        }
        
        public Personaje obtenerAventurero( int numAventurero ){
            if( numAventurero <= this.cantAventureros ){
                Personaje aventurero = this.aventureros[ numAventurero - 1 ] ;
                
                quitarAventurero( numAventurero ) ;
                
                return( aventurero ) ;
            } else {
                System.out.println( "no se encuentra el aventurero" );
                return( null ) ;
            }
            
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + Sangria.sangria( 1 ) + "aventureros: " + this.aventureros ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "cantAventureros: " + this.cantAventureros ) ;   
            texto += ( "\n" + Sangria.sangria( 1 ) + "MAX_AVENTUREROS: " + this.MAX_AVENTUREROS ) ; 

            return( texto ) ;
        }
    //
}