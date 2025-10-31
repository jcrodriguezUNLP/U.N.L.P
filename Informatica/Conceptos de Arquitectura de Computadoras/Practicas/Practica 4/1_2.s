; 2. VonSim vs WinMIPS64 ⭐   
; Indicar qué instrucciones se corresponden entre el simulador VonSim y el simulador WinMIPS64.
; Tener en cuenta que algunas de las instrucciones del VonSim pueden hacerse de distintas formas en WinMIPS64.
; y otras no pueden hacerse con una sola instrucción.
; Por ende, algunas instrucciones de la columna izquierda corresponden a varias de la derecha, y otras no corresponden a ninguna 
; Nota:  para  simplificar, usaremos los registros del WinMIPS64(r0  a  r31) como nombres de registro en las instrucciones del VonSim.  
 
; VonSim                  | WinMIPS64 
; ------------------------+---------------------
; mov r1, r2              | ld r1, variable(r0) 
; mov r1, 1               | sd r1, variable(r0) 
; mov r1, 0               | halt 
; add r1, r2              | jal etiqueta 
; add r1, 1               | j etiqueta 
; add r1, 0               | or r1, r1, r0 
; inc r1                  | or r1, r1, r2 
; dec r1                  | ori r1, r1, 1 
; or r1, r2               | dadd r1, r1, r0 
; or r1, 1                | daddi r1, r0, 0 
; or r1, 0                | daddi r1, r0, 1 
; mov r1, variable        | dadd r1, r0, r0 
; mov variable, r1        | dadd r1, r0, r2 
; add r1, variable        | daddi r1, r1, 1 
; add variable, r1        | dadd r1, r1, r2  
; mov r1, offset variable | daddi r1, r0, variable 
; jump etiqueta           | daddi r1, r2, 0 
; call etiqueta           | daddi r1, r1, -1
; hlt                     |

; VonSim                  | WinMIPS64              | accion 
; ------------------------+------------------------+-----------------------------------
; mov r1, r2              | dadd  r1, r2, r0       | r1 := r2
; ------------------------+------------------------+-----------------------------------
; mov r1, 1               | daddi r1, r0, 1        | r1 := 1
; ------------------------+------------------------+-----------------------------------
; mov r1, 0               | daddi r1, r0, 0        | r1 := 0
; ------------------------+------------------------+-----------------------------------
; add r1, r2              | dadd  r1, r1, r2       | r1 := r1 + r2
; ------------------------+------------------------+-----------------------------------
; add r1, 1               | daddi r1, r1, 1        | r1 := r1 + 1
; ------------------------+------------------------+-----------------------------------
; add r1, 0               | daddi r1, r1, 0        | r1 := r1 + 0 (no-op)
; ------------------------+------------------------+-----------------------------------
; inc r1                  | daddi r1, r1, 1        | r1 := r1 + 1
; ------------------------+------------------------+-----------------------------------
; dec r1                  | daddi r1, r1, -1       | r1 := r1 - 1
; ------------------------+------------------------+-----------------------------------
; or r1, r2               | or    r1, r1, r2       | r1 := r1 OR r2
; ------------------------+------------------------+-----------------------------------
; or r1, 1                | ori   r1, r1, 1        | r1 := r1 OR 1
; ------------------------+------------------------+-----------------------------------
; or r1, 0                | ori   r1, r1, 0        | r1 := r1 OR 0
; ------------------------+------------------------+-----------------------------------
; mov r1, variable        | ld    r1, variable(r0) | r1 := MEM[variable]
; ------------------------+------------------------+-----------------------------------
; mov variable, r1        | sd    r1, variable(r0) | MEM[variable] := r1
; ------------------------+------------------------+-----------------------------------
; add r1, variable        | ld    rX, variable(r0) | rX := MEM[var]
;                         | dadd  r1, r1, rX       | r1 := r1 + rX
; ------------------------+------------------------+-----------------------------------
; add variable, r1        | ld    rX, variable(r0) | temp := MEM[var]
;                         | dadd  rX, rX, r1       | temp := temp + r1
;                         | sd    rX, variable(r0) | MEM[var] := temp
; ------------------------+------------------------+-----------------------------------
; mov r1, offset variable | daddi r1, r0, variable | r1 := address_of(variable)
; ------------------------+------------------------+-----------------------------------
; jump etiqueta           | j   etiqueta           | salto incondicional
; ------------------------+------------------------+-----------------------------------
; call etiqueta           | jal etiqueta           | call / link (guarda return addr)
; ------------------------+------------------------+-----------------------------------
; halt                    | halt                   | detener la ejecución
; ------------------------+------------------------+-----------------------------------