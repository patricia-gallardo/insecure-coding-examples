cmake_minimum_required(VERSION 3.10)
project(insecure_coding_examples)

# CWE 124 : BUFFER UNDERFLOW
add_executable(buffer_underflow vulnerable/buffer_underflow.c)

# CWE 14 : DISAPPEARING MEMSET
add_executable(disappearing_memset vulnerable/disappearing_memset.c)
target_compile_options(disappearing_memset PRIVATE -O3)

# CWE 415 : DOUBLE FREE
add_executable(double_free vulnerable/double_free.c)

# CWE 122 : HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow vulnerable/heap_buffer_overflow.c)

# CWE 122 : HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow_cwe vulnerable/heap_buffer_overflow_cwe.c)

# CWE 704 : INCORRECT TYPE CONVERSION
add_executable(incorrect_type_conversion vulnerable/incorrect_type_conversion.c)

# INFINITE LOOP CPP
add_executable(infinite_loop_cpp vulnerable/infinite_loop.cpp)
target_compile_options(infinite_loop_cpp PRIVATE -O3 -Waggressive-loop-optimizations)

# CWE 197 : NUMERIC TRUNCATION
add_executable(numeric_truncation vulnerable/numeric_truncation.c)
target_compile_options(numeric_truncation PRIVATE -Wno-stringop-overflow)

# CWE 197 : NUMERIC TRUNCATION
add_executable(numeric_truncation_ubsan vulnerable/numeric_truncation_ubsan.c)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow vulnerable/signed_integer_overflow.c)
target_compile_options(signed_integer_overflow PRIVATE -Wno-stringop-overflow)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow_ubsan vulnerable/signed_integer_overflow_ubsan.c)

# CWE 121 & CWE 242 : STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow vulnerable/stack_buffer_overflow.c)
set_property(TARGET stack_buffer_overflow PROPERTY C_STANDARD 99)
target_compile_options(stack_buffer_overflow PRIVATE -Wno-deprecated-declarations)

# CWE 121 : STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow_cwe vulnerable/stack_buffer_overflow_cwe.c)

# CWE-134 : Use of Externally-Controlled Format String
add_executable(uncontrolled_format_string vulnerable/uncontrolled_format_string.c)

# UNNAMED LOCK GUARD
add_executable(unnamed_lock_guard vulnerable/unnamed_lock_guard.cpp)
target_compile_features(unnamed_lock_guard PRIVATE cxx_std_17)

# CWE 190 : UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound vulnerable/unsigned_integer_wraparound.c)
target_compile_options(unsigned_integer_wraparound PRIVATE -Wno-stringop-overflow)

# CWE 190 : UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound_ubsan vulnerable/unsigned_integer_wraparound_ubsan.c)

# CWE 416 : USE AFTER FREE
add_executable(use_after_free vulnerable/use_after_free.c)

# COMPILER OPTIMIZATIONS OF UNDEFINED BEHAVIOR
add_executable(undefined_behavior vulnerable/undefined_behavior.cpp)
target_compile_options(undefined_behavior PRIVATE -Wno-overflow)

add_executable(commandline alternative/commandline.cpp)

add_executable(concat_strings alternative/concat_strings.cpp)

add_executable(downcasting alternative/downcasting.cpp)

add_executable(enum_class alternative/enum_class.cpp)

add_executable(string_literals alternative/string_literals.cpp)

add_executable(strip_after_colon alternative/strip_after_colon.cpp)

add_executable(user_defined_literals alternative/user_defined_literals.cpp)

# From Smashing The Stack For Fun And Profit, Aleph One, Phrack 49

# Shellcode
add_executable(shellcode smashing/shellcode.c)
# keep the assembly
set_target_properties(shellcode PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(shellcode PRIVATE -Os)
# link in execve - check with ldd ./cmake-build-release/shellcode
set_target_properties(shellcode PROPERTIES LINK_FLAGS "-static")
# remove the stack protector : "call   0x44b950 <__stack_chk_fail_local>"
target_compile_options(shellcode PRIVATE -fno-stack-protector)

# Exit code
add_executable(exitcode smashing/exit.c)
# keep the assembly
set_target_properties(exitcode PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(exitcode PRIVATE -Os)
# link in exit- check with ldd ./cmake-build-release/exitcode
set_target_properties(exitcode PROPERTIES LINK_FLAGS "-static")

# Shellcode asm
add_executable(shellcodeasm smashing/shellcodeasm.c)
# keep the assembly
set_target_properties(shellcodeasm PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(shellcodeasm PRIVATE -O0)

# Shellcode test
add_executable(testshellcode smashing/test_shellcode.c)
# keep the assembly
set_target_properties(testshellcode PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(testshellcode PRIVATE -O0)
# remove warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
target_compile_options(testshellcode PRIVATE -Wno-pointer-to-int-cast)
# remove the stack protector
# *** stack smashing detected ***: <unknown> terminated
# Aborted (core dumped)
target_compile_options(testshellcode PRIVATE -fno-stack-protector)
# Make the stack executable - otherwise Segmentation fault (core dumped)
set_target_properties(testshellcode PROPERTIES LINK_FLAGS "-z execstack")

# Find stackpointer
add_executable(find_stackpointer handbook/find_stackpointer.c)