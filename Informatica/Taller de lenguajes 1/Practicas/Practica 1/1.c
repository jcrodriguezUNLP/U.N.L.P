#include <stdio.h>

int main() {
    char opcion;

    do {
        // Imprimir el menú de opciones
        printf( "\nMenú de Opciones:" ) ;
        printf( "\na. Decir Hola" ) ;
        printf( "\nb. Mostrar un número" ) ;
        printf( "\n0. Salir" ) ;
        printf( "\nSeleccione una opción: " ) ;
        scanf( "%d", &opcion ) ;

        // Manejar las opciones con un switch
        switch(opcion) {
            case( "a" ):
                printf( "\nHola! Espero que tengas un buen día." ) ;
                break;
            case( "b" ):
                printf( "\nEl número seleccionado es 42." ) ;
                break;
            case( 0 ):
                printf( "\nSaliendo del programa. ¡Hasta luego!" ) ;
                break;
            default:
                printf( "\nOpción inválida. Por favor, intente de nuevo." ) ;
                break;
        }
    } while(opcion != 0 ) ; // El programa continúa hasta que el usuario seleccione la opción 3

    return 0;
}
    // a
    double pi= 3.14;
    int y= 5
    printf( "pi= %d\n", pi ) ;
    
    
    // b
    int x = 10 ;
    if( x = 5 ){
        printf( "\nx = 5" ) ;
    }

    return 0;
}