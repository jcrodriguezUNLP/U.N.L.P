public abstract class Persona {
    private String nombre ;
    private String apellido ;

    // Constructores
    public Persona() {}

    public Persona( String nombre , String apellido ) {
        this.nombre = nombre ;
        this.apellido = apellido ;
    }
    //

    // Getters
    public String getNombre() { return( nombre ) ; }
    public String getApellido() { return( apellido ) ; }
    //

    // Setters
    public void setNombre( String nombre ) { this.nombre = nombre ; }
    public void setApellido( String apellido ) { this.apellido = apellido ; }
    //

    // Métodos

    public abstract void comer() ;

    @Override
    public String toString() {
        String texto = "" ;
        texto += ( "\n" + Sangria.sangria( 1 ) + "nombre: " + nombre ) ;
        texto += ( "\n" + Sangria.sangria( 1 ) + "apellido: " + apellido ) ;

        return( texto ) ;
    }
    //
}
