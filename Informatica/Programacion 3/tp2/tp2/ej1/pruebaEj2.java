package tp2.ej1;
import tp2.ej3.ContadorArbol;
import tp2.ej4.RedBinariaLlena;
import tp2.ej5.ProfundidadDeArbolBinario;
import tp2.ej6.Transformacion;

public class pruebaEj2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTree<Integer> arbol1= new BinaryTree<>(1);
		BinaryTree<Integer> arbol2= new BinaryTree<>(2);
		BinaryTree<Integer> arbol3= new BinaryTree<>(3);
		BinaryTree<Integer> arbol4= new BinaryTree<>(4);
		BinaryTree<Integer> arbol5= new BinaryTree<>(5);
		BinaryTree<Integer> arbol6= new BinaryTree<>(6);
		BinaryTree<Integer> arbol7= new BinaryTree<>(7);
		BinaryTree<Integer> arbol8= new BinaryTree<>(8);

		
		arbol1.addLeftChild(arbol2);
		arbol1.addRightChild(arbol3);
		arbol2.addRightChild(arbol4);
		arbol3.addRightChild(arbol6);
		arbol3.addLeftChild(arbol5);
		arbol5.addRightChild(arbol8);
		arbol5.addLeftChild(arbol7);

		RedBinariaLlena red = new RedBinariaLlena(arbol1);
		
		
		System.out.println(arbol1.contarHojas());
		arbol1.imprimirPorNiveles();
		System.out.println();
		System.out.println();
		BinaryTree<Integer> aInvertido= arbol1.espejo();
		aInvertido.imprimirPorNiveles();
		System.out.println();
		System.out.println();
		arbol1.imprimirPorNiveles();
		ContadorArbol contador = new ContadorArbol(arbol1);
		System.out.println();
		System.out.println(contador.numerosParesInOrder());
		System.out.println();
		
		
		/*
		long inicio = System.currentTimeMillis();
		for(int i=0;i<1000;i++) {
			red.retardoEnvio();
		}
		
		System.out.println(red.retardoEnvio());

		long fin = System.currentTimeMillis();
		System.out.println("Tiempo de ejecución metodo 1: " + (fin - inicio) + " ms");
		System.out.println();
		
		inicio = System.currentTimeMillis();
		for(int i=0;i<10000;i++) {
			red.retardoEnvio2();
		}
		System.out.println(red.retardoEnvio2());

		fin = System.currentTimeMillis();
		System.out.println("Tiempo de ejecución metodo 2: " + (fin - inicio) + " ms");
		*/
		ProfundidadDeArbolBinario prof = new ProfundidadDeArbolBinario(arbol1);
		System.out.println(prof.sumaElementosProfundidad(3));
		
		Transformacion trans = new Transformacion(arbol1);
		System.out.println();
		arbol1=trans.suma();
		arbol1.imprimirPorNiveles();
		
		
	}

}
