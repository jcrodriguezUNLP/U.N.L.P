package util;

import modelo.Clase;
import ui.Estilo;
import ui.Consola;
import ui.MenuUI;

public class TipoUtil {
    
    /**
     * Muestra el menú de tipos de datos y valida la selección del usuario.
     * @param nivelSangria Nivel de indentación para el menú.
     * @return El String que representa el tipo de dato seleccionado.
     */
    public static String obtenerTipo(int nivelSangria, java.util.List<Clase> clasesExistentes) {
        int opcion = 0;
        boolean tipoValido = false;

        while (!tipoValido) {
            System.out.println("\n    " + Estilo.ICON_INFO + Estilo.CIAN + " Seleccione Tipo de Dato:" + Estilo.RESET);
            
            String[] t = {
                Estilo.AMARILLO + "      1." + Estilo.RESET + " int",
                Estilo.AMARILLO + "      2." + Estilo.RESET + " double",
                Estilo.AMARILLO + "      3." + Estilo.RESET + " boolean",
                Estilo.AMARILLO + "      4." + Estilo.RESET + " char",
                Estilo.AMARILLO + "      5." + Estilo.RESET + " String",
                Estilo.AMARILLO + "      6." + Estilo.RESET + " List<T>",
                Estilo.AMARILLO + "      7." + Estilo.RESET + " ArrayList<T>",
                Estilo.AMARILLO + "      8." + Estilo.RESET + " void",
                Estilo.AMARILLO + "      9." + Estilo.RESET + " otro"
            };

            // Imprimir en columnas
            System.out.printf("%-30s %-30s %-30s\n", t[0], t[3], t[6]);
            System.out.printf("%-30s %-30s %-30s\n", t[1], t[4], t[7]);
            System.out.printf("%-30s %-30s %-30s\n", t[2], t[5], t[8]);

            System.out.print("\n    " + Estilo.VERDE + "  » Selección (1-9): " + Estilo.RESET);
            
            opcion = Consola.leerEntero();
            if (opcion >= 1 && opcion <= 9) {
                tipoValido = true;
            } else {
                MenuUI.imprimirError("Opción no válida.");
            }
        }
        
        return mapearOpcionATipo(opcion, clasesExistentes);
    }
    
    public static String mapearOpcionATipo(int opcion, java.util.List<Clase> clasesExistentes) {
        switch (opcion) {
            case 1: return "int";
            case 2: return "double";
            case 3: return "boolean";
            case 4: return "char";
            case 5: return "String";
            case 6: return "List<" + solicitarSubtipo(clasesExistentes) + ">";
            case 7: return "ArrayList<" + solicitarSubtipo(clasesExistentes) + ">";
            case 8: return "void";
            case 9: return solicitarTipoPersonalizado(clasesExistentes);
            default: return "Object"; 
        }
    }

    private static String solicitarSubtipo(java.util.List<Clase> clases) {
        return solicitarTipoBase(clases, "Ingrese el tipo de los elementos (T): ");
    }

    private static String solicitarTipoPersonalizado(java.util.List<Clase> clases) {
        return solicitarTipoBase(clases, "Ingrese el tipo personalizado: ");
    }

    private static String solicitarTipoBase(java.util.List<Clase> clases, String prompt) {
        String tipoFinal = "";
        if (clases != null && !clases.isEmpty()) {
            System.out.println("\n    " + Estilo.SUBRAYADO + "Clases definidas:" + Estilo.RESET);
            for (int i = 0; i < clases.size(); i++) {
                System.out.println("    " + Estilo.AMARILLO + (i + 1) + "." + Estilo.RESET + " " + clases.get(i).getNombre());
            }
            System.out.println("    " + Estilo.AMARILLO + "0." + Estilo.RESET + " Escribir manualmente");
            System.out.print("\n    " + Estilo.CIAN + "» Seleccione una opción: " + Estilo.RESET);
            int sel = Consola.leerEntero();
            
            if (sel >= 1 && sel <= clases.size()) {
                tipoFinal = clases.get(sel - 1).getNombre();
            }
            System.out.println();
        }

        if (tipoFinal.isEmpty()) {
            System.out.print("    " + Estilo.CIAN + "» " + Estilo.RESET + prompt);
            tipoFinal = Capitalize.capitalize(Consola.leerLinea());
        }

        System.out.println();
        if (Consola.leerSino("    ¿Es un array (vector)?").equals("s")) {
            tipoFinal += "[]";
        }

        return tipoFinal;
    }
}
