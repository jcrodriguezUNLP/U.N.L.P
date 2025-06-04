public class Estudiante {
    private String nombre ;
    private String apellido ;
    private int comision ;
    private String email ;
    private String direccion ;

    // Constructores
        public Estudiante() {}

        public Estudiante( String nombre , String apellido , int comision , String email , String direccion ) {
            this.nombre = nombre ;
            this.apellido = apellido ;
            this.comision = comision ;
            this.email = email ;
            this.direccion = direccion ;
        }
    //

    // Getters
        public String getNombre() { return( nombre ) ; }

        public String getApellido() { return( apellido ) ; }

        public int getComision() { return( comision ) ; }

        public String getEmail() { return( email ) ; }

        public String getDireccion() { return( direccion ) ; }
    //

    // Setters
        public void setNombre( String nombre ) { this.nombre = nombre ; }

        public void setApellido( String apellido ) { this.apellido = apellido ; }

        public void setComision( int comision ) { this.comision = comision ; }

        public void setEmail( String email ) { this.email = email ; }

        public void setDireccion( String direccion ) { this.direccion = direccion ; }
    //

    // Métodos
        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + Sangria.sangria( 1 ) + "nombre: " + nombre ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "apellido: " + apellido ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "comision: " + comision ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "email: " + email ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "direccion: " + direccion ) ;

            return( texto ) ;
        }
    //
}