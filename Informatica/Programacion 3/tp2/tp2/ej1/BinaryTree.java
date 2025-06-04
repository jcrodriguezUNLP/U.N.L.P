package tp2.ej1;
import tp1.tp1ej8.*;

public class BinaryTree<T> {
	private T data ;
	private  BinaryTree<T> leftChild;
	private  BinaryTree<T> rightChild;
	
	public BinaryTree(T data) {
		this.data=data;
		this.leftChild=null;
		this.rightChild=null;
	}

	public BinaryTree<T> getLeftChild() {
		return leftChild;
	}

	public void addLeftChild(BinaryTree<T> leftChild) {
		this.leftChild = leftChild;
	}

	public BinaryTree<T> getRightChild() {
		return rightChild;
	}

	public void addRightChild(BinaryTree<T> rightChild) {
		this.rightChild = rightChild;
	}
	
	public void removeLeftChild() {
		this.leftChild=null;
	}	
	
	public void removeRightChild() {
		this.rightChild=null;
	}	
	
	public T getData() {
		return data;
	}
	public boolean isEmpty() {
		if (this.data == null){
			return true;
		}
		return false;
	}
	
	public boolean isLeaf() {
		if(this.leftChild==null && this.rightChild==null ) {
			return true;
		}
		return false;
	}
	
	public boolean  hasLeftChild() {
		return (this.leftChild!=null);
	}
	public boolean  hasRightChild() {
		return (this.rightChild!=null);
	}
	
	public void setData(T data) {
		this.data = data;
	}
	
	public int contarHojas() {
	    if (this.isLeaf()) {  
	        return 1;
	    }
	    
	    int hojas = 0;
	    
	    if (this.hasLeftChild()) {
	        hojas += this.getLeftChild().contarHojas();
	    }
	    if (this.hasRightChild()) {
	        hojas += this.getRightChild().contarHojas();
	    }
	    
	    return hojas;
	}
	
	public BinaryTree<T> espejo(BinaryTree<T> arbol){
		BinaryTree<T> arbolNuevo = new BinaryTree<T>(arbol.getData());
		// aca cree un nuevo arbol con el mismo valor del original
		if (this.isLeaf()) {
			return arbolNuevo;
		}
		// si es una hoja lo devuelve
		
		if(this.hasLeftChild()) {
			BinaryTree<T> right = this.espejo(arbol.getLeftChild());
			arbolNuevo.addLeftChild(right);
		}
		//si tiene hijo izquierdo lo mete a la derecha
		
		if(this.hasRightChild()) {
			BinaryTree<T> left = this.espejo(arbol.getRightChild());
			arbolNuevo.addLeftChild(left);
		}
		//si tiene hijo derecho lo mete a la izquierda
		
		return arbolNuevo;
		
	}
	
	public BinaryTree<T> espejo(){
		BinaryTree<T> arbolNuevo = new BinaryTree<T>(this.getData());
		// aca cree un nuevo arbol con el mismo valor del original
		// si es una hoja lo devuelve
		
		if(this.hasLeftChild()) {
			arbolNuevo.addRightChild(this.getLeftChild().espejo());
		}
		//si tiene hijo izquierdo lo mete a la derecha
		
		if(this.hasRightChild()) {
			arbolNuevo.addLeftChild(this.getRightChild().espejo());
		}
		//si tiene hijo derecho lo mete a la izquierda
		
		return arbolNuevo;
		
		}

	
	public void imprimirPorNiveles() {
		Queue<BinaryTree<T>> cola = new Queue<>();
		BinaryTree<T> ab = null;
		cola.enqueue(this);
		cola.enqueue(null);
		
		while (!cola.isEmpty()) {
			ab=cola.dequeue();
			//si el termine el nivel
			if (ab!=null) {
				System.out.print(ab.getData()+" ");
				if(ab.hasLeftChild()) {
					cola.enqueue(ab.getLeftChild());
				}
				if(ab.hasRightChild()) {
					cola.enqueue(ab.getRightChild());
				}
		}
			else if(!cola.isEmpty()) {
				System.out.println();
			    cola.enqueue(null);
			}
				
			}
	}
	
	public void entreNiveles(int n,int m) {
		Queue<BinaryTree<T>> cola = new Queue<>();
		BinaryTree<T> arbol = null;
		int nivel=0;
		cola.enqueue(this);
		cola.enqueue(null);
		// al no ser recursivo, ya encolo el primero y marco el fin del nivel
		while (!cola.isEmpty() && nivel<=m) {
			arbol=cola.dequeue();
			if (arbol!=null) {
				if (nivel>=n) {
				System.out.println(arbol.getData());
				}
				if (arbol.hasLeftChild()) {
					cola.enqueue(arbol.getLeftChild());
				}
				
				if (arbol.hasRightChild()) {
					cola.enqueue(arbol.getRightChild());
				}
			}
			else if (!cola.isEmpty()) {
				nivel++;
				if (nivel>=n) {
					System.out.println();}
				cola.enqueue(null);
			}
			
		}
		
	}
	
}

