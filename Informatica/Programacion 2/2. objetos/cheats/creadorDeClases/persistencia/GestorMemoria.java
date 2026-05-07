package persistencia;

import modelo.Clase;
import ui.Estilo;
import ui.MenuUI;
import util.Config;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class GestorMemoria {

    public static void guardar(List<Clase> clases) {
        File carpeta = new File(Config.FOLDER_GENERADAS);
        if (!carpeta.exists()) carpeta.mkdir();

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(Config.PATH_MEMORIA))) {
            oos.writeObject(clases);
        } catch (IOException e) {
            System.out.println("❌ Error al guardar la sesión: " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    public static List<Clase> cargar() {
        File archivo = new File(Config.PATH_MEMORIA);
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
