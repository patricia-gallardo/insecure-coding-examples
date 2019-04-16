# Notes and examples
## Background

The code and examples are based on the article ['Smashing The Stack For Fun And Profit'][1] by Aleph One in Phrack magazine issue 49

## shellcode.c

~~~~
$ more cmake-build-release/shellcode.s
	.file	"shellcode.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"/bin/sh"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	leaq	.LC0(%rip), %rdi
	xorl	%edx, %edx
	movq	%rsp, %rsi
	movq	$0, 8(%rsp)
	movq	%rdi, (%rsp)
	call	execve@PLT
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
~~~~

~~~~
(gdb) set disassembly-flavor intel
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000400599 <+0>:	sub    rsp,0x18
   0x000000000040059d <+4>:	lea    rdi,[rip+0x919a0]        # 0x491f44
   0x00000000004005a4 <+11>:	xor    edx,edx
   0x00000000004005a6 <+13>:	mov    rsi,rsp
   0x00000000004005a9 <+16>:	mov    QWORD PTR [rsp+0x8],0x0
   0x00000000004005b2 <+25>:	mov    QWORD PTR [rsp],rdi
   0x00000000004005b6 <+29>:	call   0x448ac0 <execve>
   0x00000000004005bb <+34>:	xor    eax,eax
   0x00000000004005bd <+36>:	add    rsp,0x18
   0x00000000004005c1 <+40>:	ret    
End of assembler dump.
(gdb) disassemble execve
Dump of assembler code for function execve:
   0x0000000000448ac0 <+0>:	mov    eax,0x3b
   0x0000000000448ac5 <+5>:	syscall 
   0x0000000000448ac7 <+7>:	cmp    rax,0xfffffffffffff001
   0x0000000000448acd <+13>:	jae    0x448ad0 <execve+16>
   0x0000000000448acf <+15>:	ret    
   0x0000000000448ad0 <+16>:	mov    rcx,0xffffffffffffffc0
   0x0000000000448ad7 <+23>:	neg    eax
   0x0000000000448ad9 <+25>:	mov    DWORD PTR fs:[rcx],eax
   0x0000000000448adc <+28>:	or     rax,0xffffffffffffffff
   0x0000000000448ae0 <+32>:	ret    
End of assembler dump.
~~~~
~~~~
objdump -d shellcode (excerpt)
0000000000400599 <main>:
  400599:	48 83 ec 18          	sub    $0x18,%rsp
  40059d:	48 8d 3d a0 19 09 00 	lea    0x919a0(%rip),%rdi        # 491f44 <_IO_stdin_used+0x4>
  4005a4:	31 d2                	xor    %edx,%edx
  4005a6:	48 89 e6             	mov    %rsp,%rsi
  4005a9:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  4005b0:	00 00 
  4005b2:	48 89 3c 24          	mov    %rdi,(%rsp)
  4005b6:	e8 05 85 04 00       	callq  448ac0 <__execve>
  4005bb:	31 c0                	xor    %eax,%eax
  4005bd:	48 83 c4 18          	add    $0x18,%rsp
  4005c1:	c3                   	retq   
  4005c2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4005c9:	00 00 00 
  4005cc:	0f 1f 40 00          	nopl   0x0(%rax)
0000000000448ac0 <__execve>:
  448ac0:	b8 3b 00 00 00       	mov    $0x3b,%eax
  448ac5:	0f 05                	syscall 
  448ac7:	48 3d 01 f0 ff ff    	cmp    $0xfffffffffffff001,%rax
  448acd:	73 01                	jae    448ad0 <__execve+0x10>
  448acf:	c3                   	retq   
  448ad0:	48 c7 c1 c0 ff ff ff 	mov    $0xffffffffffffffc0,%rcx
  448ad7:	f7 d8                	neg    %eax
  448ad9:	64 89 01             	mov    %eax,%fs:(%rcx)
  448adc:	48 83 c8 ff          	or     $0xffffffffffffffff,%rax
  448ae0:	c3                   	retq   
  448ae1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  448ae8:	00 00 00 
  448aeb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
~~~~

## exit.c

## shellcodeasm.c

Regs            Val-1               Val-2
rdi             0x1	                0x4004a5
rdx             0x7fffffffdd38	    0x0
rax             0x400480	        0x3b
rsp             0x7fffffffdc38	    0x7fffffffdc40
rsi             0x7fffffffdd28	    0x7fffffffdc40

0x7fffffffdc40 : 0x00000000004004a5
0x7fffffffdc48 : 0x0000000000000000


[1]: http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf
