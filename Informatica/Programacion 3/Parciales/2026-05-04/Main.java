public class Main {
    
    public void simularCostos( GeneralTree< Trabajo > proyecto , String nombre , int multiplicador ) {
        if( proyecto == null   ) { return ; }
        if( proyecto.isEmpty() ) { return ; }

        double costo = proyecto.getData().getCosto() ;

        double dif = calcularCosto( proyecto , nombre , multiplicador ) ;

        proyecto.getData().actualizarCosto( (costo + dif) ) ;
    }

    private double calcularCosto( GeneralTree< Trabajo > nodo , String id , int n ) {
        String ID    = nodo.getData().getId()    ;
        double costo = nodo.getData().getCosto() ;

        double dif ;
        
        if( ID.equals( id ) ) {
            nodo.getData().actualizarCosto( (n * costo) ) ;

            dif = ( (n * costo) - costo ) ;

            return( dif ) ;
        }

        for( GeneralTree< Trabajo > hijo : nodo.getChildren() ) {
            dif = calcularCosto( hijo , id , n ) ;

            if( 0 < dif ) {
                if( !ID.equals( "Total" ) ) {
                    nodo.getData().actualizarCosto( (costo + dif) ) ;
                }

                return( dif ) ;
            }
        }

        return( 0 ) ;
    }

}