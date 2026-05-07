import modelo.Clase;
import ui.Estilo;
import ui.MenuUI;
import ui.Consola;
import ui.Visualizador;
import util.InteraccionUtils;
import util.TipoUtil;
import util.Selector;
import util.Config;
import persistencia.GestorMemoria;
import persistencia.EscritorDeArchivos;
import persistencia.LectorDeArchivos;
import servicio.CrearClase;
import servicio.ModificarClase;
import java.io.File;
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
        // Asegurar carpetas base
        new File(Config.FOLDER_GENERADAS).mkdir();
        new File(Config.FOLDER_REVISIONES).mkdir();

        Estilo.limpiarPantalla();
        // Sincronización automática al inicio
        System.out.println(Estilo.ICON_INFO + Estilo.CIAN + " Sincronizando con carpeta '" + Config.FOLDER_GENERADAS + "'..." + Estilo.RESET);
        sincronizarCarpeta(true); 

        String entrada = "";
        do {
            MenuUI.mostrarBanner();
            MenuUI.mostrarEstado(clasesGeneradas.size());
            MenuUI.mostrarMenuPrincipal(clasesGeneradas.size());
            
            entrada = Consola.leerLinea().trim().toUpperCase();
            int cantClases = clasesGeneradas.size();

            if (entrada.equals("S")) {
                System.out.println("\n" + Estilo.ICON_INFO + Estilo.CIAN + " Iniciando sincronización manual..." + Estilo.RESET);
                sincronizarCarpeta(false);
                MenuUI.esperarEnter();
                Estilo.limpiarPantalla();
                continue;
            }

            if (entrada.equals("R")) {
                System.out.println("\n" + Estilo.ICON_INFO + Estilo.CIAN + " Gestionando revisiones externas..." + Estilo.RESET);
                gestionarRevisiones();
                MenuUI.esperarEnter();
                Estilo.limpiarPantalla();
                continue;
            }

            int opcion;
            try {
                opcion = Integer.parseInt(entrada);
            } catch (NumberFormatException e) {
                MenuUI.imprimirError("Opción no válida.");
                MenuUI.esperarEnter();
                Estilo.limpiarPantalla();
                continue;
            }

            if (cantClases == 0) {
                // Menú corto
                switch(opcion) {
                    case 1: CrearClase.crearClase(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 4: break; // Salir
                    default: MenuUI.imprimirError("Opción no válida."); MenuUI.esperarEnter(); break;
                }
                if (opcion == 4) break;
            } else {
                // Menú completo
                switch(opcion) {
                    case 1: CrearClase.crearClase(clasesGeneradas); MenuUI.esperarEnter(); break;
                    case 2: ModificarClase.modificarClase(clasesGeneradas); break;
                    case 3: borrarClase(); MenuUI.esperarEnter(); break;
                    case 4: break; // Salir
                    default: MenuUI.imprimirError("Opción no válida."); MenuUI.esperarEnter(); break;
                }
                if (opcion == 4) break;
            }
            Estilo.limpiarPantalla();
        } while(!entrada.equals("4"));

        GestorMemoria.guardar(clasesGeneradas);
        MenuUI.imprimirInfo("Saliendo del programa...");
    }

    private void borrarClase() {
        Clase sel = InteraccionUtils.seleccionarClase(clasesGeneradas, "Seleccione la clase a borrar");
        if (sel != null) {
            clasesGeneradas.remove(sel);
            EscritorDeArchivos.borrarArchivo(sel);
            GestorMemoria.guardar(clasesGeneradas);
            MenuUI.imprimirExito("Clase eliminada de memoria.");
        }
    }

    private void gestionarRevisiones() {
        File carpeta = new File(Config.FOLDER_REVISIONES);
        if (!carpeta.exists() || !carpeta.isDirectory()) return;

        File[] revisiones = carpeta.listFiles((dir, name) -> name.endsWith(".java"));

        if (revisiones == null || revisiones.length == 0) {
            MenuUI.imprimirInfo("No hay revisiones pendientes.");
            return;
        }

        System.out.println(Estilo.CIAN + "\n=== REVISIONES PENDIENTES (en carpeta /" + Config.FOLDER_REVISIONES + ") ===" + Estilo.RESET);
        for (File f : revisiones) {
            String nombreClase = f.getName().replace(".java", "");
            
            // Intento de lectura para mostrar resumen
            Clase temp = LectorDeArchivos.importarDesdeArchivo(f, clasesGeneradas);
            if (temp != null) {
                // Si la clase ya existe en memoria, mostramos comparación
                Clase existente = null;
                for (Clase c : clasesGeneradas) {
                    if (c.getNombre().equalsIgnoreCase(nombreClase)) {
                        existente = c;
                        break;
                    }
                }

                if (existente != null) {
                    Visualizador.mostrarComparacion(existente, temp);
                } else {
                    Visualizador.mostrarResumen(temp);
                }
            } else {
                System.out.println("📄 " + nombreClase + " (No se pudo previsualizar)");
            }
            
            if (Consola.leerSino("¿Aplicar cambios para '" + nombreClase + "'?").equals("s")) {
                if (EscritorDeArchivos.aplicarRevision(nombreClase)) {
                    // Refrescar memoria leyendo el archivo recién aplicado en 'generadas'
                    File archivoActualizado = new File(Config.FOLDER_GENERADAS, nombreClase + ".java");
                    Clase claseActualizada = LectorDeArchivos.importarDesdeArchivo(archivoActualizado, clasesGeneradas);
                    
                    if (claseActualizada != null) {
                        // Reemplazar la vieja instancia por la nueva
                        boolean encontrada = false;
                        for (int i = 0; i < clasesGeneradas.size(); i++) {
                            if (clasesGeneradas.get(i).getNombre().equalsIgnoreCase(nombreClase)) {
                                clasesGeneradas.set(i, claseActualizada);
                                encontrada = true;
                                break;
                            }
                        }
                        if (!encontrada) clasesGeneradas.add(claseActualizada);

                        reincularHerederos(false); // Propagar cambios
                        GestorMemoria.guardar(clasesGeneradas);
                        System.out.println("🔄 Memoria y herencias actualizadas.");
                    }
                }
            } else {
                if (Consola.leerSino("¿Desea descartar (borrar) la revisión?").equals("s")) {
                    f.delete();
                    System.out.println("🗑 Revisión descartada.");
                }
            }
        }
    }

    private void sincronizarCarpeta(boolean silencioso) {
        File carpeta = new File(Config.FOLDER_GENERADAS);
        if (!carpeta.exists() || !carpeta.isDirectory()) {
            if (!silencioso) MenuUI.imprimirError("La carpeta '" + Config.FOLDER_GENERADAS + "' no existe.");
            return;
        }

        File[] archivos = carpeta.listFiles((dir, name) -> name.endsWith(".java"));
        List<String> nombresArchivos = new ArrayList<>();
        if (archivos != null) {
            for (File f : archivos) nombresArchivos.add(f.getName().replace(".java", "").toLowerCase());
        }

        int cambios = 0;

        // 1. Detectar Eliminaciones (Clase en memoria pero NO en carpeta)
        List<Clase> aEliminar = new ArrayList<>();
        for (Clase c : clasesGeneradas) {
            if (!nombresArchivos.contains(c.getNombre().toLowerCase())) {
                if (silencioso) {
                    aEliminar.add(c);
                    cambios++;
                } else {
                    System.out.println(); // Espacio antes de la advertencia
                    System.out.println(Estilo.ROJO + "⚠ Clase '" + c.getNombre() + "' no tiene archivo .java." + Estilo.RESET);
                    System.out.println("¿Qué desea hacer?");
                    System.out.println(Estilo.AMARILLO + "  B." + Estilo.RESET + " Borrar de memoria");
                    System.out.println(Estilo.AMARILLO + "  R." + Estilo.RESET + " Reescribir archivo");
                    System.out.println(Estilo.AMARILLO + "  I." + Estilo.RESET + " Ignorar");
                    System.out.print("\n» Elija una opción (b/r/i): ");
                    
                    String rta = Consola.leerLinea().trim().toLowerCase();
                    if (rta.equals("b")) {
                        aEliminar.add(c);
                        cambios++;
                    } else if (rta.equals("r")) {
                        EscritorDeArchivos.guardarClase(c);
                        System.out.println("✅ Archivo re-generado.");
                        cambios++;
                    }
                }
            }
        }
        clasesGeneradas.removeAll(aEliminar);

        // 2. Detectar Adiciones (Archivo en carpeta pero NO en memoria)
        if (archivos != null) {
            for (File f : archivos) {
                String nombreClase = f.getName().replace(".java", "");
                boolean yaExiste = false;
                for (Clase c : clasesGeneradas) {
                    if (c.getNombre().equalsIgnoreCase(nombreClase)) {
                        yaExiste = true;
                        break;
                    }
                }

                if (!yaExiste) {
                    Clase nueva = LectorDeArchivos.importarDesdeArchivo(f, clasesGeneradas);
                    if (nueva != null) {
                        if (silencioso) {
                            clasesGeneradas.add(nueva);
                            cambios++;
                        } else {
                            System.out.println();
                            Visualizador.mostrarResumen(nueva);
                            if (Consola.leerSino("¿Importar clase nueva '" + nombreClase + "'?").equals("s")) {
                                clasesGeneradas.add(nueva);
                                cambios++;
                            }
                        }
                    }
                }
            }
        }

        if (cambios > 0) {
            reincularHerederos(silencioso);
            GestorMemoria.guardar(clasesGeneradas);
            if (!silencioso) {
                MenuUI.imprimirExito("Sincronización completada: " + cambios + " cambios realizados.");
            }
        } else if (!silencioso) {
            MenuUI.imprimirInfo("La memoria ya está sincronizada con la carpeta.");
        }
    }

    private void reincularHerederos(boolean silencioso) {
        // RE-EXPORTAR TODO para que los hijos hereden los cambios del padre
        for (Clase c : clasesGeneradas) {
            if (silencioso) {
                EscritorDeArchivos.guardarClaseSilencioso(c);
            } else {
                EscritorDeArchivos.guardarClase(c);
            }
        }
    }

    // El método exportarAArchivo() ya no es necesario llamarlo desde el menú
    // pero lo dejamos como utilidad privada o lo eliminamos. 
}
