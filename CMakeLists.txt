cmake_minimum_required(VERSION 3.10)
project(insecure_coding_examples)

set(CMAKE_CXX_STANDARD 11)

add_executable(buffer_underflow buffer_underflow.c)

add_executable(disappearing_memset disappearing_memset.c)

add_executable(double_free double_free.c)

add_executable(heap_buffer_overflow heap_buffer_overflow.c)

add_executable(incorrect_type_conversion incorrect_type_conversion.c)

add_executable(numeric_truncation numeric_truncation.c)

add_executable(signed_integer_overflow signed_integer_overflow.c)

add_executable(stack_buffer_overflow stack_buffer_overflow.c)

add_executable(uncontrolled_format_string uncontrolled_format_string.c)

add_executable(unnamed_lock_guard unnamed_lock_guard.cpp)

add_executable(unsigned_integer_wraparound unsigned_integer_wraparound.c)

add_executable(use_after_free use_after_free.c)