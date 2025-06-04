import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class TestArrayList {

    public static void main(String[] args) {
        // Punto 7a
        ArrayList<Integer> numbers = new ArrayList<>();
        for (String arg : args) {
            numbers.add(Integer.parseInt(arg));
        }
        System.out.println("Contenido de la lista:");
        for (Integer number : numbers) {
            System.out.println(number);
        }

        // Punto 7b
        /*
            Diferencia entre ArrayList y LinkedList
            Si se usara un LinkedList en lugar de un ArrayList, la implementación sería casi idéntica, ya que ambas clases implementan la interfaz List. Sin embargo, las diferencias principales son:

            Rendimiento:

            ArrayList es más eficiente para acceder a elementos por índice, ya que tiene un tiempo constante O(1).
            LinkedList es más eficiente para inserciones y eliminaciones en posiciones intermedias o al inicio, pero el acceso por índice es más lento (O(n)).
            Uso de memoria:

            ArrayList usa menos memoria porque almacena los elementos en un arreglo contiguo.
            LinkedList usa más memoria debido a las referencias adicionales (nodo anterior y siguiente).
         */

        // Punto 7c
        for (int i = 0; i < numbers.size(); i++) {
            System.out.println(numbers.get(i));
        }

        numbers.forEach(System.out::println);

        // Punto 7d
        ArrayList<Estudiante> listaOriginal = new ArrayList<>();
        listaOriginal.add(new Estudiante("Juan", "Perez", 1, "juan@mail.com", "Calle Falsa 123"));
        listaOriginal.add(new Estudiante("Ana", "Gomez", 2, "ana@mail.com", "Calle Real 456"));
        listaOriginal.add(new Estudiante("Luis", "Lopez", 3, "luis@mail.com", "Calle Verdadera 789"));

        ArrayList<Estudiante> listaCopia = new ArrayList<>(listaOriginal);

        System.out.println("Lista original: " + listaOriginal);
        System.out.println("Lista copia: " + listaCopia);

        listaOriginal.get(0).setNombre("Carlos");

        System.out.println("Lista original modificada: " + listaOriginal);
        System.out.println("Lista copia después de la modificación: " + listaCopia);

        // Punto 7e
        Estudiante nuevoEstudiante = new Estudiante("Pedro", "Martinez", 4, "pedro@mail.com", "Calle Nueva 101");
        agregarEstudiante(listaOriginal, nuevoEstudiante);
        System.out.println("Lista después de agregar un nuevo estudiante: " + listaOriginal);

        // Punto 7f
        ArrayList<Integer> listaCapicua = new ArrayList<>();
        listaCapicua.add(2);
        listaCapicua.add(5);
        listaCapicua.add(2);
        System.out.println("¿Es capicúa? " + esCapicua(listaCapicua));

        // Punto 7g
        System.out.println("Sucesión para n=6: " + calcularSucesion(6));

        // Punto 7h
        ArrayList<Integer> listaInvertir = new ArrayList<>();
        listaInvertir.add(1);
        listaInvertir.add(2);
        listaInvertir.add(3);
        invertirArrayList(listaInvertir);
        System.out.println("Lista invertida: " + listaInvertir);

        // Punto 7i
        LinkedList<Integer> listaSumar = new LinkedList<>();
        listaSumar.add(1);
        listaSumar.add(2);
        listaSumar.add(3);
        System.out.println("Suma de elementos en LinkedList: " + sumarLinkedList(listaSumar));

        // Punto 7j
        ArrayList<Integer> lista1 = new ArrayList<>();
        lista1.add(1);
        lista1.add(3);
        lista1.add(5);

        ArrayList<Integer> lista2 = new ArrayList<>();
        lista2.add(2);
        lista2.add(4);
        lista2.add(6);

        System.out.println("Lista combinada ordenada: " + combinarOrdenado(lista1, lista2));
    }

    // Punto 7e
    public static void agregarEstudiante(ArrayList<Estudiante> lista, Estudiante nuevo) {
        if (!lista.contains(nuevo)) {
            lista.add(nuevo);
        }
    }

    // Punto 7f
    public static boolean esCapicua(ArrayList<Integer> lista) {
        int n = lista.size();
        for (int i = 0; i < n / 2; i++) {
            if (!lista.get(i).equals(lista.get(n - i - 1))) {
                return false;
            }
        }
        return true;
    }

    // Punto 7g
    public static List<Integer> calcularSucesion(int n) {
        List<Integer> sucesion = new ArrayList<>();
        calcularSucesionRecursiva(n, sucesion);
        return sucesion;
    }

    private static void calcularSucesionRecursiva(int n, List<Integer> sucesion) {
        sucesion.add(n);
        if (n == 1) return;
        if (n % 2 == 0) {
            calcularSucesionRecursiva(n / 2, sucesion);
        } else {
            calcularSucesionRecursiva(3 * n + 1, sucesion);
        }
    }

    // Punto 7h
    public static void invertirArrayList(ArrayList<Integer> lista) {
        invertirRecursivo(lista, 0, lista.size() - 1);
    }

    private static void invertirRecursivo(ArrayList<Integer> lista, int inicio, int fin) {
        if (inicio >= fin) return;
        int temp = lista.get(inicio);
        lista.set(inicio, lista.get(fin));
        lista.set(fin, temp);
        invertirRecursivo(lista, inicio + 1, fin - 1);
    }

    // Punto 7i
    public static int sumarLinkedList(LinkedList<Integer> lista) {
        return sumarRecursivo(lista, 0);
    }

    private static int sumarRecursivo(LinkedList<Integer> lista, int index) {
        if (index == lista.size()) return 0;
        return lista.get(index) + sumarRecursivo(lista, index + 1);
    }

    // Punto 7j
    public static ArrayList<Integer> combinarOrdenado(ArrayList<Integer> lista1, ArrayList<Integer> lista2) {
        ArrayList<Integer> resultado = new ArrayList<>();
        int i = 0, j = 0;

        while (i < lista1.size() && j < lista2.size()) {
            if (lista1.get(i) <= lista2.get(j)) {
                resultado.add(lista1.get(i++));
            } else {
                resultado.add(lista2.get(j++));
            }
        }

        while (i < lista1.size()) {
            resultado.add(lista1.get(i++));
        }

        while (j < lista2.size()) {
            resultado.add(lista2.get(j++));
        }

        return resultado;
    }
}