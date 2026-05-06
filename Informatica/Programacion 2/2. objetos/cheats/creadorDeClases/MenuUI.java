public class MenuUI {

    public static void mostrarBanner() {
        System.out.println(Estilo.AZUL + Estilo.NEGRITA + "╔══════════════════════════════════════════╗");
        System.out.println("║         JAVA CLASS GENERATOR 3.0         ║");
        System.out.println("╚══════════════════════════════════════════╝" + Estilo.RESET);
    }

    public static void mostrarEstado(int cantClases) {
        System.out.println(Estilo.CIAN + Estilo.ICON_MEMORIA + " Clases en memoria: " + Estilo.BLANCO + cantClases + Estilo.RESET);
        System.out.println(Estilo.AZUL + "------------------------------------------" + Estilo.RESET);
    }

    public static void mostrarMenuPrincipal(int cantClases) {
        System.out.println(Estilo.NEGRITA + "Seleccione una operación:" + Estilo.RESET);
        System.out.println(Estilo.AMARILLO + "  1. " + Estilo.RESET + "Nueva Clase");
        
        if (cantClases > 0) {
            System.out.println(Estilo.AMARILLO + "  2. " + Estilo.RESET + "Previsualizar Clase");
            System.out.println(Estilo.AMARILLO + "  3. " + Estilo.RESET + "Ver Todo el Proyecto");
            System.out.println(Estilo.AMARILLO + "  4. " + Estilo.RESET + "Editar Clase");
            System.out.println(Estilo.AMARILLO + "  5. " + Estilo.RESET + "Eliminar Clase");
            System.out.println(Estilo.AMARILLO + "  6. " + Estilo.RESET + Estilo.VERDE + "Exportar a .java" + Estilo.RESET);
        }
        
        System.out.println(Estilo.ROJO + "  7. " + Estilo.RESET + "Guardar y Salir");
        System.out.print("\n" + Estilo.CIAN + "» " + Estilo.RESET);
    }

    public static void imprimirExito(String mensaje) {
        System.out.println("\n" + Estilo.VERDE + Estilo.ICON_SUCCESS + " " + mensaje + Estilo.RESET);
    }

    public static void imprimirError(String mensaje) {
        System.out.println("\n" + Estilo.ROJO + Estilo.ICON_ERROR + " " + mensaje + Estilo.RESET);
    }

    public static void imprimirInfo(String mensaje) {
        System.out.println("\n" + Estilo.CIAN + Estilo.ICON_INFO + " " + mensaje + Estilo.RESET);
    }

    public static void esperarEnter() {
        System.out.println("\n" + Estilo.AMARILLO + "Presione [ENTER] para continuar..." + Estilo.RESET);
        Consola.leerLinea();
    }
}
