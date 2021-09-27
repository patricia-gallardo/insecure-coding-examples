# SL.con.3: Avoid bounds errors
add_executable(avoid_bounds_errors avoid_bounds_errors.cpp)
# SL.io.3: Prefer iostreams for I/O
add_executable(prefer_iostreams prefer_iostreams.cpp)
# SL.str.1: Use std::string to own character sequences
add_executable(use_string_for_strings use_string_for_strings.cpp)
# SL.str.5: Use std::byte to refer to byte values that do not necessarily represent characters
add_executable(use_byte_for_non_strings use_byte_for_non_strings.cpp)
target_compile_features(use_byte_for_non_strings PRIVATE cxx_std_17)
