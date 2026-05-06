import java.util.List;

public class Visualizador {

    public static void mostrarClase(List<Clase> clases) {
        Clase sel = InteraccionUtils.seleccionarClase(clases, "Seleccione la clase a mostrar");
        if (sel != null) {
            System.out.println("\n--- CÓDIGO GENERADO ---");
            System.out.println(sel.generarCodigo());
        }
    }

    public static void mostrarTodas(List<Clase> clases) {
        if (clases.isEmpty()) {
            System.out.println("No hay clases creadas.");
            return;
        }
        for (Clase c : clases) {
            System.out.println("\n================================");
            System.out.println("CLASE: " + c.getNombre());
            System.out.println("================================");
            System.out.println(c.generarCodigo());
        }
    }
}
