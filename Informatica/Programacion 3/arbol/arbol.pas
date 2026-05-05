program ArbolBinarioDinamicoPorNiveles ;

const
    MAX_COLA = 2000 ; // Tamaño suficiente para almacenar los nodos y fantasmas

type
    // 1. Estructura del Árbol Dinámico
    PArbol = ^TNodo ;
    TNodo  = record
        dato : integer ;
        HI   : PArbol ;
        HD   : PArbol ;
    end ;

    // 2. Estructura de la Cola Auxiliar para el BFS
    TCola = record
        datos  : array[1..MAX_COLA] of PArbol ;
        frente : integer ;
        fin    : integer ;
    end ;

// ==============================================================================
// MÓDULOS DE LA COLA (QUEUE)
// ==============================================================================
procedure InicializarCola( var c : TCola ) ;
begin
    c.frente := 1 ;
    c.fin    := 0 ;
end ;

procedure Encolar( var c : TCola ; a : PArbol ) ;
begin
    c.fin := c.fin + 1 ;
    c.datos[ c.fin ] := a ;
end ;

function Desencolar( var c : TCola ) : PArbol ;
var
    aux : PArbol ;
begin
    aux := c.datos[ c.frente ] ;
    c.frente := c.frente + 1 ;
    Desencolar := aux ;
end ;

// ==============================================================================
// MÓDULOS MATEMÁTICOS Y DE ESPACIADO
// ==============================================================================
function Potencia2( exp : integer ) : integer ;
var
    resultado : integer ;
    i         : integer ;
begin
    resultado := 1 ;
    i         := 0 ;
    while ( i < exp ) do
    begin
        resultado := resultado * 2 ;
        i         := i + 1 ;
    end ;
    Potencia2 := resultado ;
end ;

procedure ImprimirEspacios( cant : integer ) ;
var
    i : integer ;
begin
    i := 0 ;
    while ( i < cant ) do
    begin
        write( ' ' ) ;
        i := i + 1 ;
    end ;
end ;

function CalcularEspaciosEntreBarras( nivelInvertido : integer ) : integer ;
var
    resultado : integer ;
    i         : integer ;
begin
    resultado := 5 ;
    i         := 2 ;
    if ( nivelInvertido = 0 ) then
    begin
        resultado := 0 ;
    end
    else if ( nivelInvertido = 1 ) then
    begin
        resultado := 5 ;
    end
    else
    begin
        while ( i <= nivelInvertido ) do
        begin
            resultado := ( resultado * 2 ) + 1 ;
            i         := i + 1 ;
        end ;
    end ;
    CalcularEspaciosEntreBarras := resultado ;
end ;

function CalcularEspaciosAntesBarras( nivelInvertido : integer ) : integer ;
var
    resultado : integer ;
begin
    resultado := 0 ;
    if ( nivelInvertido = 0 ) then
    begin
        resultado := 0 ;
    end
    else
    begin
        resultado := 3 * ( Potencia2( nivelInvertido - 1 ) - 1 ) + 1 ;
    end ;
    CalcularEspaciosAntesBarras := resultado ;
end ;

// ==============================================================================
// MÓDULOS DEL ÁRBOL BINARIO DE BÚSQUEDA (BST)
// ==============================================================================
procedure InicializarArbol( var a : PArbol ) ;
begin
    a := nil ;
end ;

procedure InsertarBST( var a : PArbol ; num : integer ) ;
begin
    if ( a = nil ) then
    begin
        new( a ) ;
        a^.dato := num ;
        a^.HI   := nil ;
        a^.HD   := nil ;
    end
    else if ( num < a^.dato ) then
    begin
        InsertarBST( a^.HI, num ) ;
    end
    else
    begin
        InsertarBST( a^.HD, num ) ;
    end ;
end ;

procedure ConstruirArbolAleatorio( var a : PArbol ; cantNodos : integer ) ;
var
    i   : integer ;
    num : integer ;
begin
    i := 0 ;
    while ( i < cantNodos ) do
    begin
        num := Random( 10 ) ; // 0 a 9 para no romper la geometría de 1 caracter
        InsertarBST( a, num ) ;
        i := i + 1 ;
    end ;
end ;

function CantNiveles( a : PArbol ) : integer ;
var
    altI, altD : integer ;
begin
    if ( a = nil ) then
    begin
        CantNiveles := -1 ;
    end
    else
    begin
        altI := CantNiveles( a^.HI ) ;
        altD := CantNiveles( a^.HD ) ;
        if ( altI > altD ) then
        begin
            CantNiveles := altI + 1 ;
        end
        else
        begin
            CantNiveles := altD + 1 ;
        end ;
    end ;
end ;

// ==============================================================================
// MÓDULO: GraficarArbol_Por_Nivel (Traducción exacta de Java BFS)
// ==============================================================================
procedure GraficarArbol_Por_Nivel( a : PArbol ) ;
var
    nivelMax             : integer ;
    nivel                : integer ;
    nivelInvertido       : integer ;
    espaciosIniciales    : integer ;
    cantidadNodosXNivel  : integer ;
    espaciosEntreNodos   : integer ;
    espaciosAntesBarras  : integer ;
    espaciosDentroBarras : integer ;
    espaciosEntreBarras  : integer ;
    i                    : integer ;
    cola                 : TCola ;
    nodo                 : PArbol ;
begin
    // --- 1. INICIALIZACIÓN ---
    if ( a = nil ) then
    begin
        writeln( 'El arbol esta vacio.' ) ;
    end
    else
    begin
        nivelMax := CantNiveles( a ) ;
        InicializarCola( cola ) ;
        Encolar( cola, a ) ;
        nivel := 0 ;

        // --- 2. PROCESAMIENTO ---
        while ( nivel <= nivelMax ) do
        begin
            nivelInvertido      := nivelMax - nivel ;
            espaciosIniciales   := Potencia2( nivelInvertido + 1 ) - 2 ;
            cantidadNodosXNivel := Potencia2( nivel ) ;
            espaciosEntreNodos  := Potencia2( nivelInvertido + 2 ) - 1 ;

            write( 'Nivel ', nivel, ': ' ) ;
            ImprimirEspacios( espaciosIniciales ) ;

            i := 0 ;
            while ( i < cantidadNodosXNivel ) do
            begin
                nodo := Desencolar( cola ) ;

                if ( nodo <> nil ) then
                begin
                    write( nodo^.dato ) ;
                    Encolar( cola, nodo^.HI ) ;
                    Encolar( cola, nodo^.HD ) ;
                end
                else
                begin
                    write( ' ' ) ;
                    Encolar( cola, nil ) ; // Inyectar nodos fantasmas para simetría
                    Encolar( cola, nil ) ;
                end ;

                if ( i < ( cantidadNodosXNivel - 1 ) ) then
                begin
                    ImprimirEspacios( espaciosEntreNodos ) ;
                end ;

                i := i + 1 ;
            end ;
            writeln() ; // Salto de línea después de los nodos

            if ( nivel < nivelMax ) then
            begin
                espaciosAntesBarras  := CalcularEspaciosAntesBarras( nivelInvertido ) ;
                espaciosDentroBarras := Potencia2( nivelInvertido ) - 1 ;
                espaciosEntreBarras  := CalcularEspaciosEntreBarras( nivelInvertido ) ;

                ImprimirEspacios( 9 ) ;
                ImprimirEspacios( espaciosAntesBarras ) ;

                i := 0 ;
                while ( i < cantidadNodosXNivel ) do
                begin
                    write( '/' ) ;
                    ImprimirEspacios( espaciosDentroBarras ) ;
                    write( '\' ) ;

                    if ( i < ( cantidadNodosXNivel - 1 ) ) then
                    begin
                        ImprimirEspacios( espaciosEntreBarras ) ;
                    end ;

                    i := i + 1 ;
                end ;
                writeln() ; // Salto de línea después de las barras
            end ;

            nivel := nivel + 1 ;
        end ;
    end ;
end ;

// ==============================================================================
// MAIN: Orquestador
// ==============================================================================
var
    miArbol       : PArbol ;
    nodosAGenerar : integer ;
begin
    // --- 1. INICIALIZACIÓN ---
    Randomize ;
    nodosAGenerar := 0 ;
    InicializarArbol( miArbol ) ;

    // --- 2. PROCESAMIENTO ---
    write( 'Ingrese la cantidad de nodos aleatorios a generar (ej. 7): ' ) ;
    readln( nodosAGenerar ) ;

    ConstruirArbolAleatorio( miArbol, nodosAGenerar ) ;

    // --- 3. SALIDA ---
    writeln() ;
    writeln( 'ARBOL BINARIO DE BUSQUEDA (Impreso por BFS Nivel a Nivel):' ) ;
    writeln( '-----------------------------------------------------------' ) ;
    GraficarArbol_Por_Nivel( miArbol ) ;
    writeln( '-----------------------------------------------------------' ) ;
    
    writeln() ;
    writeln( 'Presione ENTER para salir...' ) ;
    readln() ;
end.