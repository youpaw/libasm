section .text
    global ft_strcmp

ft_strcmp:
    mov r8, 0
    mov rdx, 0
    mov rax, 0

loop:
    mov al, byte [rdi + r8]
    mov dl, byte [rsi + r8]
    sub rax, rdx
    cmp rax, 0
    jne lret
    cmp rdx, 0
    je lret
    inc r8
    jmp loop

lret:
    ret
