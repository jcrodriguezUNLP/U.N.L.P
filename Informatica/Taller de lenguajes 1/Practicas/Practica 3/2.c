// En el primer bloque de código:
// Se define una estructura llamada "persona" con dos campos: "nombre" (un arreglo de 50 caracteres) y "DNI" (un entero largo).
// Además, se declara una variable de tipo "struct persona" llamada "unaPersona".
// Finalmente, se utiliza "typedef" para crear un alias "persona_t" que equivale a "struct persona".

struct persona {
    char nombre[50] ;
    long int DNI ;
} unaPersona ;

typedef struct persona persona_t;

// En el segundo bloque de código:
// Se define una estructura llamada "persona" con los mismos campos que en el primer bloque.
// Sin embargo, aquí no se declara ninguna variable directamente.
// Se utiliza "typedef" para crear un alias "persona_t" que equivale a "struct persona".
// Esto simplifica el uso del tipo, ya que no es necesario escribir "struct" al declarar variables de este tipo.

typedef struct persona {
    char nombre[50];
    long int DNI;
} persona_t;

// Diferencias entre ambos bloques:
// 1. En el primer bloque, se declara una variable "unaPersona" de tipo "struct persona".
// 2. En el segundo bloque, no se declara ninguna variable directamente.
// 3. Ambos bloques definen un alias "persona_t" para simplificar el uso de "struct persona".