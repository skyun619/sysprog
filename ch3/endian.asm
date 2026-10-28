; endian.asm
include print.inc

.data
val1 dword 12345678h

.code
main proc
	mov	esi, offset val1	; start address
	mov	ecx, 4			; 4 units
	mov	ebx, 1			; byte 
	call	DumpMem

	mov	eax, 0			; exit 0
	call	ExitProcess	
main endp
end main
