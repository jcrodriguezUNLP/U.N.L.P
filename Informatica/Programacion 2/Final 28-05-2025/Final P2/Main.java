public class Main {
    public static void main( String[] args ) {
        Equipo equipo1 = new Equipo() ;
        Equipo equipo2 = new Equipo() ;

        Personaje aventurero1 = new Guerrero( "aventurero1" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero2 = new Mago( "aventurero2" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero3 = new Guerrero( "aventurero3" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero4 = new Mago( "aventurero4" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero5 = new Guerrero( "aventurero5" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero6 = new Mago( "aventurero6" , 1 , 10 , 10 , 2 ) ;
        
        equipo1.agregarAventurero( aventurero1 ) ;
        equipo1.agregarAventurero( aventurero2 ) ;
        equipo1.agregarAventurero( aventurero3 ) ;
        equipo1.agregarAventurero( aventurero4 ) ;
        equipo1.agregarAventurero( aventurero5 ) ;
        equipo1.agregarAventurero( aventurero6 ) ;
        
        Personaje aventurero7 = new Guerrero( "aventurero7" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero8 = new Mago( "aventurero8" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero9 = new Guerrero( "aventurero9" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero10 = new Mago( "aventurero10" , 1 , 10 , 10 , 2 ) ;
        Personaje aventurero11 = new Guerrero( "aventurero11" , 1 , 10 , 10 , 2 ) ;
        
        equipo2.agregarAventurero( aventurero7 ) ;
        equipo2.agregarAventurero( aventurero8 ) ;
        equipo2.agregarAventurero( aventurero9 ) ;
        equipo2.agregarAventurero( aventurero10 ) ;
        equipo2.agregarAventurero( aventurero11 ) ;

        Personaje aventureroAModificar = equipo1.obtenerAventurero(1) ;

        aventureroAModificar.subirDeNivel() ;
        aventureroAModificar.recibirDanio( 7 ) ;
        aventureroAModificar.recibirDanio( 1 ) ;

        equipo1.agregarAventurero( aventureroAModificar ) ;
    }
}