package tp2.ej4;

import tp1.tp1ej8.Queue;
import tp2.ej1.BinaryTree;

public class RedBinariaLlena {
	private BinaryTree<Integer> arbol;

	public RedBinariaLlena(BinaryTree<Integer> arbol) {
		this.arbol=arbol;

	}
	
	public int retardoEnvio() {
		Queue<Integer> cola = new Queue<>();
		retardoEnvio(this.arbol,cola);
		Integer valor=0,max=0,aux;
		
		while(!cola.isEmpty()) {
			aux=cola.dequeue();
			if (aux==null) {
				if(max<valor) {
					max=valor;
				}
			}
			else {
				valor+=aux;
			}
		}
		
		return max.intValue();
	}
	
	private void retardoEnvio(BinaryTree<Integer> arbol,Queue<Integer> cola) {
		cola.enqueue(arbol.getData());
		
		if (arbol.isLeaf()) {
			cola.enqueue(null);
			
		}
		
		if (arbol.hasLeftChild()) {
			retardoEnvio(arbol.getLeftChild(),cola);
		}
		
		if (arbol.hasRightChild()) {
			retardoEnvio(arbol.getRightChild(),cola);
		}
		
		cola.enqueue(arbol.getData()*(-1));
		return;
		
	}
	
	public int retardoEnvio2() {
		return calcularMaxRetardo(this.arbol);
	}

	private int calcularMaxRetardo(BinaryTree<Integer> arbol) {
		
		if (arbol==null) {
			return 0;
		}
		
		if (arbol.isLeaf()) {
			return arbol.getData();
		}
		
		int valorIzquierda = (arbol.hasLeftChild()) ?  calcularMaxRetardo(arbol.getLeftChild()):0;
		int valorDerecha = (arbol.hasRightChild()) ?  calcularMaxRetardo(arbol.getRightChild()):0;
		
		return arbol.getData() + ((valorIzquierda>valorDerecha) ? valorIzquierda:valorDerecha);
		
	}
}
