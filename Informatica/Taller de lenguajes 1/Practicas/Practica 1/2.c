// Investigue los diferentes tipos de datos del lenguaje C y luego responda: 
//      a.
//          ¿Qué ocurre cuando asignamos un char a un int? ¿y al revés?
//              - char a int: Se realiza una extensión automática. El valor ASCII del char 
//                  se convierte al entero correspondiente (ej: 'a' = 97).
//              - int a char: Se toma solo el byte menos significativo del int.
//                  Si el int > 255, se produce overflow y se pierde información.
//          Ejecute el siguiente código y analice lo que imprime.
//                  - El código imprime:
//                      char c = @ (ASCII 64)
//                      int  x = 97 (ASCII de 'a')
//              ¿Se presenta algún warning al compilar?
//                  - Warnings: Algunos compiladores pueden mostrar warnings sobre conversión
//                      implícita de tipos, especialmente si se habilitan con -Wall.

//      b.
//          ¿Qué  diferencia  existe  entre  los  tipos  float  y  double?
//              - float: Precisión simple (32 bits), aproximadamente 7 dígitos decimales
//              - double: Precisión doble (64 bits), aproximadamente 15-17 dígitos decimales
//          ¿se  puede  asignar  entre  si  sin inconvenientes? 
//              - Asignación float a double: Sin problemas, se extiende automáticamente
//              - Asignación double a float: Puede haber pérdida de precisión, algunos compiladores pueden mostrar warnings 

//      c.
//          ¿Qué sucede cuando en una operación intervienen operadores diferentes?  
//              Por ejemplo: x = 2*32+10%2-1;
//              - Se aplican las reglas de precedencia de operadores y promoción de tipos
//              - Precedencia: multiplicación (*) y módulo (%) antes que suma (+) y resta (-)
//              - El ejemplo se evalúa como: x = (2*32) + (10%2) - 1 = 64 + 0 - 1 = 63
//              - Si hay tipos mixtos, se promocionan automáticamente al tipo "más grande"
//              - Orden de precedencia: %, *, / (igual precedencia) → +, - (igual precedencia) 
//              x = 2*32+10%2-1
//              x = (2*32) + (10%2) - 1
//              x = 64 + 0 - 1
//              x = 63
//      d. 
//          Investigue el operador sizeof.
//              ¿Para qué sirve?
//                  - sizeof: Operador que devuelve el tamaño en bytes de un tipo de dato o variable
//                  - Se evalúa en tiempo de compilación, no en tiempo de ejecución
//                  - Sintaxis: sizeof(tipo) o sizeof(variable)
//                  - Útil para asignación dinámica de memoria y portabilidad 
//              Luego aplíquelo y verifique el tamaño de los distintos tipos de datos en su máquina. 
//                  * char       :  1 byte
//                  * short      :  2 bytes
//                  * int        :  4 bytes
//                  * long       :  4 bytes
//                  * long long  :  8 bytes
//                  * float      :  4 bytes
//                  * double     :  8 bytes
//                  * long double: 16 bytes


#include <stdio.h> 

int main(){ 
    char c = 'a' ; 
    int  x = 64  ; 
    
    printf( "char c = %c\n" , x ) ; 
    printf( "int  x = %d\n" , c ) ;

    printf( "\nmemoria reservada por cada tipo de dato:\n\n" ) ;
    
    printf( "    sizeof( char          ) = %zu byte\n" , sizeof( char          ) ) ;
    printf( "    sizeof( unsigned char ) = %zu byte\n" , sizeof( unsigned char ) ) ;
    
    printf( "\n    tipos enteros:\n" ) ;
    
    printf( "        sizeof( short              ) = %zu bytes\n" , sizeof( short              ) ) ;
    printf( "        sizeof( unsigned short     ) = %zu bytes\n" , sizeof( unsigned short     ) ) ;
    printf( "        sizeof( int                ) = %zu bytes\n" , sizeof( int                ) ) ;
    printf( "        sizeof( unsigned int       ) = %zu bytes\n" , sizeof( unsigned int       ) ) ;
    printf( "        sizeof( long               ) = %zu bytes\n" , sizeof( long               ) ) ;
    printf( "        sizeof( unsigned long      ) = %zu bytes\n" , sizeof( unsigned long      ) ) ;
    printf( "        sizeof( long long          ) = %zu bytes\n" , sizeof( long long          ) ) ;
    printf( "        sizeof( unsigned long long ) = %zu bytes\n" , sizeof( unsigned long long ) ) ;
   
    printf( "\n    tipos float:\n" ) ;
   
    printf( "        sizeof( float       ) = %2zu bytes\n" , sizeof( float      ) ) ;
    printf( "        sizeof( double      ) = %2zu bytes\n" , sizeof( double     ) ) ;
    printf( "        sizeof( long double ) = %2zu bytes\n" , sizeof( long double) ) ;

    return( 0 ) ; 
} 