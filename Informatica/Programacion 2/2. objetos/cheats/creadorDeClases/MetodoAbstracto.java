public class MetodoAbstracto {
    private String nombre ; // Nombre en Camel Case (Usado en el código Java)
    private String tipo ;
    private String nombreOriginal ; // Nombre ingresado por el usuario (Usado en el menú y comentarios)

    // Constructores
    public MetodoAbstracto( String tipo , String nombre, String nombreOriginal ) { 
        this.nombre = nombre ;
        this.tipo = tipo ;
        this.nombreOriginal = nombreOriginal ;
    }
    
    // Constructor de respaldo
    public MetodoAbstracto( String tipo , String nombre ) { 
        this(tipo, nombre, nombre); 
    }
    
    // Getters
    public String getNombre() {
        return nombre ;
    }

    public String getTipo() {
        return tipo ;
    }
    
    public String getNombreOriginal() {
        return nombreOriginal ;
    }

    // Setters (Necesarios para ModificarClase.java)
    public void setTipo( String tipo ) { this.tipo = tipo ; }

    public void setNombre( String nombre ) { this.nombre = nombre ; }
    
    public void setNombreOriginal( String nombreOriginal ) { this.nombreOriginal = nombreOriginal ; }

    public String generarCodigo() {
        StringBuilder codigo = new StringBuilder() ;

        // Define la firma del método usando el nombre limpio (Camel Case)
        codigo.append( "public " )
              .append( tipo )
              .append( " " )
              .append( nombre ) 
              .append( "()" ) ;

        return codigo.toString() ;
    }
}