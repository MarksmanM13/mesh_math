cmake_minimum_required(VERSION 3.20)
project(interview LANGUAGES CXX)

add_subdirectory(src)

add_executable(compute main.cxx)
target_link_libraries(compute PRIVATE helpers)
