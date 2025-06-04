import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            // Mostrar menú
            System.out.println("\n\nMenu");
            System.out.println("1. Ejercicio 1");
            System.out.println("2. Ejercicio 2");
            System.out.println("3. Ejercicio 3");
            System.out.println("4. Ejercicio 4");
            System.out.println("5. Ejercicio 5");
            System.out.println("6. Ejercicio 6");
            System.out.println("7. Ejercicio 7");
            System.out.println("8. Ejercicio 8");
            System.out.println("9. Ejercicio 9");
            System.out.println("10. Ejercicio 10");
            System.out.println("11. Ejercicio 11");
            System.out.println("12. Salir");
            System.out.print("Ingrese una opcion: ");

            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    // Ejercicio 1
                    System.out.print("\nLos numeros entre 1 y 10 con for son:");
                    EntreNumeros.imprimirEntreNumerosConFor(1, 10);

                    System.out.print("\nLos numeros entre 1 y 10 con while son:");
                    EntreNumeros.imprimirEntreNumerosConWhile(1, 10);

                    System.out.print("\nLos numeros entre 1 y 10 con recursion son:");
                    EntreNumeros.imprimirEntreNumerosConRecursion(1, 10);
                    break;

                case 2:
                    // Ejercicio 2
                    System.out.print("\n\nIngrese la cantidad de multiplos que desea generar: ");
                    int n = scanner.nextInt();
                    int[] multiplos = Multiples.generateMultiples(n);

                    System.out.print("\nLos primeros " + n + " multiplos de " + n + " son:");
                    for (int i = 0; i < multiplos.length; i++) {
                        System.out.print(" " + multiplos[i]);
                    }
                    break;

                case 3:
                    // Ejercicio 3
                    Estudiante[] estudiantes = new Estudiante[2];
                    estudiantes[0] = new Estudiante();
                    estudiantes[1] = new Estudiante();

                    Profesor[] profesores = new Profesor[3];
                    profesores[0] = new Profesor();
                    profesores[1] = new Profesor();
                    profesores[2] = new Profesor();

                    // Asignar valores a los estudiantes
                    estudiantes[0].setNombre("Juan");
                    estudiantes[0].setApellido("Perez");
                    estudiantes[0].setComision(1);
                    estudiantes[0].setEmail("email");
                    estudiantes[0].setDireccion("direccion");

                    estudiantes[1].setNombre("Ana");
                    estudiantes[1].setApellido("Gomez");
                    estudiantes[1].setComision(2);
                    estudiantes[1].setEmail("email");
                    estudiantes[1].setDireccion("direccion");

                    // Asignar valores a los profesores
                    profesores[0].setNombre("Carlos");
                    profesores[0].setApellido("Lopez");
                    profesores[0].setEmail("email");
                    profesores[0].setCatedra(101);
                    profesores[0].setFacultad("Ingenieria");

                    profesores[1].setNombre("Maria");
                    profesores[1].setApellido("Martinez");
                    profesores[1].setEmail("email");
                    profesores[1].setCatedra(102);
                    profesores[1].setFacultad("Ingenieria");

                    profesores[2].setNombre("Luis");
                    profesores[2].setApellido("Fernandez");
                    profesores[2].setEmail("email");
                    profesores[2].setCatedra(103);
                    profesores[2].setFacultad("Ingenieria");

                    // Imprimir datos de estudiantes
                    for (Estudiante estudiante : estudiantes) {
                        System.out.println(estudiante.toString());
                    }

                    // Imprimir datos de profesores
                    for (Profesor profesor : profesores) {
                        System.out.println(profesor.toString());
                    }
                    break;

                case 4:
                    // Ejercicio 4
                    int a = 1, b = 2;
                    Integer c = 3, d = 4;

                    SwapValores.swap1(a, b);
                    SwapValores.swap2(c, d);

                    System.out.println("a=" + a + " b=" + b);
                    System.out.println("c=" + c + " d=" + d);
                    break;

                case 5:
                    // Ejercicio 5
                    int[] numeros = {1, 2, 3, 4, 5};

                    System.out.print("MinMaxProm con return");
                    MinMaxProm minMaxProm = MinMaxProm.calculateWithReturn(numeros);
                    System.out.println(minMaxProm.toString());

                    System.out.print("MinMaxProm con parametro");
                    MinMaxProm minMaxProm2 = new MinMaxProm();
                    MinMaxProm.calculateWithParameter(numeros, minMaxProm2);
                    System.out.println(minMaxProm2.toString());

                    System.out.print("MinMaxProm con print");
                    MinMaxProm.calculateWithPrint(numeros);
                    break;

                case 6:
                    // Ejercicio 6: Comparación entre ArrayList y LinkedList
                    System.out.println("\n--- Comparación entre ArrayList y LinkedList ---\n");
                    System.out.println("a. ¿En qué casos ArrayList ofrece un mejor rendimiento que LinkedList?");
                    System.out.println("   - Acceso aleatorio a elementos: ArrayList es O(1), LinkedList es O(n).");
                    System.out.println("   - Iteraciones: ArrayList es más eficiente.");
                    System.out.println("   - Inserciones/eliminaciones al final: ArrayList es O(1) amortizado.");

                    System.out.println("\nb. ¿Cuándo LinkedList puede ser más eficiente que ArrayList?");
                    System.out.println("   - Inserciones/eliminaciones frecuentes en posiciones intermedias o al inicio.");
                    System.out.println("   - Cuando el tamaño de la lista cambia frecuentemente.");
                    System.out.println("   - Cuando no se necesita acceso aleatorio.");

                    System.out.println("\nc. Diferencias en el uso de memoria:");
                    System.out.println("   - ArrayList: Menor consumo por elemento, pero puede desperdiciar capacidad.");
                    System.out.println("   - LinkedList: Mayor consumo por referencias adicionales.");

                    System.out.println("\nd. ¿Cuándo usar cada uno?");
                    System.out.println("   - ArrayList: Acceso rápido por índice, tamaño estable.");
                    System.out.println("   - LinkedList: Muchas inserciones/eliminaciones, tamaño variable.");
                    System.out.println("\n--- Fin del análisis ---");
                    break;

                case 7:
                    // Ejercicio 7: Implementación de una pila (stack)
                    System.out.println("\n--- Ejercicio 7: Operaciones con una pila ---");

                    // Crear una pila
                    Stack<Integer> pila = new Stack<>();

                    // Agregar elementos a la pila
                    pila.push(10);
                    pila.push(20);
                    pila.push(30);

                    // Mostrar la pila
                    System.out.println("Pila actual: " + pila);

                    // Eliminar el elemento superior de la pila
                    int elementoEliminado = pila.pop();
                    System.out.println("Elemento eliminado: " + elementoEliminado);

                    // Mostrar la pila después de eliminar
                    System.out.println("Pila después de eliminar: " + pila);

                    // Consultar el elemento superior sin eliminarlo
                    int elementoSuperior = pila.peek();
                    System.out.println("Elemento superior: " + elementoSuperior);

                    // Verificar si la pila está vacía
                    boolean estaVacia = pila.isEmpty();
                    System.out.println("¿La pila está vacía? " + estaVacia);

                    break;

                case 8:
                    // Ejercicio 8
                    break;

                case 9:
                    // Ejercicio 9
                    break;

                case 10:
                    // Ejercicio 10
                    break;

                case 11:
                    // Ejercicio 11
                    break;

                case 12:
                    // Salir
                    System.out.println("\nGracias por usar el programa");
                    System.exit(0);
                    break;

                default:
                    System.out.println("\nOpcion no valida");
            }
        } while (opcion != 12);

        scanner.close();
    }
}