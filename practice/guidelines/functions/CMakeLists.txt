# F.53: Avoid capturing by reference in lambdas that will be used nonlocally, including returned, stored on the heap, or passed to another thread
add_executable(cautious_reference_capture cautious_reference_capture.cpp)
# F.54: If you capture this, capture all variables explicitly (no default capture)
add_executable(cautious_this_capture cautious_this_capture.cpp)
add_executable(cautious_this_capture_cpp17 cautious_this_capture_cpp17.cpp)
