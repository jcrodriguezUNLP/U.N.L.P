import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Clase implements Serializable {
    private static final long serialVersionUID = 1L;
    private String                nombre            ;
    private boolean               esAbstracta       ;
    private Clase                 claseBase         ;
    private List<Variable>        variablesPropias  ;
    private List<MetodoAbstracto> metodosAbstractos ;
    private Set<String>           imports           ;

    // Constructores
    public Clase() {
        this.variablesPropias  = new ArrayList<>();
        this.metodosAbstractos = new ArrayList<>();
        this.imports           = new HashSet<>();
    }

    public Clase( String nombre , boolean esAbstracta , Clase claseBase , List<Variable> variablesPropias , List<MetodoAbstracto> metodosAbstractos ) {
        this.nombre = nombre ;
        this.esAbstracta = esAbstracta ;
        this.claseBase = claseBase ;
        this.variablesPropias = variablesPropias ;
        this.metodosAbstractos = metodosAbstractos ;
        this.imports = new HashSet<>();
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
        analizarImports();
        StringBuilder codigo = new StringBuilder();

        codigo.append(generarImports());
        codigo.append(generarDefinicionClase());
        codigo.append(generarAtributos());
        codigo.append(generarConstructores());
        codigo.append(generarGetters());
        codigo.append(generarSetters());
        codigo.append(generarMetodos());
        codigo.append(generarToString());
        codigo.append("}\n");

        return codigo.toString();
    }

    private void analizarImports() {
        imports.clear();
        List<String> todosLosTipos = new ArrayList<>();
        
        for (Variable var : variablesPropias) todosLosTipos.add(var.getTipo());
        for (Variable var : getVariablesHeredadas()) todosLosTipos.add(var.getTipo());
        for (MetodoAbstracto met : metodosAbstractos) todosLosTipos.add(met.getTipo());
        for (MetodoAbstracto met : getMetodosAbstractosHeredados()) todosLosTipos.add(met.getTipo());

        for (String tipo : todosLosTipos) {
            if (tipo.contains("List") && !tipo.contains("ArrayList")) imports.add("java.util.List");
            if (tipo.contains("ArrayList")) {
                imports.add("java.util.List");
                imports.add("java.util.ArrayList");
            }
            if (tipo.contains("LocalDate")) imports.add("java.time.LocalDate");
            if (tipo.contains("Scanner")) imports.add("java.util.Scanner");
        }
    }

    private String generarImports() {
        StringBuilder sb = new StringBuilder();
        for (String imp : imports) {
            sb.append("import ").append(imp).append(";\n");
        }
        if (!imports.isEmpty()) sb.append("\n");
        return sb.toString();
    }

    private String generarDefinicionClase() {
        StringBuilder sb = new StringBuilder();
        sb.append("public ");
        if (esAbstracta) {
            sb.append("abstract ");
        }
        sb.append("class ").append(nombre);
        if (claseBase != null) {
            sb.append(" extends ").append(claseBase.getNombre());
        }
        sb.append(" {\n");
        return sb.toString();
    }

    private String generarAtributos() {
        StringBuilder sb = new StringBuilder();
        for (Variable var : variablesPropias) {
            sb.append(Sangria.sangria(1)).append("private ")
              .append(var.getTipo())
              .append(" ")
              .append(var.getNombre())
              .append(" ;\n");
        }
        return sb.toString();
    }

    private String generarConstructores() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append("// Constructores\n");
        sb.append(Sangria.sangria(1)).append("public ").append(nombre).append("() {}\n\n");

        List<Variable> todosLosParametros = new ArrayList<>();
        todosLosParametros.addAll(getVariablesHeredadas());
        todosLosParametros.addAll(variablesPropias);

        sb.append(Sangria.sangria(1)).append("public ").append(nombre).append("( ");

        for (int i = 0; i < todosLosParametros.size(); i++) {
            Variable var = todosLosParametros.get(i);
            sb.append(var.getTipo()).append(" ").append(var.getNombre());
            if (i < todosLosParametros.size() - 1) {
                sb.append(" , ");
            }
        }
        sb.append(" ) {\n");

        if (claseBase != null) {
            sb.append(Sangria.sangria(2)).append("super( ");
            List<Variable> heredadas = getVariablesHeredadas();
            for (int i = 0; i < heredadas.size(); i++) {
                sb.append(heredadas.get(i).getNombre());
                if (i < heredadas.size() - 1) {
                    sb.append(" , ");
                }
            }
            sb.append(" ) ;\n");
        }

        for (Variable var : variablesPropias) {
            sb.append(Sangria.sangria(2)).append("this.")
              .append(var.getNombre())
              .append(" = ")
              .append(var.getNombre())
              .append(" ;\n");
        }
        sb.append(Sangria.sangria(1)).append("}\n");
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

    private String generarGetters() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append("// Getters\n");
        for (Variable var : variablesPropias) {
            sb.append(Sangria.sangria(1)).append("public ")
              .append(var.getTipo())
              .append(" get")
              .append(Capitalize.capitalize(var.getNombre()))
              .append("() { return( ")
              .append(var.getNombre())
              .append(" ) ; }\n");
        }
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

    private String generarSetters() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append("// Setters\n");
        for (Variable var : variablesPropias) {
            sb.append(Sangria.sangria(1)).append("public void set")
              .append(Capitalize.capitalize(var.getNombre()))
              .append("( ")
              .append(var.getTipo())
              .append(" ")
              .append(var.getNombre())
              .append(" ) { this.")
              .append(var.getNombre())
              .append(" = ")
              .append(var.getNombre())
              .append(" ; }\n");
        }
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

    private String generarMetodos() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append("// Métodos\n");

        if (!esAbstracta) {
            for (MetodoAbstracto metodo : getMetodosAbstractosHeredados()) {
                sb.append(Sangria.sangria(1)).append("@Override\n")
                  .append(Sangria.sangria(1)).append(metodo.generarCodigo())
                  .append(" {\n")
                  .append(Sangria.sangria(2))
                  .append("/* Lógica para implementar ").append(metodo.getNombre()).append(" */\n");

                if (!metodo.getTipo().equalsIgnoreCase("void")) {
                    sb.append(Sangria.sangria(2)).append("return( null ) ; // Ajustar valor de retorno\n");
                }
                sb.append(Sangria.sangria(1)).append("}\n");
            }
        }

        if (esAbstracta) {
            for (MetodoAbstracto metodo : metodosAbstractos) {
                sb.append("\n")
                  .append(Sangria.sangria(1))
                  .append("public abstract ")
                  .append(metodo.generarCodigo().replace("public ", ""))
                  .append(" ;\n");
            }
        }
        return sb.toString();
    }

    private String generarToString() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append("@Override\n");
        sb.append(Sangria.sangria(1)).append("public String toString() {\n");
        sb.append(Sangria.sangria(2)).append("String texto = \"\" ;\n");

        if (claseBase != null) {
            sb.append("\n").append(Sangria.sangria(2)).append("texto += ( super.toString() ) ;\n");
        }

        for (Variable var : variablesPropias) {
            sb.append(Sangria.sangria(2)).append("texto += ( \"\\n\" + Sangria.sangria( 1 ) + \"")
              .append(var.getNombre())
              .append(": \" + ")
              .append(var.getNombre()).append(" ) ;\n");
        }

        sb.append("\n").append(Sangria.sangria(2)).append("return( texto ) ;\n");
        sb.append(Sangria.sangria(1)).append("}\n");
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

}