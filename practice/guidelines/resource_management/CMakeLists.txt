# R.11: Avoid calling new and delete explicitly
add_executable(avoid_calling_new_and_delete avoid_calling_new_and_delete.cpp)
target_compile_features(avoid_calling_new_and_delete PRIVATE cxx_std_14)
# R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
add_executable(use_raii use_raii.cpp)
