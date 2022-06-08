.data
  palabra: .space 20
  msg: .asciiz "\nIngrese una palabra (max 20 letras):"
.text
.globl main


main:
  la $a0, msg
  li $v0, 4
  syscall

  li $v0, 8
  la $a0, palabra
  li $a1, 20
  syscall

  li $t0, 0
  la $t1, palabra
  li $t2, 20

  while:
    lb $a0, 0($t1)
    li $v0, 11
    syscall

    addi $t1, $t1, 1
    addi $t0, $t0, 1
    ble $t0, $t2, while

  li $v0, 10
  syscall