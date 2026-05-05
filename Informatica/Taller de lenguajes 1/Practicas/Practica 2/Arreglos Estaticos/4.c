// ==============================================================================
// PROBLEMA 4: MATRIZ TRANSPUESTA Y ROTACIONES
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         una matriz cuadrada A.
//     imprima:
//         su matriz transpuesta en pantalla.
//     nota matemática:
//         el elemento (j, i) de la original se convierte en el (i, j) de la transpuesta.
// ==============================================================================

#include <stdio.h>

void imprimirMatriz( int m , int n , int matriz[ m ][ n ] ) {
    
    // 1. Renderizar cabecera de columnas (Índices superiores)
    printf( "      |" ) ;
    for( int columna = 0 ; columna < n ; columna++ ) {
        printf( " %3d |" , columna ) ;
    }
    printf( "\n" ) ;

    // 2. Renderizar línea separadora dinámica
    printf( "------+" ) ;
    for( int columna = 0 ; columna < n ; columna++ ) {
        printf( "-----+" ) ;
    }
    printf( "\n" ) ;

    // 3. Renderizar cuerpo de la matriz
    for( int fila = 0 ; fila < m ; fila++ ) {
        
        // Índice de la fila actual (Borde izquierdo)
        printf( "| %3d |" , fila ) ; 
        
        // Datos de la fila
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

void rotar90Grados( int n , int matriz[ n ][ n ] ) {
    int rotada[ n ][ n ] ;
    
    for( int fila = 0 ; fila < n ; fila++ ){
        for( int columna = 0 ; columna < n ; columna++ ){
            rotada[ columna ][ (n-1) - fila ] = matriz[ fila ][ columna ] ;
        }
    }

    for( int fila = 0 ; fila < n ; fila++ ) {
        for( int columna = 0 ; columna < n ; columna++ ) {
            matriz[ fila ][ columna ] = rotada[ fila ][ columna ] ;
        }
    }
}

void trasponerMatriz( int m , int n , int original[ m ][ n ] , int destino[ n ][ m ] ) {
    for( int fila = 0 ; fila < m ; fila++ ) {
        for( int columna = 0 ; columna < n ; columna++ ) {
            destino[ columna ][ fila ] = original[ fila ][ columna ] ;
        }
    }
}

int main() {
    printf( "--- Suite de Operaciones Matriciales ---\n\n" ) ;

    // ==========================================================================
    // TEST 1: Rotación 90 Grados (Matriz Cuadrada In-Place)
    // ==========================================================================
    int dimA = 3 ; // Dimensión para matriz cuadrada

    int matrizA[ 3 ][ 3 ] = {
        { 1 ,  8 , -3 } ,
        { 4 , -2 ,  5 } ,
        { 6 , -1 ,  7 }
    } ;

    printf( "[TEST 1] Matriz Original A ( %dx%d ):\n" , dimA , dimA ) ;
    imprimirMatriz( dimA , dimA , matrizA ) ;

    rotar90Grados( dimA , matrizA ) ;

    printf( "[TEST 1] Matriz A rotada 90 grados en memoria:\n" ) ;
    imprimirMatriz( dimA , dimA , matrizA ) ;


    // ==========================================================================
    // TEST 2: Transposición Universal (Matriz Rectangular con Buffer)
    // ==========================================================================
    int m = 2 ; // Filas origen
    int n = 3 ; // Columnas origen

    int matrizB[ 2 ][ 3 ] = {
        { 1 ,  8 , -3 } ,
        { 4 , -2 ,  5 }
    } ;
    
    // CREACIÓN DEL BUFFER: Matriz vacía con las dimensiones invertidas (3x2)
    int matrizB_Traspuesta[ 3 ][ 2 ] = { 0 } ;
    
    printf( "[TEST 2] Matriz Original B (Rectangular %dx%d):\n" , m , n ) ;
    imprimirMatriz( m , n , matrizB ) ;
    
    // Ejecutamos la transposición pasando origen y el buffer de destino
    trasponerMatriz( m , n , matrizB , matrizB_Traspuesta ) ;

    // Al imprimir, invertimos los parámetros a (n, m) porque ahora tiene 3 filas y 2 columnas
    printf( "[TEST 2] Matriz B traspuesta ( %dx%d ):\n" , n , m ) ;
    imprimirMatriz( n , m , matrizB_Traspuesta ) ;


    return( 0 ) ;
}