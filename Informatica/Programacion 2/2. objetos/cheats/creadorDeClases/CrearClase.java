import java.util.ArrayList;
import java.util.List;

public class CrearClase {
    
    public static void crearClase( List<Clase> clasesGeneradas ) {

        String nombreClase = Validador.solicitarNombreValido("\nIngrese el nombre de la clase: ");
        nombreClase = Capitalize.capitalize( nombreClase ) ;

        if ( nombreClase.equals( "Main" ) ) {
            System.out.println( "\nClase generada:\n" ) ;
            System.out.println( "public class Main {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "public static void main( String[] args ) {" ) ;
            System.out.println( Sangria.sangria( 1 ) + "}" ) ;
            System.out.println( "}" ) ;
        } else {
            boolean esAbstracta = Consola.leerSino("\n¿Es una clase abstracta?").equals("s");
            
            Clase claseBase = null;
            if (!clasesGeneradas.isEmpty() && Consola.leerSino("\n¿Hereda de alguna clase existente?").equals("s")) {
                claseBase = InteraccionUtils.seleccionarClase(clasesGeneradas, "Seleccione la clase de la que desea heredar");
            }

            List<Variable> variablesPropias = new ArrayList<>() ;
            while (Consola.leerSino("\n¿Desea agregar una variable?").equals("s")) {
                variablesPropias.add(InteraccionUtils.pedirVariable(variablesPropias.size() + 1));
            }

            List<MetodoAbstracto> metodosAbstractos = new ArrayList<>() ;
            if ( esAbstracta ) {
                while (Consola.leerSino("\n¿Desea agregar un método abstracto?").equals("s")) {
                    metodosAbstractos.add(InteraccionUtils.pedirMetodo(metodosAbstractos.size() + 1));
                }
            }

            Clase nuevaClase = new Clase(nombreClase, esAbstracta, claseBase, variablesPropias , metodosAbstractos ) ;
            clasesGeneradas.add( nuevaClase ) ;
            GestorMemoria.guardar(clasesGeneradas);
            EscritorDeArchivos.guardarClase(nuevaClase);

            MenuUI.imprimirExito("Clase '" + nombreClase + "' creada con éxito, guardada y exportada.");
        }
    }
}
