import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class ModificarClase {
    private static Scanner in = new Scanner(System.in);

    // --- UTILERIAS ---

    private static String toCamelCase(String s) {
        if (s == null || s.trim().isEmpty()) { return ""; }
        String[] parts = s.trim().toLowerCase().split("\\s+");
        String camelCaseString = parts[0];
        for (int i = 1; i < parts.length; i++) { camelCaseString += Capitalize.capitalize(parts[i]); }
        return camelCaseString;
    }

    // El método obtenerTipo se asume que está centralizado en TipoUtil.java
    // ...

    // --- MÉTODO PRINCIPAL DE MODIFICACIÓN ---

    public static void modificarClase(List<Clase> clasesGeneradas) {
        if (clasesGeneradas.isEmpty()) {
            System.out.println("\nNo hay clases creadas para modificar.");
            return;
        }
        // ... (Lógica de selección de clase) ...
        System.out.println("\nClases creadas:");
        for (int i = 0; i < clasesGeneradas.size(); i++) {
            System.out.println((i + 1) + ". " + clasesGeneradas.get(i).getNombre());
        }

        Clase claseSeleccionada = null;
        int seleccion = -1;
        
        while (claseSeleccionada == null) {
            System.out.print("Seleccione el número de la clase que desea modificar (0 para regresar): ");
            try {
                seleccion = Integer.parseInt(in.nextLine());
                if (seleccion == 0) return;

                if (seleccion > 0 && seleccion <= clasesGeneradas.size()) {
                    claseSeleccionada = clasesGeneradas.get(seleccion - 1);
                } else {
                    System.out.println("Selección inválida.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
        
        // --- Bucle de Modificación ---
        int opcionMod = -1;
        while (opcionMod != 0) {
            System.out.println("\n--- Modificando Clase: " + claseSeleccionada.getNombre() + " ---");
            System.out.println("1. Modificar Nombre");
            System.out.println("2. Cambiar Status Abstracto (Actual: " + (claseSeleccionada.getEsAbstracta() ? "Sí" : "No") + ")");
            System.out.println("3. Gestionar Variables Propias");
            System.out.println("4. Gestionar Métodos Abstractos");
            System.out.println("0. Terminar y regresar al menú principal");
            System.out.print("Opción de modificación: ");

            try {
                opcionMod = Integer.parseInt(in.nextLine());
                
                switch (opcionMod) {
                    case 1:
                        modificarNombre(claseSeleccionada);
                        break;
                    case 2:
                        cambiarStatusAbstracto(claseSeleccionada);
                        break;
                    case 3:
                        gestionarVariables(claseSeleccionada);
                        break;
                    case 4:
                        gestionarMetodosAbstractos(claseSeleccionada);
                        break;
                    case 0:
                        System.out.println("Modificación terminada para " + claseSeleccionada.getNombre());
                        break;
                    default:
                        System.out.println("Opción inválida.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
    }

    // --- LÓGICA DE GESTIÓN DE VARIABLES Y MÉTODOS ---

    private static void gestionarVariables(Clase clase) {
        int opVar = -1;
        while(opVar != 0) {
            System.out.println("\nVariables propias de " + clase.getNombre() + ":");
            List<Variable> vars = clase.getVariablesPropias();
            for (int i = 0; i < vars.size(); i++) {
                Variable v = vars.get(i);
                System.out.println((i + 1) + ". " + v.getTipo() + " " + v.getNombreOriginal() + " (Interno: " + v.getNombre() + ")");
            }

            System.out.println("\n1. Añadir nueva variable");
            if (!vars.isEmpty()) {
                System.out.println("2. Eliminar variable");
                System.out.println("3. Modificar variable existente"); 
            }
            System.out.println("0. Volver al menú de modificación");
            System.out.print("Opción: ");

            try {
                opVar = Integer.parseInt(in.nextLine());
                if (opVar == 1) {
                    añadirVariable(clase.getVariablesPropias());
                } else if (opVar == 2 && !vars.isEmpty()) {
                    eliminarVariable(clase.getVariablesPropias());
                } else if (opVar == 3 && !vars.isEmpty()) {
                    modificarVariable(clase.getVariablesPropias()); 
                } else if (opVar != 0) {
                    System.out.println("Opción inválida.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
                opVar = -1;
            }
        }
    }

    private static void añadirVariable(List<Variable> listaVariables) {
        System.out.print(Sangria.sangria(1) + "Nombre (con espacios si es necesario): ");
        String nombreInput = in.nextLine();
        String nombre = toCamelCase(nombreInput); 
        
        String tipo = TipoUtil.obtenerTipo(in, 1);
        
        listaVariables.add(new Variable(tipo, nombre, nombreInput)); 
        System.out.println("Variable " + tipo + " " + nombreInput + " añadida (Guardada como: " + nombre + ").");
    }

    private static void modificarVariable(List<Variable> listaVariables) {
        while (true) { // Bucle de validación de índice
            System.out.print("Ingrese el número de la variable a modificar (o 0 para cancelar): ");
            try {
                int indice = Integer.parseInt(in.nextLine()) - 1;
                
                if (indice == -1) return; // Cancelar
                
                if (indice >= 0 && indice < listaVariables.size()) {
                    Variable v = listaVariables.get(indice);
                    System.out.println("Modificando: " + v.getNombreOriginal());

                    // Modificar Nombre
                    System.out.print("Nuevo Nombre (deje vacío para mantener '" + v.getNombreOriginal() + "'): ");
                    String nuevoNombreInput = in.nextLine();
                    if (!nuevoNombreInput.trim().isEmpty()) {
                        v.setNombreOriginal(nuevoNombreInput);
                        v.setNombre(toCamelCase(nuevoNombreInput));
                        System.out.println("Nombre interno actualizado a: " + v.getNombre());
                    }

                    // Modificar Tipo
                    System.out.print("Nuevo Tipo (1-7 o 0 para mantener '" + v.getTipo() + "'): ");
                    int opcionTipo = -1;
                    try {
                        opcionTipo = Integer.parseInt(in.nextLine());
                    } catch (NumberFormatException e) {
                        opcionTipo = 0;
                    }
                    
                    if (opcionTipo >= 1 && opcionTipo <= 7) {
                        String nuevoTipo = TipoUtil.mapearOpcionATipo(in, opcionTipo); 
                        v.setTipo(nuevoTipo); 
                        System.out.println("Tipo actualizado a: " + nuevoTipo);
                    } else if (opcionTipo != 0) {
                        System.out.println("Opción de tipo ignorada.");
                    }
                    return; // Salir del bucle tras modificación exitosa
                } else {
                    System.out.println("Número de variable inválido o fuera de rango. Intente de nuevo.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
    }
    
    private static void eliminarVariable(List<Variable> listaVariables) {
        while (true) { // Bucle de validación de índice
            System.out.print("Ingrese el número de la variable a eliminar (o 0 para cancelar): ");
            try {
                int indice = Integer.parseInt(in.nextLine()) - 1;
                
                if (indice == -1) return; // Cancelar

                if (indice >= 0 && indice < listaVariables.size()) {
                    Variable v = listaVariables.remove(indice);
                    System.out.println("Variable " + v.getNombreOriginal() + " eliminada.");
                    return; // Salir del bucle tras eliminación exitosa
                } else {
                    System.out.println("Número de variable inválido o fuera de rango. Intente de nuevo.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
    }


    private static void gestionarMetodosAbstractos(Clase clase) {
        if (!clase.getEsAbstracta()) {
            System.out.println("Error: Solo se pueden gestionar métodos abstractos en clases que son abstractas.");
            return;
        }
        
        int opMet = -1;
        while(opMet != 0) {
            System.out.println("\nMétodos abstractos de " + clase.getNombre() + ":");
            List<MetodoAbstracto> metodos = clase.getMetodosAbstractos();
            for (int i = 0; i < metodos.size(); i++) {
                MetodoAbstracto m = metodos.get(i);
                System.out.println((i + 1) + ". " + m.getTipo() + " " + m.getNombreOriginal() + "() (Interno: " + m.getNombre() + ")");
            }

            System.out.println("\n1. Añadir nuevo método abstracto");
            if (!metodos.isEmpty()) {
                System.out.println("2. Eliminar método abstracto");
                System.out.println("3. Modificar método abstracto existente"); 
            }
            System.out.println("0. Volver al menú de modificación");
            System.out.print("Opción: ");

            try {
                opMet = Integer.parseInt(in.nextLine());
                if (opMet == 1) {
                    añadirMetodoAbstracto(clase.getMetodosAbstractos());
                } else if (opMet == 2 && !metodos.isEmpty()) {
                    eliminarMetodoAbstracto(clase.getMetodosAbstractos());
                } else if (opMet == 3 && !metodos.isEmpty()) {
                    modificarMetodoAbstracto(clase.getMetodosAbstractos()); 
                } else if (opMet != 0) {
                    System.out.println("Opción inválida.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
                opMet = -1;
            }
        }
    }

    private static void añadirMetodoAbstracto(List<MetodoAbstracto> listaMetodos) {
        System.out.print(Sangria.sangria(1) + "Nombre (con espacios si es necesario): ");
        String nombreInput = in.nextLine();
        String nombre = toCamelCase(nombreInput); 

        String tipo = TipoUtil.obtenerTipo(in, 1);
        
        listaMetodos.add(new MetodoAbstracto(tipo, nombre, nombreInput)); 
        System.out.println("Método abstracto " + tipo + " " + nombreInput + "() añadido (Guardado como: " + nombre + ").");
    }

    private static void modificarMetodoAbstracto(List<MetodoAbstracto> listaMetodos) {
        while (true) { // Bucle de validación de índice
            System.out.print("Ingrese el número del método abstracto a modificar (o 0 para cancelar): ");
            try {
                int indice = Integer.parseInt(in.nextLine()) - 1;
                
                if (indice == -1) return; // Cancelar

                if (indice >= 0 && indice < listaMetodos.size()) {
                    MetodoAbstracto m = listaMetodos.get(indice);
                    System.out.println("Modificando: " + m.getNombreOriginal());

                    // Modificar Nombre
                    System.out.print("Nuevo Nombre (deje vacío para mantener '" + m.getNombreOriginal() + "'): ");
                    String nuevoNombreInput = in.nextLine();
                    if (!nuevoNombreInput.trim().isEmpty()) {
                        m.setNombreOriginal(nuevoNombreInput); 
                        m.setNombre(toCamelCase(nuevoNombreInput)); 
                        System.out.println("Nombre interno actualizado a: " + m.getNombre());
                    }

                    // Modificar Tipo
                    System.out.print("Nuevo Tipo (1-7 o 0 para mantener '" + m.getTipo() + "'): ");
                    int opcionTipo = -1;
                    try {
                        opcionTipo = Integer.parseInt(in.nextLine());
                    } catch (NumberFormatException e) {
                        opcionTipo = 0; 
                    }
                    
                    if (opcionTipo >= 1 && opcionTipo <= 7) {
                        String nuevoTipo = TipoUtil.mapearOpcionATipo(in, opcionTipo); 
                        m.setTipo(nuevoTipo); 
                        System.out.println("Tipo actualizado a: " + nuevoTipo);
                    } else if (opcionTipo != 0) {
                        System.out.println("Opción de tipo ignorada.");
                    }
                    return; // Salir del bucle tras modificación exitosa
                } else {
                    System.out.println("Número de método inválido o fuera de rango. Intente de nuevo.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
    }
    
    private static void eliminarMetodoAbstracto(List<MetodoAbstracto> listaMetodos) {
        while (true) { // Bucle de validación de índice
            System.out.print("Ingrese el número del método abstracto a eliminar (o 0 para cancelar): ");
            try {
                int indice = Integer.parseInt(in.nextLine()) - 1;
                
                if (indice == -1) return; // Cancelar

                if (indice >= 0 && indice < listaMetodos.size()) {
                    MetodoAbstracto m = listaMetodos.remove(indice);
                    System.out.println("Método abstracto " + m.getNombreOriginal() + " eliminado.");
                    return; // Salir del bucle tras eliminación exitosa
                } else {
                    System.out.println("Número de método inválido o fuera de rango. Intente de nuevo.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Debe ingresar un número.");
            }
        }
    }
    
    // ... (El resto de los métodos se mantienen sin cambios) ...
    private static void modificarNombre(Clase clase) {
        System.out.print("Ingrese el nuevo nombre de la clase (Actual: " + clase.getNombre() + "): ");
        String nuevoNombre = in.nextLine();
        clase.setNombre(Capitalize.capitalize(nuevoNombre)); 
        System.out.println("Nombre actualizado a: " + clase.getNombre());
    }
    
    private static void cambiarStatusAbstracto(Clase clase) {
        String abstractaRespuesta;
        do {
            System.out.print("¿Desea que la clase sea abstracta? (s/n): ");
            abstractaRespuesta = in.nextLine().trim().toLowerCase();
        } while (!abstractaRespuesta.equals("s") && !abstractaRespuesta.equals("n"));
        
        boolean esAbstracta = abstractaRespuesta.equals("s");
        clase.setEsAbstracta(esAbstracta);
        
        System.out.println("Status abstracto actualizado a: " + (esAbstracta ? "Sí" : "No"));
        
        if (!esAbstracta && !clase.getMetodosAbstractos().isEmpty()) {
            System.out.println("Advertencia: Se recomienda implementar o eliminar los métodos abstractos propios si la clase ya no es abstracta.");
        }
    }
}