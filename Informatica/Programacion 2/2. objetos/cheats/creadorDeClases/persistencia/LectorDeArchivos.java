package persistencia;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import util.Capitalize;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LectorDeArchivos {

    /**
     * Lee un archivo .java de la carpeta 'generadas' e intenta reconstruir un objeto Clase.
     * Basado en el formato estándar del generador.
     */
    public static Clase importarDesdeArchivo(File archivo, List<Clase> clasesExistentes) {
        StringBuilder contenido = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                contenido.append(linea).append("\n");
            }
        } catch (IOException e) {
            System.out.println("❌ Error al leer el archivo: " + e.getMessage());
            return null;
        }

        String texto = contenido.toString();

        // 1. Extraer nombre de clase, si es abstracta y si tiene clase base
        // Pattern: public (abstract )?class (\w+)( extends (\w+))?
        Pattern pClase = Pattern.compile("public\\s+(abstract\\s+)?class\\s+(\\w+)(\\s+extends\\s+(\\w+))?");
        Matcher mClase = pClase.matcher(texto);

        if (!mClase.find()) {
            return null;
        }

        boolean esAbstracta = mClase.group(1) != null;
        String nombreClase = mClase.group(2);
        String nombreClaseBase = mClase.group(4);

        Clase claseBase = null;
        if (nombreClaseBase != null) {
            claseBase = buscarClasePorNombre(clasesExistentes, nombreClaseBase);
        }

        // 2. Extraer Atributos (Variables)
        // Pattern más robusto: private <tipo> <nombre> [= <valor>] ;
        List<Variable> variablesBrutas = new ArrayList<>();
        Pattern pVar = Pattern.compile("private\\s+([^\\s;=]+(?:\\s*\\[\\s*\\])?(?:\\s*<[^>]+>)?)\\s+(\\w+)\\s*(?:=\\s*([^;]+))?\\s*;");
        Matcher mVar = pVar.matcher(texto);
        while (mVar.find()) {
            String tipo = mVar.group(1).trim().replaceAll("\\s+", ""); // Normalizar tipo (quitar espacios internos)
            String nombre = mVar.group(2).trim();
            Variable v = new Variable(tipo, nombre);
            if (mVar.group(3) != null) {
                v.setTamanoMaximo(mVar.group(3).trim());
            }
            variablesBrutas.add(v);
        }

        List<Variable> variablesFinales = new ArrayList<>();
        List<Variable> faltantes = new ArrayList<>();

        // Identificar arrays primero para poder filtrar sus auxiliares
        for (Variable v : variablesBrutas) {
            if (v.isEsArray()) {
                variablesFinales.add(v);
                
                // Verificar si sus auxiliares existen en el texto
                String n = v.getNombre();
                String c = "cant" + Capitalize.capitalize(n);
                String m = "MAX_" + n.toUpperCase();

                boolean tieneCant = false;
                boolean tieneMax = false;
                for (Variable aux : variablesBrutas) {
                    if (aux.getNombre().equals(c)) tieneCant = true;
                    if (aux.getNombre().equals(m)) tieneMax = true;
                }

                if (!tieneCant) faltantes.add(new Variable("int", c));
                if (!tieneMax) faltantes.add(new Variable("int", m));
            }
        }

        for (Variable v : variablesBrutas) {
            if (v.isEsArray()) continue;

            String nombreVar = v.getNombre();
            boolean esAuxiliarDeAlguien = false;
            boolean esHuerfana = false;

            // Patrones de auxiliares
            boolean pareceCant = nombreVar.startsWith("cant") && nombreVar.length() > 4;
            boolean pareceMax = nombreVar.startsWith("MAX_") && nombreVar.length() > 4;

            if (pareceCant || pareceMax) {
                // Intentar encontrar su vector padre
                String nombreBaseSugerido = "";
                if (pareceCant) {
                    nombreBaseSugerido = Character.toLowerCase(nombreVar.charAt(4)) + nombreVar.substring(5);
                } else {
                    nombreBaseSugerido = nombreVar.substring(4).toLowerCase();
                }

                boolean vectorEncontrado = false;
                for (Variable arr : variablesFinales) {
                    if (arr.getNombre().equalsIgnoreCase(nombreBaseSugerido)) {
                        vectorEncontrado = true;
                        esAuxiliarDeAlguien = true;
                        
                        // Si es el MAX, extraer el valor para el modelo
                        if (pareceMax) {
                            Pattern pVal = Pattern.compile(nombreVar + "\\s*=\\s*(\\w+)\\s*;");
                            Matcher mVal = pVal.matcher(texto);
                            if (mVal.find()) {
                                arr.setTamanoMaximo(mVal.group(1));
                            }
                        }
                        break;
                    }
                }

                if (!vectorEncontrado) {
                    esHuerfana = true; // Parece una auxiliar pero no tiene vector padre
                }
            }

            // SOLO agregamos la variable si NO es una auxiliar asociada Y NO es una auxiliar huérfana
            if (!esAuxiliarDeAlguien && !esHuerfana) {
                variablesFinales.add(v);
            }
        }

        // 3. Extraer Métodos Abstractos (solo si la clase es abstracta)
        List<MetodoAbstracto> metodos = new ArrayList<>();
        if (esAbstracta) {
            Pattern pMet = Pattern.compile("public\\s+abstract\\s+([^\\s(]+)\\s+(\\w+)\\s*\\(([^)]*)\\)\\s*;");
            Matcher mMet = pMet.matcher(texto);
            while (mMet.find()) {
                String tipo = mMet.group(1).trim();
                String nombre = mMet.group(2).trim();
                String paramsStr = mMet.group(3).trim();

                MetodoAbstracto met = new MetodoAbstracto(tipo, nombre);
                if (!paramsStr.isEmpty()) {
                    String[] parts = paramsStr.split(",");
                    for (String part : parts) {
                        String[] p = part.trim().split("\\s+");
                        if (p.length >= 2) {
                            met.getParametros().add(new Variable(p[0], p[1]));
                        }
                    }
                }
                metodos.add(met);
            }
        }
        
        Clase nuevaClase = new Clase(nombreClase, esAbstracta, claseBase, variablesFinales, metodos);
        nuevaClase.getVariablesFaltantes().addAll(faltantes);
        return nuevaClase;
    }

    private static Clase buscarClasePorNombre(List<Clase> clases, String nombre) {
        for (Clase c : clases) {
            if (c.getNombre().equalsIgnoreCase(nombre)) return c;
        }
        return null;
    }
}
