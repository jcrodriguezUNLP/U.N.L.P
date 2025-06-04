import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree<Integer> binaryTree = new BinaryTree<>();
        BinaryTreeInteger binaryTreeInteger = new BinaryTreeInteger();
        int option;

        do {
            System.out.println("\n" + Sangria.sangria(0) + "--- Menú Principal ---\n");
            System.out.println(Sangria.sangria(1) + "1. Salir");
            System.out.println(Sangria.sangria(1) + "2. Operaciones con BinaryTree");
            System.out.println(Sangria.sangria(1) + "3. Operaciones con BinaryTree<Integer>");
            System.out.println(Sangria.sangria(1) + "4. Comparar prefijos de BinaryTreeInteger");        
            System.out.print("\n" + Sangria.sangria(1) + "Seleccione una opción: ");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.println("\nSaliendo del programa...\n");
                    break;

                case 2:
                    menuBinaryTree(scanner, binaryTree, 1);
                    break;

                case 3:
                    menuBinaryTreeInteger(scanner, binaryTreeInteger, 1);
                    break;
                
                case 4:
                    System.out.println("\n" + Sangria.sangria(1) + "Comparar prefijos de BinaryTreeInteger\n");

                    int nivelSangria = 2; // Define nivelSangria

                    // Crear árbol 1 como prefijo explícito
                    BinaryTreeInteger arbol1 = new BinaryTreeInteger(2);
                    arbol1.addLeftChild(new BinaryTreeInteger(4));
                    arbol1.addRightChild(new BinaryTreeInteger(5));
                    arbol1.getLeftChild().addLeftChild(new BinaryTreeInteger(7));

                    // Graficar el árbol 1
                    System.out.println(Sangria.sangria(nivelSangria) + "Árbol 1 generado correctamente.\n");
                    arbol1.graficarArbol_Por_Nivel(); // Graficar el árbol 1

                    // Crear árbol 2 que contiene a árbol 1 como prefijo
                    BinaryTreeInteger arbol2 = new BinaryTreeInteger(2);
                    arbol2.addLeftChild(new BinaryTreeInteger(4));
                    arbol2.addRightChild(new BinaryTreeInteger(5));
                    arbol2.getLeftChild().addLeftChild(new BinaryTreeInteger(7));
                    arbol2.getRightChild().addRightChild(new BinaryTreeInteger(8));

                    // Graficar el árbol 2
                    System.out.println(Sangria.sangria(nivelSangria) + "Árbol 2 generado correctamente.\n");
                    arbol2.graficarArbol_Por_Nivel(); // Graficar el árbol 2

                    // Verificar si árbol 1 es prefijo de árbol 2
                    System.out.println("\n" + Sangria.sangria(1) + "¿Es el árbol 1 prefijo del árbol 2? " + (esPrefijo(arbol1, arbol2) ? "Sí" : "No") + "\n");
                    break;

                default:
                    System.out.println("\n" + Sangria.sangria(1) + "Opción inválida. Intente nuevamente.\n");
            }
        } while (option != 1);

        scanner.close();
    }

    // Menú para BinaryTree
    private static void metodosGenerales(Scanner scanner, BinaryTree<Integer> tree, int nivelSangria) {
        int option;
        do {
            System.out.println(Sangria.sangria(nivelSangria) + "1. Atrás");
            System.out.println(Sangria.sangria(nivelSangria) + "2. Generar árbol de pruebas");
            System.out.println(Sangria.sangria(nivelSangria) + "3. Verificar si el árbol está vacío");
            System.out.println(Sangria.sangria(nivelSangria) + "4. Graficar árbol");
            System.out.println(Sangria.sangria(nivelSangria) + "5. Contar hojas");
            System.out.println(Sangria.sangria(nivelSangria) + "6. Generar árbol espejo");
            System.out.println(Sangria.sangria(nivelSangria) + "7. Mostrar niveles entre n y m");
            System.out.println(Sangria.sangria(nivelSangria) + "8. toString");
            System.out.println(Sangria.sangria(nivelSangria) + "9. Insertar un nodo");
            System.out.println(Sangria.sangria(nivelSangria) + "10. Eliminar un nodo");
            System.out.println(Sangria.sangria(nivelSangria) + "11. Buscar un nodo");
            System.out.println(Sangria.sangria(nivelSangria) + "12. Graficar árbol por nivel");
            System.out.print("\n" + Sangria.sangria(nivelSangria) + "Seleccione una opción: ");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Regresando...\n");
                    break;

                case 2:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Generando árbol de pruebas...\n");

                    // Generar árbol de pruebas con un máximo de 3 niveles
                    generarArbolDePruebas((BinaryTreeInteger) tree, 3);

                    System.out.println(Sangria.sangria(nivelSangria) + "Árbol generado correctamente.\n");
                    break;

                case 3:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + (tree.isEmpty() ? "El árbol está vacío.\n" : "El árbol no está vacío.\n"));
                    break;

                case 4:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Gráfico del árbol:\n");
                    int[] nivelAnt = null; // Simula una variable por referencia
                    tree.graficarArbol(100, 0, nivelAnt);
                    System.out.println();
                    break;

                case 5:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Cantidad de hojas: " + tree.contarHojas() + "\n");
                    break;

                case 6:
                    BinaryTree<Integer> espejo = tree.espejo();
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Árbol espejo generado. Raíz del espejo: " + espejo.getData() + "\n");
                    break;

                case 7:
                    System.out.print("\n" + Sangria.sangria(nivelSangria) + "Ingrese el nivel n: ");
                    int n = scanner.nextInt();
                    System.out.print(Sangria.sangria(nivelSangria) + "Ingrese el nivel m: ");
                    int m = scanner.nextInt();
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Niveles entre " + n + " y " + m + ":\n");
                    tree.entreNiveles(n, m);
                    System.out.println();
                    break;

                case 8:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Representación del árbol:\n" + tree.toString() + "\n");
                    break;

                case 9:
                    System.out.print("\n" + Sangria.sangria(nivelSangria) + "Ingrese el valor del nodo a insertar: ");
                    int valueToInsert = scanner.nextInt();
                    tree.insert(valueToInsert);
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Nodo insertado correctamente.\n");
                    break;

                case 10:
                    System.out.print("\n" + Sangria.sangria(nivelSangria) + "Ingrese el valor del nodo a eliminar: ");
                    int valueToRemove = scanner.nextInt();
                    tree.remove(valueToRemove);
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Nodo eliminado correctamente (si existía).\n");
                    break;

                case 11:
                    System.out.print("\n" + Sangria.sangria(nivelSangria) + "Ingrese el valor del nodo a buscar: ");
                    int valueToSearch = scanner.nextInt();
                    BinaryTree<Integer> foundNode = tree.search(valueToSearch);
                    if (foundNode != null) {
                        System.out.println("\n" + Sangria.sangria(nivelSangria) + "Nodo encontrado: " + foundNode.getData() + "\n");
                    } else {
                        System.out.println("\n" + Sangria.sangria(nivelSangria) + "Nodo no encontrado.\n");
                    }
                    break;

                case 12:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Graficar árbol POR NIVEL:\n");
                    tree.graficarArbol_Por_Nivel();
                    break;

                default:
                    System.out.println("\n" + Sangria.sangria(nivelSangria) + "Opción inválida. Intente nuevamente.\n");
            }
        } while (option != 1);
    }

    private static void menuBinaryTree(Scanner scanner, BinaryTree<Integer> tree, int nivelSangria) {
        System.out.println("\n" + Sangria.sangria(nivelSangria) + "--- Menú BinaryTree ---\n");

        metodosGenerales(scanner, tree, nivelSangria + 1);
    }

    // Menú para BinaryTree<Integer>
    private static void menuBinaryTreeInteger(Scanner scanner, BinaryTreeInteger tree, int nivelSangria) {
        int option;

        do {
            System.out.println("\n" + Sangria.sangria(nivelSangria) + "--- Menú BinaryTree<Integer> ---\n");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "1. Atrás");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "2. Métodos generales");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "3. Mostrar números pares en inorden");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "4. Mostrar números pares en postorden");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "5. Calcular el mayor retardo de reenvío");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "6. Sumar elementos en una profundidad específica");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "7. Transformar el árbol");
            System.out.println(Sangria.sangria(nivelSangria + 1) + "8. Comparar hijos únicos en subárboles izquierdo y derecho");
            System.out.print("\n" + Sangria.sangria(nivelSangria + 1) + "Seleccione una opción: ");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "Regresando...\n");
                    break;

                case 2:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "--- Metodos generales ---\n");
                    metodosGenerales(scanner, tree, nivelSangria + 2);
                    break;

                case 3:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "Números pares en inorden:\n");
                    LinkedList<Integer> numerosParesInOrden = tree.numerosPares_InOrden();
                    for (Integer num : numerosParesInOrden) {
                        System.out.println(Sangria.sangria(nivelSangria + 2) + num);
                    }
                    break;

                case 4:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "Números pares en postorden:\n");
                    LinkedList<Integer> numerosParesPostOrden = tree.numerosPares_PostOrden();
                    for (Integer num : numerosParesPostOrden) {
                        System.out.println(Sangria.sangria(nivelSangria + 2) + num);
                    }
                    break;

                case 5:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "Mayor retardo de reenvío: " + tree.maximoRetardo() + "\n");
                    break;
                
                case 6:
                    System.out.print("\n" + Sangria.sangria(nivelSangria + 1) + "Ingrese la profundidad para calcular la suma de elementos: ");
                    int profundidad = scanner.nextInt();
                    int suma = tree.sumaElementosProfundidad(profundidad);
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "La suma de los elementos en la profundidad " + profundidad + " es: " + suma + "\n");
                    break;

                case 7:
                    System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "Transformando el árbol...\n");
                    tree.Transformacion();
                    System.out.println(Sangria.sangria(nivelSangria + 1) + "Árbol transformado correctamente.\n");
                    break;
                
                case 8:
                    System.out.print("\n" + Sangria.sangria(nivelSangria + 1) + "Ingrese el valor del nodo para comparar hijos únicos: ");
                    int num = scanner.nextInt();
                    boolean resultado = tree.compararUnicosHijos(num);
                    
                    if (resultado) {
                        System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "El número de hijos únicos en el subárbol izquierdo es mayor que en el derecho.\n");
                    } else {
                        System.out.println("\n" + Sangria.sangria(nivelSangria + 1) + "El número de hijos únicos en el subárbol izquierdo no es mayor que en el derecho.\n");
                    }

                    break ;

                default:
                    System.out.println( "\n" + Sangria.sangria(nivelSangria + 1) + "Opción inválida. Intente nuevamente.\n" ) ;
            }
        } while( option != 1 ) ;
    }

    private static boolean esPrefijo( BinaryTreeInteger arbol1 , BinaryTreeInteger arbol2 ) {
        boolean resultado = false ;

        if ( arbol1 == null ) {
            // Si arbol1 es nulo, es prefijo de cualquier árbol
            resultado = true ;
        } else if ( arbol2 == null ) {
            // Si arbol2 es nulo pero arbol1 no lo es, entonces no puede ser prefijo
            resultado = false ;
        } else if (!arbol1.getData().equals(arbol2.getData())) {
            // Si los datos de los nodos actuales no coinciden, no es prefijo
            resultado = false;
        } else {
            // Verificar recursivamente las ramas izquierda y derecha
            boolean izqPrefijo = esPrefijo(arbol1.getLeftChild(), arbol2.getLeftChild());
            boolean derPrefijo = esPrefijo(arbol1.getRightChild(), arbol2.getRightChild());

            // Si ambos subárboles son prefijos, entonces arbol1 es prefijo de arbol2
            resultado = ( izqPrefijo && derPrefijo ) ;
        }

        return( resultado ) ;
    }

    // Método auxiliar para generar un árbol de pruebas
    private static void generarArbolDePruebas(BinaryTreeInteger tree, int maxNiveles) {
        Random random = new Random();
        Queue<BinaryTreeInteger> cola = new LinkedList<>();
        tree.setData(random.nextInt(10)); // Asignar un valor aleatorio a la raíz
        cola.add(tree);

        int nivelActual = 1;

        while (!cola.isEmpty() && nivelActual < maxNiveles) {
            int nodosEnNivel = cola.size();

            for (int i = 0; i < nodosEnNivel; i++) {
                BinaryTreeInteger nodo = cola.poll();

                // Decidir aleatoriamente si agregar un hijo izquierdo
                if (random.nextBoolean()) {
                    BinaryTreeInteger hijoIzquierdo = new BinaryTreeInteger(random.nextInt(10));
                    nodo.addLeftChild(hijoIzquierdo);
                    cola.add(hijoIzquierdo);
                }

                // Decidir aleatoriamente si agregar un hijo derecho
                if (random.nextBoolean()) {
                    BinaryTreeInteger hijoDerecho = new BinaryTreeInteger(random.nextInt(10));
                    nodo.addRightChild(hijoDerecho);
                    cola.add(hijoDerecho);
                }
            }

            nivelActual++;
        }
    }
}