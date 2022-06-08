.data
inputmessage: .asciiz "\n Ingresar numero: "
suma: .asciiz "\n La suma es: "
resta: .asciiz "\n La resta es: "
multi: .asciiz "\n La multiplicacion es: "
divi: .asciiz "\n La division es: "

.text
.globl main

main:

    li $v0, 4
    la $a0, inputmessage
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    
    li $v0, 4
    la $a0, inputmessage
    syscall

    li $v0, 5
    syscall

    move $t1, $v0

    add $t2, $t0, $t1
    sub $t3, $t0, $t1
    mult $t0, $t1
    mflo $t4
    mfhi $t5
    div $t0, $t1
    mflo $t6


    li $v0, 4
    la $a0, suma
    syscall
    move $a0, $t2
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, resta
    syscall
    move $a0, $t3
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, multi
    syscall
    move $a0, $t4
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, divi
    syscall
    move $a0, $t6
    li $v0, 1
    syscall

    li $v0, 10
    syscall