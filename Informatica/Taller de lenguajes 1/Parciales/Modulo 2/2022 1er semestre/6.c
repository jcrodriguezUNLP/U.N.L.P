// escriba un programa que realice la suma de una secuencia de numeros flotantes

// a)
//    dicho programa debe reciir la secunecia de numeris cimi argumentos a la funcion main y calcula el promedio de estos
//    en caso de que el programa no reciba la cantidad de argumeentos correcta debe imprimir un mensaje de error

// b)
//    asumiendo que el programa se llama sumaNros.exe
//    muestre un ejemplo de su uso y muestre la salida

#include <stdio.h>
#include <stdlib.h> // Necesario para la función atof()

// argc: Argument Count (cuenta cuántas palabras hay en la línea de comandos)
// argv: Argument Vector (arreglo de strings con cada palabra)
int main( int argc , char *argv[] ) {
    
    // 1. Validación: El programa necesita al menos un número (argc >= 2)
    // (argc vale 1 cuando solo se escribe el nombre del programa)
    if (argc < 2) {
        printf("Error: No se han proporcionado numeros.\n");
        printf("Uso correcto: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1; // Retornamos 1 para indicar error
    }

    double suma = 0.0;
    int i;
    int cantidadNumeros = argc - 1; // Restamos 1 porque argv[0] es el nombre del ejecutable

    // 2. Recorrido y Suma
    // Empezamos el ciclo en i=1 porque argv[0] es "sumaNros.exe"
    for (i = 1; i < argc; i++) {
        // atof convierte un string (char*) a un double (float)
        suma += atof(argv[i]);
    }

    // 3. Cálculo del Promedio
    double promedio = suma / cantidadNumeros;

    // 4. Salida
    printf("Cantidad de numeros procesados: %d\n", cantidadNumeros);
    printf("Suma total: %.2f\n", suma);
    printf("Promedio: %.2f\n", promedio);

    return 0; // Terminación exitosa
}