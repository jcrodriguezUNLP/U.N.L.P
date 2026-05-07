import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class EscritorDeArchivos {

    public static void guardarClase(Clase clase) {
        String codigo = clase.generarCodigo();
        String nombreArchivo = clase.getNombre() + ".java";
        
        // Crear carpeta 'generadas' si no existe
        File carpeta = new File("generadas");
        if (!carpeta.exists()) {
            carpeta.mkdir();
        }

        File archivo = new File(carpeta, nombreArchivo);
        
        try (FileWriter fw = new FileWriter(archivo)) {
            fw.write(codigo);
            System.out.println("\n✅ Archivo '" + nombreArchivo + "' guardado con éxito en la carpeta '/generadas'.");
        } catch (IOException e) {
            System.out.println("\n❌ Error al guardar el archivo: " + e.getMessage());
        }
    }

    public static void borrarArchivo(Clase clase) {
        String nombreArchivo = clase.getNombre() + ".java";
        File archivo = new File("generadas", nombreArchivo);

        if (archivo.exists()) {
            if (archivo.delete()) {
                System.out.println("✅ Archivo '" + nombreArchivo + "' eliminado de la carpeta '/generadas'.");
            } else {
                System.out.println("❌ No se pudo eliminar el archivo '" + nombreArchivo + "'.");
            }
        }
    }

    public static void renombrarArchivo(String nombreViejo, String nombreNuevo) {
        File archivoViejo = new File("generadas", nombreViejo + ".java");
        File archivoNuevo = new File("generadas", nombreNuevo + ".java");

        if (archivoViejo.exists()) {
            if (archivoViejo.renameTo(archivoNuevo)) {
                System.out.println("✅ Archivo renombrado: " + nombreViejo + ".java -> " + nombreNuevo + ".java");
            } else {
                System.out.println("❌ No se pudo renombrar el archivo físico.");
            }
        }
    }
}
