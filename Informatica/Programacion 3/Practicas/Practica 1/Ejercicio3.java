// ==============================================================================
// MAIN: Modelado de Estudiantes y Profesores
// ==============================================================================
//   orquesta:
//     - Creación de arreglos para Estudiantes (2) y Profesores (3).
//     - Instanciación de objetos individuales.
//   flujo:
//     - Carga de datos mediante setters.
//   salida:
//     - Impresión de datos mediante el método tusDatos().
// ==============================================================================

public class Ejercicio3 {
    
    // metodos
        public static void main( String[ ] args ) {
            Estudiante[ ] arregloEstudiantes ;
            Profesor[ ]   arregloProfesores  ;

            // Instanciación de los arreglos en memoria
            arregloEstudiantes = new Estudiante[ 2 ] ;
            arregloProfesores  = new Profesor[ 3 ]   ;

            // Instanciación de cada objeto individual (Evita el NullPointerException)
            arregloEstudiantes[ 0 ] = new Estudiante() ;
            arregloEstudiantes[ 1 ] = new Estudiante() ;

            arregloProfesores[ 0 ]  = new Profesor() ;
            arregloProfesores[ 1 ]  = new Profesor() ;
            arregloProfesores[ 2 ]  = new Profesor() ;


            // Carga Estudiante 1
            arregloEstudiantes[ 0 ].setNombre( "Ada" )               ;
            arregloEstudiantes[ 0 ].setApellido( "Lovelace" )        ;
            arregloEstudiantes[ 0 ].setComision( "1A" )              ;
            arregloEstudiantes[ 0 ].setEmail( "ada@unlp.edu.ar" )    ;
            arregloEstudiantes[ 0 ].setDireccion( "Calle Falsa 123" ) ;

            // Carga Estudiante 2
            arregloEstudiantes[ 1 ].setNombre( "Alan" )                    ;
            arregloEstudiantes[ 1 ].setApellido( "Turing" )                  ;
            arregloEstudiantes[ 1 ].setComision( "1B" )                      ;
            arregloEstudiantes[ 1 ].setEmail( "alan@unlp.edu.ar" )           ;
            arregloEstudiantes[ 1 ].setDireccion( "Avenida Siempre Viva 742" ) ;

            // Carga Profesor 1
            arregloProfesores[ 0 ].setNombre( "John" )                         ;
            arregloProfesores[ 0 ].setApellido( "von Neumann" )                ;
            arregloProfesores[ 0 ].setEmail( "john@unlp.edu.ar" )              ;
            arregloProfesores[ 0 ].setCatedra( "Arquitectura de Computadoras" ) ;
            arregloProfesores[ 0 ].setFacultad( "Informatica" )                 ;

            // Carga Profesor 2
            arregloProfesores[ 1 ].setNombre( "Grace" )        ;
            arregloProfesores[ 1 ].setApellido( "Hopper" )      ;
            arregloProfesores[ 1 ].setEmail( "grace@unlp.edu.ar" ) ;
            arregloProfesores[ 1 ].setCatedra( "Compiladores" )    ;
            arregloProfesores[ 1 ].setFacultad( "Informatica" )    ;

            // Carga Profesor 3
            arregloProfesores[ 2 ].setNombre( "Dennis" )            ;
            arregloProfesores[ 2 ].setApellido( "Ritchie" )          ;
            arregloProfesores[ 2 ].setEmail( "dennis@unlp.edu.ar" )  ;
            arregloProfesores[ 2 ].setCatedra( "Sistemas Operativos" ) ;
            arregloProfesores[ 2 ].setFacultad( "Informatica" )      ;


            System.out.println( "--- DATOS DE ESTUDIANTES ---" ) ;
            for( int i = 0 ; i < 2 ; i++ ) {
                System.out.println( arregloEstudiantes[ i ].tusDatos() ) ;
                System.out.println( "---------------------------" ) ;
            }

            System.out.println( "\n--- DATOS DE PROFESORES ---" ) ;
            for( int i = 0 ; i < 3 ; i++ ) {
                System.out.println( arregloProfesores[ i ].tusDatos() ) ;
                System.out.println( "---------------------------" ) ;
            }
        }
    //
}
