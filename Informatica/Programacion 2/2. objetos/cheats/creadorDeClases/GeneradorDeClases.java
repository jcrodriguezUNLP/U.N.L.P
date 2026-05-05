import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GeneradorDeClases {
    private static List<Clase> clasesGeneradas = new ArrayList<>() ;
    private static Scanner in = new Scanner( System.in ) ;

    public static void main( String[] args ) {
        int opcion = 0 ;
        do {
            System.out.println( "\n1. Crear clase"            ) ;
            System.out.println( "2. Mostrar clase individual" ) ;
            System.out.println( "3. Mostrar todas las clases" ) ;
            System.out.println( "4. Modificar clase"          ) ;
            System.out.println( "5. Salir"                    ) ;
            System.out.print  ("Opción: "                     ) ;
            
            try {
                opcion = in.nextInt() ;
                in.nextLine() ;
                
                switch( opcion ) {
                    case 1:
                        CrearClase.crearClase( clasesGeneradas ) ;
                        break ;
                    case 2:
                        MostrarClase.mostrarClase( clasesGeneradas ) ;
                        break ;
                    case 3:
                        MostrarClases.mostrarClases( clasesGeneradas ) ;
                        break ;
                    case 4:
                        ModificarClase.modificarClase( clasesGeneradas ) ; // LLAMADA A LA NUEVA CLASE
                        break ;
                    case 5:
                        System.out.println("Saliendo...") ;
                        break ;
                    default:
                        System.out.println("Opción no válida") ;
                }
            } catch (java.util.InputMismatchException e) {
                System.out.println("Error: Ingrese un número válido.");
                in.nextLine(); // Limpia el buffer del scanner
                opcion = 0; // Asegura que el bucle continúe
            }
        } while( opcion != 5 ) ;
    }
}