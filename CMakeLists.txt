cmake_minimum_required(VERSION 3.10)
project(insecure_coding_examples)

# -----------------------------------------------------------------
#
# EXPLOITABLE
#
# -----------------------------------------------------------------

# CWE 124 : BUFFER UNDERFLOW
add_executable(buffer_underflow exploitable/buffer_underflow.c)

# CWE 416 : USE AFTER FREE - string_view
add_executable(dangling_pointer exploitable/dangling_pointer.cpp)
target_compile_features(dangling_pointer PRIVATE cxx_std_17)

# CWE 14 : DISAPPEARING MEMSET
add_executable(disappearing_memset exploitable/disappearing_memset.c)
target_compile_options(disappearing_memset PRIVATE -O3)

# CWE 415 : DOUBLE FREE
add_executable(double_free exploitable/double_free.c)

# CWE 122 : HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow exploitable/heap_buffer_overflow.c)

# CWE 122 : HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow_cwe exploitable/heap_buffer_overflow_cwe.c)

# CWE 704 : INCORRECT TYPE CONVERSION
add_executable(incorrect_type_conversion exploitable/incorrect_type_conversion.cpp)

# INFINITE LOOP CPP
add_executable(infinite_loop_cpp exploitable/infinite_loop.cpp)
target_compile_options(infinite_loop_cpp PRIVATE -O3 -Waggressive-loop-optimizations)

# CWE 197 : NUMERIC TRUNCATION
add_executable(numeric_truncation exploitable/numeric_truncation.c)

# CWE 197 : NUMERIC TRUNCATION
add_executable(numeric_truncation_ubsan exploitable/numeric_truncation_ubsan.c)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow exploitable/signed_integer_overflow.c)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow_simple exploitable/signed_integer_overflow_simple.c)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow_ubsan exploitable/signed_integer_overflow_ubsan.c)

# CWE 121 & CWE 242 : STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow exploitable/stack_buffer_overflow.c)
set_property(TARGET stack_buffer_overflow PROPERTY C_STANDARD 99)
target_compile_options(stack_buffer_overflow PRIVATE -Wno-deprecated-declarations)

# CWE 121 : STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow_cwe exploitable/stack_buffer_overflow_cwe.c)

# CWE 416 : USE AFTER FREE
add_executable(temporary_capture exploitable/temporary_capture.cpp)

# CWE-134 : Use of Externally-Controlled Format String
add_executable(uncontrolled_format_string exploitable/uncontrolled_format_string.c)

# UNNAMED LOCK GUARD
add_executable(unnamed_lock_guard exploitable/unnamed_lock_guard.cpp)
target_compile_features(unnamed_lock_guard PRIVATE cxx_std_17)

# CWE 190 : UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound exploitable/unsigned_integer_wraparound.c)

# CWE 190 : UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound_ubsan exploitable/unsigned_integer_wraparound_ubsan.c)

# CWE 416 : USE AFTER FREE
add_executable(use_after_free exploitable/use_after_free.c)

# COMPILER OPTIMIZATIONS OF UNDEFINED BEHAVIOR
add_executable(undefined_behavior exploitable/undefined_behavior.cpp)
target_compile_options(undefined_behavior PRIVATE -Wno-overflow)

# -----------------------------------------------------------------
#
# PRACTICE
#
# -----------------------------------------------------------------

add_executable(commandline practice/commandline.cpp)

add_executable(concat_strings practice/concat_strings.cpp)

# Array Pointer Decay
add_executable(decay practice/decay.cpp)
target_compile_features(decay PRIVATE cxx_std_17)

add_executable(constexpr_ub practice/if_constexpr.cpp)
target_compile_features(constexpr_ub PRIVATE cxx_std_17)
target_compile_options(constexpr_ub PRIVATE -Wno-overflow)

# Needs C++20
#add_executable(midpoint_library practice/midpoint_library.cpp)
#target_compile_features(constexpr_ub PRIVATE cxx_std_20)

add_executable(downcasting practice/downcasting.cpp)

add_executable(enum_class practice/enum_class.cpp)

# Needs clang 7 or gcc 8
#add_executable(filesystem practice/filesystem.cpp)
#target_compile_features(filesystem PRIVATE cxx_std_17)

add_executable(string_literals practice/string_literals.cpp)

add_executable(strip_after_colon practice/strip_after_colon.cpp)

add_executable(user_defined_literals practice/user_defined_literals.cpp)

# -----------------------------------------------------------------
#
# EXPLOIT
#
# -----------------------------------------------------------------

# -----------------------------------------------------------------
# SMASHING: From Smashing The Stack For Fun And Profit, Aleph One, Phrack 49
# -----------------------------------------------------------------

# Shellcode
add_executable(shellcode exploit/smashing/shellcode.c)
# keep the assembly
set_target_properties(shellcode PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(shellcode PRIVATE -Os)
# link in execve - check with ldd ./cmake-build-release/shellcode
set_target_properties(shellcode PROPERTIES LINK_FLAGS "-static")
# remove the stack protector : "call   0x44b950 <__stack_chk_fail_local>"
target_compile_options(shellcode PRIVATE -fno-stack-protector)

# Exit code
add_executable(exitcode exploit/smashing/exit.c)
# keep the assembly
set_target_properties(exitcode PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(exitcode PRIVATE -Os)
# link in exit- check with ldd ./cmake-build-release/exitcode
set_target_properties(exitcode PROPERTIES LINK_FLAGS "-static")

# Shellcode asm
add_executable(shellcodeasm exploit/smashing/shellcodeasm.c)
# keep the assembly
set_target_properties(shellcodeasm PROPERTIES COMPILE_FLAGS "-save-temps")
# make the code small
target_compile_options(shellcodeasm PRIVATE -O0)

# Shellcode test
add_executable(testshellcode exploit/smashing/test_shellcode.c)
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

# -----------------------------------------------------------------
# HANDBOOK
# -----------------------------------------------------------------

# Find stackpointer
add_executable(find_stackpointer exploit/handbook/find_stackpointer.c)

# -----------------------------------------------------------------
# FORMAT: Hacking, the Art of Exploitation (Jon Erickson)
# -----------------------------------------------------------------

add_executable(getenvaddr exploit/format/getenvaddr.c)

add_executable(format_exploitable exploit/format/exploitable.c)
target_compile_options(format_exploitable PRIVATE -Wno-format-security)

add_executable(format_exploitable_simple exploit/format/exploitable_simple.c)
target_compile_options(format_exploitable_simple PRIVATE -Wno-format-security)

# Shellcode test
add_executable(environment_variable_shellcode exploit/format/environment_variable_shellcode.c)
# remove the stack protector
# *** stack smashing detected ***: <unknown> terminated
# Aborted (core dumped)
target_compile_options(environment_variable_shellcode PRIVATE -fno-stack-protector)
# Make the stack executable - otherwise Segmentation fault (core dumped)
set_target_properties(environment_variable_shellcode PROPERTIES LINK_FLAGS "-z execstack")

# -----------------------------------------------------------------
# WARGAMES
# -----------------------------------------------------------------

# Wargames C
## -------------------------
add_executable(launch exploit/wargames/launch.c)
# Get gets - removed from C11
set_property(TARGET launch PROPERTY C_STANDARD 99)
# Remove most of the warnings about gets
target_compile_options(launch PRIVATE -Wno-deprecated-declarations)
# Remove Fortify protection in libc
#*** buffer overflow detected ***: ./launch terminated
#Aborted (core dumped)
target_compile_options(launch PRIVATE -D_FORTIFY_SOURCE=0)
# remove the stack protector
# *** stack smashing detected ***: <unknown> terminated
# Aborted (core dumped)
target_compile_options(launch PRIVATE -fno-stack-protector)
# Make the stack executable - otherwise Segmentation fault (core dumped)
set_target_properties(launch PROPERTIES LINK_FLAGS "-z execstack")

# Wargames C++
# -------------------------
add_executable(launch_cpp exploit/wargames/launch.cpp)
# remove the stack protector
# *** stack smashing detected ***: <unknown> terminated
# Aborted (core dumped)
target_compile_options(launch_cpp PRIVATE -fno-stack-protector)

# Wargames Fixed C++
# -------------------------
add_executable(launch_fixed_cpp exploit/wargames/launch_fixed.cpp)

# Stack Variable Overwrite Exploit
# -------------------------
add_executable(simple_exploit exploit/wargames/stack_variable_exploit.c)

# Wargames C++
# -------------------------
add_executable(launch_bigger exploit/wargames/launch_bigger.cpp)
# remove the stack protector
# *** stack smashing detected ***: <unknown> terminated
# Aborted (core dumped)
target_compile_options(launch_bigger PRIVATE -fno-stack-protector)

# Attempt 1: Shellcode inspirted by Smashing the Stack for Fun and Profit
# Test
# -------------------------
add_executable(simple_stack_overflow_test exploit/wargames/smashing_shellcode_test.c)
# Exploit
# -------------------------
add_executable(simple_stack_overflow_exploit exploit/wargames/smashing_shellcode_exploit.c)

# Attempt 2: Shellcode that pushes the string on the stack to null terminate it
# Test
# -------------------------
add_executable(simple_stack_overflow_test2 exploit/wargames/push_string_shellcode_test.c)
# Exploit
# -------------------------
add_executable(simple_stack_overflow_exploit2 exploit/wargames/push_string_shellcode_exploit.c)

# Attempt 3: Stack Buffer Shellcode in C
# C code
# -------------------------
add_executable(shellcode_tty exploit/wargames/tty_shellcode.c)
# Inline Asm
# -------------------------
add_executable(shellcode_asm exploit/wargames/tty_shellcode_asm.c)
# Test
# -------------------------
add_executable(shellcode_test exploit/wargames/tty_shellcode_test.c)
# Exploit
# -------------------------
add_executable(shellcode_exploit exploit/wargames/tty_shellcode_exploit.c)
