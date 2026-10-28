.386
.model flat, C
.code
sum proc
	push ebp
	mov ebp, esp

	mov eax, 0
	mov ebx, [ebp+8]
	cmp ebx, 0	 
	jle L2
	mov ecx, ebx
L1:	add eax, ecx
	loop L1

L2:	pop ebp
	ret
sum endp
end