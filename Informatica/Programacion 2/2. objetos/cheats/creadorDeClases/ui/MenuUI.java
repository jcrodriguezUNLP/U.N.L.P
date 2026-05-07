package ui;

import util.Config;

public class MenuUI {

    public static void mostrarBanner() {
        System.out.println(Estilo.AZUL + "╔══════════════════════════════════════════════╗");
        System.out.println("║ " + Estilo.CIAN + "            JAVA CLASS GENERATOR 3.0" + Estilo.AZUL + "         ║");
        System.out.println("╚══════════════════════════════════════════════╝" + Estilo.RESET);
    }

    public static void mostrarEstado(int cantClases) {
        System.out.println(Estilo.ICON_MEMORIA + "  " + Estilo.CIAN + "Estado de Memoria: " + Estilo.BLANCO + cantClases + " clases cargadas" + Estilo.RESET);
        System.out.println(Estilo.AZUL + "------------------------------------------------" + Estilo.RESET);
    }

    public static void mostrarMenuPrincipal(int cantClases) {
        System.out.println(Estilo.NEGRITA + "  " + Estilo.ICON_EDIT + " OPERACIONES" + Estilo.RESET);
        System.out.println(Estilo.AMARILLO + "    1." + Estilo.RESET + " Nueva Clase");
        
        if (cantClases > 0) {
            System.out.println(Estilo.AMARILLO + "    2." + Estilo.RESET + " Editar Clase");
            System.out.println(Estilo.AMARILLO + "    3." + Estilo.RESET + " Eliminar Clase");
        }
        System.out.println(Estilo.AMARILLO + "    S." + Estilo.RESET + " Sincronizar Carpeta");
        
        // Solo mostrar si hay revisiones pendientes
        java.io.File carpetaRevisiones = new java.io.File(Config.FOLDER_REVISIONES);
        java.io.File[] revisiones = carpetaRevisiones.listFiles((dir, name) -> name.endsWith(".java"));
        if (revisiones != null && revisiones.length > 0) {
            System.out.println(Estilo.AMARILLO + "    R." + Estilo.RESET + Estilo.VERDE + " Confirmar Revisiones (" + revisiones.length + " pendientes)" + Estilo.RESET);
        }
        
        System.out.println(Estilo.AMARILLO + "    4." + Estilo.RESET + " Guardar y Salir");
        System.out.print("\n" + Estilo.VERDE + "  » " + Estilo.RESET);
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
