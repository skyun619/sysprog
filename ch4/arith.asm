; arith.asm
include print.inc

.data
R	dword ?
X  	dword 26
Y  	dword 30
Z  	dword 40
.code
main proc
	mov 	eax, X	; EAX = -X	
	neg 	eax 	;  -26
	mov 	ebx, Y	; EBX = Y - Z
	sub 	ebx, Z 	;  -10
	add 	eax,ebx ; EAX = (-X)+(Y-Z)
	mov 	R, eax 	;  -36
	
	mov 	eax, R		; print R
	call	WriteHex
	mov		eax, 0		; exit 0
	call	ExitProcess	
main endp
end main
