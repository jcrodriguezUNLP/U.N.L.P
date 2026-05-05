public class Nodo {
    String  id     ;
    Boolean active ;

    // Constructores
        public Nodo( String id , Boolean active ) {
            this.id     = id     ;
            this.active = active ;
        }
    //

    // Getters
        public String  getId()     { return( id     ) ; }
        public Boolean getActive() { return( active ) ; }
    //

    // Metodos
        public Boolean isActive() { return( active ) ; }
    //
    
}
