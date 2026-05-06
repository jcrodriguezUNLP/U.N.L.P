public class TipoUtil {
    
    /**
     * Muestra el menú de tipos de datos y valida la selección del usuario.
     * @param nivelSangria Nivel de indentación para el menú.
     * @return El String que representa el tipo de dato seleccionado.
     */
    public static String obtenerTipo(int nivelSangria) {
        int opcion = 0;
        boolean tipoValido = false;

        while (!tipoValido) {
            String s = Sangria.sangria(nivelSangria);
            System.out.println(s + Estilo.CIAN + "Tipo de dato:" + Estilo.RESET);
            
            String[] opciones = {
                "1. int", "2. double", "3. boolean",
                "4. char", "5. String", "6. List<T>",
                "7. ArrayList<T>", "8. void", "9. otro"
            };

            for (int i = 0; i < opciones.length; i += 3) {
                System.out.printf("%s  %-18s %-18s %-18s\n", 
                                  s, opciones[i], opciones[i+1], opciones[i+2]);
            }

            System.out.print("\n" + s + Estilo.AMARILLO + "Elegir tipo (1-9): " + Estilo.RESET);
            
            opcion = Consola.leerEntero();
            if (opcion >= 1 && opcion <= 9) {
                tipoValido = true;
            } else {
                MenuUI.imprimirError("Opción no válida.");
            }
        }
        
        return mapearOpcionATipo(opcion);
    }
    
    public static String mapearOpcionATipo(int opcion) {
        switch (opcion) {
            case 1: return "int";
            case 2: return "double";
            case 3: return "boolean";
            case 4: return "char";
            case 5: return "String";
            case 6: return "List<" + solicitarSubtipo() + ">";
            case 7: return "ArrayList<" + solicitarSubtipo() + ">";
            case 8: return "void";
            case 9: {
                System.out.print("Ingrese el tipo personalizado: ");
                return Capitalize.capitalize(Consola.leerLinea()); 
            }
            default: return "Object"; 
        }
    }

    private static String solicitarSubtipo() {
        System.out.print("Ingrese el tipo de los elementos (T): ");
        return Capitalize.capitalize(Consola.leerLinea());
    }
}
