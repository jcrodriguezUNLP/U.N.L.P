// ==============================================================================
// CLASE: Profesor - Representación de un docente de la facultad
// ==============================================================================
//   estado (Atributos):
//     - String nombre: nombre del docente.
//     - String apellido: apellido del docente.
//     - String email: correo electrónico institucional.
//     - String catedra: nombre de la cátedra a la que pertenece.
//     - String facultad: nombre de la facultad.
//   comportamiento (Métodos):
//     - tusDatos(): concatena y retorna la información del docente.
//   restricciones:
//     - Encapsulamiento estricto (private).
// ==============================================================================

public class Profesor {
    private String nombre   ;
    private String apellido ;
    private String email    ;
    private String catedra  ;
    private String facultad ;

    // constructores
        public Profesor() {
        }

        public Profesor( String nombre , String apellido , String email , String catedra , String facultad ) {
            this.nombre   = nombre   ;
            this.apellido = apellido ;
            this.email    = email    ;
            this.catedra  = catedra  ;
            this.facultad = facultad ;
        }
    //

    // getters
        public String getNombre()   { return( nombre   ) ; }
        public String getApellido() { return( apellido ) ; }
        public String getEmail()    { return( email    ) ; }
        public String getCatedra()  { return( catedra  ) ; }
        public String getFacultad() { return( facultad ) ; }
    //

    // setters
        public void setNombre( String nombre ) {
            this.nombre = nombre ;
        }

        public void setApellido( String apellido ) {
            this.apellido = apellido ;
        }

        public void setEmail( String email ) {
            this.email = email ;
        }

        public void setCatedra( String catedra ) {
            this.catedra = catedra ;
        }

        public void setFacultad( String facultad ) {
            this.facultad = facultad ;
        }
    //

    // metodos
        public String tusDatos() {
            String texto = "" ;

            texto += ( "\n" + "nombre: "   + nombre   ) ;    
            texto += ( "\n" + "apellido: " + apellido ) ;
            texto += ( "\n" + "email: "    + email    ) ;      
            texto += ( "\n" + "catedra: "  + catedra  ) ;  
            texto += ( "\n" + "facultad: " + facultad ) ;

            return( texto ) ;
        }
    //
}
