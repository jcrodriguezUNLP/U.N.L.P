package persistencia;

import modelo.Clase;
import ui.Estilo;
import util.Config;
import servicio.GeneradorDeCodigo;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class EscritorDeArchivos {

    public static void guardarClase(Clase clase) {
        asegurarCarpeta(Config.FOLDER_GENERADAS);
        guardarEnArchivo(Config.FOLDER_GENERADAS, clase.getNombre() + ".java", GeneradorDeCodigo.generar(clase), "Archivo", false);
    }

    public static void guardarClaseSilencioso(Clase clase) {
        asegurarCarpeta(Config.FOLDER_GENERADAS);
        guardarEnArchivo(Config.FOLDER_GENERADAS, clase.getNombre() + ".java", GeneradorDeCodigo.generar(clase), "Archivo", true);
    }

    public static void guardarRevision(Clase clase) {
        asegurarCarpeta(Config.FOLDER_REVISIONES);
        guardarEnArchivo(Config.FOLDER_REVISIONES, clase.getNombre() + ".java", GeneradorDeCodigo.generar(clase), "Revisión", false);
    }

    private static void asegurarCarpeta(String nombre) {
        File carpeta = new File(nombre);
        if (!carpeta.exists()) carpeta.mkdirs();
    }

    private static void guardarEnArchivo(String carpetaRaiz, String nombreArchivo, String codigo, String tipo, boolean silencioso) {
        File archivo = new File(carpetaRaiz, nombreArchivo);
        try (FileWriter fw = new FileWriter(archivo)) {
            fw.write(codigo);
            if (!silencioso) {
                System.out.println(Estilo.CIAN + "? " + Estilo.RESET + tipo + " '" + nombreArchivo + "' guardada con éxito en /" + carpetaRaiz + ".");
            }
        } catch (IOException e) {
            System.out.println("❌ Error al guardar en " + carpetaRaiz + ": " + e.getMessage());
        }
    }

    public static boolean aplicarRevision(String nombreClase) {
        asegurarCarpeta(Config.FOLDER_GENERADAS);
        File rev = new File(Config.FOLDER_REVISIONES, nombreClase + ".java");
        File original = new File(Config.FOLDER_GENERADAS, nombreClase + ".java");

        if (rev.exists()) {
            try {
                // Copiar contenido de rev a original (más seguro que rename entre carpetas)
                java.nio.file.Files.copy(rev.toPath(), original.toPath(), java.nio.file.StandardCopyOption.REPLACE_EXISTING);
                rev.delete();
                System.out.println("✅ Revisión aplicada a '" + nombreClase + ".java'.");
                return true;
            } catch (IOException e) {
                System.out.println("❌ Error al aplicar revisión: " + e.getMessage());
            }
        }
        return false;
    }

    public static void borrarArchivo(Clase clase) {
        String nombreArchivo = clase.getNombre() + ".java";
        File archivo = new File(Config.FOLDER_GENERADAS, nombreArchivo);

        if (archivo.exists()) {
            if (archivo.delete()) {
                System.out.println(Estilo.CIAN + "? " + Estilo.RESET + "Archivo '" + nombreArchivo + "' eliminado de la carpeta '/" + Config.FOLDER_GENERADAS + "'.");
            } else {
                System.out.println(Estilo.ROJO + "! " + Estilo.RESET + "No se pudo eliminar el archivo '" + nombreArchivo + "'.");
            }
        }
    }

    public static void renombrarArchivo(String nombreViejo, String nombreNuevo) {
        File archivoViejo = new File(Config.FOLDER_GENERADAS, nombreViejo + ".java");
        File archivoNuevo = new File(Config.FOLDER_GENERADAS, nombreNuevo + ".java");

        if (archivoViejo.exists()) {
            if (archivoViejo.renameTo(archivoNuevo)) {
                System.out.println("✅ Archivo renombrado: " + nombreViejo + ".java -> " + nombreNuevo + ".java");
            } else {
                System.out.println("❌ No se pudo renombrar el archivo físico.");
            }
        }
    }
}
