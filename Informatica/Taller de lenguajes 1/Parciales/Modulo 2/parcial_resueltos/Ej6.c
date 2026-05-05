#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char * argv[])
{   int i;
    if (argc==1)
        printf("Ingrese al menos una palabra");
    else
       printf("Se ingresaron %d palabras\n", argc-1);
       for(i=1; i<argc; i++)
           printf("%s ",argv[i]);
    return 0;
}
