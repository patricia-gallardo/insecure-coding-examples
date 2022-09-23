add_subdirectory(guidelines)

# -----------------------------------------------------------------
#
# PRACTICE
#
# -----------------------------------------------------------------

add_executable(commandline commandline.cpp)

add_executable(concat_strings concat_strings.cpp)

# Array Pointer Decay
add_executable(decay decay.cpp)

add_executable(constexpr_ub if_constexpr.cpp)
target_compile_options(constexpr_ub PRIVATE -Wno-overflow)

# Needs C++20
add_executable(midpoint_library midpoint_library.cpp)

add_executable(numeric_truncation_safe numeric_truncation_safe.c)

add_executable(signed_integer_overflow_safe signed_integer_overflow_safe.c)

add_executable(downcasting downcasting.cpp)

add_executable(enum_class enum_class.cpp)

# Needs clang 7 or gcc 8
add_executable(filesystem filesystem.cpp)

add_executable(string_literals string_literals.cpp)

add_executable(unsigned_integer_wraparound_safe unsigned_integer_wraparound_safe.c)

add_executable(strip_after_colon strip_after_colon.cpp)

add_executable(user_defined_literals user_defined_literals.cpp)
