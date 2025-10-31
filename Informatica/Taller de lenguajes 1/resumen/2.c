#include <stdio.h>

// CONTEO: Este código recorre N bit por bit, comenzando por el bit 0.
// Si un bit está encendido, lo apaga usando XOR (^).
// Si un bit está apagado, no hace nada (XOR con 0).

// -----------------------------------------------------------------
// FUNCIÓN SECUNDARIA: Aisla un bit de N y desplaza la máscara para la siguiente posición.
// -----------------------------------------------------------------
unsigned F( unsigned N ) {
    // 1. MÁSCARA ESTÁTICA: 'mask' se inicializa a 1 (000...0001) solo la primera vez.
    //    En llamadas subsecuentes, conserva su valor anterior y lo desplaza.
    static unsigned mask = 1; 
    
    // 2. AISLAR BIT: Auxiliar toma el valor del bit de N en la posición de 'mask'.
    //    - Si el bit de N está APAGADO, aux es 0.
    //    - Si el bit de N está ENCENDIDO, aux toma el valor de 'mask' (1, 2, 4, 8, etc.).
    unsigned aux = N & mask;  
    
    // 3. DESPLAZAR MÁSCARA: Se mueve la posición '1' de la máscara un bit a la izquierda (x2).
    //    Esto asegura que la próxima llamada a F() verificará el siguiente bit.
    mask = mask << 1;         
    
    // 4. RETORNO: Retorna 0 o el valor de la máscara, indicando si el bit estaba encendido.
    return(aux);              
}

// -----------------------------------------------------------------
// FUNCIÓN PRINCIPAL: Bucle y Operación de Limpieza de Bits
// -----------------------------------------------------------------
int main() {
    // VALOR INICIAL: N = 7 (Binario: 0000 0111). Tiene 3 bits encendidos.
    unsigned N = 7; 
    
    // BUCLE DE LIMPIEZA: Se ejecuta mientras N sea distinto de cero.
    // El bucle debería ejecutarse hasta que todos los bits de N hayan sido apagados.
    while( N ){
        // OPERACIÓN CRÍTICA: Limpia el bit de N correspondiente a la posición actual de 'mask'.
        // La función F(N) retorna el valor del bit de N en la posición de 'mask'.
        // Si aux (el retorno de F(N)) es > 0 (bit encendido): 
        //    N ^ aux invierte ese bit, apagándolo.
        // Si aux es 0 (bit apagado): 
        //    N ^ 0 no cambia N.
        // El valor de N se va reduciendo (de 7 a 6 a 4 a 0).
        N = N ^ F(N);

        // IMPRESIÓN 1: Muestra el valor de N antes de la operación de limpieza (N=7, N=6, N=4)
        printf("N = %u\n", N); 
        
    }
    
    return 0;
}

// -----------------------------------------------------------------
// EXPLICACIÓN DEL RASTREO (Trazado de N y mask)
// -----------------------------------------------------------------
/*
N INICIAL: 7 (0000 0111)

ITERACIÓN 1:
    - while(7): Verdadero.
    - printf: Imprime N=7
    - Llamada F(7):
        - mask (static) = 1 (001)
        - aux = 7 & 1 = 1. (Bit 0 de N está ON)
        - mask = 1 << 1 = 2.
        - Retorna 1.
    - N = N ^ 1: 7 ^ 1 = 6. (0000 0111 ^ 0000 0001 = 0000 0110). El Bit 0 se apaga.
    
ITERACIÓN 2:
    - while(6): Verdadero.
    - printf: Imprime N=6
    - Llamada F(6):
        - mask (static) = 2 (010)
        - aux = 6 & 2 = 2. (Bit 1 de N está ON)
        - mask = 2 << 1 = 4.
        - Retorna 2.
    - N = N ^ 2: 6 ^ 2 = 4. (0000 0110 ^ 0000 0010 = 0000 0100). El Bit 1 se apaga.
    
ITERACIÓN 3:
    - while(4): Verdadero.
    - printf: Imprime N=4
    - Llamada F(4):
        - mask (static) = 4 (100)
        - aux = 4 & 4 = 4. (Bit 2 de N está ON)
        - mask = 4 << 1 = 8.
        - Retorna 4.
    - N = N ^ 4: 4 ^ 4 = 0. (0000 0100 ^ 0000 0100 = 0000 0000). El Bit 2 se apaga.

FINAL:
    - while(0): Falso. Sale del bucle.
    - printf: Imprime N=0
*/

// -----------------------------------------------------------------
// RESPUESTA IMPRESA POR EL CÓDIGO:
// -----------------------------------------------------------------
/*
N=7
N=6
N=4
N=0
*/