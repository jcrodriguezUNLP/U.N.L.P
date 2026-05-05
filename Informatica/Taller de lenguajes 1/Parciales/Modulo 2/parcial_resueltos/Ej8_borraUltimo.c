#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
   int dato;
   struct nodo * sigte;
} lista;

void agregar(lista ** , int);
void verLista(lista * );
int	main(int argc, char * argv[])
{  lista * L=NULL;
   int i;

   for (i=10; i<=100; i=i+10)
        agregar(&L, i);

   verLista(L);

   while (L!=NULL){
     borrarUltimo(&L);
     verLista(L);
   }
   return(0);
}
void agregar(lista ** milista, int nro){
    lista * aux, * auxL;

    aux = malloc(sizeof(lista));
    aux->dato = nro;
    aux->sigte = NULL;

    auxL = *milista;
    if (auxL==NULL)
        *milista = aux;
    else {
       while (auxL->sigte != NULL)
            auxL = auxL->sigte;

       auxL->sigte = aux;
    }
}
void verLista(lista * L){
     while (L!=NULL){
        printf("%d ", L->dato);
        L = L->sigte;
     }
     printf("\n");
}

void borrarUltimo(lista ** milista){
    lista * ant, * auxL;

    auxL = *milista;
    if (auxL!=NULL){
       ant = auxL;
       while (auxL->sigte != NULL){
            ant = auxL;
            auxL = auxL->sigte;
       }
       if (ant==auxL){
           free(ant);
           *milista = NULL;
       }
       else {
           ant->sigte=NULL;
           free(auxL);
       }


    }
}
