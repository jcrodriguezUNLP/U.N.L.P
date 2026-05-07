package modelo;

public class Variable extends Elemento {
    private static final long serialVersionUID = 1L;
    private boolean esArray;
    private String tamanoMaximo; // Puede ser un número o el nombre de otra variable

    public Variable(String tipo, String nombre) {
        super(tipo, nombre);
        this.esArray = tipo.contains("[]");
        this.tamanoMaximo = "";
    }

    @Override
    public void setTipo(String tipo) {
        super.setTipo(tipo);
        this.esArray = tipo.contains("[]");
    }

    public boolean isEsArray() { return esArray; }

    public String getTamanoMaximo() { return tamanoMaximo; }
    public void setTamanoMaximo(String tamanoMaximo) { this.tamanoMaximo = tamanoMaximo; }

    @Override
    public String generarCodigo() {
        return "private " + tipo + " " + nombre + " ;";
    }
}
