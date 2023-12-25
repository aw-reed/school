.data
enterNum: .asciiz "Please enter a number: "
even_sum: .asciiz "Sum of even numbers is: "
odd_sum: .asciiz "Sum of odd numbers is: "
newline: .asciiz "\n"
.text
.globl main
main:
    li $s0, 0 # even_sum = 0
    li $s1, 0 # odd_sum = 0
loop:
    # print prompt
    la $a0, enterNum
    li $v0, 4
    syscall
    # read integer
    li $v0, 5
    syscall
    move $t0, $v0 # t0 = integer input
    beq $t0, $zero, done # exit loop if input is 0
    andi $t1, $t0, 0x1 # t1 = input % 2
    bne $t1, $zero, add_odd # if input is odd, go to add_odd
    add $s0, $s0, $t0 # add input to even_sum
    j loop # continue loop
add_odd:
    add $s1, $s1, $t0 # add input to odd_sum
    j loop # continue loop
done:
    # print even sum
    la $a0, even_sum
    li $v0, 4
    syscall
    move $a0, $s0
    li $v0, 1
    syscall
    # print newline
    la $a0, newline
    li $v0, 4
    syscall
    # print odd sum
    la $a0, odd_sum
    li $v0, 4
    syscall
    move $a0, $s1
    li $v0, 1
    syscall
    # print newline
    la $a0, newline
    li $v0, 4
    syscall
    # exit program
    li $v0, 10
    syscall
