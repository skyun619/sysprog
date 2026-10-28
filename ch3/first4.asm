; first4.asm
include print.inc

.data
sum dword 0

.code
main proc
	mov	eax,5				
	add	eax,6				
	mov	sum,eax
	call	WriteHex		; Write EAX register

	mov	eax, 0		; exit 0
	call	ExitProcess	
main endp
end main
