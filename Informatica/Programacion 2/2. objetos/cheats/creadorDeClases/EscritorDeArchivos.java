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
}
