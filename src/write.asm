section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1
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