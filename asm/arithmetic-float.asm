.data
.text
.globl main

main:
    li $t0, 5
    li.s $f1, 2.5
    mtc1 $t0, $f0
    add.s $f2, $f0, $f1
    sub.s $f3, $f0, $f1
    div.s $f4, $f0, $f1
    mul.s $f5, $f0, $f1
    li $v0, 10
    syscall

