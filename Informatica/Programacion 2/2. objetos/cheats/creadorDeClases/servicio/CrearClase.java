package servicio;

import modelo.Clase;
import modelo.Variable;
import modelo.MetodoAbstracto;
import ui.Estilo;
import ui.Consola;
import ui.MenuUI;
import util.Validador;
import util.Capitalize;
import util.Sangria;
import util.InteraccionUtils;
import persistencia.GestorMemoria;
import persistencia.EscritorDeArchivos;
import java.util.ArrayList;
import java.util.List;

public class CrearClase {
    
    public static void crearClase( List<Clase> clasesGeneradas ) {
        System.out.println();
        String nombreClase = Validador.solicitarNombreValido("  " + Estilo.CIAN + "» Ingrese el nombre de la clase: " + Estilo.RESET);
        nombreClase = Capitalize.capitalize( nombreClase ) ;

        if ( nombreClase.equals( "Main" ) ) {
            System.out.println( "\n  " + Estilo.CIAN + "Clase generada:\n" + Estilo.RESET ) ;
            System.out.println( "  public class Main {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "public static void main( String[] args ) {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "}" ) ;
            System.out.println( "  }" ) ;
        } else {
            System.out.println();
            boolean esAbstracta = Consola.leerSino("  ¿Es una clase abstracta?").equals("s");
            
            Clase claseBase = null;
            System.out.println();
            if (!clasesGeneradas.isEmpty() && Consola.leerSino("  ¿Hereda de alguna clase existente?").equals("s")) {
                System.out.println();
                claseBase = InteraccionUtils.seleccionarClase(clasesGeneradas, "  Seleccione la clase de la que desea heredar");
            }

            List<Variable> variablesPropias = new ArrayList<>() ;
            System.out.println();
            while (Consola.leerSino("  ¿Desea agregar una variable?").equals("s")) {
                variablesPropias.add(InteraccionUtils.pedirVariable(variablesPropias.size() + 1, clasesGeneradas));
                System.out.println();
            }

            List<MetodoAbstracto> metodosAbstractos = new ArrayList<>() ;
            if ( esAbstracta ) {
                System.out.println();
                while (Consola.leerSino("  ¿Desea agregar un método abstracto?").equals("s")) {
                    metodosAbstractos.add(InteraccionUtils.pedirMetodo(metodosAbstractos.size() + 1, clasesGeneradas));
                    System.out.println();
                }
            }

            Clase nuevaClase = new Clase(nombreClase, esAbstracta, claseBase, variablesPropias , metodosAbstractos ) ;
            clasesGeneradas.add( nuevaClase ) ;
            
            GestorMemoria.guardar(clasesGeneradas);
            MenuUI.imprimirInfo("Sesión guardada automáticamente.");
            EscritorDeArchivos.guardarClase(nuevaClase);

            MenuUI.imprimirExito("Clase '" + nombreClase + "' creada con éxito, guardada y exportada.");
        }
    }
}
