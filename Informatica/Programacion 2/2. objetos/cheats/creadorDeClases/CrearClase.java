import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CrearClase {
    // constructor
    public CrearClase() {}
    //
    
    private static Scanner in = new Scanner( System.in ) ;

    private static String toCamelCase(String s) {
        // ... (Tu función toCamelCase, sin cambios) ...
        if (s == null || s.trim().isEmpty()) {
            return "";
        }
        String[] parts = s.trim().toLowerCase().split("\\s+");
        
        if (parts.length == 0) {
            return ""; 
        }
        
        String camelCaseString = parts[0];
        for (int i = 1; i < parts.length; i++) {
            camelCaseString += Capitalize.capitalize(parts[i]); 
        }
        return camelCaseString;
    }
    
    public static void crearClase( List<Clase> clasesGeneradas ) {

        // ... (Lógica de inicio, Main, esAbstracta, hereda) ...
        System.out.print( "\n" + "Ingrese el nombre de la clase: " ) ;
        String nombreClase = in.nextLine() ;
        nombreClase = Capitalize.capitalize( nombreClase ) ;

        if ( nombreClase.equals( "Main" ) ) {
            System.out.println( "\nClase generada:\n" ) ;

            System.out.println( "public class Main {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "public static void main( String[] args ) {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "}" ) ;
            System.out.println( "}" ) ;
        } else {
            // --- VALIDACIÓN: ¿Es abstracta? ---
            String abstractaRespuesta;
            do {
                System.out.print( "\n" + "¿Es una clase abstracta? ( s/n ): ") ;
                abstractaRespuesta = in.nextLine().trim().toLowerCase();
            } while (!abstractaRespuesta.equals("s") && !abstractaRespuesta.equals("n"));
            
            boolean esAbstracta = abstractaRespuesta.equals("s");
            
            // --- VALIDACIÓN: ¿Hereda? ---
            String heredaRespuesta;
            do {
                System.out.print( "\n" + "¿Hereda de alguna clase existente? ( s/n ): " ) ;
                heredaRespuesta = in.nextLine().trim().toLowerCase();
            } while (!heredaRespuesta.equals("s") && !heredaRespuesta.equals("n"));
            
            Clase claseBase = null;
            
            if ( heredaRespuesta.equals("s") ) {
                System.out.println( "Clases disponibles para heredar:" ) ;

                if ( clasesGeneradas.isEmpty() ) {
                    System.out.println( "No hay clases disponibles" ) ;
                    claseBase = null ;
                } else {
                    boolean seleccionValida = false;
                    while (!seleccionValida) {
                        for ( int i = 0; i < clasesGeneradas.size() ; i++) {
                            System.out.println( (i + 1) + ". " + clasesGeneradas.get( i ).getNombre()) ;
                        }
                        System.out.print( "Ingrese el número correspondiente a la clase de la que desea heredar: " ) ;
                        
                        try {
                            int seleccion = Integer.parseInt( in.nextLine() ) - 1 ;
                            if (seleccion >= 0 && seleccion < clasesGeneradas.size()) {
                                claseBase = clasesGeneradas.get( seleccion ) ;
                                seleccionValida = true;
                            } else {
                                System.out.println("Opción fuera de rango. Intente de nuevo.");
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("Entrada inválida. Debe ingresar un número.");
                        }
                    }
                }
            }

            List<Variable> variablesPropias = new ArrayList<>() ;

            // --- VALIDACIÓN: ¿Desea agregar una variable? (Primer pregunta) ---
            String respuesta;
            do {
                System.out.print( "\n¿Desea agregar una variable? (s/n): " ) ;
                respuesta = in.nextLine().trim().toLowerCase() ;
            } while (!respuesta.equals("s") && !respuesta.equals("n"));

            boolean agregarVariable = respuesta.equals("s");

            while (agregarVariable) {
                System.out.println( "\n" + "Nueva variable:" ) ;

                // Solicitar el nombre de la variable
                System.out.print( Sangria.sangria( 1 ) + "Nombre: " ) ;
                String nombreInput = in.nextLine() ;
                String nombre = toCamelCase(nombreInput); 

                // *** CAMBIO: Usar TipoUtil ***
                // La función se encarga de mostrar el menú y validar la entrada
                String tipo = TipoUtil.obtenerTipo(in, 1); 

                // Crear la instancia de Variable y agregarla a la lista
                variablesPropias.add( new Variable( tipo , nombre, nombreInput ) ) ; 

                // --- VALIDACIÓN: ¿Desea agregar otra variable? ---
                String otraRespuesta;
                do {
                    System.out.print( "\n¿Desea agregar otra variable? (s/n): " ) ;
                    otraRespuesta = in.nextLine().trim().toLowerCase() ;
                } while (!otraRespuesta.equals("s") && !otraRespuesta.equals("n"));

                if (!otraRespuesta.equals( "s" )) {
                    agregarVariable = false ; 
                }
            }


            List<MetodoAbstracto> metodosAbstractos = new ArrayList<>() ;

            // metodos abstractos
            if ( esAbstracta ) {
                // --- VALIDACIÓN: ¿Desea agregar métodos abstractos? ---
                String metodosAbstractosRespuesta;
                do {
                    System.out.print( "\n" + "¿Desea agregar métodos abstractos? ( s/n ): " ) ;
                    metodosAbstractosRespuesta = in.nextLine().trim().toLowerCase();
                } while (!metodosAbstractosRespuesta.equals("s") && !metodosAbstractosRespuesta.equals("n"));

                boolean agregarMetodos = metodosAbstractosRespuesta.equals("s");

                int cantMetodos = 0 ;
                while ( agregarMetodos ) {
                    System.out.println( "\n" + "Método abstracto N°" + (cantMetodos + 1) + ":" ) ;

                    System.out.print( Sangria.sangria( 1 ) + "Nombre: " ) ;
                    String nombreInput = in.nextLine() ;
                    String nombre = toCamelCase(nombreInput); 

                    // *** CAMBIO: Usar TipoUtil ***
                    String tipo = TipoUtil.obtenerTipo(in, 1); 

                    metodosAbstractos.add( new MetodoAbstracto( tipo , nombre, nombreInput ) ) ; 

                    // --- VALIDACIÓN: ¿Desea agregar otro método abstracto? ---
                    String otroMetodoRespuesta;
                    do {
                        System.out.print( "\n" + "¿Desea agregar otro método abstracto? ( s/n ): " ) ;
                        otroMetodoRespuesta = in.nextLine().trim().toLowerCase();
                    } while (!otroMetodoRespuesta.equals("s") && !otroMetodoRespuesta.equals("n"));
                    
                    agregarMetodos = otroMetodoRespuesta.equals("s");
                    cantMetodos++ ;
                }
            }

            Clase nuevaClase = new Clase(nombreClase, esAbstracta, claseBase, variablesPropias , metodosAbstractos ) ;
            clasesGeneradas.add( nuevaClase ) ;

            System.out.println( "\nClase generada:\n" ) ;
            System.out.println( nuevaClase.generarCodigo() ) ;
        }
    }
    
    // NOTA: La antigua función obtenerTipo y su lógica se ELIMINARON de aquí.
}