.data
array: .space 16
msg: .asciiz "\n Numero: "
swapmsg: .asciiz "\n Swap numero en posicion: "
swapmsg2: .asciiz "\n con numero en posicion: "
.text
.globl main

main:

    li $t0, 0 #i = 0
    la $t1, array #pos = 0
while:

    #imprimir mensaje
    la $a0, msg
    li $v0, 4
    syscall

    #leer entero de consola
    li $v0, 5
    syscall
    move $t2, $v0 #t2 = numero que lei de consola

    #guardar en array
    sw $t2, 0($t1) #arr[pos] = numero que lei de consola

    #incrementar posicion en array
    addi $t1, $t1, 4 # pos+=4
    #incrementar contador
    addi $t0, $t0, 1 # i++
    blt $t0, 4, while

    #imprimir mensaje
    la $a0, swapmsg
    li $v0, 4
    syscall

    #leer entero de consola
    li $v0, 5
    syscall
    move $t1, $v0

    #imprimir mensaje
    la $a0, swapmsg2
    li $v0, 4
    syscall

    #leer entero de consola
    li $v0, 5
    syscall
    move $t2, $v0

    #swap
    la $t0, array
    li $t3, 4
    mult $t1, $t3 
    mflo $t1
    add $t1, $t1, $t0
    lw $t4, 0($t1)

    mult $t2, $t3 
    mflo $t2
    add $t2, $t2, $t0
    lw $t5, 0($t2)

    sw $t5, 0($t1)
    sw $t4, 0($t2)


    li $v0, 10
    syscall



