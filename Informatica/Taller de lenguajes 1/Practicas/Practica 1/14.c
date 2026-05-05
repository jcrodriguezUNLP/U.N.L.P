// ==============================================================================
// PROBLEMA 14: INVERSIÓN DE DÍGITOS
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un número entero.
//     retorne:
//         el número resultante de invertir la posición de todos sus dígitos.
//     ejemplo:
//         entrada: 1234 -> salida: 4321.
// ==============================================================================

#include <stdio.h>

// --- 1. FUNCIÓN CORE ---
int invertir( int num ) {
    int invertido = 0 ;

    // Iteramos mientras queden dígitos por procesar
    while( num != 0 ) {
        
        // 1. "Empujamos" los dígitos que ya tenemos en el acumulador
        //    una posición a la izquierda (base 10)
        invertido *= 10 ;
        
        // 2. Extraemos el último dígito del número original y lo sumamos
        invertido += ( num % 10 ) ;

        // 3. "Cortamos" el último dígito del número original para avanzar
        num /= 10 ;
    }

    return( invertido ) ;
}

int main() {
    // --- 2. INICIALIZACIÓN ---
    int num ;
    int numInvertido ;

    printf( "--- Inversor de Digitos ---\n\n" ) ;

    // --- 3. PROCESAMIENTO ---
    printf( "Ingrese un numero entero: " ) ;
    scanf( "%d" , &num ) ;

    numInvertido = invertir( num ) ;

    // --- 4. SALIDA ---
    printf( "El numero %d invertido es: %d\n" , num , numInvertido ) ;

    return( 0 ) ;
}