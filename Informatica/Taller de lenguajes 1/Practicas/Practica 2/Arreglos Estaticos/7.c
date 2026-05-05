// ==============================================================================
// PROBLEMA 7: ANÁLISIS DE PRECIPITACIONES CLIMÁTICAS
// ==============================================================================
// Contexto:
//     - Se dispone de un arreglo multidimensional con la información de las 
//       precipitaciones de todos los días, de todos los meses, de los últimos 10 años.
//     - Asuma, por simplicidad, que todos los meses tienen 30 días exactos.
// Tarea / Responda:
//     Desarrolle un programa que procese la matriz e informe:
//     1. Para cada año, el mes en que menos llovió.
//     2. El año que tuvo la menor precipitación promedio en general.
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- MÓDULO 1: Nivel Mes (1D) ---
// Responsabilidad: Sumar toda la lluvia de un mes (un arreglo lineal de 30 días)
int procesarMes( int dias , int mes[ dias ] ) {
    int sumaMensual = 0 ;

    for( int d = 0 ; d < dias ; d++ ) {
        sumaMensual += mes[ d ] ;
    }

    return( sumaMensual ) ;
}

// --- MÓDULO 2: Nivel Año (2D) ---
// Responsabilidad: Encontrar el mes más seco e informar la suma total del año
int procesarAno( int meses , int dias , int ano[ meses ][ dias ] ) {
    
    // 1. Pivote: Procesamos el mes 0 usando el Módulo 1
    int lluviaMinima = procesarMes( dias , ano[ 0 ] ) ;
    int mesMinimo = 0 ;
    int sumaAnual = lluviaMinima ; // Iniciamos la suma global del año

    // 2. Iteramos el resto de los meses
    for( int m = 1 ; m < meses ; m++ ) {
        
        int lluviaMesActual = procesarMes( dias , ano[ m ] ) ;
        sumaAnual += lluviaMesActual ; // Acumulamos para el total anual
        
        // Comparamos para buscar la sequía
        if( lluviaMesActual < lluviaMinima ) {
            lluviaMinima = lluviaMesActual ;
            mesMinimo = m ;
        }
    }

    // Cumplimos la Consigna 1: Imprimir el mes que menos llovió para este año
    printf( "    Mes mas seco: %d\n"           , (mesMinimo+1)    ) ;
    printf( "    Lluvia total del mes: %dmm\n" , (lluviaMinima+1) ) ;

    // Retornamos la suma total para que el Módulo 3 calcule el promedio
    return( sumaAnual ) ;
}

// --- MÓDULO 3: Nivel Clima (3D) ---
// Responsabilidad: Evaluar todos los años y encontrar el promedio histórico más bajo
void procesarClima( int anios , int meses , int dias , int cubo[ anios ][ meses ][ dias ] ) {
    int a = 0 ;
    printf( "--- REPORTE CLIMATICO MODULAR ---\n\n" ) ;

    // 1. Pivote: Procesamos el Año 0 usando el Módulo 2
    int anioMasSeco = 0 ;
    printf( "anio: %d\n" , (a+1) ) ;
    int lluviaTotalAno0 = procesarAno( meses , dias , cubo[ 0 ] ) ;
    float promedioMenor = (float)lluviaTotalAno0 / ( meses * dias ) ;

    // 2. Iteramos el resto de los años
    for( a = 1 ; a < anios ; a++ ) {
        
        printf( "\nanio: %d\n" , (a+1) ) ;
        int lluviaTotalActual = procesarAno( meses , dias , cubo[ a ] ) ;
        float promedioActual = (float)lluviaTotalActual / ( meses * dias ) ;

        // Comparamos los promedios
        if( promedioActual < promedioMenor ) {
            promedioMenor = promedioActual ;
            anioMasSeco = a ;
        }
    }

    // Cumplimos la Consigna 2: Imprimir el año con menor precipitación promedio
    printf( "\n--------------------------------------------------------------\n" ) ;
    printf( "CONCLUSION GENERAL:\n" ) ;
    printf( "El Ano %d tuvo la menor precipitacion promedio ( %.2f mm/dia )\n" , (anioMasSeco+1) , promedioMenor ) ;
}

int main() {
    int anios = 10 , meses = 12 , dias = 30 ;
    int datosClima[ 10 ][ 12 ][ 30 ] = { 0 } ;

    // Inyección de entropía para testear
    srand( time( NULL ) ) ;
    for( int a = 0 ; a < anios ; a++ ) {
        for( int m = 0 ; m < meses ; m++ ) {
            for( int d = 0 ; d < dias ; d++ ) {
                datosClima[ a ][ m ][ d ] = rand() % 51 ; 
            }
        }
    }

    // Forzamos sequía en el Año 4 para que sea predecible en el testing
    for( int m = 0 ; m < meses ; m++ ) {
        for( int d = 0 ; d < dias ; d++ ) {
            datosClima[ 4 ][ m ][ d ] = 1 ;
        }
    }

    // Ejecución de la cascada
    procesarClima( anios , meses , dias , datosClima ) ;

    return( 0 ) ;
}