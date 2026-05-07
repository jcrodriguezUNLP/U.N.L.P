package ui;

public class Estilo {
    // Colores ANSI
    public static final String RESET = "\u001B[0m";
    public static final String NEGRO = "\u001B[30m";
    public static final String ROJO = "\u001B[31m";
    public static final String VERDE = "\u001B[32m";
    public static final String AMARILLO = "\u001B[33m";
    public static final String AZUL = "\u001B[34m";
    public static final String PURPURA = "\u001B[35m";
    public static final String CIAN = "\u001B[36m";
    public static final String BLANCO = "\u001B[37m";

    // Estilos
    public static final String NEGRITA = "\u001B[1m";
    public static final String SUBRAYADO = "\u001B[4m";

    // Iconos
    public static final String ICON_SUCCESS = "✅";
    public static final String ICON_ERROR = "❌";
    public static final String ICON_INFO = "ℹ️ ";
    public static final String ICON_MEMORIA = "🧠";
    public static final String ICON_FILE = "📄";
    public static final String ICON_EDIT = "✏️ ";

    public static void limpiarPantalla() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
