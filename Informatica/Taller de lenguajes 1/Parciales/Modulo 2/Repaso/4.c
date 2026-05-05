/*
    4. (1 punto) Indique con V (verdadero) o F (falso) el valor de verdad de las siguientes afirmaciones:
        a) La siguiente instrucción imprime dos valores distintos:
            printf( "%d %d", sizeof (double *), sizeof(int *) ) ;
            FALSO (En arquitecturas de 64 bits, todos los punteros tienen el mismo tamaño).

        b) Dada la siguiente  declaración:
            int M[3][2] ;
            la instrucción imprime el valor del elemento ubicado en la 1ra columna de la 3ra fila usando 
                *(M + 4)
            FALSO. la expresion correcta es *( *(M+2) + 0 ) o equivalentemente *( &M[0][0] + 4 ) o *( (int*)M + 4 ).

            ejemplo:
                int M[3][2] = { {10,11}, {20,21}, {30,31} };

                printf( "M[2][0]           = %d\n", M[2][0]           ) ; // 30
                printf( "*( *(M+2) + 0 )   = %d\n", *( *(M+2)   + 0 ) ) ; // 30
                printf( "*( &M[0][0] + 4 ) = %d\n", *( &M[0][0] + 4 ) ) ; // 30
                printf( "*( (int*)M  + 4 ) = %d\n", *( (int*)M  + 4 ) ) ; // 30

        c) La instrucción printf( "2^5 = %d", 2^5 ) imprime el valor 7
            VERDADERO ( 2 XOR 5 en binario es 010 XOR 101 = 111 = 7 )

        d) La única diferencia entre los modos "w+" y "a+" es la posición donde se comienza a escribir.
            FALSO ( "w+" trunca el archivo, "a+" no ) .
        
        e) Cuando el archivo existe, es lo mismo abrirlo con "r+" que con "w+".
            FALSO ( "w+" trunca, "r+" preserva el contenido ).

        f) Si se utiliza la función fopen() para abrir un archivo que no existe con el modo "a", retornará NULL.
            FALSO ( Los modos 'a' y 'w' crean el archivo si no existe ).
        
        g) fputc( 'a', stdout ) equivale a putchar('a').
            VERDADERO ( putchar es generalmente una macro para fputc/putc en stdout ).

        h) Si sólo se va a leer un archivo de texto es lo mismo abrirlo con modo "a" que con "a+".
            FALSO ( El modo 'a' solo permite escritura ).

        i) La función feof() permite saber si el indicador de posición del archivo se encuentra posicionado en el límite de dicho archivo.
            FALSO ( feof() solo se vuelve TRUE DESPUES de un intento de lectura fallido ).

        j) La función fwrite() puede retornar un valor entre 0 y las cantidad de elementos que se desean escribir.
            VERDADERO ( Retorna el numero de elementos escritos exitosamente ).
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("--- Solucion Pregunta 4 (V/F) ---\n");
    printf("a) FALSO\n");
    printf("b) FALSO\n");
    printf("c) VERDADERO\n");
    printf("d) FALSO\n");
    printf("e) FALSO\n");
    printf("f) FALSO\n");
    printf("g) VERDADERO\n");
    printf("h) FALSO\n");
    printf("i) FALSO\n");
    printf("j) VERDADERO\n");
    
    printf("\n--- Verificacion c) ---\n");
    printf("2^5 (XOR) es: %d\n", 2^5); // Imprime 7
    
    return 0;
}