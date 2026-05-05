public class ArbolBinarioVisual {

    public static void main(String[] args) {
        int nivelMax = 7 ;
        char letra = 'a';

        for (int nivel = 0; nivel <= nivelMax; nivel++) {
            int nivelInvertido = nivelMax - nivel;
            int espaciosIniciales = (int) Math.pow(2, nivelInvertido + 1) - 2;
            int cantidadNodosXNivel = (int) Math.pow(2, nivel);
            int espaciosEntreNodos = (int) Math.pow(2, nivelInvertido + 2) - 1;

            // Imprimir nodos del nivel actual
            System.out.print("Nivel " + nivel + ": ");
            System.out.print(" ".repeat(espaciosIniciales));

            for (int i = 0; i < cantidadNodosXNivel; i++) {
                System.out.print(letra++);
                if (i < cantidadNodosXNivel - 1) {
                    System.out.print(" ".repeat(espaciosEntreNodos));
                }
            }
            System.out.println(); // Salto de línea después de los nodos

            // Imprimir conexiones entre nodos (barras)
            if (nivel < nivelMax) {
                int espaciosAntesBarras = calcularEspaciosAntesBarras(nivelInvertido);
                int espaciosDentroBarras = (int) Math.pow(2, nivelInvertido) - 1;
                int espaciosEntreBarras = calcularEspaciosEntreBarras(nivelInvertido);

                System.out.print(" ".repeat(9)); // Espaciado inicial para "Nivel n:"
                System.out.print(" ".repeat(espaciosAntesBarras));

                for (int i = 0; i < cantidadNodosXNivel; i++) {
                    System.out.print("/");
                    System.out.print(" ".repeat(espaciosDentroBarras));
                    System.out.print("\\");
                    if (i < cantidadNodosXNivel - 1) {
                        System.out.print(" ".repeat(espaciosEntreBarras));
                    }
                }
                System.out.println(); // Salto de línea después de las barras
            }
        }
    }

    private static int calcularEspaciosEntreBarras(int nivelInvertido) {
        if (nivelInvertido == 0) return 0;
        if (nivelInvertido == 1) return 5;

        int resultado = 5;
        for (int i = 2; i <= nivelInvertido; i++) {
            resultado = resultado * 2 + 1;
        }
        return resultado;
    }

    private static int calcularEspaciosAntesBarras(int nivelInvertido) {
        if (nivelInvertido == 0) return 0;
        return 3 * ((int) Math.pow(2, nivelInvertido - 1) - 1) + 1;
    }
}