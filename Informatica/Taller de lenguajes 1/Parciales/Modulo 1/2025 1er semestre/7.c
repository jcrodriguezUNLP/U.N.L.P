// Escriba un programa que:
//     Defina el tipo de estructura struct estudiante que represente a un alumno de la universidad con los campos:
//         int legajo
//         char carrera[80]
//         char nombre[50]
//         float promedio
//
//     Renombre el tipo struct estudiante como estudiante_t.
//
//     Defina la función cargar_estudiante
//        inicialice un estudiante a partir de valores ingresados por teclado.
//
//     Defina la función cant_estudiantes_carrera
//        reciba
//            un arreglo de estudiantes
//            un entero con su cantidad
//            una cadena con el nombre de una carrera
//            retorne la cantidad de estudiantes de dicha carrera.
//
//     Lea desde teclado
//        100 estudiantes.
//
//     Obtenga la cantidad de estudiantes de la carrera "Ingeniería en Computación".
//
//     Imprima el resultado en pantalla.

#include <stdio.h>
#include <string.h>

#define CANT_ESTUDIANTES 3

struct estudiante {
    int   legajo        ;
    char  carrera[ 80 ] ;
    char  nombre[ 50 ]  ;
    float promedio      ;
} ;

// typedef struct estudiante estudiante_t ;  // --> correcto
typedef struct estudiante TEstudiante ;      // --> pq quiero 

void cargarEstudiante( TEstudiante* estudiante ) {
    printf( "\nIngrese legajo: "      ) ;
    scanf ( "%d" , &(estudiante->legajo) ) ;
    
    printf( "\nIngrese carrera: "      ) ;
    scanf ( "%s" , estudiante->carrera ) ;
    
    printf( "\nIngrese nombre: "      ) ;
    scanf ( "%s" , estudiante->nombre ) ;
    
    printf( "\nIngrese promedio: "      ) ;
    scanf ( "%f" , &(estudiante->promedio) ) ;
}

int cantEstudiantesCarrera( TEstudiante estudiantes[] , int dimL , char carrera[] ) {
    int cant = 0 ;

    for( int i = 0 ; i < dimL ; i++ ) {
        int distintos = strcmp( estudiantes[i].carrera , carrera ) ;
        
        if( !distintos ) {
            cant++ ;
        }
    }

    return( cant ) ;
}

int main() {
    TEstudiante estudiantes[ CANT_ESTUDIANTES ] ;

    for( int i = 0 ; i < CANT_ESTUDIANTES ; i++ ) {
        cargarEstudiante( &estudiantes[ i ] ) ;
    }

    int cantIngEnComp = cantEstudiantesCarrera( estudiantes , CANT_ESTUDIANTES , "IngenieriaEnComputacion" ) ;

    printf( "Hay %d ingenieros en computacion" , cantIngEnComp ) ;

    return( 0 ) ;
}