package util;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import modelo.Elemento;
import ui.Estilo;
import ui.Consola;
import ui.MenuUI;
import persistencia.GestorMemoria;
import java.util.List;

public class InteraccionUtils {

    public static Variable pedirVariable(int num, java.util.List<Clase> clasesExistentes) {
        System.out.println("\n  " + Estilo.CIAN + Estilo.ICON_EDIT + " Variable #" + num + Estilo.RESET);
        String nombre = Validador.solicitarNombreValido("    » Nombre: ");
        String tipo = TipoUtil.obtenerTipo(1, clasesExistentes);
        Variable var = new Variable(tipo, nombre);

        if (var.isEsArray()) {
            String nombreCapitalizado = Capitalize.capitalize(nombre);
            String singular = tipo.replace("[]", "");
            singular = Character.toLowerCase(singular.charAt(0)) + singular.substring(1);
            String singularCap = Capitalize.capitalize(singular);

            System.out.println("\n    " + Estilo.CIAN + "[ VECTOR DETECTADO ]" + Estilo.RESET);
            System.out.println("    - Dimensión Lógica: " + Estilo.AMARILLO + "cant" + nombreCapitalizado + Estilo.RESET);
            System.out.println("    - Dimensión Física: " + Estilo.AMARILLO + "MAX_" + nombre.toUpperCase() + Estilo.RESET);
            System.out.println("    - Métodos: " + Estilo.BLANCO + "agregar" + singularCap + ", eliminar" + singularCap + Estilo.RESET);
            
            System.out.print("\n    " + Estilo.CIAN + "» Ingrese valor MAX: " + Estilo.RESET);
            var.setTamanoMaximo(Consola.leerLinea().trim());
        }
        return var;
    }

    public static MetodoAbstracto pedirMetodo(int num, java.util.List<Clase> clasesExistentes) {
        System.out.println("\n  " + Estilo.CIAN + Estilo.ICON_EDIT + " Método Abstracto #" + num + Estilo.RESET);
        String nombre = Validador.solicitarNombreValido("    » Nombre: ");
        String tipo = TipoUtil.obtenerTipo(1, clasesExistentes);
        MetodoAbstracto met = new MetodoAbstracto(tipo, nombre);

        System.out.println();
        if (Consola.leerSino("    ¿Desea agregar parámetros?").equals("s")) {
            int pNum = 1;
            do {
                System.out.println("\n    " + Estilo.ICON_INFO + " Parámetro #" + pNum);
                String pNom = Validador.solicitarNombreValido("      » Nombre: ");
                String pTip = TipoUtil.obtenerTipo(2, clasesExistentes);
                met.getParametros().add(new Variable(pTip, pNom));
                pNum++;
                System.out.println();
            } while (Consola.leerSino("    ¿Agregar otro parámetro?").equals("s"));
        }

        return met;
    }

    public static <T extends Elemento> void gestionarListaElementos(
        String titulo, 
        List<T> lista, 
        int tipoElemento, // 1: Variable/Parametro, 2: Metodo
        List<Clase> clasesGeneradas
    ) {
        int op = -1;
        while(op != 0) {
            System.out.println(Estilo.SUBRAYADO + "\n" + titulo + ":" + Estilo.RESET);
            if (lista.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "  (Sin elementos)" + Estilo.RESET);
            } else {
                for (int i = 0; i < lista.size(); i++) {
                    System.out.print(Estilo.CIAN + (i + 1) + ". " + Estilo.RESET);
                    T elem = lista.get(i);
                    if (elem instanceof MetodoAbstracto) {
                        System.out.println(elem.getTipo() + " " + elem.getNombre() + "()");
                    } else {
                        System.out.println(elem.getTipo() + " " + elem.getNombre());
                    }
                }
            }

            System.out.println("\n" + Estilo.AMARILLO + "1." + Estilo.RESET + " Añadir");
            if (!lista.isEmpty()) {
                System.out.println(Estilo.AMARILLO + "2." + Estilo.RESET + " Eliminar");
                System.out.println(Estilo.AMARILLO + "3." + Estilo.RESET + " Modificar");
            }
            System.out.println(Estilo.ROJO + "0." + Estilo.RESET + " Volver");
            System.out.print("\n» ");

            op = Consola.leerEntero();
            if (op == 1) {
                if (tipoElemento == 1) {
                    lista.add((T) pedirVariable(lista.size() + 1, clasesGeneradas));
                } else {
                    lista.add((T) pedirMetodo(lista.size() + 1, clasesGeneradas));
                }
                GestorMemoria.guardar(clasesGeneradas);
            } else if (op == 2 && !lista.isEmpty()) {
                if (eliminarElemento(lista)) GestorMemoria.guardar(clasesGeneradas);
            } else if (op == 3 && !lista.isEmpty()) {
                if (modificarElemento(lista, clasesGeneradas)) GestorMemoria.guardar(clasesGeneradas);
            }
        }
    }

    public static <T extends Elemento> boolean eliminarElemento(List<T> lista) {
        System.out.print("Número de elemento a eliminar (0 para cancelar): ");
        int sel = Consola.leerEntero() - 1;
        if (sel >= 0 && sel < lista.size()) {
            lista.remove(sel);
            MenuUI.imprimirExito("Elemento eliminado.");
            MenuUI.esperarEnter();
            return true;
        }
        return false;
    }

    public static <T extends Elemento> boolean modificarElemento(List<T> lista, List<Clase> clasesGeneradas) {
        System.out.print("Número de elemento a modificar (0 para cancelar): ");
        int sel = Consola.leerEntero() - 1;
        if (sel >= 0 && sel < lista.size()) {
            T elem = lista.get(sel);
            String nuevoNombre = Validador.solicitarNombreValido("Nuevo nombre (Actual: " + elem.getNombre() + "): ");
            elem.setNombre(nuevoNombre);
            
            if (Consola.leerSino("¿Cambiar tipo? (Actual: " + elem.getTipo() + ")").equals("s")) {
                elem.setTipo(TipoUtil.obtenerTipo(1, clasesGeneradas));
            }

            if (elem instanceof Variable) {
                Variable var = (Variable) elem;
                if (var.isEsArray()) {
                    if (Consola.leerSino("¿Cambiar tamaño máximo? (Actual: " + var.getTamanoMaximo() + ")").equals("s")) {
                        System.out.print("Ingrese el nuevo tamaño máximo (número o constante): ");
                        var.setTamanoMaximo(Consola.leerLinea().trim());
                    }
                }
            }

            if (elem instanceof MetodoAbstracto) {
                MetodoAbstracto met = (MetodoAbstracto) elem;
                if (Consola.leerSino("¿Desea gestionar los parámetros del método?").equals("s")) {
                    gestionarListaElementos("PARÁMETROS DE: " + met.getNombre(), met.getParametros(), 1, clasesGeneradas);
                }
            }

            MenuUI.imprimirExito("Elemento actualizado.");
            MenuUI.esperarEnter();
            return true;
        }
        return false;
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
        
        System.out.println(mensaje + ":");
        
        java.util.List<Clase> raices = new java.util.ArrayList<>();
        for (Clase c : clases) {
            if (c.getClaseBase() == null || !clases.contains(c.getClaseBase())) {
                raices.add(c);
            }
        }

        int index = 1;
        java.util.Map<Integer, Clase> mapaSeleccion = new java.util.HashMap<>();
        for (Clase raiz : raices) {
            index = imprimirJerarquia(raiz, clases, 0, index, mapaSeleccion);
        }

        System.out.print("\nSeleccione un número (0 para cancelar): ");
        int sel = Consola.leerEntero();
        return mapaSeleccion.getOrDefault(sel, null);
    }

    private static int imprimirJerarquia(Clase actual, List<Clase> todas, int nivel, int index, java.util.Map<Integer, Clase> mapa) {
        StringBuilder sb = new StringBuilder();
        sb.append(Estilo.AMARILLO).append("  ").append(index).append(". ").append(Estilo.RESET);
        for (int i = 0; i < nivel; i++) sb.append("  ");
        sb.append(actual.getNombre());
        System.out.println(sb.toString());
        
        mapa.put(index, actual);
        int siguienteIndex = index + 1;

        for (Clase posibleHijo : todas) {
            if (posibleHijo.getClaseBase() == actual) {
                siguienteIndex = imprimirJerarquia(posibleHijo, todas, nivel + 1, siguienteIndex, mapa);
            }
        }
        return siguienteIndex;
    }
}
