package servicio;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import modelo.Elemento;
import ui.Estilo;
import ui.Consola;
import ui.MenuUI;
import util.Validador;
import util.Capitalize;
import util.InteraccionUtils;
import util.TipoUtil;
import persistencia.GestorMemoria;
import persistencia.EscritorDeArchivos;
import java.util.List;

public class ModificarClase {

    public static void modificarClase(List<Clase> clasesGeneradas) {
        Clase claseSeleccionada = InteraccionUtils.seleccionarClase(clasesGeneradas, "EDITAR CLASE");
        if (claseSeleccionada == null) return;
        
        int opcionMod = -1;
        while (opcionMod != 0) {
            System.out.println("\n--- CONFIGURACIÓN: " + claseSeleccionada.getNombre() + " ---");
            System.out.println("1. Modificar Nombre");
            System.out.println("2. Cambiar Status Abstracto (Actual: " + (claseSeleccionada.getEsAbstracta() ? "Sí" : "No") + ")");
            System.out.println("3. Gestionar Variables Propias");
            
            // Solo mostrar si es abstracta
            if (claseSeleccionada.getEsAbstracta()) {
                System.out.println("4. Gestionar Métodos Abstractos");
            }
            
            System.out.println("5. Gestionar Herencia (Padre: " + (claseSeleccionada.getClaseBase() != null ? claseSeleccionada.getClaseBase().getNombre() : "Ninguno") + ")");
            System.out.println("0. Volver");
            System.out.print("\n» ");

            opcionMod = Consola.leerEntero();
            
            // Validar que no elija 4 si no es abstracta
            if (opcionMod == 4 && !claseSeleccionada.getEsAbstracta()) {
                MenuUI.imprimirError("Opción no válida para clase no abstracta.");
                continue;
            }

            switch (opcionMod) {
                case 1: modificarNombre(claseSeleccionada); GestorMemoria.guardar(clasesGeneradas); break;
                case 2: cambiarStatusAbstracto(claseSeleccionada); GestorMemoria.guardar(clasesGeneradas); break;
                case 3: InteraccionUtils.gestionarListaElementos("Variables de " + claseSeleccionada.getNombre(), claseSeleccionada.getVariablesPropias(), 1, clasesGeneradas); break;
                case 4: InteraccionUtils.gestionarListaElementos("Métodos de " + claseSeleccionada.getNombre(), claseSeleccionada.getMetodosAbstractos(), 2, clasesGeneradas); break;
                case 5: gestionarHerencia(claseSeleccionada, clasesGeneradas); break;
            }
            if (opcionMod >= 1 && opcionMod <= 5) {
                // Actualizar en cascada: Re-exportar todas las clases para mantener consistencia
                for (Clase c : clasesGeneradas) {
                    EscritorDeArchivos.guardarClaseSilencioso(c);
                }
                MenuUI.imprimirExito("Cambios aplicados y propagados en cascada.");
            }
        }
    }

    private static void gestionarHerencia(Clase clase, List<Clase> clasesGeneradas) {
        System.out.println("\n--- GESTIONAR HERENCIA: " + clase.getNombre() + " ---");
        System.out.println("1. " + (clase.getClaseBase() == null ? "Asignar Padre" : "Cambiar Padre"));
        if (clase.getClaseBase() != null) {
            System.out.println("2. Eliminar Herencia (Volver a clase independiente)");
        }
        System.out.println("0. Cancelar");
        System.out.print("\n» ");

        int op = Consola.leerEntero();
        if (op == 1) {
            // Filtrar la propia clase y cualquier clase que ya herede de esta (para evitar ciclos)
            List<Clase> posiblesPadres = new java.util.ArrayList<>();
            for (Clase c : clasesGeneradas) {
                if (c != clase && !esDescendiente(clase, c)) {
                    posiblesPadres.add(c);
                }
            }
            
            if (posiblesPadres.isEmpty()) {
                MenuUI.imprimirError("No hay otras clases disponibles para heredar (o causarían un ciclo).");
                MenuUI.esperarEnter();
                return;
            }

            Clase nuevoPadre = InteraccionUtils.seleccionarClase(posiblesPadres, "Seleccione el nuevo Padre");
            if (nuevoPadre != null) {
                clase.setClaseBase(nuevoPadre);
                MenuUI.imprimirExito("Herencia actualizada.");
                GestorMemoria.guardar(clasesGeneradas);
            }
        } else if (op == 2 && clase.getClaseBase() != null) {
            clase.setClaseBase(null);
            MenuUI.imprimirExito("Herencia eliminada. Ahora '" + clase.getNombre() + "' es una clase base.");
            GestorMemoria.guardar(clasesGeneradas);
        }
    }

    private static void modificarNombre(Clase clase) {
        String nombreViejo = clase.getNombre();
        String nuevoNombre = Validador.solicitarNombreValido("Nuevo nombre (Actual: " + nombreViejo + "): ");
        String nombreCapitalizado = Capitalize.capitalize(nuevoNombre);
        
        if (!nombreViejo.equals(nombreCapitalizado)) {
            clase.setNombre(nombreCapitalizado);
            EscritorDeArchivos.renombrarArchivo(nombreViejo, nombreCapitalizado);
        }
    }

    private static void cambiarStatusAbstracto(Clase clase) {
        clase.setEsAbstracta(Consola.leerSino("¿Hacer abstracta?").equals("s"));
    }

    private static boolean esDescendiente(Clase actual, Clase potencialPadre) {
        // Si el potencialPadre tiene como ancestro a 'actual', entonces es un descendiente
        Clase ancestro = potencialPadre.getClaseBase();
        while (ancestro != null) {
            if (ancestro == actual) return true;
            ancestro = ancestro.getClaseBase();
        }
        return false;
    }
}
