; loop1.asm
include print.inc

.data
intarray WORD 100h,200h,300h,400h

.code
main proc
	mov edi, OFFSET intarray	; address of intarray
	mov ecx, LENGTHOF intarray	; loop counter(4)
	mov ax, 0			; zero the accumulator
L1:
	add ax, [edi]			; add an integer
	add edi,2			; point	to next	integer(+2)
	loop L1
	call DumpRegs

	mov eax, 0			; exit 0
	call ExitProcess	
main endp
end main