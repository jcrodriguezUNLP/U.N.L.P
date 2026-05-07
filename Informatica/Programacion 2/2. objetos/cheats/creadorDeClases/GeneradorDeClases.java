import java.util.ArrayList;
import java.util.List;

public class GeneradorDeClases {
    private List<Clase> clasesGeneradas;

    public GeneradorDeClases() {
        this.clasesGeneradas = GestorMemoria.cargar();
    }

    public static void main(String[] args) {
        new GeneradorDeClases().iniciar();
    }

    public void iniciar() {
        int opcion = 0;
        do {
            Estilo.limpiarPantalla();
            MenuUI.mostrarBanner();
            MenuUI.mostrarEstado(clasesGeneradas.size());
            MenuUI.mostrarMenuPrincipal(clasesGeneradas.size());
            
            opcion = Consola.leerEntero();
            int cantClases = clasesGeneradas.size();

            if (cantClases == 0) {
                // Menú corto (solo 1 y 6)
                switch(opcion) {
                    case 1: CrearClase.crearClase(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 6: break; // Salir
                    default: MenuUI.imprimirError("Opción no válida."); MenuUI.esperarEnter(); break;
                }
                if (opcion == 6) break;
            } else {
                // Menú completo
                switch(opcion) {
                    case 1: CrearClase.crearClase(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 2: Visualizador.mostrarClase(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 3: Visualizador.mostrarTodas(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 4: ModificarClase.modificarClase(clasesGeneradas); break;
                    case 5: borrarClase(); MenuUI.esperarEnter(); break;
                    case 6: break; // Salir
                    default: MenuUI.imprimirError("Opción no válida."); MenuUI.esperarEnter(); break;
                }
                if (opcion == 6) break;
            }
        } while(opcion != 6);

        GestorMemoria.guardar(clasesGeneradas);
        MenuUI.imprimirInfo("Saliendo del programa...");
    }

    private void borrarClase() {
        Clase sel = InteraccionUtils.seleccionarClase(clasesGeneradas, "Seleccione la clase a borrar");
        if (sel != null) {
            clasesGeneradas.remove(sel);
            EscritorDeArchivos.borrarArchivo(sel);
            GestorMemoria.guardar(clasesGeneradas);
            System.out.println("✅ Clase eliminada de memoria.");
        }
    }

    // El método exportarAArchivo() ya no es necesario llamarlo desde el menú
    // pero lo dejamos como utilidad privada o lo eliminamos. 
}
