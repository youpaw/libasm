section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy

ft_strdup:
    cmp rdi, 0
    je lnull
    push rdi
    call ft_strlen
    mov rdi, rax
    inc rdi
    call [rel malloc wrt ..got]
    cmp rax, 0
	je lret
	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret

lnull:
	mov rax, 0
lret:
	ret
