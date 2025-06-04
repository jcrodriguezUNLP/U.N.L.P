public class EntreNumeros {
    // Constructor
        public EntreNumeros() {}
    //

    // Métodos
        // metodo q imprime los numeros entre dos numeros con for
            public static void imprimirEntreNumerosConFor( int num1 , int num2 ) {
                System.out.print( "\nLos numeros entre " + num1 + " y " + num2 + " con for son:" ) ;
                for( int i = num1 + 1 ; i < num2 ; i++ ) {
                    System.out.print( " " + i ) ;
                }
            }
        //

        // metodo q imprime los numeros entre dos numeros con while
            public static void imprimirEntreNumerosConWhile( int num1 , int num2 ) {
                int i = num1 + 1 ;
                System.out.print( "\nLos numeros entre " + num1 + " y " + num2 + " con while son:" ) ;
                while( i < num2 ) {
                    System.out.print( " " + i ) ;
                    i++ ;
                }
            }
        //

        // metodo q imprime los numeros entre dos numeros con recursion
            public static void imprimirEntreNumerosConRecursion( int num1 , int num2 ) {
                if( num1 + 1 < num2 ) {
                    System.out.print( " " + ( num1 + 1 ) ) ;
                    imprimirEntreNumerosConRecursion( (num1 + 1) , num2 ) ;
                }
            }
        //

        @Override
        public String toString() {
            String texto = "" ;

            return( texto ) ;
        }
    //
}