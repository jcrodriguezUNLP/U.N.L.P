// ==============================================================================
// MAIN: Cálculo de Máximo, Mínimo y Promedio
// ==============================================================================
//   orquesta:
//     - Inicialización de arreglo de prueba y objetos Metricas.
//   flujo:
//     - Ejecución de las tres variantes de cálculo (Inciso A, B y C).
//   salida:
//     - Impresión de resultados por consola.
// ==============================================================================

public class Ejercicio5 {

    private static int[ ]  arregloGlobal ;
    private static int     maxGlobal     ;
    private static int     minGlobal     ;
    private static double  promGlobal    ;

    // metodos
        public static void main( String[ ] args ) {
            int[ ]   miArreglo  = { 10 , 5 , 20 , 15 , 8 } ;
            Metricas resultadoA                            ;
            Metricas resultadoB = new Metricas()           ;

            System.out.println( "Arreglo de prueba: [ 10, 5, 20, 15, 8 ]\n" ) ;

            // Test Inciso A: El método devuelve una instancia nueva
            System.out.println( "--- INCISO A (Retorno de Instancia) ---" ) ;
            resultadoA = calcularA( miArreglo ) ;
            System.out.println( "Max: " + resultadoA.getMaximo() + " | Min: " + resultadoA.getMinimo() + " | Prom: " + resultadoA.getPromedio() + "\n" ) ;

            // Test Inciso B: El método inyecta los datos en el wrapper que le enviamos
            System.out.println( "--- INCISO B (Mutación de Parámetro) ---" ) ;
            calcularB( miArreglo , resultadoB ) ;
            System.out.println( "Max: " + resultadoB.getMaximo() + " | Min: " + resultadoB.getMinimo() + " | Prom: " + resultadoB.getPromedio() + "\n" ) ;

            // Test Inciso C: Inyectamos el arreglo al estado global antes de llamar al método
            System.out.println( "--- INCISO C (Estado Estático) ---" ) ;
            arregloGlobal = miArreglo ; 
            calcularC() ;
            System.out.println( "Max: " + maxGlobal + " | Min: " + minGlobal + " | Prom: " + promGlobal + "\n" ) ;

            System.out.println( "Pruebas finalizadas con exito." ) ;
        }

        public static Metricas calcularA( int[ ] arreglo ) {
            Metricas res  = new Metricas() ;
            int      suma = 0              ;

            if( 0 < arreglo.length ) {
                res.setMaximo( arreglo[ 0 ] ) ;
                res.setMinimo( arreglo[ 0 ] ) ;

                for( int i = 0 ; i < arreglo.length ; i++ ) {
                    if( res.getMaximo() < arreglo[ i ] ) {
                        res.setMaximo( arreglo[ i ] ) ;
                    }
                    
                    if( arreglo[ i ] < res.getMinimo() ) {
                        res.setMinimo( arreglo[ i ] ) ;
                    }
                    
                    suma += arreglo[ i ] ;
                }
                
                res.setPromedio( (double) suma / arreglo.length ) ;
            }

            return( res ) ;
        }

        public static void calcularB( int[ ] arreglo , Metricas wrapper ) {
            int suma = 0 ;

            if( 0 < arreglo.length ) {
                wrapper.setMaximo( arreglo[ 0 ] ) ;
                wrapper.setMinimo( arreglo[ 0 ] ) ;

                for( int i = 0 ; i < arreglo.length ; i++ ) {
                    if( wrapper.getMaximo() < arreglo[ i ] ) {
                        wrapper.setMaximo( arreglo[ i ] ) ;
                    }
                    
                    if( arreglo[ i ] < wrapper.getMinimo() ) {
                        wrapper.setMinimo( arreglo[ i ] ) ;
                    }
                    
                    suma += arreglo[ i ] ;
                }
                
                wrapper.setPromedio( (double) suma / arreglo.length ) ;
            }
        }

        public static void calcularC() {
            int suma = 0 ;

            if( arregloGlobal != null ) {
                if( 0 < arregloGlobal.length ) {
                    maxGlobal = arregloGlobal[ 0 ] ;
                    minGlobal = arregloGlobal[ 0 ] ;

                    for( int i = 0 ; i < arregloGlobal.length ; i++ ) {
                        if( maxGlobal < arregloGlobal[ i ] ) {
                            maxGlobal = arregloGlobal[ i ] ;
                        }
                        
                        if( arregloGlobal[ i ] < minGlobal ) {
                            minGlobal = arregloGlobal[ i ] ;
                        }
                        
                        suma += arregloGlobal[ i ] ;
                    }
                    
                    promGlobal = (double) suma / arregloGlobal.length ;
                }
            }
        }
    //
}
