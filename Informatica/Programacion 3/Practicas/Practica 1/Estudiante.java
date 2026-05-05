// ==============================================================================
// CLASE: Estudiante - Representación de un alumno de la facultad
// ==============================================================================
//   estado (Atributos):
//     - String nombre: nombre del alumno.
//     - String apellido: apellido del alumno.
//     - String comision: identificador de la comisión.
//     - String email: correo electrónico institucional.
//     - String direccion: domicilio del alumno.
//   comportamiento (Métodos):
//     - tusDatos(): concatena y retorna la información del alumno.
//     - equals( Object ): compara estudiantes por su email.
//   restricciones:
//     - Encapsulamiento estricto (private).
//     - Uso obligatorio de this. para desambiguar parámetros.
// ==============================================================================

public class Estudiante {
    
    private String nombre    ;
    private String apellido  ;
    private String comision  ;
    private String email     ;
    private String direccion ;

    // constructores
        public Estudiante() {
        }

        public Estudiante( String nombre , String apellido , String comision , String email , String direccion ) {
            this.nombre    = nombre    ;
            this.apellido  = apellido  ;
            this.comision  = comision  ;
            this.email     = email     ;
            this.direccion = direccion ;
        }
    //

    // getters
        public String getNombre()    { return( nombre    ) ; }
        public String getApellido()  { return( apellido  ) ; }
        public String getComision()  { return( comision  ) ; }
        public String getEmail()     { return( email     ) ; }
        public String getDireccion() { return( direccion ) ; }
    //

    // setters
        public void setNombre( String nombre ) {
            this.nombre = nombre ;
        }

        public void setApellido( String apellido ) {
            this.apellido = apellido ;
        }

        public void setComision( String comision ) {
            this.comision = comision ;
        }

        public void setEmail( String email ) {
            this.email = email ;
        }

        public void setDireccion( String direccion ) {
            this.direccion = direccion ;
        }
    //

    // metodos
        public String tusDatos() {
            String texto = "" ;

            texto += ( "\n" + "nombre: "    + nombre    ) ;    
            texto += ( "\n" + "apellido: "  + apellido  ) ;
            texto += ( "\n" + "comision: "  + comision  ) ;
            texto += ( "\n" + "email: "     + email     ) ;      
            texto += ( "\n" + "direccion: " + direccion ) ;

            return( texto ) ;
        }

        @Override
        public boolean equals( Object obj ) {
            if ( this == obj ) {
                return( true ) ;
            }
            
            if ( obj == null ) {
                return( false ) ;
            }
            
            if ( getClass() == obj.getClass() ) {
                Estudiante otro = (Estudiante) obj ;
                
                if ( email.equals( otro.getEmail() ) ) {
                    return( true ) ;
                }
            }

            return( false ) ;
        }
    //
}
