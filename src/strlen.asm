BITS 64

section .text
global ft_strlen

ft_strlen:
    mov rax, 0

loop:
    cmp byte [rdi + rax], 0
    je lret
    inc rax
    jmp loop

lret:
    ret
