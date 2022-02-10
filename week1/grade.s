main:


    la  $a0, string
    li  $v0, 4
    syscall

     li   $v0, 5          # scanf("%d", x);
     syscall

    move $t0, $v0
loop:
    bge $t0, 85, HD
    bge $t0, 75, DN
    bge $t0, 65, CR
    bge $t0, 50, PS
    bge $t0, 0, FL

HD:
    la  $a0, string1
    li  $v0, 4
    syscall
    b return

DN:
    la  $a0, string2
    li  $v0, 4
    syscall
    b return
CR:
    la  $a0, string3
    li  $v0, 4
    syscall
    b return

PS:
    la  $a0, string4
    li  $v0, 4
    syscall
    b return

FL:
    la  $a0, string5
    li  $v0, 4
    syscall
    b return

return:
    li  $v0, 0      # return 0
    jr  $ra


    .data
string:
    .asciiz "Enter a mark: "
string1:
    .asciiz "HD\n"
string2:
    .asciiz "DN\n"
string3:
    .asciiz "CR\n"
string4:
    .asciiz "PS\n"
string5:
    .asciiz "FL\n"
