#include <stdio.h>

/*
 * =========================================================
 * USO DE MÁSCARAS DE BITS EN C
 * CONCEPTO: Una máscara es un valor constante (int o unsigned int) 
 * que se utiliza junto con operadores a nivel de bit 
 * (&, |, ^, ~) para manipular bits específicos dentro de un
 * valor de datos sin afectar a los demás.
 * =========================================================
*/

// Definición de las constantes (máscaras) para los bits del 0 al 7
// Cada constante tiene un único bit en '1'.
#define FLAG_A (1 << 0) // Bit 0 (Valor decimal: 1)
#define FLAG_B (1 << 1) // Bit 1 (Valor decimal: 2)
#define FLAG_C (1 << 2) // Bit 2 (Valor decimal: 4)
#define FLAG_D (1 << 3) // Bit 3 (Valor decimal: 8)
#define FLAG_E (1 << 4) // Bit 4 (Valor decimal: 16)
#define FLAG_F (1 << 5) // Bit 5 (Valor decimal: 32)
#define FLAG_G (1 << 6) // Bit 6 (Valor decimal: 64)
#define FLAG_H (1 << 7) // Bit 7 (Valor decimal: 128)

// -------------------------------------------------------------
// Función auxiliar para mostrar el valor entero y su binario (simplificado)
// -------------------------------------------------------------
void mostrar_estado(const char *nombre, unsigned char valor) {
    printf("  [ %-15s ] = %3u ( Binario: ", nombre, valor);
    // Imprime el binario (solo los 8 bits menos significativos)
    for (int i = 7; i >= 0; i--) {
        printf("%d", (valor >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" "); // Separador de nibble
    }
    printf(" )\n");
}

int main() {
    // Variable donde almacenaremos los estados de los flags (nuestro registro de control)
    unsigned char estado = 0x00; // Inicialmente todos los bits están en 0.
    
    printf("================================================\n");
    printf("            DEMOSTRACIÓN DE MÁSCARAS DE BITS    \n");
    printf("================================================\n");
    mostrar_estado("Inicial", estado);

    // =========================================================
    // 1. ENCENDER UN BIT (SET)
    // =========================================================
    // OPERADOR: OR a nivel de bit ( | )
    // LÓGICA: Cualquier bit | 1 siempre da 1.
    //         Cualquier bit | 0 no se altera.
    
    printf("\n--- 1. ENCENDER BITS (Operador: | ) ---\n");
    
    // Encender FLAG_B (Bit 1)
    estado = estado | FLAG_B; 
    mostrar_estado("Encender FLAG_B", estado); // Binario: 0000 0010
    
    // Encender FLAG_F (Bit 5)
    estado |= FLAG_F; // Forma abreviada
    mostrar_estado("Encender FLAG_F", estado); // Binario: 0010 0010
    
    // Encender múltiples bits a la vez (FLAG_A y FLAG_D)
    estado |= (FLAG_A | FLAG_D);
    mostrar_estado("Encender A y D", estado);  // Binario: 0010 1011
    
    // =========================================================
    // 2. APAGAR UN BIT (CLEAR/RESET)
    // =========================================================
    // OPERADOR: AND a nivel de bit (&) con la máscara NEGADA (~)
    // LÓGICA: Cualquier bit & 0 siempre da 0.
    //         Cualquier bit & 1 no se altera.
    
    printf("\n--- 2. APAGAR BITS (Operador: & ~ ) ---\n");

    // Apagar FLAG_B (Bit 1)
    estado = estado & (~FLAG_B);
    mostrar_estado("Apagar FLAG_B", estado);  // Binario: 0010 1001 (Antes era 0010 1011)
    
    // Apagar FLAG_D y FLAG_F a la vez
    // Se crea una máscara con los bits a apagar en 1 (0010 1000)
    // Se niega la máscara (~0010 1000 = 1101 0111)
    // Luego se aplica AND.
    estado &= (~(FLAG_D | FLAG_F)); 
    mostrar_estado("Apagar D y F", estado);   // Binario: 0000 0001 (Solo queda FLAG_A)
    
    // =========================================================
    // 3. VERIFICAR UN BIT (CHECK)
    // =========================================================
    // OPERADOR: AND a nivel de bit (&)
    // LÓGICA: (Valor & Máscara) solo será distinto de cero si el bit de interés está en 1.
    
    printf("\n--- 3. VERIFICAR BITS (Operador: & ) ---\n");
    
    // El estado actual es 0000 0001 (Solo FLAG_A está encendido)
    
    if (estado & FLAG_A) {
        printf("  -> FLAG_A está encendido.\n");
    } else {
        printf("  -> FLAG_A está apagado.\n");
    }

    if (estado & FLAG_C) {
        printf("  -> FLAG_C está encendido.\n");
    } else {
        printf("  -> FLAG_C está apagado.\n");
    }
    
    // Verificar si MÚLTIPLES bits están encendidos (FLAG_A Y FLAG_D)
    // Si (Valor & Máscara Combinada) == Máscara Combinada, TODOS los bits están encendidos.
    if ((estado & (FLAG_A | FLAG_D)) == (FLAG_A | FLAG_D)) {
        printf("  -> FLAG_A y FLAG_D están AMBOS encendidos.\n"); // Falso
    } else {
        printf("  -> FLAG_A y FLAG_D NO están AMBOS encendidos.\n"); // Verdadero
    }


    // =========================================================
    // 4. ALTERNAR UN BIT (TOGGLE/INVERT)
    // =========================================================
    // OPERADOR: XOR a nivel de bit ( ^ )
    // LÓGICA: Bit ^ 1 invierte el bit (0->1, 1->0).
    //         Bit ^ 0 no se altera.
    
    printf("\n--- 4. ALTERNAR BITS (Operador: ^ ) ---\n");
    
    // Estado inicial: 0000 0001 (FLAG_A encendido)
    
    // 4.1. Alternar FLAG_C (Apagado -> Encendido)
    estado = estado ^ FLAG_C;
    mostrar_estado("Alternar C (OFF->ON)", estado); // Binario: 0000 0101 (A y C encendidos)

    // 4.2. Alternar FLAG_A (Encendido -> Apagado)
    estado ^= FLAG_A; // Forma abreviada
    mostrar_estado("Alternar A (ON->OFF)", estado); // Binario: 0000 0100 (Solo C encendido)
    
    // 4.3. Alternar C y H a la vez (C apagado, H encendido)
    estado ^= (FLAG_C | FLAG_H); 
    mostrar_estado("Alternar C y H", estado);     // Binario: 1000 0000 (Solo H encendido)

    printf("================================================\n");

    return 0;
}