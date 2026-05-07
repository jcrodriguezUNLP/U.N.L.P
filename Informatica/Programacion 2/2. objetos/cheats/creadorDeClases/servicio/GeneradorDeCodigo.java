package servicio;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import util.Sangria;
import util.Capitalize;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GeneradorDeCodigo {

    private static Set<String> imports;

    public static String generar(Clase clase) {
        analizarImports(clase);
        StringBuilder codigo = new StringBuilder();

        codigo.append(generarImports());
        codigo.append(generarDefinicionClase(clase));
        codigo.append(generarAtributos(clase));
        codigo.append(generarConstructores(clase));
        codigo.append(generarGetters(clase));
        codigo.append(generarSetters(clase));
        codigo.append(generarMetodosYToString(clase));
        codigo.append("}\n");

        return codigo.toString();
    }

    private static void analizarImports(Clase clase) {
        imports = new HashSet<>();
        List<String> todosLosTipos = new ArrayList<>();
        
        for (Variable var : clase.getVariablesPropias()) {
            todosLosTipos.add(var.getTipo());
        }
        for (Variable var : clase.getVariablesHeredadas()) {
            todosLosTipos.add(var.getTipo());
        }
        for (MetodoAbstracto met : clase.getMetodosAbstractos()) todosLosTipos.add(met.getTipo());
        for (MetodoAbstracto met : clase.getMetodosAbstractosHeredados()) todosLosTipos.add(met.getTipo());

        for (String tipo : todosLosTipos) {
            if (tipo.contains("List") && !tipo.contains("ArrayList")) imports.add("java.util.List");
            if (tipo.contains("ArrayList")) {
                imports.add("java.util.List");
                imports.add("java.util.ArrayList");
            }
            if (tipo.contains("Map") && !tipo.contains("HashMap")) imports.add("java.util.Map");
            if (tipo.contains("HashMap")) {
                imports.add("java.util.Map");
                imports.add("java.util.HashMap");
            }
            if (tipo.contains("Set") && !tipo.contains("HashSet")) imports.add("java.util.Set");
            if (tipo.contains("HashSet")) {
                imports.add("java.util.Set");
                imports.add("java.util.HashSet");
            }
            if (tipo.contains("LocalDate")) imports.add("java.time.LocalDate");
            if (tipo.contains("Date") && !tipo.contains("LocalDate")) imports.add("java.util.Date");
            if (tipo.contains("Scanner")) imports.add("java.util.Scanner");
        }
    }

    private static String generarImports() {
        StringBuilder sb = new StringBuilder();
        for (String imp : imports) {
            sb.append("import ").append(imp).append(" ;\n");
        }
        if (!imports.isEmpty()) sb.append("\n");
        return sb.toString();
    }

    private static String generarDefinicionClase(Clase clase) {
        StringBuilder sb = new StringBuilder();
        sb.append("public ");
        if (clase.getEsAbstracta()) {
            sb.append("abstract ");
        }
        sb.append("class ").append(clase.getNombre());
        if (clase.getClaseBase() != null) {
            sb.append(" extends ").append(clase.getClaseBase().getNombre());
        }
        sb.append(" {\n");
        return sb.toString();
    }

    private static String generarAtributos(Clase clase) {
        StringBuilder sb = new StringBuilder();
        
        for (Variable var : clase.getVariablesPropias()) {
            sb.append(Sangria.sangria(1)).append(var.generarCodigo()).append("\n");
            if (var.isEsArray()) {
                sb.append("\n");
                String nombreBase = var.getNombre();
                String nombreCant = "cant" + Capitalize.capitalize(nombreBase);
                String nombreMax = "MAX_" + nombreBase.toUpperCase();

                sb.append(Sangria.sangria(1)).append("private int ").append(nombreCant).append(" ;\n");
                sb.append(Sangria.sangria(1)).append("private int ").append(nombreMax).append(" ;\n");
            }
        }
        return sb.toString();
    }

    private static boolean tieneArrays(Clase clase) {
        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) return true;
        }
        return false;
    }

    private static String generarConstructores(Clase clase) {
        StringBuilder sb = new StringBuilder();
        
        int cant = 1;
        if (!tieneArrays(clase)) {
            List<Variable> params = new ArrayList<>();
            params.addAll(clase.getVariablesHeredadas());
            params.addAll(clase.getVariablesPropias());
            if (!params.isEmpty()) cant++;
        }

        sb.append("\n\n").append(Sangria.sangria(1)).append(cant > 1 ? "// Constructores\n" : "// Constructor\n");
        sb.append(Sangria.sangria(2)).append("public ").append(clase.getNombre()).append("() {\n");
        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) {
                String nombreBase = var.getNombre();
                String nombreCant = "cant" + Capitalize.capitalize(nombreBase);
                String nombreMax = "MAX_" + nombreBase.toUpperCase();
                String val = var.getTamanoMaximo().isEmpty() ? "10" : var.getTamanoMaximo();
                
                sb.append(Sangria.sangria(3)).append(nombreCant).append(" = 0 ;\n\n");
                sb.append(Sangria.sangria(3)).append(nombreMax).append(" = ").append(val).append(" ;\n\n");
                sb.append(Sangria.sangria(3)).append(var.getNombre())
                  .append(" = new ")
                  .append(var.getTipo().replace("[]", ""))
                  .append("[ ").append(nombreMax).append(" ] ;\n");
            }
        }
        sb.append(Sangria.sangria(2)).append("}\n");

        if (!tieneArrays(clase)) {
            List<Variable> todosLosParametros = new ArrayList<>();
            todosLosParametros.addAll(clase.getVariablesHeredadas());
            todosLosParametros.addAll(clase.getVariablesPropias());

            if (!todosLosParametros.isEmpty()) {
                sb.append("\n");
                sb.append(Sangria.sangria(2)).append("public ").append(clase.getNombre()).append("( ");

                for (int i = 0; i < todosLosParametros.size(); i++) {
                    Variable var = todosLosParametros.get(i);
                    sb.append(var.getTipo()).append(" ").append(var.getNombre());
                    if (i < todosLosParametros.size() - 1) {
                        sb.append(" , ");
                    }
                }
                sb.append(" ) {\n");

                if (clase.getClaseBase() != null) {
                    sb.append(Sangria.sangria(3)).append("super( ");
                    List<Variable> heredadas = clase.getVariablesHeredadas();
                    for (int i = 0; i < heredadas.size(); i++) {
                        sb.append(heredadas.get(i).getNombre());
                        if (i < heredadas.size() - 1) {
                            sb.append(" , ");
                        }
                    }
                    sb.append(" ) ;\n");
                }

                for (Variable var : clase.getVariablesPropias()) {
                    sb.append(Sangria.sangria(3)).append("this.")
                      .append(var.getNombre())
                      .append(" = ")
                      .append(var.getNombre())
                      .append(" ;\n");
                }
                sb.append(Sangria.sangria(2)).append("}\n");
            }
        }
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

    private static String generarGetters(Clase clase) {
        if (clase.getVariablesPropias().isEmpty()) return "";

        int cant = 0;
        for (Variable var : clase.getVariablesPropias()) {
            cant += var.isEsArray() ? 3 : 1;
        }

        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append(cant > 1 ? "// Getters\n" : "// Getter\n");
        for (Variable var : clase.getVariablesPropias()) {
            sb.append(Sangria.sangria(2)).append("public ")
              .append(var.getTipo())
              .append(" get")
              .append(Capitalize.capitalize(var.getNombre()))
              .append("() { return( ")
              .append(var.getNombre())
              .append(" ) ; }\n");
            
            if (var.isEsArray()) {
                String nombreBase = var.getNombre();
                String nombreCant = "cant" + Capitalize.capitalize(nombreBase);
                String nombreMax = "MAX_" + nombreBase.toUpperCase();
                
                sb.append(Sangria.sangria(2)).append("public int get")
                  .append(Capitalize.capitalize(nombreCant))
                  .append("() { return( ")
                  .append(nombreCant)
                  .append(" ) ; }\n");
                
                sb.append(Sangria.sangria(2)).append("public int get")
                  .append(Capitalize.capitalize(nombreMax))
                  .append("() { return( ")
                  .append(nombreMax)
                  .append(" ) ; }\n");
            }
        }
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }

    private static String generarSetters(Clase clase) {
        int cant = 0;
        for (Variable var : clase.getVariablesPropias()) {
            if (!var.isEsArray()) cant++;
        }
        if (cant == 0) return "";

        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append(cant > 1 ? "// Setters\n" : "// Setter\n");
        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) continue; 
            
            sb.append(Sangria.sangria(2)).append("public void set")
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

    private static String generarMetodosYToString(Clase clase) {
        int cant = 1; 
        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) cant += 2;
        }
        if (!clase.getEsAbstracta()) cant += clase.getMetodosAbstractosHeredados().size();
        if (clase.getEsAbstracta()) cant += clase.getMetodosAbstractos().size();

        StringBuilder sb = new StringBuilder();
        sb.append("\n").append(Sangria.sangria(1)).append(cant > 1 ? "// Métodos\n" : "// Método\n");

        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) {
                String nombreBase = var.getNombre();
                String nombreSingular = var.getTipo().replace("[]", "");
                nombreSingular = Character.toLowerCase(nombreSingular.charAt(0)) + nombreSingular.substring(1);
                
                String nombreCant = "cant" + Capitalize.capitalize(nombreBase);
                String nombreMax = "MAX_" + nombreBase.toUpperCase();
                String tipoElem = var.getTipo().replace("[]", "");

                sb.append(Sangria.sangria(2)).append("public void agregar")
                  .append(Capitalize.capitalize(nombreSingular))
                  .append("( ").append(tipoElem).append(" ").append(nombreSingular).append(" ) {\n")
                  .append(Sangria.sangria(3)).append("if( ").append(nombreCant).append(" < ").append(nombreMax).append(" ) {\n")
                  .append(Sangria.sangria(4)).append(nombreBase).append("[ ").append(nombreCant).append(" ] = ").append(nombreSingular).append(" ;\n\n")
                  .append(Sangria.sangria(4)).append(nombreCant).append("++ ;\n")
                  .append(Sangria.sangria(3)).append("} else {\n")
                  .append(Sangria.sangria(4)).append("System.out.println( \"No se pueden agregar más ").append(nombreBase).append("\" ) ;\n")
                  .append(Sangria.sangria(3)).append("}\n")
                  .append(Sangria.sangria(2)).append("}\n\n");

                sb.append(Sangria.sangria(2)).append("public void eliminar")
                  .append(Capitalize.capitalize(nombreSingular))
                  .append("( int posicion ) {\n")
                  .append(Sangria.sangria(3)).append("if( (1 <= posicion) && (posicion <= ").append(nombreCant).append(") ) {\n")
                  .append(Sangria.sangria(4)).append("for( int i = (posicion - 1) ; i < ").append(nombreCant).append(" - 1 ; i++ ) {\n")
                  .append(Sangria.sangria(5)).append(nombreBase).append("[ i ] = ").append(nombreBase).append("[ i + 1 ] ;\n")
                  .append(Sangria.sangria(4)).append("}\n\n")
                  .append(Sangria.sangria(4)).append(nombreCant).append("-- ;\n\n")
                  .append(Sangria.sangria(4)).append(nombreBase).append("[ ").append(nombreCant).append(" ] = null ;\n")
                  .append(Sangria.sangria(3)).append("}\n")
                  .append(Sangria.sangria(2)).append("}\n\n");
            }
        }

        if (!clase.getEsAbstracta()) {
            for (MetodoAbstracto metodo : clase.getMetodosAbstractosHeredados()) {
                sb.append(Sangria.sangria(2)).append("@Override\n")
                  .append(Sangria.sangria(2)).append(metodo.generarCodigo())
                  .append(" {\n")
                  .append(Sangria.sangria(3)).append("/* Lógica para implementar ").append(metodo.getNombre()).append(" */\n");

                if (!metodo.getTipo().equalsIgnoreCase("void")) {
                    String valorRetorno = "null";
                    String tipo = metodo.getTipo().toLowerCase();
                    if (tipo.equals("double") || tipo.equals("float")) valorRetorno = "0.0";
                    else if (tipo.equals("int") || tipo.equals("long") || tipo.equals("short") || tipo.equals("byte")) valorRetorno = "0";
                    else if (tipo.equals("boolean")) valorRetorno = "false";
                    else if (tipo.equals("char")) valorRetorno = "' '";
                    sb.append(Sangria.sangria(3)).append("return( ").append(valorRetorno).append(" ) ; \n");
                }
                sb.append(Sangria.sangria(2)).append("}\n");
            }
        }

        if (clase.getEsAbstracta()) {
            for (MetodoAbstracto metodo : clase.getMetodosAbstractos()) {
                sb.append("\n").append(Sangria.sangria(2)).append("public abstract ")
                  .append(metodo.generarCodigo().replace("public ", "")).append(" ;\n");
            }
        }

        sb.append("\n").append(Sangria.sangria(2)).append("@Override\n");
        sb.append(Sangria.sangria(2)).append("public String toString() {\n");
        sb.append(Sangria.sangria(3)).append("String texto ;\n\n");
        sb.append(Sangria.sangria(3)).append("texto = ( \"").append(clase.getNombre().toUpperCase()).append(":\" ) ;\n");

        if (clase.getClaseBase() != null) {
            sb.append("\n").append(Sangria.sangria(3)).append("texto += ( \"\\n\" + super.toString() ) ;\n");
        }

        for (Variable var : clase.getVariablesPropias()) {
            if (var.isEsArray()) {
                String nombreBase = var.getNombre();
                String nombreCant = "cant" + Capitalize.capitalize(nombreBase);
                String iName = "num" + Capitalize.capitalize(nombreBase);
                if (iName.endsWith("s")) iName = iName.substring(0, iName.length() - 1);

                sb.append("\n").append(Sangria.sangria(3))
                  .append("for ( int ").append(iName).append(" = 0 ; ").append(iName).append(" < ").append(nombreCant).append(" ; ").append(iName).append("++ ) {\n")
                  .append(Sangria.sangria(4)).append("texto += \"\\n\" + Sangria.sangria( 1 ) + ")
                  .append(nombreBase).append("[ ").append(iName).append(" ].toString() ;\n")
                  .append(Sangria.sangria(3)).append("}\n");
            } else {
                sb.append(Sangria.sangria(3)).append("texto += ( \"\\n\" + Sangria.sangria( 1 ) + \"")
                  .append(var.getNombre()).append(": \" + ").append(var.getNombre()).append(" ) ;\n");
            }
        }
        sb.append("\n").append(Sangria.sangria(3)).append("return( texto ) ;\n");
        sb.append(Sangria.sangria(2)).append("}\n");
        sb.append(Sangria.sangria(1)).append("//\n");
        return sb.toString();
    }
}
