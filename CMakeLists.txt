cmake_minimum_required(VERSION 3.10)
project(insecure_coding_examples)

set(CMAKE_CXX_STANDARD 11)

# CWE 124 : BUFFER UNDERFLOW
add_executable(buffer_underflow buffer_underflow.c)

# DISAPPEARING MEMSET
add_executable(disappearing_memset disappearing_memset.c)

# DOUBLE FREE
add_executable(double_free double_free.c)

# HEAP BUFFER OVERFLOW
add_executable(heap_buffer_overflow heap_buffer_overflow.c)

# INCORRECT TYPE CONVERSION
add_executable(incorrect_type_conversion incorrect_type_conversion.c)

# INFINITE LOOP
add_executable(infinite_loop infinite_loop.c)
target_compile_options(infinite_loop PRIVATE -O3)

# NUMERIC TRUNCATION
add_executable(numeric_truncation numeric_truncation.c)
target_compile_options(numeric_truncation PRIVATE -Wno-stringop-overflow)

# SIGNED INTEGER OVERFLOW
add_executable(signed_integer_overflow signed_integer_overflow.c)
target_compile_options(signed_integer_overflow PRIVATE -Wno-stringop-overflow)

# STACK BUFFER OVERFLOW
add_executable(stack_buffer_overflow stack_buffer_overflow.c)
set_property(TARGET stack_buffer_overflow PROPERTY C_STANDARD 99)
target_compile_options(stack_buffer_overflow PRIVATE -Wno-deprecated-declarations)

# UNCONTROLLED FORMAT STRING
add_executable(uncontrolled_format_string uncontrolled_format_string.c)

# UNNAMED LOCK GUARD
add_executable(unnamed_lock_guard unnamed_lock_guard.cpp)

# UNSIGNED INTEGER WRAPAROUND
add_executable(unsigned_integer_wraparound unsigned_integer_wraparound.c)
target_compile_options(unsigned_integer_wraparound PRIVATE -Wno-stringop-overflow)

# USE AFTER FREE
add_executable(use_after_free use_after_free.c)