.data
    CADENA_A: .asciiz "Esta es una cadena."
    CADENA_B: .asciiz "Esta es otra cadena"
    RES: .word 0

.code
    ; Inicializar SP para el entorno del simulador
    daddi $sp, $zero, 0x400

    daddi $a0, $0, CADENA_A
    daddi $a1, $0, CADENA_B

    jal COMPARAR_CADENAS

    sd $v0, RES($0)
halt

SON_IGUALES:
    ; recibe:
    ;   $a0: carcter
    ;   $a1: caracter
    ; retorna:
    ;   $v0: 1 si son iguales, 0 si no lo son

    dsub $t0, $a0, $a1
    beqz $t0, iguales

    daddi $v0, $0, 0
    j FIN_SON_IGUALES

    iguales:
        daddi $v0, $0, 1

    FIN_SON_IGUALES:
jr $ra

COMPARAR_CADENAS:
    ; recibe:
    ;   $a0: direccion de la primera cadena
    ;   $a1: direccion de la segunda cadena
    ; retorna:
    ;   $v0: 1 si son iguales, 0 si no lo son

    ; salvar $ra, $s0, $s1
    daddi $sp, $sp, -24
    sd $s0,  0($sp)
    sd $s1,  8($sp)
    sd $ra, 16($sp)

    dadd $s0, $a0, $0   ; $s0 = dir cadena A
    dadd $s1, $a1, $0   ; $s1 = dir cadena B

    COMPARAR_LOOP:
        lbu $a0, 0($s0)   ; cargar caracter de cadena A
        lbu $a1, 0($s1)   ; cargar caracter de cadena B
        
        dsub $t0, $a0, $0
        beqz $t0, salirBucle  ; si llegamos al final de la cadena A

        jal SON_IGUALES

        daddi $s0, $s0, 1  ; avanzar al siguiente caracter en cadena A
        daddi $s1, $s1, 1  ; avanzar al siguiente caracter en cadena B
    bnez $v0, COMPARAR_LOOP  ; si son iguales, continuar

    ; $v0 = 0 (no son iguales)
    ; $v0 = 1 (son iguales)

    salirBucle:
        ; restablecer $ra, $s0, $s1
        ld $s0, 0($sp)
        ld $s1, 8($sp)
        ld $ra, 16($sp)
        daddi $sp, $sp, 24
jr $ra