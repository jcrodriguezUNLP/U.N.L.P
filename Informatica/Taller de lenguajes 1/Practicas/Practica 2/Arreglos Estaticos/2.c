// ==============================================================================
// PROBLEMA 2: ESTADÍSTICAS DE UN ARREGLO
// ==============================================================================
// Desarrolle 3 funciones independientes que:
//     reciban:
//         un arreglo unidimensional de tipo float.
//     retornen:
//         a. el promedio de sus valores.
//         b. el mínimo de sus valores.
//         c. la posición del máximo de sus valores.
// ==============================================================================

#include <stdio.h>
#include <float.h> // Necesario si usas FLT_MAX

float calcularPromedio( float vector[] , int dimL ) {
    float suma = 0.0f ;

    // Protección defensiva para evitar división por cero
    if( dimL <= 0 ) {
        return( 0.0f ) ;
    }

    // Recorremos el arreglo desde el índice 0 hasta el último válido (dimL - 1)
    for( int i = 0 ; i < dimL ; i++ ) {
        suma += vector[ i ] ;
    }

    return( (suma / dimL) ) ;
}

float min( float vector[] , int dimL ) {
    if( dimL <= 0 ){
        return( FLT_MAX ) ;
    }
    
    float min = vector[ 0 ] ;

    for( int i = 1 ; i < dimL ; i++ ) {
        if( vector[ i ] < min ) {
            min = vector[ i ] ;
        }
    }

    return( min ) ;
}

int calcularPosMax( float vector[] , int dimL ) {
    if( dimL <= 0 ){
        return( -1 ) ;
    }
    
    int pos = 0 ;

    for( int i = 1 ; i < dimL ; i++ ) {
        if( vector[ pos ] < vector[ i ] ) {
            pos = i ;
        }
    }

    return( pos ) ;
}

int main() {
    // --- 2. INICIALIZACIÓN ---
    // Vector de prueba con casos variados (negativos, decimales, etc.)
    float vectorPrueba[] = { 12.5f , -4.2f , 8.9f , 45.1f , 2.1f , 0.0f , 45.1f } ;
    
    // Calculamos la dimensión dinámica para no hardcodear el número
    int dimL = ( sizeof( vectorPrueba ) / sizeof( vectorPrueba[0] ) ) ;

    printf( "--- Suite de Pruebas: Estadisticas de Arreglo ---\n\n" ) ;

    // --- 3. PROCESAMIENTO Y SALIDA ---
    // Imprimimos el vector para tener contexto visual en la consola
    printf( "Vector analizado: [ " ) ;
    for( int i = 0 ; i <= (dimL - 1) ; i++ ) {
        printf( "%.1f " , vectorPrueba[ i ] ) ;
    }
    printf( "]\n\n" ) ;

    // Test A: Promedio
    printf( "    -> Promedio de los valores : %.2f\n" , calcularPromedio( vectorPrueba , dimL ) ) ;
    
    // Test B: Mínimo (con validación defensiva)
    float valorMinimo = min( vectorPrueba , dimL ) ;
    if( valorMinimo != FLT_MAX ) {
        printf( "    -> Valor minimo            : %.2f\n" , valorMinimo ) ;
    } else {
        printf( "    -> Valor minimo            : [ERROR] Arreglo vacio.\n" ) ;
    }
    
    // Test C: Posición del Máximo (con validación defensiva)
    int posMaximo = calcularPosMax( vectorPrueba , dimL ) ;
    if( posMaximo != -1 ) {
        printf( "    -> Posicion del maximo     : Indice %d (Valor: %.2f)\n" , posMaximo , vectorPrueba[ posMaximo ] ) ;
    } else {
        printf( "    -> Posicion del maximo     : [ERROR] Arreglo vacio o invalido.\n" ) ;
    }

    printf( "\n" ) ;

    return( 0 ) ;
}