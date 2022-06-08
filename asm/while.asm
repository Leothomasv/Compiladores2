.data
message: .asciiz "\n Ingrese numero: "
result: .asciiz "\n current: "
.text
.globl main

main:

    li $v0, 4
    la $a0, message
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    li $t2, 1
while:

    addi $t3, $t2, 1
    li $v0, 4
    la $a0,  result
    syscall
    
    mult $t2, $t3
    mflo $a0

    li $v0, 1
    syscall

    addi $t2, $t2, 1
    ble $t2, $t0, while



    li $v0, 10
    syscall