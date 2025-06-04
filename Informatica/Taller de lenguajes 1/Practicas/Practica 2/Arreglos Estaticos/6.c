#include <stdio.h>

#define DIGITOS 10 // Cantidad de dígitos (0-9)

// Función para contar las apariciones de los dígitos
void contarDigitos(int numero, int contador[]) {
    // Asegurarse de trabajar con el valor absoluto del número
    if (numero < 0) {
        numero = -numero;
    }

    // Inicializar el contador
    for (int i = 0; i < DIGITOS; i++) {
        contador[i] = 0;
    }

    // Contar las apariciones de cada dígito
    while (numero > 0) {
        int digito = numero % 10; // Obtener el último dígito
        contador[digito]++;       // Incrementar el contador correspondiente
        numero /= 10;             // Eliminar el último dígito
    }
}

// Función para imprimir los resultados
void imprimirFrecuenciaDigitos( int numero ) {
    int contador[DIGITOS]; // Array para contar las apariciones de cada dígito

    contarDigitos(numero, contador); // Llamar a la función para contar los dígitos

    printf("Frecuencia de los dígitos:\n");
    for (int i = 0; i < DIGITOS; i++) {
        if (contador[i] > 0) {
            printf("Dígito %d: %d veces\n", i, contador[i]);
        }
    }
}

int main() {
    int numero;
    int contador[ DIGITOS ] ; // Array para contar las apariciones de cada dígito

    // Leer un número entero desde teclado
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    // Llamar a la función para imprimir los resultados
    imprimirFrecuencia( numero ) ;

    return 0;
}