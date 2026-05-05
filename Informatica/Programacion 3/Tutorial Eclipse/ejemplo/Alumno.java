// ==============================================================================
//   [A] CLASE: Alumno
//    estado (Atributos Privados / Encapsulamiento Estricto):
//      - legajo.
//      - nombre.
//      - apellido.
//      - dni.
//      - email.
//    comportamiento (Métodos):
//      - Constructor(): Inicializa estado por defecto / Instanciación mediante new.
//      - tusDatos(): retorne un String con los datos de los atributos.
//    restricciones:
//      - Los atributos deben ser 'private' (Regla Arquitectónica).
//      - Implementar getters y setters por exigencia de la cátedra.
// ==============================================================================

public class Alumno {
    private String legajo   ;
    private String nombre   ;
    private String apellido ;
    private int    dni      ;
    private String email    ;

    // Constructores
        public Alumno() {}

        public Alumno( String legajo , String nombre , String apellido , int dni , String email ) {
            this.legajo   = legajo   ;
            this.nombre   = nombre   ;
            this.apellido = apellido ;
            this.dni      = dni      ;
            this.email    = email    ;
        }
    //

    // Getters
        public String getLegajo() { return( legajo ) ; }

        public String getNombre() { return( nombre ) ; }

        public String getApellido() { return( apellido ) ; }

        public int getDni() { return( dni ) ; }

        public String getEmail() { return( email ) ; }
    //

    // Setters
        public void setLegajo( String legajo ) { this.legajo = legajo ; }

        public void setNombre( String nombre ) { this.nombre = nombre ; }

        public void setApellido( String apellido ) { this.apellido = apellido ; }

        public void setDni( int dni ) { this.dni = dni ; }

        public void setEmail( String email ) { this.email = email ; }
    //

    // Métodos
        public String tusDatos() {
            String texto = "" ;

            texto += ( "\n" + "legajo: "   + legajo   ) ;
            texto += ( "\n" + "nombre: "   + nombre   ) ;
            texto += ( "\n" + "apellido: " + apellido ) ;
            texto += ( "\n" + "dni: "      + dni      ) ;
            texto += ( "\n" + "email: "    + email    ) ;

            return( texto ) ;
        }

        @Override
        public String toString() {
            return( this.tusDatos() ) ;
        }

        @Override
        public boolean equals( Object obj ) {

            // --- 2. PROCESAMIENTO ---
            if ( this == obj ) { return( true ) ; }
            
            if ( obj == null ) { return( false ) ; }
            
            if ( this.getClass() == obj.getClass() ) {
                Alumno otro = (Alumno) obj ;
                
                // Comparamos por el atributo único que define a un alumno (dni)
                if ( this.dni == otro.getDni() ) {
                    return( true ) ;
                }
            }

            return( false ) ;
        }
    //
}