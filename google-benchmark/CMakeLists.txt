cmake_minimum_required(VERSION 3.11)
project(myproject VERSION 1.0.0)

find_package(benchmark REQUIRED)

add_executable(cmake-good main.cpp)

target_link_libraries(cmake-good PRIVATE benchmark::benchmark)
