public class Variable extends Elemento {
    private static final long serialVersionUID = 1L;

    public Variable(String tipo, String nombre) {
        super(tipo, nombre);
    }

    @Override
    public String generarCodigo() {
        return "private " + tipo + " " + nombre + " ;";
    }
}
