import java.util.ArrayList;
import java.util.List;

class Clase {
    private String                nombre            ;
    private boolean               esAbstracta       ;
    private Clase                 claseBase         ;
    private List<Variable>        variablesPropias  ;
    private List<MetodoAbstracto> metodosAbstractos ;

    // Constructores
    public Clase() {
        this.variablesPropias  = new ArrayList<>();
        this.metodosAbstractos = new ArrayList<>();
    }

    public Clase( String nombre , boolean esAbstracta , Clase claseBase , List<Variable> variablesPropias , List<MetodoAbstracto> metodosAbstractos ) {
        this.nombre = nombre ;
        this.esAbstracta = esAbstracta ;
        this.claseBase = claseBase ;
        this.variablesPropias = variablesPropias ;
        this.metodosAbstractos = metodosAbstractos ;
    }
    //

    // Getters
    public String getNombre() { return nombre ; }

    public boolean getEsAbstracta() { return esAbstracta ; }

    public Clase getClaseBase() { return claseBase ; }

    public List<Variable> getVariablesPropias() {
        return variablesPropias ;
    }

    public List<MetodoAbstracto> getMetodosAbstractos() {
        return metodosAbstractos ;
    }

    public List<Variable> getVariablesHeredadas() {
        List<Variable> variablesHeredadas = new ArrayList<>() ;

        if( claseBase != null ) {
            // Recursivamente obtener variables de la cadena de herencia
            variablesHeredadas.addAll( claseBase.getVariablesHeredadas() ) ;
            variablesHeredadas.addAll( claseBase.getVariablesPropias() ) ;
        }
        
        return variablesHeredadas ;
    }

    public List<MetodoAbstracto> getMetodosAbstractosHeredados() {
        List<MetodoAbstracto> metodosAbstractosHeredados = new ArrayList<>() ;
        if( claseBase != null ) {
            metodosAbstractosHeredados.addAll( claseBase.getMetodosAbstractosHeredados() ) ;
            metodosAbstractosHeredados.addAll( claseBase.getMetodosAbstractos() ) ;
        }
        return metodosAbstractosHeredados ;
    }
    //

    // --- Setters (Añadidos para ModificarClase) ---
    public void setNombre(String nombre) { 
        this.nombre = nombre; 
    }

    public void setEsAbstracta(boolean esAbstracta) { 
        this.esAbstracta = esAbstracta; 
    }
    // --- Fin Setters ---


    public String generarCodigo() {
        StringBuilder codigo = new StringBuilder() ;

        // Definir la clase
        codigo.append( "public " ) ;
        if( esAbstracta ) {
            codigo.append( "abstract " ) ;
        }
        codigo.append( "class " ).append( nombre ) ;
        if( claseBase != null ) {
            codigo.append( " extends " ).append( claseBase.getNombre() ) ;
        }
        codigo.append( " {\n" ) ;

        // Declarar variables propias
        for( Variable var : variablesPropias ) {
            codigo.append( Sangria.sangria( 1 ) + "private " )
                  .append( var.getTipo() )
                  .append( " " )
                  .append( var.getNombre() )
                  .append( " ;\n" ) ;
        }

        // --- Constructores ---
        codigo.append( "\n" + Sangria.sangria( 1 ) + "// Constructores" ) ;
        codigo.append( "\n" + Sangria.sangria( 1 ) + "public " ).append( nombre ).append( "() {}" + "\n" ) ;

        // Constructor Completo (con corrección de la coma)

        // 1. Unir variables heredadas y propias para gestionar la coma
        List<Variable> todosLosParametros = new ArrayList<>();
        todosLosParametros.addAll(getVariablesHeredadas());
        todosLosParametros.addAll(variablesPropias);
        
        codigo.append( "\n" + Sangria.sangria( 1 ) + "public " ).append( nombre ).append( "( " ) ;

        for( int i = 0 ; i < todosLosParametros.size() ; i++ ) {
            Variable var = todosLosParametros.get( i ) ;
            codigo.append( var.getTipo() )
                  .append( " " )
                  .append( var.getNombre() ) ;
            
            if( i < todosLosParametros.size() - 1 ) { // Corrección: solo añade coma si no es el último parámetro
                codigo.append( " , " ) ;
            }
        }
        
        codigo.append( " ) {\n" ) ;

        // Llamada al constructor de la clase base si existe
        if( claseBase != null ) {
            codigo.append( Sangria.sangria( 2 ) + "super( " ) ;
            for( int i = 0 ; i < getVariablesHeredadas().size() ; i++ ) {
                Variable var = getVariablesHeredadas().get( i ) ;
                codigo.append( var.getNombre() ) ;
                if( i < getVariablesHeredadas().size() - 1 ) {
                    codigo.append( " , " ) ;
                }
            }
            codigo.append( " ) ;" + "\n" ) ;
        }

        // Asignación de las variables propias
        for( Variable var : variablesPropias ) {
            codigo.append( Sangria.sangria( 2 ) + "this." )
                  .append( var.getNombre() )
                  .append( " = " )
                  .append( var.getNombre() )
                  .append( " ;\n" ) ;
        }
        codigo.append( Sangria.sangria( 1 ) + "}" ) ;
        codigo.append( "\n" + Sangria.sangria( 1 ) + "//" + "\n" ) ;
        // --- Fin Constructores ---

        // --- Getters ---
        codigo.append( "\n" + Sangria.sangria( 1 ) + "// Getters" ) ;

        for( Variable var : variablesPropias ) {
            codigo.append( "\n" + Sangria.sangria( 1 ) + "public " )
                  .append( var.getTipo() )
                  .append( " get" )
                  .append( Capitalize.capitalize( var.getNombre() ) )
                  .append( "() { return( " )
                  .append( var.getNombre() )
                  .append( " ) ; }" )
                  .append( "\n" ) ;
        }
        codigo.append( Sangria.sangria( 1 ) + "//\n" ) ;
        // --- Fin Getters ---

        // --- Setters ---
        codigo.append( "\n" + Sangria.sangria( 1 ) + "// Setters" ) ;
        
        for( Variable var : variablesPropias ) {
            codigo.append( "\n" + Sangria.sangria( 1 ) + "public void set" )
                  .append( Capitalize.capitalize( var.getNombre() ) )
                  .append( "( " )
                  .append( var.getTipo() )
                  .append( " " )
                  .append( var.getNombre() )
                  .append( " ) { this." )
                  .append( var.getNombre() )
                  .append( " = " )
                  .append( var.getNombre() )
                  .append( " ; }" )
                  .append( "\n" ) ;
        }
        codigo.append( Sangria.sangria( 1 ) + "//\n" ) ;
        // --- Fin Setters ---

        // --- Métodos Abstractos (Implementación y Declaración) ---
        codigo.append( "\n" + Sangria.sangria( 1 ) + "// Métodos" ) ;

        // Implementación de métodos abstractos heredados (si la clase NO es abstracta)
        if (!esAbstracta) {
             for( MetodoAbstracto metodo : getMetodosAbstractosHeredados() ) {
                codigo.append( "\n" + Sangria.sangria( 1 )+ "@Override\n" )
                      .append( Sangria.sangria( 1 ) + metodo.generarCodigo() )
                      .append( " {" )
                      .append( "\n" )
                      .append( Sangria.sangria( 2 ) )
                      .append( "/* Lógica para implementar " + metodo.getNombre() + " */" )
                      .append( "\n" ) ;

                // Si no es void, añadir un retorno de placeholder
                if (!metodo.getTipo().equalsIgnoreCase("void")) {
                     codigo.append( Sangria.sangria( 2 ) )
                           .append( "return( null ) ; // Ajustar valor de retorno\n" ) ;
                }

                codigo.append( Sangria.sangria( 1 ) )
                      .append( "}" )
                      .append( "\n" ) ;
            }
        }
        
        // Declaración de métodos abstractos propios (solo si la clase ES abstracta)
        if (esAbstracta) {
            for( MetodoAbstracto metodo : metodosAbstractos ) {
                codigo.append( "\n" )
                      .append( Sangria.sangria( 1 ) )
                      .append( "public abstract " )
                      .append( metodo.generarCodigo().replace("public ", "") ) // Elimina el "public " extra
                      .append( " ;\n" ) ;
            }
        }

        // --- Método toString() ---
        codigo.append( "\n" + Sangria.sangria( 1 ) + "@Override" ) ;
        codigo.append( "\n" + Sangria.sangria( 1 ) + "public String toString() {" ) ;
        codigo.append( "\n" + Sangria.sangria( 2 ) + "String texto = \"\" ;\n" ) ;
        
        // Agregar toString de la clase base si tiene
        if( claseBase != null ) {
            codigo.append( "\n" + Sangria.sangria(2) + "texto += ( super.toString() ) ;" ) ;
        }

        // Agregar las variables propias
        for( int i = 0 ; i < variablesPropias.size() ; i++ ) {
            Variable var = variablesPropias.get( i ) ;
            codigo.append( "\n" + Sangria.sangria(2) + "texto += ( \"\\n\" + Sangria.sangria( 1 ) + \"" )
                  .append( var.getNombre() )
                  .append( ": \" + " )
                  .append( var.getNombre() + " ) ;" ) ;
        }

        codigo.append( "\n\n" + Sangria.sangria( 2 ) + "return( texto ) ;" ) ;
        codigo.append( "\n" + Sangria.sangria( 1 ) + "}" ) ;
        codigo.append( "\n" + Sangria.sangria( 1 ) + "//" ) ;
        codigo.append( "\n" + "}\n" ) ;


        return codigo.toString() ;
    }
}