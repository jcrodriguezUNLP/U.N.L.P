// ==============================================================================
//   [A] CLASE: AplicacionDePrueba
//    comportamiento (Métodos):
//      - main(): Punto de entrada. Orquesta la creación de un array de alumnos
//        y la visualización selectiva mediante argumentos de consola.
//    restricciones:
//      - Uso de tipos de datos primitivos y arrays estáticos (100 posiciones).
//      - Manejo de argumentos (args) para acceso por índice.
// ==============================================================================

public class AplicacionDePrueba {

    public static void main( String[] args ) {
        
        // --- 1. INICIALIZACIÓN ---
        Alumno[] arrAlumnos = new Alumno[ 100 ] ;
        int      indice     ;
        Alumno   seleccion  ;

        // --- 2. PROCESAMIENTO (Instanciación y Carga) ---
        // Alumno 0
        arrAlumnos[ 0 ] = new Alumno() ;
        arrAlumnos[ 0 ].setLegajo(   "45896/8"             ) ;
        arrAlumnos[ 0 ].setDni(      23654645              ) ;
        arrAlumnos[ 0 ].setApellido( "Gonzalez"            ) ;
        arrAlumnos[ 0 ].setNombre(   "Jacinto"             ) ;         
        arrAlumnos[ 0 ].setEmail(    "jaci_g@hotmail.com"  ) ;
        
        // Alumno 1
        arrAlumnos[ 1 ] = new Alumno() ;
        arrAlumnos[ 1 ].setLegajo(   "35516/0"             ) ;
        arrAlumnos[ 1 ].setDni(      29654879              ) ;
        arrAlumnos[ 1 ].setApellido( "Pereyra"             ) ;
        arrAlumnos[ 1 ].setNombre(   "Felipe"              ) ;
        arrAlumnos[ 1 ].setEmail(    "feli_p_p@hotmail.com") ;

        // --- 3. SALIDA (Lógica de Visualización) ---
        if ( args.length == 0 ) {
            System.out.println( "El programa se ejecuto sin parametros." ) ;
        } else {
            indice    = Integer.parseInt( args[ 0 ] ) ;
            seleccion = arrAlumnos[ indice ] ;

            if ( seleccion != null ) {
                System.out.println( "Datos del alumno en la posicion: " + indice ) ;
                System.out.println( "----------------------------------"       ) ;
                
                // Aprovechamos el método tusDatos() o toString() de la clase Alumno
                System.out.println( seleccion.tusDatos() ) ;
            } else {
                System.out.println( "No hay un alumno cargado en la posicion: " + indice ) ;
            }
        }
    }
}