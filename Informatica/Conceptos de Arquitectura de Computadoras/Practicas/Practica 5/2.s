; 2) Es posible convertir valores enteros almacenados en alguno de los registros r1-r31 a su representación equivalente en punto flotante y viceversa.
;    Describa la funcionalidad de las instrucciones mtc1, cvt.l.d, cvt.d.l y mfc1.

; mtc1: Mueve un valor entero desde un registro de propósito general (r1-r31) a un registro de punto flotante (f0-f31).
; cvt.l.d: Convierte un valor de punto flotante de doble precisión (f0-f31) a un valor entero de 64 bits y lo almacena en un registro de propósito general (r1-r31).
; cvt.d.l: Convierte un valor entero de 64 bits (r1-r31) a un valor de punto flotante de doble precisión (f0-f31).
; mfc1: Mueve un valor desde un registro de punto flotante (f0-f31) a un registro de propósito general (r1-r31).
; Estas instrucciones permiten la interoperabilidad entre los registros de propósito general y los registros de punto flotante, facilitando operaciones mixtas entre enteros y números de punto flotante en el MIPS64.