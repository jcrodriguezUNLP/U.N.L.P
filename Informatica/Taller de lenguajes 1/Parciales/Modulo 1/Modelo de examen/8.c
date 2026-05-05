// a)
//     Defina:
//         un tipo enumerativo:
//             para trabajar con tres tipos de figura:
//                 cuadrado
//                 triángulo rectángulo
//                 círculo
//
//         una estructura:
//             para representar la figura utilizando:
//                 el tipo enumerativo (definido arriba)
//                 atributos comunes:
//                     color
//                 atributos específicos:
//                     cuadrado:
//                         longitud del lado
//                     triángulo rectángulo:
//                         longitud de la base
//                         longitud de la altura
//                     círculo:
//                         radio

// b)
//     Defina:
//         una función:
//             que reciba:
//                 la estructura definida en a)
//             que imprima:
//                 de la figura:
//                     nombre
//                     color
//                     área calculada

#include <stdio.h>

#define pi 3.14

typedef enum {
    CUADRADO = 1 ,
    TRIANGULO_RECTANGULO ,
    CIRCULO
} TOpcionFigura ;

typedef struct {
    TOpcionFigura opcionElegida ;
    char color[ 10 ] ;

    union {
        float lado ;               // Para el CUADRADO
        
        struct {                   // Para el TRIANGULO_RECTANGULO
            float base ;
            float altura ;
        } datosTriangulo ;         // Agrupados para que existan juntos
        
        float radio ;              // Para el CIRCULO
    } medidas ;
} TFigura ;

float potencia( float x , int n ) {
    if( n == 0 ) {
        return( 1 ) ;
    }

    float potencia = x ;

    for( int i = 1 ; i < n ; i++ ) {
        potencia *= x ;
    }

    return( potencia ) ;
}

float area( TFigura *dirMemFigura ) {
    if( dirMemFigura->opcionElegida == CUADRADO ) {
        float lado = dirMemFigura->medidas.lado ;

        return( potencia( lado , 2) ) ;
    }
    
    if( dirMemFigura->opcionElegida == TRIANGULO_RECTANGULO ) {
        float base   = dirMemFigura->medidas.datosTriangulo.base ;
        float altura = dirMemFigura->medidas.datosTriangulo.altura ;

        return( (base * altura) / 2.0 ) ;
    }
    
    if( dirMemFigura->opcionElegida == CIRCULO ) {
        float radio = dirMemFigura->medidas.radio ;

        return( pi * potencia( radio , 2) ) ;
    }
}

void leerFigura( TFigura *dirMemFigura ) {
    int opcionElegida ;
    
    do{
        printf( "Seleccione tipo (1-Cuadrado, 2-Triangulo, 3-Circulo): " ) ;
        scanf ( "%d" , &opcionElegida                                    ) ;
    } while( opcionElegida < 1 || 3 < opcionElegida ) ;
    

    dirMemFigura->opcionElegida = opcionElegida ;

    printf( "Ingrese el color: "       ) ;
    scanf ( "%s" , dirMemFigura->color ) ;

    switch( dirMemFigura->opcionElegida ) {
        case CUADRADO:
            printf( "Ingrese lado: "                     ) ;
            scanf ( "%f" , &(dirMemFigura->medidas.lado) ) ;
        break ;
        case TRIANGULO_RECTANGULO:
            printf( "Ingrese base: "                                    ) ;
            scanf ( "%f" , &(dirMemFigura->medidas.datosTriangulo.base) ) ;
            
            printf( "Ingrese altura: "                                    ) ;
            scanf ( "%f" , &(dirMemFigura->medidas.datosTriangulo.altura) ) ;
        break ;
        case CIRCULO:
            printf( "Ingrese radio: "                     ) ;
            scanf ( "%f" , &(dirMemFigura->medidas.radio) ) ;
        break ;
    }
}

void imprimirFigura( TFigura *dirMemFigura ) {
    printf( "nombre: " ) ;
    switch( dirMemFigura->opcionElegida ) {
        case CUADRADO:
            printf( "Cuadrado\n" ) ;
        break ;
        case TRIANGULO_RECTANGULO:
            printf( "Triangulo\n" ) ;
        break ;
        case CIRCULO:
            printf( "Circulo\n" ) ;
        break ;
    
    }
    printf( "color: %s\n"  , dirMemFigura->color  ) ;
    printf( "area: %.2f\n" , area( dirMemFigura ) ) ;
}

int main() {



    return( 0 ) ;
}