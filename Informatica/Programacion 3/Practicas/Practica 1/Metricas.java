// ==============================================================================
// CLASE: Metricas - Contenedor de resultados estadísticos
// ==============================================================================
//   estado (Atributos):
//     - int maximo: valor máximo encontrado.
//     - int minimo: valor mínimo encontrado.
//     - double promedio: valor promedio calculado.
//   comportamiento (Métodos):
//     - Getters y Setters para cada atributo.
//   restricciones:
//     - Encapsulamiento estricto (private).
//     - Uso obligatorio de this. para desambiguar parámetros.
// ==============================================================================

public class Metricas {

    private int    maximo   ;
    private int    minimo   ;
    private double promedio ;

    // constructores
        public Metricas() {
            maximo   = Integer.MIN_VALUE ;
            minimo   = Integer.MAX_VALUE ;
            promedio = 0.0               ;
        }
    //

    // getters
        public int    getMaximo()   { return( maximo   ) ; }
        public int    getMinimo()   { return( minimo   ) ; }
        public double getPromedio() { return( promedio ) ; }
    //

    // setters
        public void setMaximo( int maximo ) {
            this.maximo = maximo ;
        }

        public void setMinimo( int minimo ) {
            this.minimo = minimo ;
        }

        public void setPromedio( double promedio ) {
            this.promedio = promedio ;
        }
    //

    // metodos
    //
}
