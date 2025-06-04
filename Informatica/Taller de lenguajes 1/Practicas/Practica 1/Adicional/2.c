#include <stdio.h>

int convertirABinario( int num ){
    int binario = 0 ;
    int factor  = 1 ;
    
    while( num != 0 ){
        binario += ( (num % 2) * factor ) ;
        
        factor *= 10 ;
        num    /= 2  ;
    }

    return( binario ) ;
}

int convertirABinarioRecursivo( int num ){
    int binario ;

    if( num != 0 ){
        binario = ( (num % 2) + (10 * convertirABinarioRecursivo( (num / 2) )) ) ;
    }

    return( binario ) ;
}

int main() {
    int numero;

    // Solicitar al usuario un número natural
    printf("Ingrese un numero natural: ");
    scanf("%d", &numero);

    // Validar que el número sea natural (positivo o cero)
    if (numero < 0) {
        printf("Por favor, ingrese un numero natural (positivo).\n");
        return 1;
    }

    // Llamar a la función y mostrar el resultado
    int binario = convertirABinario(numero);
    printf("La representacion binaria de %d es: %d\n", numero, binario);
    
    int binarioRecursivo = convertirABinarioRecursivo(numero);
    printf("La representacion binariaRecursiva de %d es: %d\n", numero, binarioRecursivo ) ;

    return 0 ;
}