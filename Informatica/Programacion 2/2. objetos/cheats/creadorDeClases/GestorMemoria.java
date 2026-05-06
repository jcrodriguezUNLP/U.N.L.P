import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class GestorMemoria {
    private static final String ARCHIVO_MEMORIA = "generadas/memoria.dat";

    public static void guardar(List<Clase> clases) {
        // Asegurar que la carpeta exista
        File carpeta = new File("generadas");
        if (!carpeta.exists()) {
            carpeta.mkdir();
        }

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(ARCHIVO_MEMORIA))) {
            oos.writeObject(clases);
            System.out.println("💾 Sesión guardada automáticamente.");
        } catch (IOException e) {
            System.out.println("❌ Error al guardar la sesión: " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    public static List<Clase> cargar() {
        File archivo = new File(ARCHIVO_MEMORIA);
        if (!archivo.exists()) {
            return new ArrayList<>();
        }

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(archivo))) {
            return (List<Clase>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("⚠️ No se pudo cargar la sesión previa: " + e.getMessage());
            return new ArrayList<>();
        }
    }
}
