import java.util.List ;
import java.util.Queue ;
import java.util.LinkedList ;

public class GeneralTree<T> {
    private T data ;
    private List<GeneralTree<T>> children = new LinkedList<>() ;

    // Constructores
        public GeneralTree( T data ) {
			this.data = data ; 
		}

        public GeneralTree( T data , List< GeneralTree<T> > children ) {
            this.data = data ;
            this.children = children ;
        }
    //

    // Getters
        public T getData() { return( data) ; }

        public List< GeneralTree<T> > getChildren() { return( this.children ) ; }
    //

    // Setters
        public void setData(T data) { this.data = data ; }

        public void setChildren( List< GeneralTree<T> > children ) {
            if (children != null){
				 this.children = children ; 
			}
        }

        public void addChild( GeneralTree<T> child ) { this.getChildren().add( child ) ; }
    //

    // Métodos
        public boolean isLeaf() { return( !this.hasChildren() ) ; }

        public boolean hasChildren() { return( (children != null) && !children.isEmpty() ) ; }

        public boolean isEmpty() { return( (this.data == null) && !hasChildren() ) ; }

        public void removeChild(GeneralTree<T> child) {
            if (this.hasChildren()) {
                List<GeneralTree<T>> children = this.getChildren() ;
                if (children.contains(child)) { children.remove(child) ; }
            }
        }

        // Agregar nodo al primer nivel incompleto (Grado 3)
        public void agregarNodoPrimerVacioGrado3(GeneralTree<T> nodo) {
            if (this.isEmpty()) {
                this.data = nodo.getData() ;
                this.children = nodo.getChildren() ;
            } else {
                boolean fin = false ;
                GeneralTree<T> treeAux ;
                Queue<GeneralTree<T>> queue = new LinkedList<>() ;

                queue.add(this) ;

                do {
                    treeAux = queue.poll() ;

                    if (treeAux.getChildren().size() < 3) {
                        treeAux.addChild(nodo) ;
                        fin = true ;
                    } else {
                        List<GeneralTree<T>> children = treeAux.getChildren() ;

                        for (GeneralTree<T> child : children) {
                            queue.add(child) ;
                        }
                    }
                } while (!queue.isEmpty() && !fin) ;
            }
        }
    //
}
