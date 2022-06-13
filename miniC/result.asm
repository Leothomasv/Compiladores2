.data 
string_2: .asciiz "\t"
string_3: .asciiz "\n"
string_6: .asciiz "\t"
string_7: .asciiz "\n"
string_8: .asciiz "Input list ...\n"
string_13: .asciiz "Sorted Element List ...\n"
string_14: .asciiz "\nNumber of passes taken to sort the list:"
string_15: .asciiz "\n"

.global main

.text

li.s $f0, 2.5

li.s $f1, 4.6

add.s $f0, $f0, $f1

mov.s $f12, $f0
li $v0, 2
syscall

while_0: 

bc1f endWhile_1



la $a0, string_2
li $v0, 4
syscall



j while_0
endWhile_1: 


la $a0, string_3
li $v0, 4
syscall


while_4: 

bc1f endWhile_5



la $a0, string_6
li $v0, 4
syscall



j while_4
endWhile_5: 


la $a0, string_7
li $v0, 4
syscall




la $a0, string_8
li $v0, 4
syscall



while_9: 

bc1f endWhile_10

while_11: 

bc1f endWhile_12



j while_11
endWhile_12: 




j while_9
endWhile_10: 


la $a0, string_13
li $v0, 4
syscall



la $a0, string_14
li $v0, 4
syscall




la $a0, string_15
li $v0, 4
syscall


