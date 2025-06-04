// 16
    void swap( int (*a) , int (*b) );

    int main() {
        int x, y;

        x = 10;
        y = 20;

        printf("x = %d\n" , x ) ;
        printf("y = %d\n" , y ) ;

        swap( &x , &y ) ;

        printf( "\n" ) ;

        printf("x = %d\n" , x ) ;
        printf("y = %d\n" , y ) ;

        return 0 ;
    }

    void swap( int (*a) , int (*b) ){
        int tmp;

        tmp = (*a) ; // guarda el valor de a
        (*a) = (*b) ;   // almacena b en a
        (*b) = tmp ; // almacena a en b
    }


/*

















// 17

// 18

// 19

// 20
*/
/* Explicacion de random
    #include <time.h>
    srand( time(null) ) ;
    rand()%20; // numero entero 0 - RAND_MAX=20
*/
