program a ;
const
    dimF = 100 ;

type
    TVector = array[ 1..dimf ] of integer ;

    TLista = ^nodo ;

    nodo = record
        dato : integer ;
        sig  : TLista   ;
    end ;

// vector
    // procedure insertarInicioVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        procedure insertarInicioVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        var
            pos : integer ;
        
        begin
            if( dimL < dimF ) then
            begin
                for pos := dimL downto 1 do
                begin
                    v[ pos + 1 ] := v[ pos ] ;
                end ;
                
                v[ 1 ] := dato       ;
                dimL   := (dimL + 1) ;
            end ;
        end ;
    //

    // procedure insertarUbiVector( var v : TVector ; var dimL : integer ; dato : integer ; ubi : integer ) ;
        procedure insertarUbiVector( var v : TVector ; var dimL : integer ; dato : integer ; ubi : integer ) ;
        var
            pos : integer ;
        
        begin
            if( dimL < dimF ) then
            begin
                for pos := dimL downto ubi do
                begin
                    v[ pos + 1 ] := v[ pos ] ;
                end ;
                
                v[ ubi ] := dato       ;
                dimL     := (dimL + 1) ;
            end ;
        end ;
    //

    // procedure insertarOrdenadoVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        procedure insertarOrdenadoVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        var
            pos : integer ;
            ubi : integer ;

        begin
            if( dimL < dimF ) then
            begin
                pos := 1 ;
                
                while( pos <= dimL ) and ( v[ pos ] < dato ) do
                begin
                    pos := ( pos + 1 ) ;
                end ;

                ubi := pos ;
                
                for pos := dimL downto ubi do
                begin
                    v[ pos + 1 ] := v[ pos ] ;
                end ;

                v[ ubi ] := dato       ;
                dimL     := (dimL + 1) ;
            end ;
        end;
    //

    // procedure insertarFinVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        procedure insertarFinVector( var v : TVector ; var dimL : integer ; dato : integer ) ;
        begin
            if( dimL < dimF ) then
            begin
                dimL      := (dimL + 1) ;
                v[ dimL ] := dato       ;
            end ;
        end ;
    //

    // function minimoVector( v : TVector ; dimL : integer ) : integer ;
        function minimoVector( v : TVector ; dimL : integer ) : integer ;
        var
            pos : integer ;
            min : integer ;
        
        begin
            min := v[ 1 ] ;

            for pos := 2 to dimL do
            begin
                if( v[ pos ] < min ) then
                begin
                    min := v[ pos ] ;
                end ;
            end ;

            minimoVector := min ;
        end ;
    //

    // function promedioVector( v : TVector ; dimL : integer ) : real ;
        function promedioVector( v : TVector ; dimL : integer ) : real ;
        var
            pos : integer ;
            sum : integer ;
        
        begin
            sum := 0 ;

            for pos := 1 to dimL do
            begin
                sum := ( sum + v[ pos ] ) ;
            end ;

            promedioVector := ( sum / dimL ) ;
        end ;
    //

    // function maximoVector( v : TVector ; dimL : integer ) : integer ;
        function maximoVector( v : TVector ; dimL : integer ) : integer ;
        var
            pos : integer ;
            max : integer ;
        
        begin
            max := v[ 1 ] ;

            for pos := 2 to dimL do
            begin
                if( v[ pos ] > max ) then
                begin
                    max := v[ pos ] ;
                end ;
            end ;

            maximoVector := max ;
        end ;
    //

    // function busquedaBinariaVector( v : TVector ; dimL : integer ; dato : integer ) : integer ;
        function busquedaBinariaVector( v : TVector ; dimL : integer ; dato : integer ) : integer ;
        var
            pri : integer ;
            ult : integer ;
            med : integer ;
        
        begin
            pri := 1       ;
            ult := dimL    ;
            med := (pri + ult) div 2 ;

            while( (pri <= ult) and (v[ med ] <> dato) ) do
            begin
                if( v[ med ] < dato ) then
                begin
                    pri := (med + 1) ;
                end else
                begin
                    ult := (med - 1) ;
                end ;

                med := (pri + ult) div 2 ;
            end ;

            if( pri <= ult ) then
            begin
                busquedaBinariaVector := med ;
            end else
            begin
                busquedaBinariaVector := 0 ;
            end ;
        end ;
    //

    // function busquedaSecuencialVector( v : TVector ; dimL : integer ; dato : integer ) : integer ;
        function busquedaSecuencialVector( v : TVector ; dimL : integer ; dato : integer ) : integer ;
        var
            pos : integer ;
        
        begin
            pos := 1 ;

            while( (pos <= dimL) and (v[ pos ] <> dato) ) do
            begin
                pos := (pos + 1) ;
            end ;

            if( pos <= dimL ) then
            begin
                busquedaSecuencialVector := pos ;
            end else
            begin
                busquedaSecuencialVector := 0 ;
            end ;
        end ;
    //
//

// lista
    // procedure insertarInicioLista( var L : TLista ; dato : integer ) ;
        procedure insertarInicioLista( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;
            nue^.sig  := L    ;

            L := aux ;
        end ;
    //

    // procedure insertarOrdenadoLista( var L : TLista ; dato : integer ) ;
        procedure insertarOrdenadoLista( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
            ant : TLista ;
            act : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;

            ant := L ;
            act := L ;

            while( act <> nil ) and ( act^.dato < dato ) do
            begin
                ant := act      ;
                act := act^.sig ;
            end ;

            if( ant = act ) then
            begin
                nue^.sig := L   ;
                L        := nue ;
            end else
            begin
                ant^.sig := nue ;
                nue^.sig := act ;
            end ;
        end ;
    //

    // procedure insertarFinLista( var L : TLista ; dato : integer ) ;
        procedure insertarFinLista( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
            act : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;
            nue^.sig  := nil  ;

            if( L = nil ) then
            begin
                L := nue ;
            end else
            begin
                act := L^.sig ;

                while( act <> nil ) do
                begin
                    act := act^.sig ;
                end ;

                act := nue ;
            end ;
        end ;
    //
//

// lista doblemente enlazada
    // procedure insertarInicioListaDoble( var L : TLista ; dato : integer ) ;
        procedure insertarInicioListaDoble( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;
            nue^.sig  := L    ;
            nue^.ant  := nil  ;

            if( L <> nil ) then
            begin
                L^.ant := nue ;
            end ;

            L := nue ;
        end ;
    //

    // procedure insertarOrdenadoListaDoble( var L : TLista ; dato : integer ) ;
        procedure insertarOrdenadoListaDoble( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
            ant : TLista ;
            act : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;

            ant := L ;
            act := L ;

            while( act <> nil ) and ( act^.dato < dato ) do
            begin
                ant := act      ;
                act := act^.sig ;
            end ;

            if( ant = act ) then
            begin
                nue^.sig := L   ;
                nue^.ant := nil ;
                L        := nue ;
            end else
            begin
                nue^.ant := ant ;
                nue^.sig := act ;

                ant^.sig := nue ;
                act^.ant := nue ;
            end ;
        end ;
    //

    // procedure insertarFinListaDoble( var L : TLista ; dato : integer ) ;
        procedure insertarFinListaDoble( var L : TLista ; dato : integer ) ;
        var
            nue : TLista ;
            act : TLista ;
        
        begin
            new( nue ) ;

            nue^.dato := dato ;
            nue^.sig  := nil  ;

            if( L = nil ) then
            begin
                nue^.ant := nil ;
                L        := nue ;
            end else
            begin
                act := L ;

                while( act^.sig <> nil ) do
                begin
                    act := act^.sig ;
                end ;

                nue^.ant := act ;
                act^.sig := nue ;
            end ;
        end ;
    //
//

begin
    WriteLn( 'Unit cargada' ) ;
end.