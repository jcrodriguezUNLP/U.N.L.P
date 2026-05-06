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
            System.out.println("4. Gestionar Métodos Abstractos");
            System.out.println("0. Volver");
            System.out.print("\n» ");

            opcionMod = Consola.leerEntero();
            switch (opcionMod) {
                case 1: modificarNombre(claseSeleccionada); break;
                case 2: cambiarStatusAbstracto(claseSeleccionada); break;
                case 3: gestionarVariables(claseSeleccionada); break;
                case 4: gestionarMetodosAbstractos(claseSeleccionada); break;
            }
        }
    }

    private static void gestionarVariables(Clase clase) {
        int opVar = -1;
        while(opVar != 0) {
            System.out.println(Estilo.SUBRAYADO + "\nVariables de " + clase.getNombre() + ":" + Estilo.RESET);
            List<Variable> vars = clase.getVariablesPropias();
            if (vars.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "  (Sin variables)" + Estilo.RESET);
            } else {
                for (int i = 0; i < vars.size(); i++) {
                    System.out.println(Estilo.CIAN + (i + 1) + ". " + Estilo.RESET + vars.get(i).getTipo() + " " + vars.get(i).getNombre());
                }
            }

            System.out.println("\n" + Estilo.AMARILLO + "1." + Estilo.RESET + " Añadir");
            if (!vars.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "2." + Estilo.RESET + " Eliminar");
                System.out.println(Estilo.AMARILLO + "3." + Estilo.RESET + " Modificar");
            }
            System.out.println(Estilo.ROJO + "0." + Estilo.RESET + " Volver");
            System.out.print("\n» ");

            opVar = Consola.leerEntero();
            if (opVar == 1) {
                clase.getVariablesPropias().add(InteraccionUtils.pedirVariable(vars.size() + 1));
            } else if (opVar == 2 && !vars.isEmpty()) {
                eliminarElemento(clase.getVariablesPropias());
            } else if (opVar == 3 && !vars.isEmpty()) {
                modificarElemento(clase.getVariablesPropias());
            }
        }
    }

    private static void gestionarMetodosAbstractos(Clase clase) {
        if (!clase.getEsAbstracta()) {
            MenuUI.imprimirError("Esta clase no es abstracta.");
            MenuUI.esperarEnter();
            return;
        }
        int opMet = -1;
        while(opMet != 0) {
            System.out.println(Estilo.SUBRAYADO + "\nMétodos de " + clase.getNombre() + ":" + Estilo.RESET);
            List<MetodoAbstracto> mets = clase.getMetodosAbstractos();
            if (mets.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "  (Sin métodos)" + Estilo.RESET);
            } else {
                for (int i = 0; i < mets.size(); i++) {
                    System.out.println(Estilo.CIAN + (i + 1) + ". " + Estilo.RESET + mets.get(i).getTipo() + " " + mets.get(i).getNombre() + "()");
                }
            }

            System.out.println("\n" + Estilo.AMARILLO + "1." + Estilo.RESET + " Añadir");
            if (!mets.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "2." + Estilo.RESET + " Eliminar");
                System.out.println(Estilo.AMARILLO + "3." + Estilo.RESET + " Modificar");
            }
            System.out.println(Estilo.ROJO + "0." + Estilo.RESET + " Volver");
            System.out.print("\n» ");

            opMet = Consola.leerEntero();
            if (opMet == 1) {
                clase.getMetodosAbstractos().add(InteraccionUtils.pedirMetodo(mets.size() + 1));
            } else if (opMet == 2 && !mets.isEmpty()) {
                eliminarElemento(clase.getMetodosAbstractos());
            } else if (opMet == 3 && !mets.isEmpty()) {
                modificarElemento(clase.getMetodosAbstractos());
            }
        }
    }

    private static <T extends Elemento> void eliminarElemento(List<T> lista) {
        System.out.print("Número de elemento a eliminar (0 para cancelar): ");
        int sel = Consola.leerEntero() - 1;
        if (sel >= 0 && sel < lista.size()) {
            lista.remove(sel);
            MenuUI.imprimirExito("Elemento eliminado.");
            MenuUI.esperarEnter();
        }
    }

    private static <T extends Elemento> void modificarElemento(List<T> lista) {
        System.out.print("Número de elemento a modificar (0 para cancelar): ");
        int sel = Consola.leerEntero() - 1;
        if (sel >= 0 && sel < lista.size()) {
            T elem = lista.get(sel);
            String nuevoNombre = Validador.solicitarNombreValido("Nuevo nombre (Actual: " + elem.getNombre() + "): ");
            elem.setNombre(nuevoNombre);
            
            if (Consola.leerSino("¿Cambiar tipo? (Actual: " + elem.getTipo() + ")").equals("s")) {
                elem.setTipo(TipoUtil.obtenerTipo(1));
            }
            MenuUI.imprimirExito("Elemento actualizado.");
            MenuUI.esperarEnter();
        }
    }

    private static void modificarNombre(Clase clase) {
        String nuevoNombre = Validador.solicitarNombreValido("Nuevo nombre (Actual: " + clase.getNombre() + "): ");
        clase.setNombre(Capitalize.capitalize(nuevoNombre));
    }

    private static void cambiarStatusAbstracto(Clase clase) {
        clase.setEsAbstracta(Consola.leerSino("¿Hacer abstracta?").equals("s"));
    }
}
