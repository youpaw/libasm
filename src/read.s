section .text
    global _ft_read
    extern ___error

_ft_read:
    mov rax, 0x02000003
    syscall
	jc lerr
	ret

lerr:
	mov rdx, rax
	push rdx
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret