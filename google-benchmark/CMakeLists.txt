cmake_minimum_required(VERSION 3.11)
project(myproject VERSION 1.0.0)

find_package(benchmark REQUIRED)
find_package(cppzmq REQUIRED)
find_package(g3log CONFIG REQUIRED)

add_compile_options(-O3)
include_directories(${CMAKE_INCLUDE_PATH})


add_executable(zmq zmq.cpp)
target_link_libraries(zmq PRIVATE benchmark::benchmark cppzmq)

add_executable(g3log-logging g3log-logging.cpp)
target_link_libraries(g3log-logging PRIVATE benchmark::benchmark g3log)
target_compile_features(g3log-logging PRIVATE cxx_std_17)

add_executable(liblogger liblogger.cpp)
target_link_libraries(liblogger PRIVATE benchmark::benchmark g3log logger)
target_compile_features(liblogger PRIVATE cxx_std_17)
