; addtwo.asm
include print.inc
.data
sum dword ?

.code
main proc
	push 6
	push 5
	call addtwo
	add esp, 8
	mov sum, eax

	call DumpRegs
	mov eax, 0
	call ExitProcess
main endp

addtwo proc
	push ebp
	mov ebp, esp
	mov eax, [ebp+12]	; y
	add eax, [ebp+8]	; x
	pop ebp
	ret
addtwo endp
end main