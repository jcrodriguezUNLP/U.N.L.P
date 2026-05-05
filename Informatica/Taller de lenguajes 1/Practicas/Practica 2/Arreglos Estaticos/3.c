// ==============================================================================
// PROBLEMA 3: MULTIPLICACIÓN ESCALAR DE MATRIZ
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         una matriz A (de m filas y n columnas) y un número escalar c.
//     modifique:
//         la matriz A, almacenando en ella el resultado de la multiplicación escalar (c * A).
//     nota matemática:
//         se debe multiplicar cada entrada de A por c.
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

void multiplicarMatrizPorEscalar( int m , int n , int matriz[m][n] , int c ) {
    // Protección defensiva para evitar procesar dimensiones inválidas
    if( m <= 0 || n <= 0 ) {
        return ;
    }

    for( int fila = 0 ; fila < m ; fila++ ) {
        for( int columna = 0 ; columna < n ; columna++ ){
            matriz[ fila ][ columna ] *= c ;
        }
    }
}

int main() {
    // --- 2. INICIALIZACIÓN ---
    int m = 2 ; // Filas
    int n = 3 ; // Columnas
    int c = 2 ; // Escalar

    // Matriz del ejemplo del PDF
    int matrizA[ 2 ][ 3 ] = {
        { 1 ,  8 , -3 } ,
        { 4 , -2 ,  5 }
    } ;

    printf( "--- Calculadora de Matrices: Escalar --- \n\n" ) ;

    // --- 3. PROCESAMIENTO ---
    printf( "Matriz Original A ( %d x %d ):\n" , m , n ) ;
    imprimirMatriz( m , n , matrizA ) ;

    // La matriz decae a puntero y se modifica in-place
    multiplicarMatrizPorEscalar( m , n , matrizA , c ) ;

    // --- 4. SALIDA ---
    printf( "\nMatriz A modificada ( %d * A ):\n" , c ) ;
    imprimirMatriz( m , n , matrizA ) ;

    printf( "\n" ) ;

    return( 0 ) ;
}