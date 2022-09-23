# ES.103: Don’t overflow
add_executable(dont_overflow dont_overflow.cpp)
# ES.104: Don’t underflow
add_executable(dont_underflow dont_underflow.cpp)
add_executable(dont_underflow_cpp dont_underflow_cpp.cpp)
add_executable(dont_underflow_c dont_underflow_c.c)
# ES.1: Prefer the standard library to other libraries and to “handcrafted code”
add_executable(prefer_the_standard_library prefer_the_standard_library.cpp)
# ES.20: Always initialize an object
add_executable(always_initialize always_initialize.cpp)
# ES.27: Use std::array or stack_array for arrays on the stack
add_executable(use_std_array use_std_array.cpp)
# ES.42: Keep use of pointers simple and straightforward
add_executable(cautious_pointer_use cautious_pointer_use.cpp)
add_executable(cautious_pointer_use_decay cautious_pointer_use_decay.cpp)
# ES.48: Avoid casts
add_executable(avoid_casts avoid_casts.cpp)
# ES.49: If you must use a cast, use a named cast
add_executable(use_named_cast use_named_cast.cpp)
add_executable(use_braced_init use_braced_init.cpp)
