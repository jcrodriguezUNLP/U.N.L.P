Program luisMiguelOriginal ;
Uses
     sysutils;
Type
     str70= string[70];
     
	 persona = record
        DNI: longint;
	    nombre_apellido: str70;
        correo:str70;
	    pago:str70;
     end;

	fecha=record
		dia:1..31;
		mes:1..12;
		anio:integer;
	end;
	
    entrada= record
		codigo: longint;
		butaca: 1..100;
		fila: 1..10;
		precio: real;
		fecha_show: fecha;
        platea: 'A'..'K';
		comprador: persona;
     end;
     
	 lista = ^nodoLista;
     nodoLista = record
	    dato: entrada;
	    sig: lista;
     end;
     
	 nombres= array [1..20] of str70;
     plateas= array [1..11] of char;
	 dias= array [1..10] of integer;

     {Completar con los tipos de datos necesarios}

procedure cargarFecha(var f: fecha);
var
v:dias;
pos:integer;
begin
  v[1]:=3;
  v[2]:=4;
  v[3]:=6;
  v[4]:=8;
  v[5]:=9;
  v[6]:=12;
  v[7]:=15;
  v[8]:=16;
  v[9]:=17;
  v[10]:=18;
  pos:=random(10)+1;
  f.dia:=v[pos];
  f.mes := 8;
  f.anio:=2023;
end;

Procedure agregar(var l: lista; e: entrada);
var
      aux: lista;
begin
     new(aux);
     aux^.dato := e;
     aux^.sig := l;
     l:= aux;
end;

procedure cargarComprador(var p: persona);
var
   pos: integer;
   v,v2,v3: nombres;
begin
	{Nombres}
     v[1]:='Lionel Perez';
     v[2]:='Martin Fernandez';
     v[3]:='Mariano Gomez';
     v[4]:='Alejandro Gonzalez';
     v[5]:='Fermin Martinez';
     v[6]:='Nicolas Castro';
     v[7]:='Gonzalo Villareal';
     v[8]:='Tadeo Pardo';
     v[9]:='Juan Pablo Silvestre';
     v[10]:='Mariano Tello';
     v[11]:='Alejo Ruiz';
     v[12]:='Agustin Paz';
     v[13]:='Juan Salto';
     v[14]:='Matias Pidone';
     v[15]:='Luis Hernandez';
     v[16]:='Cristian Herrera';
     v[17]:='Santiago Manzur';
     v[18]:='Julian Darino';
     v[19]:='Victor Abila';
     v[20]:='Luciano Segura';
	 {Correos}
	 v2[1]:='lionel.perez@gmail.com';
     v2[2]:='martin.fernandez@gmail.com';
     v2[3]:='mariano.gomez@gmail.com';
     v2[4]:='alejandro.gonzalez@gmail.com';
     v2[5]:='fermin.martinez@gmail.com';
     v2[6]:='nicolas.castro@gmail.com';
     v2[7]:='gonzalo.villareal@gmail.com';
     v2[8]:='tadeo.pardo@gmail.com';
     v2[9]:='juan.pablo.silvestre@gmail.com';
     v2[10]:='mariano.tello@gmail.com';
     v2[11]:='alejo.ruiz@gmail.com';
     v2[12]:='agustin.paz@gmail.com';
     v2[13]:='juan.salto@gmail.com';
     v2[14]:='matias.pidone@gmail.com';
     v2[15]:='luis.hernandez@gmail.com';
     v2[16]:='cristian.herrera@gmail.com';
     v2[17]:='santiago.manzur@gmail.com';
     v2[18]:='julian.darino@gmail.com';
     v2[19]:='victor.abila@gmail.com';
     v2[20]:='luciano.segura@gmail.com';
	 {M�todo de pago}
	 v3[1]:='Tarjeta de Credito';
     v3[2]:='Tarjeta de Debito';
     v3[3]:='Efectivo';
	 
   with(p) do begin
	  DNI := random(18000000)+20000000;
	  pos:= random(20)+1;
	  nombre_apellido:= v[pos];
	  correo:= v2[pos];
	  pago:=v3[random(3)+1];
   end;
end;

procedure crearLista(var l: lista);
var
   e: entrada;
   cant,i,j,pos,repe: integer;
   v: plateas;
begin
     cant := random(100)+1;
     v[1]:= 'A';
     v[2]:= 'B';
     v[3]:= 'C';
     v[4]:= 'D';
     v[5]:= 'E';
     v[6]:= 'F';
     v[7]:= 'G';
     v[8]:= 'H';
     v[9]:= 'I';
     v[10]:= 'J';
     v[11]:= 'K';
     for i:=1 to cant do
     begin
          with(e) do begin
               codigo:= random (100000)+1;
               butaca:=random (100)+1;
			   fila:=random (10)+1;
			   pos:= random(11)+1;
			   platea:=v[pos];
			   precio:=random(75000)+10000;
			   cargarFecha(fecha_show);
               cargarComprador(comprador);
          end;
          agregar(l, e);
          repe:=random(3)+1;
          if(repe>2)then
          begin
          for j:=1 to repe do
          begin
               with(e) do begin
               codigo:= random (100000)+1;
               butaca:=random (100)+1;
			   fila:=random (10)+1;
			   pos:= random(11)+1;
			   platea:=v[pos];
			   precio:=random (75000)+10000;
			   cargarFecha(fecha_show);
               end;
              agregar(l, e);
          end;
          end;
       end;
end;


procedure imprimirComprador(p: persona);
begin
     with (p) do begin
          writeln('COMPRADOR: ', nombre_apellido, ' | DNI: ',DNI, ' | CORREO: ', correo, ' | PAGO: ', pago);
     end;
end;

procedure imprimir(e: entrada);
begin
     with (e) do begin
          writeln('');
          writeln('ENTRADA: ', codigo, ' | BUTACA: ',butaca, ' | FILA: ', fila, ' | PLATEA: ', platea, ' | precio: ', precio:0:2, ' | FECHA: ', fecha_show.dia,'/',fecha_show.mes,'/',fecha_show.anio);
          imprimirComprador(comprador);
     end;
end;

procedure imprimirLista(l: lista);
begin
     while (l <> nil) do begin
          imprimir(l^.dato);
          l:= l^.sig;
     end;
end;


var
   l: lista;
begin
     Randomize;

     l:= nil;
     crearLista(l); {carga automatica de la estructura disponible}
     writeln ('LISTA GENERADA: ');
     imprimirLista(l);

     {Completar el programa}

     writeln('Fin del programa');
     readln;
end.
