// ==============================================================================
// PROBLEMA 6: CONVERSIÓN DE DISTANCIAS
// ==============================================================================
// Escriba un programa que:
//     lea:
//         un número flotante desde teclado (distancia en kilómetros).
//     imprima:
//         su equivalente en millas.
//     nota:
//         1,61 Km ≈ 1 milla.
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. INICIALIZACIÓN ---
    float km     ;
    float millas ;

    // --- 2. PROCESAMIENTO ---
    printf( "Ingrese una distancia en km: " ) ;
    scanf( "%f" , &km ) ;

    // MEJORA TÉCNICA: El sufijo 'f' en 1.61f le indica al compilador de forma 
    // estricta que es un tipo 'float' y no un 'double'. Esto evita conversiones 
    // implícitas en memoria durante el cálculo.
    millas = ( km / 1.61f ) ;

    // --- 3. SALIDA ---
    // MEJORA VISUAL: Usamos '%.2f' para recortar la impresión a 2 decimales, 
    // manteniendo la terminal limpia y legible para el usuario.
    printf( "%.2f km equivalen a %.2f millas\n" , km , millas ) ;

    return( 0 ) ;
}