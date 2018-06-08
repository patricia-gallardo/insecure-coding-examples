cmake_minimum_required(VERSION 3.10)
project(insecure_coding_examples)

# CWE 124 : BUFFER UNDERFLOW
add_executable(buffer_underflow buffer_underflow.c)

# CWE 14 : DISAPPEARING MEMSET
add_executable(disappearing_memset disappearing_memset.c)
target_compile_options(disappearing_memset PRIVATE -O3)

# CWE 415 : DOUBLE FREE
add_executable(double_free double_free.c)

# CWE 122 : HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow heap_buffer_overflow.c)

# CWE 704 : INCORRECT TYPE CONVERSION
add_executable(incorrect_type_conversion incorrect_type_conversion.c)

# INFINITE LOOP
add_executable(infinite_loop infinite_loop.c)
target_compile_options(infinite_loop PRIVATE -O3)

# CWE 197 : NUMERIC TRUNCATION
add_executable(numeric_truncation numeric_truncation.c)
target_compile_options(numeric_truncation PRIVATE -Wno-stringop-overflow)

# CWE 190 : SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow signed_integer_overflow.c)
target_compile_options(signed_integer_overflow PRIVATE -Wno-stringop-overflow)

# CWE 121 & CWE 242 : STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow stack_buffer_overflow.c)
set_property(TARGET stack_buffer_overflow PROPERTY C_STANDARD 99)
target_compile_options(stack_buffer_overflow PRIVATE -Wno-deprecated-declarations)

# CWE 134 : UNCONTROLLED FORMAT STRING
add_executable(uncontrolled_format_string uncontrolled_format_string.c)

# UNNAMED LOCK GUARD
add_executable(unnamed_lock_guard unnamed_lock_guard.cpp)
target_compile_features(unnamed_lock_guard PRIVATE cxx_std_17)

# CWE 190 : UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound unsigned_integer_wraparound.c)
target_compile_options(unsigned_integer_wraparound PRIVATE -Wno-stringop-overflow)

# CWE 416 : USE AFTER FREE
add_executable(use_after_free use_after_free.c)