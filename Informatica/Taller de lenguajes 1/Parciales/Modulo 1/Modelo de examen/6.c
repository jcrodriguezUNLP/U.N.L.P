// El siguiente bloque de código define la estructura struct alu: 
 
// struct alu { 
//     char apellido[ 50 ] ; 
//     char nombre  [ 50 ] ; 
//     char legajo  [ 8  ] ; 
// } ;
 
// A partir de la definición anterior, realice: 
//     a) Renombre el tipo struct alu a alumno. 
//     b) Defina una función que permita inicializar una estructura alumno. 
//     c) Defina un arreglo de 10 elementos de tipo alumno e inicialice cada uno de ellos utilizando la función definida en el punto b). 
//     d) Imprima la información de cada alumno con el siguiente formato: 
//         Apellido y nombre: Perez, Juan | Legajo: 7751/8  
//         Apellido y nombre: García, Pablo | Legajo: 6952/1 

#include <stdio.h>

// A)
    struct alu { 
        char apellido[ 50 ] ; 
        char nombre  [ 50 ] ; 
        char legajo  [ 8  ] ; 
    } ;

    typedef struct alu TAlumno ;    // en vez de usarlo asi -> | struct alu alumno
                                    //                         |      |
                                    //                         |      v
                                    //        es lo mismo q -> | TAlumno    alumno

    // tmb puede ser asi
        typedef struct {
            char apellido[ 50 ] ; 
            char nombre  [ 50 ] ; 
            char legajo  [ 8  ] ; 
        } TAlumno_ ;
    //
//

// B)
    void leerAlumno( TAlumno *dirMemAlumno ) {
        printf( "Ingrese el Apellido: "       ) ;
        scanf ( "%s" , dirMemAlumno->apellido ) ;
        
        printf( "Ingrese el Nombre: "       ) ;
        scanf ( "%s" , dirMemAlumno->nombre ) ;
        
        printf( "Ingrese el Legajo: "       ) ;
        scanf ( "%s" , dirMemAlumno->legajo ) ;
    }
//

// D)
    void imprimirAlumno( TAlumno *dirMemAlumno ) {
        printf( "Apellido y nombre: %s, %s | Legajo: %s\n" , dirMemAlumno->apellido , dirMemAlumno->nombre , dirMemAlumno->legajo ) ;
    }
//

int main() {
    // C)
        TAlumno alumnos[ 10 ] ;

        for( int i = 0 ; i < 10 ; i++ ) {
            leerAlumno( &alumnos[ i ] ) ;
        }
    //

    // D)
        for( int i = 0 ; i < 10 ; i++ ) {
            imprimirAlumno( &alumnos[ i ] ) ;
        }
    //

    return( 0 ) ;
}