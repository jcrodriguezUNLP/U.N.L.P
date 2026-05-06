public class Validador {
    
    /**
     * Verifica si un string es un identificador válido en Java.
     * No debe tener espacios, ni empezar por número, ni contener caracteres especiales prohibidos.
     */
    public static boolean esIdentificadorValido(String s) {
        if (s == null || s.isEmpty()) return false;
        
        // El primer carácter debe ser una letra, _ o $
        if (!Character.isJavaIdentifierStart(s.charAt(0))) return false;
        
        // El resto de los caracteres
        for (int i = 1; i < s.length(); i++) {
            if (!Character.isJavaIdentifierPart(s.charAt(i))) return false;
        }
        
        return true;
    }

    public static String solicitarNombreValido(String mensaje) {
        String nombre;
        while (true) {
            System.out.print(mensaje);
            String input = Consola.leerLinea().trim();
            nombre = toCamelCase(input);
            
            if (esIdentificadorValido(nombre)) {
                return nombre;
            } else {
                System.out.println("❌ Error: '" + input + "' no es un nombre válido. Use letras, números, _ o $.");
            }
        }
    }

    public static String toCamelCase(String s) {
        if (s == null || s.trim().isEmpty()) return "";
        String[] parts = s.trim().split("[\\s_\\-]+"); // Separa por espacio, _ o -
        
        StringBuilder sb = new StringBuilder(parts[0].toLowerCase());
        for (int i = 1; i < parts.length; i++) {
            if (parts[i].length() > 0) {
                sb.append(Capitalize.capitalize(parts[i].toLowerCase()));
            }
        }
        return sb.toString();
    }
}
