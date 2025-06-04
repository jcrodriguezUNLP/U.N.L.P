//2
    // a
    int main(){
        char c= 'a' ;
        int x= 64 ;

        printf("char c= %c\n", x) ;
        printf("int x= %d\n", c) ;

        return 0 ;
    }

    // d
    int main() {
        // Tipos de datos primitivos
        printf("Tamaño de char: %zu bytes\n", sizeof(char));
        printf("Tamaño de int: %zu bytes\n", sizeof(int));
        printf("Tamaño de float: %zu bytes\n", sizeof(float));
        printf("Tamaño de double: %zu bytes\n", sizeof(double));

        // Usando sizeof con variables
        char c = 'A';
        int i = 10;
        float f = 3.14f;
        double d = 6.28;

        printf("Tamaño de variable 'c' (char): %zu bytes\n", sizeof(c));
        printf("Tamaño de variable 'i' (int): %zu bytes\n", sizeof(i));
        printf("Tamaño de variable 'f' (float): %zu bytes\n", sizeof(f));
        printf("Tamaño de variable 'd' (double): %zu bytes\n", sizeof(d));

        // Tamaño de un array
        int arr[10];
        printf("Tamaño de array 'arr' de 10 enteros: %zu bytes\n", sizeof(arr));

        return 0;
    }