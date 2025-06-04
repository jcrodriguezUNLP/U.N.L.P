package tp2.ej5;
import tp1.tp1ej8.Queue;
import tp2.ej1.BinaryTree;

public class ProfundidadDeArbolBinario {
	private BinaryTree<Integer> arbol;
	public ProfundidadDeArbolBinario(BinaryTree<Integer> arbol) {
		this.setArbol(arbol);
	}
	
	public BinaryTree<Integer> getArbol() {
		return arbol;
	}
	public void setArbol(BinaryTree<Integer> arbol) {
		this.arbol = arbol;
	}
	
	public int sumaElementosProfundidad(int p) {
		BinaryTree<Integer> a = null;
		Queue<BinaryTree<Integer>> cola = new Queue<>();
		cola.enqueue(this.arbol);
		cola.enqueue(null);
		int nivel=0,suma=0;
		while (!cola.isEmpty()) {
			a=cola.dequeue();
			if (a!=null) {
				if(nivel==p) {
					suma+=a.getData().intValue();
				}
				//si estoy en el nivel, sumo y djo de encolar
				else {
					if (a.hasLeftChild()) {
						cola.enqueue(a.getLeftChild());
					}
					if(a.hasRightChild()) {
						cola.enqueue(a.getRightChild());
					}
				}
				
			}
			// si a es null
			else if (!cola.isEmpty()) {
				nivel++;
				cola.enqueue(null);
			}
		}
		return suma;
	}

}
