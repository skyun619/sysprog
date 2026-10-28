; addtwo2.asm 
include print.inc

.code
addtwo proc
	push ebp
	mov ebp, esp
	mov eax, [ebp+12]	; y
	add eax, [ebp+8]	; x
	pop ebp
;	ret
	ret 8
addtwo endp
end
