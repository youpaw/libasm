section .text
    global _ft_strcmp

_ft_strcmp:
    mov rcx, 0
    mov rax, 0

    loop:
    mov al, byte [rdi + rcx]
    sub al, byte [rsi + rcx]
    cmp al, 0
    jne lret
    cmp byte [rdi + rcx], 0
    jne lret
    inc rcx
    jmp loop

    lret:
    ret