cmake_minimum_required(VERSION 3.11)
project(myproject VERSION 1.0.0)

find_package(benchmark REQUIRED)
find_package(cppzmq REQUIRED)
find_package(g3log CONFIG REQUIRED)

add_executable(zmq zmq.cpp)
add_executable(logging logging.cpp)
add_compile_options(-O3)

target_link_libraries(zmq PRIVATE benchmark::benchmark cppzmq)
target_link_libraries(logging PRIVATE benchmark::benchmark)
target_link_libraries(logging PRIVATE g3log)
target_compile_features(logging PRIVATE cxx_std_17)
