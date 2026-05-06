import java.io.Serializable;

public abstract class Elemento implements Serializable {
    private static final long serialVersionUID = 1L;
    protected String nombre;
    protected String tipo;

    public Elemento(String tipo, String nombre) {
        this.tipo = tipo;
        this.nombre = nombre;
    }

    public String getNombre() { return nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }
    
    public String getTipo() { return tipo; }
    public void setTipo(String tipo) { this.tipo = tipo; }

    public abstract String generarCodigo();
}
