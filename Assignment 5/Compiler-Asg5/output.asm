	.486
	.model flat, stdcall
	option casemap :none

	include \masm32\include\windows.inc
	include \masm32\macros\macros.asm

	include \masm32\include\masm32.inc
	include \masm32\include\gdi32.inc
	include \masm32\include\user32.inc
	include \masm32\include\kernel32.inc
	include \masm32\include\msvcrt.inc

	includelib \masm32\lib\masm32.lib
	includelib \masm32\lib\gdi32.lib
	includelib \masm32\lib\user32.lib
	includelib \masm32\lib\kernel32.lib
	includelib \masm32\lib\msvcrt.lib

	.data
	 temp0 DD ?
	 temp1 DD ?
	 temp2 DD ?
	 temp3 DD ?
	 temp4 DD ?
	 temp5 DD ?

	.code
start:
	call main
	exit
main proc
	LOCAL var0 :DWORD
	LOCAL var1 :DWORD
	LOCAL var2 :DWORD
	mov temp0, 0
	mov eax, temp0
	mov var0, eax
	mov temp1, 0
	mov eax, temp1
	mov var1, eax
	mov temp2, 0
	mov eax, temp2
	mov var0, eax
@1:
	mov temp3, 5
	mov eax, var0
	cmp eax, temp3
	jl @0
	jmp @2
@0:
	mov temp4, 1
	mov eax, temp4
	mov var2, eax
	print str$(var2)
	print chr$(13, 10)
	mov temp5, 3
	mov eax, var0
	cmp eax, temp5
	je @3
	jmp @4
@3:
	jmp @2
@4:
	inc var0
	jmp @1
@2:
	print str$(var1)
	print chr$(13, 10)
	ret
main endp
end start
