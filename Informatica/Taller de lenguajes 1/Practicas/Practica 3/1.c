#include <stdio.h>

// definir estructuras
struct rectangulo {
    float base   ;
    float altura ;
} ;

typedef struct rectangulo TRectangulo ;

void inicializarRectangulo( struct rectangulo *r ) {
    // leer base y altura
    float base   ;
    float altura ;

    printf("Base: ");
    scanf("%f", &base);

    printf("Altura: ");
    scanf("%f", &altura);

    // inicializar el rectangulo
    r->base   = base   ;
    r->altura = altura ;
    
    // inicializar el rectangulo
    (*r).base   = base   ;
    (*r).altura = altura ;
}

float areaRectangulo( struct rectangulo *r ) {
    // calcular el area
    return( (*r).base * (*r).base ) ;
}

int main() {
    TRectangulo rectangulos[10];
    int i, indiceMenorArea = 0;
    float menorArea;

    // Inicializar los rectángulos
    for ( i = 0 ; i < 10 ; i++ ) {
        printf("Rectángulo %d:\n", i + 1);
        inicializarRectangulo( &rectangulos[i] );
    }

    // Calcular el área del primer rectángulo como referencia
    menorArea = rectangulos[0].base * rectangulos[0].altura;

    // Encontrar el rectángulo con menor área
    for (i = 1; i < 10; i++) {
        float areaActual = rectangulos[i].base * rectangulos[i].altura;
        
        if (areaActual < menorArea) {
            menorArea = areaActual;
            indiceMenorArea = i;
        }
    }

    // Informar el número del rectángulo con menor área
    printf("El rectángulo con menor área es el número %d con un área de %.2f\n", indiceMenorArea + 1, menorArea);

    return( 0 ) ;
}