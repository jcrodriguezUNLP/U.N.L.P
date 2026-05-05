// Analice y ejecute el siguiente código:

#include <stdio.h> 
#include <stdlib.h> 

#define DEBUG 0
 
int main(){ 
    int x = 15 ; 
    int y = 0  ;        // Variable usada solo en modo DEBUG debe declararse siempre
                        // declarada por mi para q no de error de compilacion
 
    while( x < 50 ){ 
        #if DEBUG 
            printf( "x = %d" , x ) ; 
            y = ( y + 1 ) ; 
        #endif 
        
        x++ ; 
    } 
    
    return( 0 ) ; 
} 

// A)
//     ¿El código compila?
//          Si
//     ¿Por qué?
//          ya que DEBUG es igual a 0 por lo que el bloque dentro del #if no se toma en cuenta y el no ve la variable y sin declarar.
// B)
//     ¿Qué sucedería al cambiar la constante simbólica DEBUG al valor 1?
//          DEBUG != 0 por lo que el bloque dentro del #if se toma en cuenta. variable y no declarada por lo tanto da error de compilación.
//     Evalúe el comportamiento del código
//     ¿Qué beneficios trae en este caso la compilación condicional?
//          Permite incluir o excluir partes del código dependiendo de ciertas condiciones, en este caso permite incluir código de depuración solo cuando se necesita, evitando así errores de compilación cuando no se usa.
// C)
//     ¿Es posible cambiar el valor de la constante simbólica DEBUG en tiempo de ejecución?
//          No, las constantes simbólicas definidas con #define son procesadas por el preprocesador antes de la compilación y no pueden cambiarse en tiempo de ejecución. 
// D)
//     ¿Qué sucede si en lugar de utilizar la directiva #if se emplea #ifdef?
//          #ifdef verifica si la macro está definida, independientemente de su valor. Si DEBUG está definido (sin importar si es 0 o 1), el bloque se incluirá en la compilación.
//     ¿Incide el valor de la constante simbólica DEBUG en el resultado de la compilación?
//          No, con #ifdef solo importa si DEBUG está definido o no, no su valor.