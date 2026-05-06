import java.util.List;

public class InteraccionUtils {

    public static Variable pedirVariable(int num) {
        System.out.println(Estilo.CIAN + "\nVariable #" + num + Estilo.RESET);
        String nombre = Validador.solicitarNombreValido(Sangria.sangria(1) + "Nombre: ");
        String tipo = TipoUtil.obtenerTipo(1);
        return new Variable(tipo, nombre);
    }

    public static MetodoAbstracto pedirMetodo(int num) {
        System.out.println(Estilo.CIAN + "\nMétodo #" + num + Estilo.RESET);
        String nombre = Validador.solicitarNombreValido(Sangria.sangria(1) + "Nombre: ");
        String tipo = TipoUtil.obtenerTipo(1);
        return new MetodoAbstracto(tipo, nombre);
    }

    public static void listarClases(List<Clase> clases) {
        if (clases.isEmpty()) {
            System.out.println("No hay clases disponibles.");
            return;
        }
        for (int i = 0; i < clases.size(); i++) {
            System.out.println((i + 1) + ". " + clases.get(i).getNombre());
        }
    }

    public static Clase seleccionarClase(List<Clase> clases, String mensaje) {
        if (clases.isEmpty()) return null;
        
        System.out.println(Estilo.SUBRAYADO + "\n" + mensaje + ":" + Estilo.RESET);
        for (int i = 0; i < clases.size(); i++) {
            System.out.println(Estilo.AMARILLO + "  " + (i + 1) + ". " + Estilo.RESET + clases.get(i).getNombre());
        }
        System.out.print("\nSeleccione un número (0 para cancelar): ");
        
        int sel = Consola.leerEntero() - 1;
        if (sel >= 0 && sel < clases.size()) {
            return clases.get(sel);
        }
        return null;
    }
}
