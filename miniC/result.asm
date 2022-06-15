.data 
string_0: .asciiz "Input list ...\n"
string_5: .asciiz "Sorted Element List ...\n"
string_6: .asciiz "\nNumber of passes taken to sort the list:"
string_7: .asciiz "\n"

.global main

.text
test: 
addiu $sp, $sp, -20

sw $ra, 0($sp)

li $t0, 0

sw $t0, 16($sp)


la $a0, string_0
li $v0, 4
syscall

li $t0, 0

sw $t0, 4($sp)

while_1: 
lw $t0, 4($sp)

li $t1, 10

slt $t0, $t0, $t1

beqz $t0, endWhile_2
lw $t0, 4($sp)

li $t1, 1

add $t0, $t0, $t1

sw $t0, 8($sp)

while_3: 
lw $t0, 8($sp)

li $t1, 10

slt $t0, $t0, $t1

beqz $t0, endWhile_4
lw $t0, 8($sp)

li $t1, 1

add $t0, $t0, $t1

sw $t0, 8($sp)


j while_3
endWhile_4: 

lw $t0, 4($sp)

li $t1, 1

add $t0, $t0, $t1

sw $t0, 4($sp)

lw $t0, 16($sp)

li $t1, 1

add $t0, $t0, $t1

sw $t0, 16($sp)


j while_1
endWhile_2: 


la $a0, string_5
li $v0, 4
syscall


la $a0, string_6
li $v0, 4
syscall

lw $t0, 16($sp)

move $a0, $t0
li $v0, 1
syscall


la $a0, string_7
li $v0, 4
syscall



addiu $sp, $sp, 20
jr $ra

