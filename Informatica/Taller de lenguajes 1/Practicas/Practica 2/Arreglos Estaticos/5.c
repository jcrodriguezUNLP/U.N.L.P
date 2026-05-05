// ==============================================================================
// PROBLEMA 5: SUMA DE MATRICES
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         tres matrices A, B y C de las mismas dimensiones (m x n).
//     modifique:
//         la matriz C, almacenando en ella el resultado de la suma de A y B.
//     nota matemática:
//         (A+B)i,j = Ai,j + Bi,j
// ==============================================================================

#include <stdio.h>

// --- COMPONENTE UI: Renderizador Genérico ---
void imprimirMatriz( int m , int n , int matriz[ m ][ n ] ) {
    printf( "      |" ) ;
    for( int columna = 0 ; columna < n ; columna++ ) {
        printf( " %3d |" , columna ) ;
    }
    printf( "\n" ) ;

    printf( "------+" ) ;
    for( int columna = 0 ; columna < n ; columna++ ) {
        printf( "-----+" ) ;
    }
    printf( "\n" ) ;

    for( int fila = 0 ; fila < m ; fila++ ) {
        printf( "| %3d |" , fila ) ; 
        for( int columna = 0 ; columna < n ; columna++ ) {
            printf( " %3d |" , matriz[ fila ][ columna ] ) ;
        }
        printf( "\n" ) ;
        
        printf( "------+" ) ;
        for( int columna = 0 ; columna < n ; columna++ ) {
            printf( "-----+" ) ;
        }
        printf( "\n" ) ;
    }
    printf( "\n" ) ;
}

// --- FUNCIÓN CORE ---
void sumarMatrices( int m , int n , int A[ m ][ n ] , int B[ m ][ n ] , int C[ m ][ n ] ) {
    
    // Protección defensiva
    if( m <= 0 || n <= 0 ) return ;

    for( int fila = 0 ; fila < m ; fila++ ) {
        for( int columna = 0 ; columna < n ; columna++ ) {
            
            // CORRECCIÓN: Suma atómica utilizando los iteradores espaciales
            C[ fila ][ columna ] = A[ fila ][ columna ] + B[ fila ][ columna ] ;
            
        }
    }
}

int main() {
    // --- 1. INICIALIZACIÓN ---
    int m = 2 ; // Filas
    int n = 3 ; // Columnas

    // Matriz A (Basada en el ejemplo de la Práctica 2)
    int matrizA[ 2 ][ 3 ] = {
        { 1 , 3 , 1 } ,
        { 1 , 0 , 0 }
    } ;

    // Matriz B (Basada en el ejemplo de la Práctica 2)
    int matrizB[ 2 ][ 3 ] = {
        { 0 , 0 , 5 } ,
        { 7 , 5 , 0 }
    } ;

    // Buffer de Destino: Matriz C inicializada en 0
    int matrizC[ 2 ][ 3 ] = { 0 } ;

    printf( "--- Calculadora de Matrices: Suma (A + B = C) ---\n\n" ) ;

    // --- 2. PROCESAMIENTO Y SALIDA ---
    printf( "Matriz A:\n" ) ;
    imprimirMatriz( m , n , matrizA ) ;

    printf( "Matriz B:\n" ) ;
    imprimirMatriz( m , n , matrizB ) ;

    // Ejecutamos la función de suma pasando los punteros (Array Decay)
    sumarMatrices( m , n , matrizA , matrizB , matrizC ) ;

    printf( "Resultado - Matriz C ( A + B ):\n" ) ;
    imprimirMatriz( m , n , matrizC ) ;

    return( 0 ) ;
}