#include <stdio.h>
#include <math.h>
enum opciones {CUAD, CIRC, RECT};
struct figGeom {
   enum opciones tipo;
   union uFig {
      unsigned radio;
      unsigned lado;
      struct fRec {
         unsigned short int base;
         unsigned short int altura;
      } rec;
   } figura;
};
void verFiguras(struct figGeom [], int);
int main(){
    struct figGeom V[3];

    V[0].tipo = CUAD;
    V[0].figura.lado = 2;

    V[1].tipo = RECT;
    V[1].figura.rec.base = 2;
    V[1].figura.rec.altura = 5;

    V[2].tipo = CIRC;
    V[2].figura.radio = 4;

    verFiguras(V,3);
    return 0;
}

void verFiguras(struct figGeom V[], int cant)
{   int i;
    for (i=0; i<cant; i++)
      switch (V[i].tipo)
      {  case CUAD:
            printf("%d - CUADRADO - %d\n", i, 4*V[i].figura.lado);
          break;
         case CIRC:
            printf("%d - CIRCUNFERENCIA - %f\n", i, 2*M_PI*V[i].figura.radio);
         break;
         case RECT:
            printf("%d - RECTANGULO - %d\n", i,
                   2*V[i].figura.rec.base+2*V[i].figura.rec.altura);

      }
}