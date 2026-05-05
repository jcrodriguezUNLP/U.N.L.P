// ==============================================================================
// PROBLEMA 7: Uso de API de Listas (ArrayList y LinkedList)
// ==============================================================================
//   REQUISITO ARQUITECTÓNICO GLOBAL:
//     - Todas las clases deben pertenecer al paquete: tp1.ejercicio7
//
//   [A] CLASE: TestArrayList
//     [B] MAIN: main (Orquestador Incisos A, B, C)
//       orquesta:
//         - Instanciación de listas tipo ArrayList.
//       flujo:
//         - (Inciso A) Recibe secuencia de números desde teclado o hardcodeados.
//         - (Inciso A) Los agrega a la lista.
//       salida:
//         - (Inciso A) Imprime contenido iterando sobre cada elemento.
//         - (Incisos B y C) Imprime en consola o comenta las justificaciones teóricas pedidas.
//
//     [C] MÓDULO AISLADO: demostrarCopiaSuperficial (Inciso D)
//       recibe:
//         - Ninguno.
//       modifica:
//         - Crea lista de 3 estudiantes.
//         - Genera una nueva lista que sea copia de la original (Shallow Copy).
//         - Modifica algún dato de los estudiantes.
//       retorna:
//         - Void (imprime el contenido de ambas listas demostrando el cambio compartido).
//
//     [C] MÓDULO AISLADO: agregarEstudianteUnico (Inciso E)
//       recibe:
//         - ArrayList< Estudiante > lista.
//         - Estudiante nuevo.
//       modifica:
//         - Inserta el estudiante en la lista.
//       retorna:
//         - Void.
//       restricciones:
//         - Condición: Verifica previamente que no estaba incluido usando .contains().
//
//     [C] MÓDULO AISLADO: esCapicua (Inciso F)
//       recibe:
//         - ArrayList< Integer > lista.
//       modifica:
//         - Ninguno.
//       retorna:
//         - boolean (verdadero o falso si la secuencia es capicúa).
//       restricciones:
//         - Firma exacta: public boolean esCapicua( ArrayList< Integer > lista ).
//
//     [C] MÓDULO AISLADO: invertirArrayList (Inciso H)
//       recibe:
//         - ArrayList< Integer > lista.
//       modifica:
//         - Invierte orden de elementos in-place (mutando la lista original).
//       retorna:
//         - Void.
//       restricciones:
//         - Firma exacta: public void invertirArrayList( ArrayList< Integer > lista ).
//         - Debe implementarse obligatoriamente de forma recursiva.
//
//     [C] MÓDULO AISLADO: sumarLinkedList (Inciso I)
//       recibe:
//         - LinkedList< Integer > lista.
//       modifica:
//         - Ninguno.
//       retorna:
//         - int con la suma calculada.
//       restricciones:
//         - Firma exacta: public int sumarLinkedList( LinkedList< Integer > lista ).
//         - Debe implementarse obligatoriamente de forma recursiva.
//
//     [C] MÓDULO AISLADO: combinarOrdenado (Inciso J)
//       recibe:
//         - ArrayList< Integer > lista1.
//         - ArrayList< Integer > lista2.
//       modifica:
//         - Ninguno.
//       retorna:
//         - ArrayList< Integer > nueva combinada y ordenada.
//       restricciones:
//         - Firma exacta: public ArrayList< Integer > combinarOrdenado( ArrayList< Integer > lista1 , ArrayList< Integer > lista2 ).
// ==============================================================================

import java.util.ArrayList ;
import java.util.Arrays ;
import java.util.LinkedList ;
import java.util.Scanner ;

public class TestArrayList {

    // ==========================================================================
    //   [B] MAIN: Orquestador General
    // ==========================================================================
    public static void main( String[] args ) {
        
        // --- 1. INICIALIZACIÓN ---
        Scanner               teclado    = new Scanner( System.in ) ;
        ArrayList< Integer >    numeros    = new ArrayList<>() ;
        int                   numIngreso ;
        ArrayList< Estudiante > listaEst   = new ArrayList<>() ;

        // --- 2. PROCESAMIENTO ---
        // TEST INCISOS A, B, C (Lectura e Iteración)
        System.out.println( "=== TEST INCISO A ===" ) ;
        System.out.println( "Ingrese numeros (0 para terminar):" ) ;
        numIngreso = teclado.nextInt() ;
        while ( numIngreso != 0 ) {
            numeros.add( numIngreso ) ;
            numIngreso = teclado.nextInt() ;
        }

        // --- 3. SALIDA ---
        System.out.println( "\nContenido (Iteracion):" ) ;
        for ( int num : numeros ) {
            System.out.print( num + " " ) ;
        }
        System.out.println( "\n" ) ;
        teclado.close() ; 

        // ==============================================================
        // TEST RESTO DE INCISOS
        // ==============================================================
        System.out.println( "=== TEST INCISO D ===" ) ;
        demostrarCopiaSuperficial() ;
        System.out.println() ;

        System.out.println( "=== TEST INCISO E ===" ) ;
        Estudiante base = new Estudiante( "Alan" , "Turing" , "1A" , "alan@unlp.edu.ar" , "Calle 1" ) ;
        listaEst.add( base ) ;
        Estudiante clon = new Estudiante( "Impostor" , "X" , "1A" , "alan@unlp.edu.ar" , "Calle X" ) ;
        agregarEstudianteUnico( listaEst , clon ) ; 
        Estudiante nuevo = new Estudiante( "Ada" , "Lovelace" , "1B" , "ada@unlp.edu.ar" , "Calle 2" ) ;
        agregarEstudianteUnico( listaEst , nuevo ) ; 
        System.out.println() ;

        System.out.println( "=== TEST INCISO F ===" ) ;
        ArrayList< Integer > capiSi = new ArrayList<>( Arrays.asList( 2 , 5 , 2 ) ) ;
        ArrayList< Integer > capiNo = new ArrayList<>( Arrays.asList( 4 , 5 , 6 , 3 , 4 ) ) ;
        System.out.println( "La lista " + capiSi + " es capicua? -> " + esCapicua( capiSi ) ) ;
        System.out.println( "La lista " + capiNo + " es capicua? -> " + esCapicua( capiNo ) ) ;
        System.out.println() ;

        System.out.println( "=== TEST INCISO H ===" ) ;
        ArrayList< Integer > listaAInvertir = new ArrayList<>( Arrays.asList( 1 , 2 , 3 , 4 , 5 ) ) ;
        System.out.println( "Lista Original : " + listaAInvertir ) ;
        invertirArrayList( listaAInvertir ) ;
        System.out.println( "Lista Invertida: " + listaAInvertir ) ;
        System.out.println() ;

        System.out.println( "=== TEST INCISO I ===" ) ;
        LinkedList< Integer > listaASumar = new LinkedList<>( Arrays.asList( 10 , 20 , 30 ) ) ;
        System.out.println( "Lista a sumar: " + listaASumar ) ;
        System.out.println( "Suma total   : " + sumarLinkedList( listaASumar ) ) ;
        System.out.println( "La lista original NO se destruyo: " + listaASumar ) ;
        System.out.println() ;

        System.out.println( "=== TEST INCISO J ===" ) ;
        ArrayList< Integer > ordenada1 = new ArrayList<>( Arrays.asList( 1 , 3 , 5 , 7 ) ) ;
        ArrayList< Integer > ordenada2 = new ArrayList<>( Arrays.asList( 2 , 4 , 6 , 8 , 9 , 10 ) ) ;
        System.out.println( "Lista 1: " + ordenada1 ) ;
        System.out.println( "Lista 2: " + ordenada2 ) ;
        System.out.println( "Mezcla : " + combinarOrdenado( ordenada1 , ordenada2 ) ) ;
    }

    // metodos
        public static void demostrarCopiaSuperficial() {
            ArrayList< Estudiante > listaOriginal = new ArrayList<>() ;
            ArrayList< Estudiante > listaCopia    = new ArrayList<>() ;
            
            Estudiante est1 = new Estudiante( "Alan"  , "Turing"   , "1A" , "alan@unlp.edu.ar" , "Calle 1" ) ;
            Estudiante est2 = new Estudiante( "Ada"   , "Lovelace" , "1B" , "ada@unlp.edu.ar"  , "Calle 2" ) ;
            Estudiante est3 = new Estudiante( "Grace" , "Hopper"   , "1C" , "grace@unlp.edu.ar", "Calle 3" ) ;

            listaOriginal.add( est1 ) ;
            listaOriginal.add( est2 ) ;
            listaOriginal.add( est3 ) ;

            listaCopia.addAll( listaOriginal ) ;
            listaOriginal.get( 0 ).setNombre( "Alan Mathison" ) ;

            System.out.println( "Nombre en Lista Original: " + listaOriginal.get( 0 ).getNombre() ) ;
            System.out.println( "Nombre en Lista Copia   : " + listaCopia.get( 0 ).getNombre() ) ;
        }

        public static void agregarEstudianteUnico( ArrayList< Estudiante > lista , Estudiante nuevo ) {
            if ( !lista.contains( nuevo ) ) {
                lista.add( nuevo ) ;
                System.out.println( "INSERCION EXITOSA: Estudiante agregado." ) ;
            } else {
                System.out.println( "RECHAZADO: El estudiante ya existe." ) ;
            }
        }

        public static boolean esCapicua( ArrayList< Integer > lista ) {
            boolean esCapi = true ;
            int     size   = lista.size() ;
            int     i      = 0 ;

            while ( ( i < ( size / 2 ) ) && esCapi ) {
                if ( !lista.get( i ).equals( lista.get( size - 1 - i ) ) ) {
                    esCapi = false ;
                }
                i++ ;
            }
            return( esCapi ) ;
        }

        public static void invertirArrayList( ArrayList< Integer > lista ) {
            int primerElemento ;
            if ( 1 < lista.size() ) {
                primerElemento = lista.remove( 0 ) ;
                invertirArrayList( lista ) ;
                lista.add( primerElemento ) ;
            }
        }

        public static int sumarLinkedList( LinkedList< Integer > lista ) {
            int suma = 0 ;
            int primerElemento ;
            if ( 0 < lista.size() ) {
                primerElemento = lista.removeFirst() ;
                suma           = primerElemento + sumarLinkedList( lista ) ;
                lista.addFirst( primerElemento ) ; 
            }
            return( suma ) ;
        }

        public static ArrayList< Integer > combinarOrdenado( ArrayList< Integer > lista1 , ArrayList< Integer > lista2 ) {
            ArrayList< Integer > combinada = new ArrayList<>() ;
            int                i         = 0 ;
            int                j         = 0 ;

            while ( ( i < lista1.size() ) && ( j < lista2.size() ) ) {
                if ( lista1.get( i ) < lista2.get( j ) ) {
                    combinada.add( lista1.get( i ) ) ;
                    i++ ;
                } else {
                    combinada.add( lista2.get( j ) ) ;
                    j++ ;
                }
            }
            while ( i < lista1.size() ) {
                combinada.add( lista1.get( i ) ) ;
                i++ ;
            }
            while ( j < lista2.size() ) {
                combinada.add( lista2.get( j ) ) ;
                j++ ;
            }
            return( combinada ) ;
        }
    //
}
