package modelo;

import util.Capitalize;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Clase implements Serializable {
    private static final long serialVersionUID = 1L;
    private String                nombre            ;
    private boolean               esAbstracta       ;
    private Clase                 claseBase         ;
    private List<Variable>        variablesPropias  ;
    private List<MetodoAbstracto> metodosAbstractos ;
    private Set<String>           imports           ;
    private transient List<Variable> variablesFaltantes ; // No se guarda, solo para comparación

    // Constructores
    public Clase() {
        this.variablesPropias  = new ArrayList<>();
        this.metodosAbstractos = new ArrayList<>();
        this.imports           = new HashSet<>();
        this.variablesFaltantes = new ArrayList<>();
    }

    public Clase( String nombre , boolean esAbstracta , Clase claseBase , List<Variable> variablesPropias , List<MetodoAbstracto> metodosAbstractos ) {
        this.nombre = nombre ;
        this.esAbstracta = esAbstracta ;
        this.claseBase = claseBase ;
        this.variablesPropias = variablesPropias ;
        this.metodosAbstractos = metodosAbstractos ;
        this.imports = new HashSet<>();
        this.variablesFaltantes = new ArrayList<>();
    }

    public List<Variable> getVariablesFaltantes() {
        if (variablesFaltantes == null) variablesFaltantes = new ArrayList<>();
        return variablesFaltantes;
    }
    //

    // Getters
    public String getNombre() { return nombre ; }

    public boolean getEsAbstracta() { return esAbstracta ; }

    public Clase getClaseBase() { return claseBase ; }

    public List<Variable> getVariablesPropias() {
        return variablesPropias ;
    }

    /**
     * Devuelve las variables propias más las auxiliares (cant, MAX) 
     * que se generan para los vectores. Útil para comparaciones con archivos físicos.
     */
    public List<Variable> getVariablesEfectivas() {
        List<Variable> efectivas = new ArrayList<>(variablesPropias);
        for (Variable var : variablesPropias) {
            if (var.isEsArray()) {
                String nombreBase = var.getNombre();
                efectivas.add(new Variable("int", "cant" + Capitalize.capitalize(nombreBase)));
                efectivas.add(new Variable("int", "MAX_" + nombreBase.toUpperCase()));
            }
        }
        return efectivas;
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

    public void setClaseBase(Clase claseBase) {
        this.claseBase = claseBase;
    }

    public void setVariablesPropias(List<Variable> variables) {
        this.variablesPropias = variables;
    }

    public void setMetodosAbstractos(List<MetodoAbstracto> metodos) {
        this.metodosAbstractos = metodos;
    }
    // --- Fin Setters ---

}