; main2.asm  (require addtwo2.asm)
include print.inc

addtwo proto

.data
sum dword ?

.code
main proc
	push 6
	push 5
	call addtwo
;	add esp, 8
	mov sum, eax
	
	call DumpRegs
	mov eax, 0
	call ExitProcess
main endp
end main

