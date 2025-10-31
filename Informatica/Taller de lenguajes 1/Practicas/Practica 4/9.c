// Indique para cada arreglo definido: 
// a. ¿Qué tipo de arreglo se está utilizando (estático/dinámico/de longitud variable)? 
// b. ¿En qué momento se determina cuánta memoria se va a reservar (compilación/ejecución)? 
// c. ¿Cuál es el límite de tamaño de cada tipo de arreglo? 
// d. ¿Se puede cambiar el tamaño en ejecución? 
// e. ¿Se puede liberar la memoria reservada? 
// f. ¿El nombre del arreglo puede apuntar a otra dirección? 
// g. ¿Todos los códigos compilan de acuerdo a ANSI C90?

// Código 1:

#include <stdio.h> 
#include <stdlib.h> 
#define N 50 

int main() { 
    int arreglo1[N]; 
    return 0; 
}


// Código 2:

#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int n; 
    scanf("%d",&n);  
    /* el usuario ingresa 50 */ 
    int arreglo2[n]; 
    return 0; 
} 


// Código 3:  

#include <stdio.h> 
#include <stdlib.h> 
#define N 50 
 
int main() { 
    int * arreglo3 = (int *) malloc (N*sizeof(int)); 
    
    return 0; 
} 
 