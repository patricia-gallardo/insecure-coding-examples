cmake_minimum_required(VERSION 3.16)
project(insecure_coding_examples LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(exploit)
add_subdirectory(exploitable)
add_subdirectory(practice)
add_subdirectory(vulnerability)
