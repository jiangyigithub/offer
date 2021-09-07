cmake_minimum_required(VERSION 3.0.0)
project(CMAKE_TEST VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CMAKE_TEST queue.cpp)
add_executable(fib fib.cpp)
add_executable(tree tree.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
