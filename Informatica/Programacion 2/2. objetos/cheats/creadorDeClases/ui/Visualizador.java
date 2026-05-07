package ui;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import modelo.Elemento;
import util.InteraccionUtils;
import util.Capitalize;
import servicio.GeneradorDeCodigo;
import java.util.List;

public class Visualizador {

    public static void mostrarClase(List<Clase> clases) {
        Clase sel = InteraccionUtils.seleccionarClase(clases, "Seleccione la clase a mostrar");
        if (sel != null) {
            System.out.println("\n--- CÓDIGO GENERADO ---");
            System.out.println(GeneradorDeCodigo.generar(sel));
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
            System.out.println(GeneradorDeCodigo.generar(c));
        }
    }

    public static void mostrarResumen(Clase c) {
        System.out.println(Estilo.AZUL + "\n--- RESUMEN DE ESTRUCTURA: " + c.getNombre() + " ---" + Estilo.RESET);
        System.out.println("🔹 Tipo: " + (c.getEsAbstracta() ? Estilo.AMARILLO + "ABSTRACTA" : Estilo.VERDE + "NORMAL") + Estilo.RESET);
        System.out.println("🔹 Hereda de: " + (c.getClaseBase() != null ? c.getClaseBase().getNombre() : "Ninguna"));
        
        System.out.println("🔹 Variables:");
        if (c.getVariablesPropias().isEmpty()) {
            System.out.println("   (Ninguna)");
        } else {
            for (Variable v : c.getVariablesPropias()) {
                System.out.println("   - " + v.getTipo() + " " + v.getNombre());
            }
        }

        if (c.getEsAbstracta()) {
            System.out.println("🔹 Métodos Abstractos:");
            if (c.getMetodosAbstractos().isEmpty()) {
                System.out.println("   (Ninguna)");
            } else {
                for (MetodoAbstracto m : c.getMetodosAbstractos()) {
                    System.out.println("   - " + m.generarCodigo().replace("public ", ""));
                }
            }
        }
        System.out.println(Estilo.AZUL + "----------------------------------------" + Estilo.RESET);
    }

    public static void mostrarComparacion(Clase actual, Clase propuesta) {
        System.out.println(Estilo.AMARILLO + "\n--- COMPARACIÓN DE CAMBIOS: " + actual.getNombre() + " ---" + Estilo.RESET);
        
        // 1. Comparar Abstracto
        if (actual.getEsAbstracta() != propuesta.getEsAbstracta()) {
            System.out.println("🔸 Tipo: " + (actual.getEsAbstracta() ? "Abstracta" : "Normal") + 
                               Estilo.CIAN + " -> " + Estilo.RESET + 
                               (propuesta.getEsAbstracta() ? "Abstracta" : "Normal"));
        }

        // 2. Comparar Herencia
        String padreActual = actual.getClaseBase() != null ? actual.getClaseBase().getNombre() : "Ninguna";
        String padrePropuesto = propuesta.getClaseBase() != null ? propuesta.getClaseBase().getNombre() : "Ninguna";
        if (!padreActual.equals(padrePropuesto)) {
            System.out.println("🔸 Hereda de: " + padreActual + Estilo.CIAN + " -> " + Estilo.RESET + padrePropuesto);
        }

        // 3. Comparar Variables (Pasando faltantes para proponer restauración)
        compararElementos("Variables", actual.getVariablesEfectivas(), propuesta.getVariablesEfectivas(), propuesta.getVariablesFaltantes());

        // 4. Comparar Métodos Abstractos
        compararElementos("Métodos Abstractos", actual.getMetodosAbstractos(), propuesta.getMetodosAbstractos(), null);

        System.out.println(Estilo.AMARILLO + "----------------------------------------" + Estilo.RESET);
    }

    private static <T extends Elemento> void compararElementos(String etiqueta, List<T> actuales, List<T> propuestos, List<Variable> faltantes) {
        boolean hayCambios = false;
        StringBuilder sb = new StringBuilder("🔸 " + etiqueta + ":\n");
        java.util.Set<String> procesados = new java.util.HashSet<>();

        // 1. Detectar borrados
        for (T a : actuales) {
            if (procesados.contains(a.getNombre())) continue;

            boolean sigueEstando = false;
            for (T p : propuestos) {
                if (a.getNombre().equals(p.getNombre())) {
                    sigueEstando = true;
                    break;
                }
            }

            if (!sigueEstando) {
                String desc = (a instanceof MetodoAbstracto) ? ((MetodoAbstracto)a).generarCodigo().replace("public ", "") : a.getTipo() + " " + a.getNombre();
                sb.append(Estilo.ROJO + "   [ELIMINADO] " + desc + Estilo.RESET + "\n");
                procesados.add(a.getNombre());
                hayCambios = true;

                // Si es un vector, buscar sus auxiliares y marcarlas como borradas jerárquicamente
                if (a instanceof Variable && ((Variable)a).isEsArray()) {
                    String n = a.getNombre();
                    String c = "cant" + Capitalize.capitalize(n);
                    String m = "MAX_" + n.toUpperCase();

                    for (T sub : actuales) {
                        if (sub.getNombre().equals(c) || sub.getNombre().equals(m)) {
                            sb.append(Estilo.ROJO + "      ↳ [AUX] " + sub.getTipo() + " " + sub.getNombre() + Estilo.RESET + "\n");
                            procesados.add(sub.getNombre());
                        }
                    }
                }
            }
        }

        // 2. Detectar añadidos o cambios
        for (T p : propuestos) {
            if (procesados.contains(p.getNombre())) continue;

            T original = null;
            for (T a : actuales) {
                if (a.getNombre().equals(p.getNombre())) {
                    original = a;
                    break;
                }
            }

            String descP = (p instanceof MetodoAbstracto) ? ((MetodoAbstracto)p).generarCodigo().replace("public ", "") : p.getTipo() + " " + p.getNombre();

            if (original == null) {
                sb.append(Estilo.VERDE + "   [NUEVO] " + descP + Estilo.RESET + "\n");
                procesados.add(p.getNombre());
                hayCambios = true;

                // Si el nuevo es un vector, agrupar sus auxiliares bajo él
                if (p instanceof Variable && ((Variable)p).isEsArray()) {
                    String n = p.getNombre();
                    String c = "cant" + Capitalize.capitalize(n);
                    String m = "MAX_" + n.toUpperCase();

                    for (T sub : propuestos) {
                        if (sub.getNombre().equals(c) || sub.getNombre().equals(m)) {
                            sb.append(Estilo.VERDE + "      ↳ [AUX] " + sub.getTipo() + " " + sub.getNombre() + Estilo.RESET + "\n");
                            procesados.add(sub.getNombre());
                        }
                    }
                }
            } else {
                String descA = (original instanceof MetodoAbstracto) ? ((MetodoAbstracto)original).generarCodigo().replace("public ", "") : original.getTipo() + " " + original.getNombre();
                
                if (!descA.equals(descP)) {
                    sb.append(Estilo.CIAN + "   [CAMBIO] " + descA + " -> " + descP + Estilo.RESET + "\n");
                    hayCambios = true;
                }

                // SI el vector existe pero le faltan auxiliares, mostrarlas como restauración
                if (p instanceof Variable && ((Variable)p).isEsArray() && faltantes != null) {
                    String n = p.getNombre();
                    String c = "cant" + Capitalize.capitalize(n);
                    String m = "MAX_" + n.toUpperCase();

                    for (Variable f : faltantes) {
                        if (f.getNombre().equals(c) || f.getNombre().equals(m)) {
                            sb.append(Estilo.AMARILLO + "      ↳ [RESTAURAR] " + f.getTipo() + " " + f.getNombre() + Estilo.RESET + "\n");
                            hayCambios = true;
                        }
                    }
                }
            }
        }

        if (hayCambios) System.out.print(sb.toString());
    }
}