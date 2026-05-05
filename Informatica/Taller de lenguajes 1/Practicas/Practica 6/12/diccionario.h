#ifndef DICCIONARIO_H
    #define DICCIONARIO_H

    #include <stdio.h>

    // Estructura para cada palabra (nodo de la lista)
    typedef struct NodoPalabra {
        char* palabra;              // String dinámico
        struct NodoPalabra* sig;    // Puntero al siguiente nodo
    } NodoPalabra;

    // Estructura principal del diccionario
    typedef struct {
        NodoPalabra* cabeza;        // Inicio de la lista
        int cantidad;               // Contador de palabras
    } Diccionario;

    // --- Prototipos de Funciones ---

    // a. Inicializa
    Diccionario* dic_crear();

    // b. Agrega (retorna 1 si agregó, 0 si ya existía o error)
    int dic_agregar(Diccionario* dic, const char* texto);

    // c. Existe (retorna 1 si existe, 0 si no)
    int dic_existe(Diccionario* dic, const char* texto);

    // d. Eliminar (retorna 1 si eliminó, 0 si no existía)
    int dic_eliminar(Diccionario* dic, const char* texto);

    // e. Cargar desde archivo (retorna cant. palabras cargadas)
    int dic_cargar(Diccionario* dic, const char* nombreArchivo);

    // f. Guardar a archivo (retorna 1 si éxito, 0 error)
    int dic_guardar(Diccionario* dic, const char* nombreArchivo);

    // g. Liberar memoria
    void dic_destruir(Diccionario* dic);

    // Extra: Imprimir para debug
    void dic_imprimir(Diccionario* dic);

#endif // DICCIONARIO_H