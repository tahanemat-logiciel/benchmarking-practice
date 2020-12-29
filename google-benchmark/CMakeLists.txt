cmake_minimum_required(VERSION 3.11)
project(myproject VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(benchmark REQUIRED)
find_package(cppzmq REQUIRED)
find_package(g3log CONFIG REQUIRED)

add_compile_options(-O3)

add_executable(zmq zmq.cpp)
target_link_libraries(zmq PRIVATE benchmark::benchmark cppzmq)

add_executable(g3log-logging g3log-logging.cpp)
target_link_libraries(g3log-logging PRIVATE benchmark::benchmark g3log)
target_compile_features(g3log-logging PRIVATE cxx_std_17)

add_executable(liblogger liblogger.cpp)
target_link_libraries(liblogger PRIVATE benchmark::benchmark g3log logger)
target_compile_features(liblogger PRIVATE cxx_std_17)

add_executable(logilogging-benchmark logilogging.cpp)

add_subdirectory(modules/LogiLogging)
include_directories(modules/LogiLogging/include)
list(APPEND LINKLIBS logilogging zlib logicommon)
target_link_libraries(logilogging-benchmark PRIVATE benchmark::benchmark ${LINKLIBS})
target_compile_features(logilogging-benchmark PRIVATE cxx_std_17)

