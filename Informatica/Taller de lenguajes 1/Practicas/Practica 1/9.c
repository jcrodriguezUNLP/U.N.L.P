// ==============================================================================
// PROBLEMA 9: CALCULADORA BÁSICA
// ==============================================================================
// Escriba un programa que:
//     lea:
//         2 números enteros y 1 carácter (operador matemático: +, -, /, x).
//     imprima:
//         el resultado de realizar la operación pedida en pantalla.
//     condición:
//         si el carácter no es un operador válido, imprimir un mensaje de error.
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. INICIALIZACIÓN ---
    int   a ;
    int   b ;
    char  op ;
    
    // Inicializamos banderas de estado y acumulador
    float res = 0.0f ; 
    int   exito ;
    int   errorDivCero = 0 ;

    // --- 2. PROCESAMIENTO: LECTURA DE OPERANDOS ---
    printf( "Ingrese el primer numero entero: " ) ;
    scanf( "%d" , &a ) ;
    
    printf( "Ingrese el segundo numero entero: " ) ;
    scanf( "%d" , &b ) ;

    // --- 3. PROCESAMIENTO: MOTOR DE OPERACIONES ---
    do {
        // Asumimos que el usuario ingresará un operador correcto
        exito = 1 ; 

        printf( "Ingrese el operador matematico (+, -, *, /): " ) ;
        
        // CORRECCIÓN PORTABLE: El espacio antes de %c reemplaza al fflush(stdin)
        scanf( " %c" , &op ) ; 

        switch( op ) {
            case '+':
                res = (float)( a + b ) ;
                break ;
                
            case '-':
                res = (float)( a - b ) ;
                break ;
                
            case 'x': // Contemplamos 'x' minúscula, mayúscula y el asterisco
            case 'X':
            case '*':
                res = (float)( a * b ) ;
                break ;
                
            case '/':
                if( b == 0 ) {
                    printf( "Error: No se puede dividir por cero.\n" ) ;
                    errorDivCero = 1 ;
                } else {
                    // Casting explícito a float para no perder decimales
                    res = ( (float)a / b ) ;
                }
                break ;
                
            default:
                printf( "Error: Operador '%c' invalido. Intente de nuevo.\n\n" , op ) ;
                exito = 0 ; // Disparamos la repetición del bucle
                break ;
        }
    } while( !exito ) ;

    // --- 4. SALIDA ---
    // Solo imprimimos el resultado si no ocurrió el error crítico de división
    if( !errorDivCero ) {
        printf( "Resultado: %d %c %d = %.2f\n" , a , op , b , res ) ;
    }

    return( 0 ) ;
}