import java.util.LinkedList;
import java.util.List;

public class RedSolarEspacial {
    private GeneralTree< Nodo > red ;

    // Constructores
        public RedSolarEspacial( GeneralTree< Nodo > red ) {
            this.red = red ;
        }
    //

    // Getters
        public GeneralTree< Nodo > getred() { return( red ) ; }
    //

    // Metodos
        // public double minimoSuministroEnergia( double energiaTotal , String panelInicial )
            public double minimoSuministroEnergia( double energiaTotal , String panelInicial ) {
                GeneralTree< Nodo > redEncontrada = buscarRed( red , panelInicial ) ;

                if( (redEncontrada != null) && redEncontrada.getData().isActive() ) {
                    return( calcularEnergiaMinima(redEncontrada, energiaTotal) ) ;
                }

                return( -1 ) ;
            }

            private GeneralTree< Nodo > buscarRed( GeneralTree< Nodo > red , String idBuscado ) {
                if( red.getData().getId().equals( idBuscado ) ) { return( red ) ; }

                List< GeneralTree<Nodo> > hijos = red.getChildren() ;

                for( GeneralTree< Nodo > hijo : hijos ) {
                    GeneralTree< Nodo > redEncontrada = buscarRed( hijo , idBuscado ) ;

                    if( redEncontrada != null ) { return( redEncontrada ) ; }
                }

                return( null ) ;
            }

            private double calcularEnergiaMinima( GeneralTree< Nodo > red , double energia ) {
                if( !nodo.getData().isActive() ) { return( -1 ) ; }
                
                if( nodo.isLeaf() ) { return( energia ) ; }

                List< GeneralTree<Nodo> > hijos = red.getChildren() ;
                
                List< GeneralTree<Nodo> > hijosActivos = new LinkedList<>() ;
                    
                int cantHijosActivos = 0 ;

                for( GeneralTree< Nodo > hijo : hijos ) {
                    if( hijo.getData().isActive() ) {
                        hijosActivos.add( hijo ) ;

                        cantHijosActivos++ ;
                    }
                }

                if( cantHijosActivos == 0 ) { return( -1 ) ; }
                
                double energiaDistribuida = ( energia / cantHijosActivos ) ;

                double energiaMinima = Double.MAX_VALUE ;

                Boolean huboCamino = false ;

                for( GeneralTree< Nodo > hijo : hijosActivos ) {
                    double minimoActual = calcularMinimo( hijo , energiaDistribuida ) ;

                    if( minimoActual != -1 ){
                        huboCamino = true ;

                        if( minimoActual < energiaMinima ) {
                            energiaMinima = minimoActual ;
                        }
                    }
                }

                if( huboCamino ) { return( energiaMinima ) ; }

                return( -1 ) ;
            }
        //
    //
}
