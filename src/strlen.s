section .text
    global _ft_strlen

_ft_strlen:
    mov rcx, 0
    lcmp:
    cmp rdi, 0
    je lexit
    inc rdi
    inc rcx
    jmp lcmp
   lexit:
    mov rdi, rcx
    ret