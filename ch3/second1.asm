.386
.model flat, stdcall
.stack 4096

; prototype declaration
ExitProcess proto,dwExitCode:dword	; exit 
DumpRegs proto				; print registers
DumpMem proto				; print memory area

.data
sum dword 0

.code
main proc
	mov	eax,5				
	add	eax,6				
	mov	sum,eax
	
	call	DumpRegs

	mov	esi, offset sum		; start address
	mov	ecx, 1			; number of units
	mov	ebx, 4			; unit size (B)
	call	DumpMem

	mov	eax, 0			; exit 0
	call	ExitProcess	
main endp
end main
