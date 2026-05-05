public class Variable {
    private String tipo ;
    private String nombre ; // Nombre en Camel Case (Usado en el código Java)
    private String nombreOriginal ; // Nombre ingresado por el usuario (Usado en toString)

    // Constructores
    public Variable() {}

    public Variable( String tipo , String nombre , String nombreOriginal ) {
        this.tipo = tipo ;
        this.nombre = nombre ;
        this.nombreOriginal = nombreOriginal ; 
    }
    
    // Constructor de respaldo (asume que nombre original es igual a nombre limpio)
    public Variable( String tipo , String nombre ) { 
        this(tipo, nombre, nombre); 
    }
    //

    // Getters
    public String getTipo() { return tipo ; }

    public String getNombre() { return nombre ; }

    public String getNombreOriginal() { return nombreOriginal ; } 
    //

    // Setters (Necesarios para ModificarClase.java)
    public void setTipo( String tipo ) { this.tipo = tipo ; }

    public void setNombre( String nombre ) { this.nombre = nombre ; }
    
    public void setNombreOriginal( String nombreOriginal ) { this.nombreOriginal = nombreOriginal ; }
    //
}