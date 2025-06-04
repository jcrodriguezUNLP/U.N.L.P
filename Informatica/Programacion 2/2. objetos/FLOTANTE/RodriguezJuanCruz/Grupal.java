public class Grupal extends Visita {    
    private String destino_U_Origen ;
    private String tipoDeDocumento ;
    private int numDeDocumento ;
    private int[] edades ;
    
    private int MAX_INTEGRANTES ;
    private int cantIntegrantes ;

    // Construct|es
        public Grupal() {}

        public Grupal( int numDeVisita , String fecha , boolean egreso , String destino_U_Origen , String tipoDeDocumento , int numDeDocumento ) {
            super( numDeVisita , fecha , egreso ) ;
            
            this.destino_U_Origen = destino_U_Origen ;
            this.tipoDeDocumento = tipoDeDocumento ;
            this.numDeDocumento = numDeDocumento ;
            
            MAX_INTEGRANTES = 6 ;
            cantIntegrantes = 0 ;
            
            this.edades = new int[ MAX_INTEGRANTES ] ;
        }
    //

    // Getters
        public String getDestino_U_Origen() { return( destino_U_Origen ) ; }

        public String getTipoDeDocumento() { return( tipoDeDocumento ) ; }

        public int getNumDeDocumento() { return( numDeDocumento ) ; }

        public int[] getEdades() { return( edades ) ; }
        
        
        
        public int getMAX_INTEGRANTES() { return( MAX_INTEGRANTES ) ; }

        public int getCantIntegrantes() { return( cantIntegrantes ) ; }
    //

    // Setters
        public void setDestino_U_Origen( String destino_U_Origen ) { this.destino_U_Origen = destino_U_Origen ; }

        public void setTipoDeDocumento( String tipoDeDocumento ) { this.tipoDeDocumento = tipoDeDocumento ; }

        public void setNumDeDocumento( int numDeDocumento ) { this.numDeDocumento = numDeDocumento ; }
    //

    // Métodos
        public void agregarEdad( int edad ) {
            if ( cantIntegrantes < MAX_INTEGRANTES ) {
                edades[ cantIntegrantes ] = edad ;
                cantIntegrantes++ ;
            } else {
                System.out.println( "\n" + "grupo lleno" ) ;
            }
        }
    
        public double costoVisita() {
            int i ;
            
            double costo = 0 ;
            
            boolean egreso = super.getEgreso() ;
            String fecha = super.getFecha() ;
            
            double costoMenorEdad = 2500 ;
            double costoMayorEdad = 8000 ;
            
            if ( 4 < cantIntegrantes ) {
                costoMenorEdad *= 1.075 ;
                costoMayorEdad *= 1.075 ;
            } else if ( cantIntegrantes < 4 ) {
                costoMenorEdad *= 1.05 ;
                costoMayorEdad *= 1.05 ;
            }
            
            for ( i = 0 ; i < cantIntegrantes ; i++ ) {
                if ( 17 < edades[ i ] ) {
                    costo += costoMayorEdad ;
                } else {
                     costo += costoMenorEdad ;                   
                }
            }
            
            if ( egreso ) {
                if ( destino_U_Origen.equals( "Chile"    ) |
                     destino_U_Origen.equals( "Paraguay" ) |
                     destino_U_Origen.equals( "Bolivia"  ) |
                     destino_U_Origen.equals( "Brasil"   ) |
                     destino_U_Origen.equals( "Uruguay"  )
                    ) { 
                        costo *= 0.875 ;
                }
            } else if ( destino_U_Origen.equals( "Colombia"  ) |
                        destino_U_Origen.equals( "Perú"      ) |
                        destino_U_Origen.equals( "Ecuad|"    ) |
                        destino_U_Origen.equals( "Venezuela" )
                      ) {
                          costo += ( 4000 * cantIntegrantes ) ;
            }
            
            if ( fecha.equals( "11 de Octubre de 2024"   ) |
                 fecha.equals( "18 de Noviembre de 2024" ) 
               ) {
                    costo *= 1.10 ;
            }
            
            return( costo ) ;
        }

        @Override
        public String toString() {
            int i ;
            
            String texto = "" ;

            texto += ( super.toString() ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "MAX_INTEGRANTES: " + MAX_INTEGRANTES ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "cantIntegrantes: " + cantIntegrantes ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "destino_U_Origen: " + destino_U_Origen ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "tipoDeDocumento: " + tipoDeDocumento ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "numDeDocumento: " + numDeDocumento ) ;
            
            for ( i = 0 ; i < cantIntegrantes ; i++ ) {
                texto += ( "\n" + Sangria.sangria( 1 ) + "edad: " + edades[ i ] ) ;  
            }

            return( texto ) ;
        }
    //
}