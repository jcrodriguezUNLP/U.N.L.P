import java.util.List ;
import java.util.LinkedList ;

// ==============================================================================
// CLASE: GeneralTree - Estructura de datos recursiva de árbol general
// ==============================================================================
//   estado (Atributos):
//     - T data: El valor contenido en el nodo.
//     - List< GeneralTree< T > > children: Lista de subárboles hijos.
//   comportamiento (Métodos):
//     - getters/setters para los atributos.
//     - addChild/removeChild: Gestión de la lista de hijos.
//     - hasChildren/isLeaf/isEmpty: Verificación de estado del árbol.
//   restricciones:
//     - Ninguna específica sobre el tipo T.
// ==============================================================================

public class GeneralTree< T > {
    private T data ;

    private List< GeneralTree<T> > children ;

    // constructores
        public GeneralTree( T data ) {
            this.data = data ;

            this.children = new LinkedList< GeneralTree<T> >() ;
        }
        
        public GeneralTree( T data , List< GeneralTree<T> > children ) {
            this.data = data ;
            
			this.children = children ;
        }
    //
	
    // getters
        public T getData() { return( data ) ; }
        
		public List< GeneralTree<T> > getChildren() { return( children ) ; }
    //

    // setters
        public void setData( T data ) {
            this.data = data ;
        }

        public void setChildren( List< GeneralTree<T> > children ) {
            if ( children != null ) {
                this.children = children ;
            }
        }

        public void addChild( GeneralTree<T> child ) {
            children.add( child ) ;
        }

        public void removeChild( GeneralTree<T> child ) {
            if ( hasChildren() ) {
                if ( children.contains( child ) ) {
                    children.remove( child ) ;
                }
            }
        }
    //

    // metodos
        public boolean hasChildren() {
            return( ( children != null ) && !children.isEmpty() ) ;
        }

        public boolean isEmpty() {
            return( ( data == null ) && !hasChildren() ) ;
        }

        public boolean isLeaf() {
            return( !hasChildren() ) ;
        }
    //
}
