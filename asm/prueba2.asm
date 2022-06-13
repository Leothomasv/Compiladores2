.data

array: .space 20

msg: .asciiz "\n Ingrese numero: "

.text
.globl main


main:
    li $t0 0 #i = 0
    la $t1, array #pos = 0
while:
    la $a0, msg
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    move $t2, $v0 #t2

    sw $t2, 0($t1) #arr[pos]

    addi $t1, $t1, 4
    addi $t0, $t0, 1
    blt $t0, 5  , while

 li $v0, 10
 syscall
