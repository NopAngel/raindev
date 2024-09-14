section .data
msg: DB '#021210555', 10
msgSize EQU $ - msg

global start

section .text

    start:
    mov rax, 4
    mov rbx, 1
    mov rcx, msg
    mov rdx, msgSize
    int 0x800