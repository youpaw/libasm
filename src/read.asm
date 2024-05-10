section .text
    global ft_read
    extern __errno_location

ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
	jl lerr
	ret

lerr:
    neg rax
	mov rdx, rax
	call [rel __errno_location wrt ..got]
	mov [rax], rdx
	mov rax, -1
	ret