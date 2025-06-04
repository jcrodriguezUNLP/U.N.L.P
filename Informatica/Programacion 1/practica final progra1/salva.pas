program salva ;
type
    TCaracteres = set of char ;

// procedure leerCaracteres( var ingresados : TCaracteres ) ;
    procedure leerCaracteres( var ingresados : TCaracteres ) ;
    var
        abcdarioMin : char ;

    begin
        WriteLn ;
        write( 'Introduzca los caracteres del conjunto, finalizando con #: ' ) ;
        read( abcdarioMin ) ;

        while( abcdarioMin <> '#' ) do
        begin
            ingresados := ingresados + [ abcdarioMin ] ;
            read( abcdarioMin ) ;
        end ;

    end ;
//

// procedure fueraDelConjunto(  var abcdarioMin : TCaracteres ; var ingresados : TCaracteres ) ;
    procedure fueraDelConjunto(  var abcdarioMin : TCaracteres ; var ingresados : TCaracteres ) ;
    var
        numCarsFuera : integer ;
        i            : char    ;

    begin
        numCarsFuera := 0 ;

        writeln ;
        for i := 'a' to 'z' do
        begin
            if( not(i in ingresados) ) then
            begin
                numCarsFuera := numCarsFuera + 1 ;
                write( i , ' ' ) ;
            end;
        end;
        
        writeln ;
        writeln ;
        writeln( 'El numCarsFueraero de caracteres que no pertenecen al conjunto es: ', numCarsFuera ) ;
    end ;
//

var
    abcdarioMin : TCaracteres ;
    ingresados : TCaracteres ;

    caracteingresados : char ;

begin
    abcdarioMin := [ 'a' .. 'z' ] ;
    ingresados := [] ;

    leerCaracteres( ingresados ) ;
    fueraDelConjunto( abcdarioMin, ingresados ) ;
end.