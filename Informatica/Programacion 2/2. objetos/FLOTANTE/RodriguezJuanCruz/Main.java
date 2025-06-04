public class Main {
    public static void main( String[] args ) {
        int i ;
        
        Visita[] visitas ;
        
        int cantVisitas = 2 ;
        
        Personal persona1 ;
        Grupal grupo1 ;
        
        persona1 = new Personal( 1 , "11 de Octubre de 2024" , true , false ) ;
        
        
        grupo1 = new Grupal( 2 , "18 de Noviembre de 2024" , false , "Colombia" , "DNI" , 45297935 ) ;
        
        grupo1.agregarEdad( 18 ) ;
        grupo1.agregarEdad( 19 ) ;
        grupo1.agregarEdad( 20 ) ;
        grupo1.agregarEdad( 21 ) ;
        grupo1.agregarEdad( 22 ) ;
        grupo1.agregarEdad( 5  ) ;
        grupo1.agregarEdad( 7  ) ;
        
        visitas = new Visita[ cantVisitas ] ;
        
        visitas[ 0 ] = persona1 ;
        visitas[ 1 ] = grupo1 ;
        
        for ( i = 0 ; i < cantVisitas ; i++ ) {
            System.out.println( visitas[ i ].toString() ) ;
            System.out.println( "costo: " + visitas[ i ].costoVisita() ) ;
        }
        
        double cantVisitasMas20000 = 0 ;
        
        for ( i = 0 ; i < cantVisitas ; i++ ) {
            if ( 20000 < visitas[ i ].costoVisita() ) {
                cantVisitasMas20000++ ;
            }
        }
        
        double promedioVisitasMas20000 = ( cantVisitasMas20000 / cantVisitas ) ;
        
        System.out.println( "\n" + "promedio visitas mas 20000: " + promedioVisitasMas20000 ) ;
    }
}