package tp1.ejercicio11;

import java.util.LinkedList;

public class LineaColectivo {
    private String nombreLinea;
    private LinkedList<String> paradas;

    // Constructor
    public LineaColectivo(String nombreLinea) {
        this.nombreLinea = nombreLinea;
        this.paradas = new LinkedList<>();
    }

    // Agregar una parada al final del recorrido
    public void agregarParada(String parada) {
        paradas.addLast(parada);
    }

    // Insertar una parada en una posición específica
    public void insertarParada(int posicion, String parada) {
        if (posicion < 0 || posicion > paradas.size()) {
            throw new IndexOutOfBoundsException("Posición inválida");
        }
        paradas.add(posicion, parada);
    }

    // Eliminar una parada por nombre
    public void eliminarParada(String parada) {
        paradas.remove(parada);
    }

    // Obtener todas las paradas
    public LinkedList<String> obtenerParadas() {
        return paradas;
    }

    // Imprimir el recorrido completo
    @Override
    public String toString() {
        return "Línea " + nombreLinea + ": " + paradas.toString();
    }

    public static void main(String[] args) {
        // Crear una línea de colectivos
        LineaColectivo linea = new LineaColectivo("Linea 214");

        // Agregar paradas
        linea.agregarParada("Plaza Italia");
        linea.agregarParada("Calle 7 y 50");
        linea.agregarParada("Estación de trenes");
        linea.agregarParada("Hospital San Martín");

        // Imprimir recorrido
        System.out.println(linea);

        // Insertar una parada intermedia
        linea.insertarParada(2, "Calle 12 y 54");
        System.out.println("Después de insertar una parada: " + linea);

        // Eliminar una parada
        linea.eliminarParada("Estación de trenes");
        System.out.println("Después de eliminar una parada: " + linea);
    }
}