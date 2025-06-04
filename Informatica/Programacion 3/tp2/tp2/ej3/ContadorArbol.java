package tp2.ej3;

import java.util.LinkedList;

import tp2.ej1.BinaryTree;

public class ContadorArbol {

	private BinaryTree<Integer> arbol;
	
	public ContadorArbol(BinaryTree<Integer> arbol) {
		this.arbol=arbol;
	}
	
	public LinkedList<Integer> numerosParesInOrder(){
		LinkedList<Integer> lista = new LinkedList<Integer>();
		numerosParesInOrderPriv(this.arbol,lista);
		return lista;
		
	}
	
	private void numerosParesInOrderPriv(BinaryTree<Integer> arbol,LinkedList<Integer> lista ){
		
		
		
		if (arbol.hasLeftChild()){
			numerosParesInOrderPriv(arbol.getLeftChild(),lista);
		}
		
		if ((arbol.getData()%2)==0) {
			lista.add(arbol.getData());
		} // si cambio esto cambia el orden
		
		if (arbol.hasRightChild()){
			numerosParesInOrderPriv(arbol.getRightChild(),lista);
		}
		
		
		
		
	}
	
}
