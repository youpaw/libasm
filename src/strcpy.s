section .text
    global _ft_strcpy

_ft_strcpy:
    mov rcx, 0
    mov rax, rdi

    loop:
    mov dl, byte [rsi + rcx]
    mov byte [rdi + rcx], dl
    cmp byte [rsi + rcx], 0
    je lret
    inc rcx
    jmp loop

    lret:
    ret