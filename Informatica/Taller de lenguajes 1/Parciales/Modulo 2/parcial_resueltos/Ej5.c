#include <stdio.h>
struct destino {
   int codProv;
   int codLoc;
   char nomLoc[30];
   int nHab;
};
typedef struct destino TipoDest;

int	main()
{   FILE * archT, * archB;
    TipoDest D, aux;

    archT = fopen("c:/TL1/Habitantes.txt", "r");
    archB = fopen("c:/TL1/Habitantes.dat", "wb+");

    if ((archT==NULL) || (archB==NULL)){
        printf("Error con los archivos");
        return(-1);
    }
    else {
       fscanf(archT, "%d %d %s %d", &D.codLoc, &D.codProv, D.nomLoc, &D.nHab);
       while (!feof(archT)){
           printf("%d %d %s %d\n", D.codLoc, D.codProv, D.nomLoc, D.nHab);
           fwrite(&D, sizeof(D),1,archB);
           fscanf(archT, "%d %d %s %d", &D.codLoc, &D.codProv, D.nomLoc, &D.nHab);
       }


       aux.nHab = 0;
       fseek(archB, 0, SEEK_SET);
       fread(&D, sizeof(D),1,archB);

       while(!feof(archB)){
          if (D.nHab>aux.nHab)
            aux = D;
          fread(&D, sizeof(D),1,archB);
       }
       printf("Loc %d  %s tiene %d hab.", aux.codLoc, aux.nomLoc, aux.nHab);

       fclose(archT);
       fclose(archB);
       return(0);
    }
}

