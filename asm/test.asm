.data
    temp: .ascii "Hola mundo!"
.text
.globl main

main:
    la $s0, temp
    lw $t1, 0($s0)
    lw $t2, 4($s0)

    move $a0, $s0
    li $v0, 4
    syscall

    li $v0, 10
    syscall