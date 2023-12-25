.data
n:	.word 25
str1:	.asciiz "Less than \n"
str2:	.asciiz "Less than or equal to\n"
str3:	.asciiz "Greater than\n"
str4:	.asciiz "Greater than or equal to\n"
integer:	.asciiz "Enter an integer: "

.text
.globl main
main:
	# print integer statement
	la $a0, integer
	li $v0, 4
	syscall
	
	# get integer from user
	li $v0, 5
	syscall
	move $t0, $v0
	
	# compare with n
	lw $t1, n	# load n from memory
	slt $t2, $t0, $t1	# set $t2 to 1 if $t0 < $t1
	beq $t2, 1, lessthan # if $t2 is 1, print str1
	sltu $t2, $t0, $t1
	beq $t2, 1, lessthanequal
	j greaterthan
	
lessthan:
	# print less than
	la $a0, str1
	li $v0, 4
	syscall
	j exit
	
lessthanequal:
	# print less than or equal to
	la $a0, str2
	li $v0, 10
	syscall
	j exit
	
greaterthan:
	# print greater than
	la $a0, str3
	li $v0, 4
	syscall
	
greaterthanequal:
	# print greater than or equal to
	la $a0, str4
	li $v0, 4
	syscall
	
exit:
	# exit program
	li $v0, 10
	syscall
