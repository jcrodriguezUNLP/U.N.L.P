import java.util.Scanner;

public class TipoUtil {
    
    /**
     * Muestra el menú de tipos de datos y valida la selección del usuario.
     * @param in El objeto Scanner para leer la entrada del usuario.
     * @param nivelSangria Nivel de indentación para el menú (usando Sangria.sangria()).
     * @return El String que representa el tipo de dato seleccionado.
     */
    public static String obtenerTipo(Scanner in, int nivelSangria) {
        int opcion = 0;
        boolean tipoValido = false;

        while (!tipoValido) {
            System.out.println( Sangria.sangria( nivelSangria ) + "Tipo:" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "1. int" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "2. double" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "3. boolean" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "4. char" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "5. String" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "6. void" ) ;
            System.out.println( Sangria.sangria( nivelSangria + 1 ) + "7. otro" ) ;
            System.out.print( Sangria.sangria( nivelSangria ) + "Ingrese el número correspondiente al tipo: " ) ;
            
            try {
                // Leer la opción
                opcion = in.nextInt() ; 
                in.nextLine() ; // Consume el salto de línea

                if (opcion >= 1 && opcion <= 7) {
                    tipoValido = true;
                } else {
                    System.out.println("Opción de tipo inválida. Ingrese un número entre 1 y 7.");
                }
            } catch (java.util.InputMismatchException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
                in.nextLine(); // Limpia el buffer del scanner
            }
        }
        
        return mapearOpcionATipo(in, opcion);
    }
    
    /**
     * Mapea la opción numérica a su String de tipo de dato correspondiente.
     * Este método es AHORA PÚBLICO para ser accesible directamente por ModificarClase.
     * @param in El objeto Scanner (necesario para la opción 7).
     * @param opcion La opción numérica seleccionada (1-7).
     * @return El String del tipo de dato.
     */
    public static String mapearOpcionATipo(Scanner in, int opcion) { // CORREGIDO: de private a public
        switch (opcion) {
            case 1:
                return "int" ;
            case 2:
                return "double" ;
            case 3:
                return "boolean" ;
            case 4:
                return "char" ;
            case 5:
                return "String" ;
            case 6:
                return "void" ;
            case 7: {
                System.out.print( "Ingrese el tipo personalizado: " ) ;
                String tipoPersonalizado = in.nextLine() ;
                // Se asume que Capitalize.java es accesible.
                return Capitalize.capitalize( tipoPersonalizado ) ; 
            }
            default:
                return "Object"; 
        }
    }
}