public class Multiples {

    // Método de clase que devuelve un arreglo con los primeros n múltiplos de n
    public static int[] generateMultiples( int n ) {
        int[] multiples = new int[ n ] ;

        for (int i = 0; i < n; i++) {
            multiples[ i ] = ( n * (i + 1) ) ;
        }

        return multiples ;
    }
}