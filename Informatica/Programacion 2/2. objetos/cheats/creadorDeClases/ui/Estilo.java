package ui;

public class Estilo {
    /** 
     * Cambiar a 'false' si usas BlueJ o una terminal que no soporta colores ANSI.
     */
    public static final boolean USAR_COLORES = false;

    // Colores ANSI (condicionales)
    public static final String RESET    = USAR_COLORES ? "\u001B[0m"  : "";
    public static final String NEGRO    = USAR_COLORES ? "\u001B[30m" : "";
    public static final String ROJO     = USAR_COLORES ? "\u001B[31m" : "";
    public static final String VERDE    = USAR_COLORES ? "\u001B[32m" : "";
    public static final String AMARILLO = USAR_COLORES ? "\u001B[33m" : "";
    public static final String AZUL     = USAR_COLORES ? "\u001B[34m" : "";
    public static final String PURPURA  = USAR_COLORES ? "\u001B[35m" : "";
    public static final String CIAN     = USAR_COLORES ? "\u001B[36m" : "";
    public static final String BLANCO   = USAR_COLORES ? "\u001B[37m" : "";

    // Estilos
    public static final String NEGRITA   = USAR_COLORES ? "\u001B[1m" : "";
    public static final String SUBRAYADO = USAR_COLORES ? "\u001B[4m" : "";

    // Iconos (pueden ser strings vacíos en terminales muy viejas, pero BlueJ suele soportar emojis)
    public static final String ICON_SUCCESS = "✅";
    public static final String ICON_ERROR   = "❌";
    public static final String ICON_INFO    = "ℹ️ ";
    public static final String ICON_MEMORIA = "🧠";
    public static final String ICON_FILE    = "📄";
    public static final String ICON_EDIT    = "✏️ ";

    public static void limpiarPantalla() {
        if (USAR_COLORES) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
        } else {
            // Salto de línea masivo como alternativa para BlueJ
            for (int i = 0; i < 50; i++) System.out.println();
        }
    }
}
