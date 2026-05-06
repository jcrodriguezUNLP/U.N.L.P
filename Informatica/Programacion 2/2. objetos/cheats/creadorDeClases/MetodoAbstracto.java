public class MetodoAbstracto extends Elemento {
    private static final long serialVersionUID = 1L;

    public MetodoAbstracto(String tipo, String nombre) {
        super(tipo, nombre);
    }

    @Override
    public String generarCodigo() {
        return "public " + tipo + " " + nombre + "()";
    }
}
