int main(void) {
  __asm__(
      "jmp push_string\n\t" // Jump to the call instruction to get the address of the string which is right after the call
      "pop_string: pop %rdi\n\t" // Pop off the return address of the call, which is actually the address of the string
      "xor %rdx, %rdx\n\t" // Zero out rdx - without using 0
      "xor %rax, %rax\n\t" // Zero out rax - without using 0
      "mov %rsp, %rsi\n\t" // Move the address of the top on the stack into rsi ????
      "mov %rdx, 8(%rsp)\n\t" // Write 0 in the slot below, without using 0
      "mov %rdi, (%rsp)\n\t" // Move what is in rdi into what the top of stack points to ???
      "mov $0x3b, %al\n\t" // Write the syscall number (59) to al (eax, avoiding zero bytes)
      "syscall\n\t" // Do the syscall
      "push_string: call pop_string\n\t" // Push the address of the next instruction, actually the address of the string
      ".string \"/bin/sh\"\n\t" // The string
    );
}