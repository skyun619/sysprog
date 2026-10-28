int sum(int n)
{
	int result;
	__asm {
		mov eax, 0
		mov ebx, n
		cmp ebx, 0
		jle L2
		mov ecx, ebx
	L1 : add eax, ecx
		loop L1
	L2 : mov result, eax
	}
	return result;
}
