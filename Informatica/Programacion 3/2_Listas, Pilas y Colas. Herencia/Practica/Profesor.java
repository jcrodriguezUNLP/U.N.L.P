public class Profesor {
    private String nombre ;
    private String apellido ;
    private String email ;
    private int catedra ;
    private String facultad ;

    // Constructores
        public Profesor() {}

        public Profesor( String nombre , String apellido , String email , int catedra , String facultad ) {
            this.nombre = nombre ;
            this.apellido = apellido ;
            this.email = email ;
            this.catedra = catedra ;
            this.facultad = facultad ;
        }
    //

    // Getters
        public String getNombre() { return( nombre ) ; }

        public String getApellido() { return( apellido ) ; }

        public String getEmail() { return( email ) ; }

        public int getCatedra() { return( catedra ) ; }

        public String getFacultad() { return( facultad ) ; }
    //

    // Setters
        public void setNombre( String nombre ) { this.nombre = nombre ; }

        public void setApellido( String apellido ) { this.apellido = apellido ; }

        public void setEmail( String email ) { this.email = email ; }

        public void setCatedra( int catedra ) { this.catedra = catedra ; }

        public void setFacultad( String facultad ) { this.facultad = facultad ; }
    //

    // Métodos
        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + Sangria.sangria( 1 ) + "nombre: " + nombre ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "apellido: " + apellido ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "email: " + email ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "catedra: " + catedra ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "facultad: " + facultad ) ;

            return( texto ) ;
        }
    //
}
