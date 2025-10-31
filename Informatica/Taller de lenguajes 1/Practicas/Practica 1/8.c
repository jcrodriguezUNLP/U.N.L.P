// Identifique y corrija los errores en cada uno de los siguientes códigos
// Puede haber más de uno.

#include <stdio.h>

int main() {
    // a.
        int edad ;
        
        if( edad >= 40 ) ; 
            printf( "Tiene %d años o más" , &40 ) ; 
        else 
            printf( "Tiene menos de %d años" , &40 ) ;
    
        // explicación de los errores:
        // 1. La variable 'edad' no está inicializada antes de usarse en la condición if.
        //    Se debe leer un valor para 'edad' usando scanf.
        // 2. Hay un punto y coma (;) después de la condición if, lo que termina la instrucción if prematuramente.
        //    Esto hace que el bloque if siempre se ejecute, independientemente de la condición
        // 3. En los printf, se está usando '&40' en lugar de '40'. El operador '&' obtiene la dirección de memoria,
        //    pero aquí se quiere imprimir el valor literal 40.
        //    como es constante, no es necesario usar un especificador de formato con variable.
        //    Debería ser simplemente '40'.
        // 4. Falta un salto de línea '\n' al final de los mensajes para mejor formato en la salida.
        // 5. Aunque no es un error, es buena práctica usar llaves {} para delimitar los bloques if y else, incluso si contienen una sola línea.
        //    Esto mejora la legibilidad y evita errores si se agregan más líneas en el futuro.

        // corrección:
        int edad ;

        scanf( "%d" , &edad ) ;

        if( 40 <= edad ) { 
            printf( "Tiene 40 años o más\n" ) ; 
        } else { 
            printf( "Tiene menos de 40 años\n" ) ;
        }
 
    // b.
        int total ;

        int x = 1 ;

        while( x <= 10 ) { 
            total += x ;
            
            ++x ; 
        }

        printf( "Total = %f" , total ) ; 
        
        // explicación de los errores:
        // 1. La variable 'total' no está inicializada antes de usarse.
        // 2. El formato de printf para 'total' es incorrecto. 'total' es un entero, no un flotante.
        //    Debería usar '%d' en lugar de '%f'.
        // 3. Falta un salto de línea '\n' al final del mensaje para mejor formato en la salida.
        // 4. Aunque no es un error, es buena práctica usar llaves {} para delimitar los bloques while, incluso si contienen una sola línea.
        //    Esto mejora la legibilidad y evita errores si se agregan más líneas en el futuro.

        // corrección:
        int total = 0 ;
        int     x = 1 ;

        while( x <= 10 ) { 
            total += x ;
            
            ++x ; 
        }

        printf( "Total = %d\n" , total ) ;

    // c.
        int valor ;

        scanf( "%d" , &valor ) ;

        switch( valor % 2 ) { 
            case 0:
                printf( "El valor es par" ) ; 
            case 1:
                printf( "El valor es impar" ) ;    
        }
        
        // explicación de los errores:
        // 1. Falta la instrucción 'break;' al final de cada caso en el switch.
        //    Sin los 'break;', si se cumple un caso, se ejecutarán todos los casos siguientes (fallthrough).
        //    Esto significa que si 'valor' es par, también imprimirá "El valor es impar".
        // 2. Falta un salto de línea '\n' al final de los mensajes para mejor formato en la salida.
        // 3. Aunque no es un error, sería más claro usar 'default' para manejar cualquier otro caso inesperado.
        //    En este caso no es estrictamente necesario porque el módulo 2 solo puede dar 0 o 1, pero es una buena práctica.

        // correcion: 
        int valor ;

        scanf( "%d" , &valor ) ;

        switch( valor % 2 ) { 
            case 0:
                printf( "El valor es par\n" ) ; 
                break ;
            case 1:
                printf( "El valor es impar\n" ) ;
                break ;
            default:
                printf( "Valor inesperado\n" ) ;
                break ; 
        }


    // d.
        int x ;
        int y ; 

        scanf( "%d" , x ) ; 
        scanf( "%d" , y ) ;

        printf( "x + y = %d " , x + y ) ;

    return( 0 ) ;
}