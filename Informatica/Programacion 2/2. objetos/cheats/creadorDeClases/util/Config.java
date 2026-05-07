package util;

public class Config {
    /** Carpeta donde se guardan los archivos .java generados */
    public static final String FOLDER_GENERADAS = "generadas";
    
    /** Subcarpeta para revisiones externas detectadas */
    public static final String FOLDER_REVISIONES = FOLDER_GENERADAS + "/revisiones";
    
    /** Ruta al archivo de persistencia binaria */
    public static final String PATH_MEMORIA = FOLDER_GENERADAS + "/memoria.dat";
}
