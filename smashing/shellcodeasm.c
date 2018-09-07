int main(void) {
  __asm__(
      "jmp 0x1a\n\t" // To the call to get the address of the string which is right after the call
      "pop %rdi\n\t" // Pop off the return address, which is actually the address of the string
      "xorl %edx, %edx\n\t" // Zero out edx
      "mov %rsp, %rsi\n\t" // Move the address of the top on the stack into rsi ????
      "mov %edx, 8(%rsp)\n\t" // Write 0 in the slot below, without using 0
      "mov %rdi, (%rsp)\n\t" // Move what is in rdi into what the top of stack points to ???
      "mov $0x3b, %al\n\t" // Write the syscall number (59) to al (eax, avoiding zero bytes)
      "syscall\n\t" // Do the syscall
      "call -0x1f\n\t" // Push the address of the next instruction, actually the address of the string, call offset is from next instruction
      ".string \"/bin/sh\"\n\t" // The string
    );
}