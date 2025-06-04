package tp1.ejercicio10;

import java.util.PriorityQueue;

class Cliente implements Comparable<Cliente> {
    private String nombre;
    private int edad;
    private boolean embarazada;
    private boolean movilidadReducida;

    public Cliente(String nombre, int edad, boolean embarazada, boolean movilidadReducida) {
        this.nombre = nombre;
        this.edad = edad;
        this.embarazada = embarazada;
        this.movilidadReducida = movilidadReducida;
    }

    public String getNombre() {
        return nombre;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "nombre='" + nombre + '\'' +
                ", edad=" + edad +
                ", embarazada=" + embarazada +
                ", movilidadReducida=" + movilidadReducida +
                '}';
    }

    // Comparador para determinar la prioridad
    @Override
    public int compareTo(Cliente otro) {
        // Mayor prioridad para embarazadas, movilidad reducida o mayores de 70 años
        if (this.embarazada || this.movilidadReducida || this.edad >= 70) {
            if (!otro.embarazada && !otro.movilidadReducida && otro.edad < 70) {
                return -1; // Este cliente tiene mayor prioridad
            }
        } else if (!this.embarazada && !this.movilidadReducida && this.edad < 70) {
            if (otro.embarazada || otro.movilidadReducida || otro.edad >= 70) {
                return 1; // Otro cliente tiene mayor prioridad
            }
        }
        return 0; // Igual prioridad
    }
}

public class Banco {
    public static void main(String[] args) {
        PriorityQueue<Cliente> colaBanco = new PriorityQueue<>();

        // Agregar clientes a la cola
        colaBanco.add(new Cliente("Juan", 30, false, false));
        colaBanco.add(new Cliente("Ana", 75, false, false));
        colaBanco.add(new Cliente("María", 28, true, false));
        colaBanco.add(new Cliente("Luis", 40, false, true));
        colaBanco.add(new Cliente("Pedro", 65, false, false));

        // Atender clientes según prioridad
        System.out.println("Atendiendo clientes:");
        while (!colaBanco.isEmpty()) {
            System.out.println(colaBanco.poll());
        }
    }
}