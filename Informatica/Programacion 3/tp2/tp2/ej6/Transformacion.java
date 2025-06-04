package tp2.ej6;
import tp2.ej1.BinaryTree;

public class Transformacion {
	private BinaryTree<Integer> arbol;
	public Transformacion(BinaryTree<Integer> arbol) {
		this.arbol=arbol;
	}
	
	public BinaryTree<Integer> suma(){
		 sumaPrivate(this.arbol);
		 return arbol;
	}
	
	private Integer sumaPrivate(BinaryTree<Integer> arbol){
		Integer suma=arbol.getData();
		Integer valorNodo=suma;
		if (arbol.isLeaf()) {
			arbol.setData(0);
			return valorNodo;
		}
		
		if (arbol.hasLeftChild()) {
			suma+= sumaPrivate(arbol.getLeftChild());
		}
		if (arbol.hasRightChild()) {
			suma+= sumaPrivate(arbol.getRightChild());
		}
		arbol.setData(suma-valorNodo);
		return suma;
		
	}

}
