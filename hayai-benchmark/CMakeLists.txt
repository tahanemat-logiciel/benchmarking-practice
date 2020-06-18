cmake_minimum_required(VERSION 3.11)

project(myproject VERSION 1.0.0)

find_path(HAYAI_INCLUDE_DIR hayai.h PATH_SUFFIXES hayai)

find_library(HAYAI_LIBRARY NAMES hayai_main)

set(HAYAI_LIBRARIES ${HAYAI_LIBRARY})

set(HAYAI_INCLUDE_DIRS ${HAYAI_INCLUDE_DIR})

mark_as_advanced(HAYAI_INCLUDE_DIR HAYAI_LIBRARIES)

add_executable(cmake-good main.cpp)

target_link_libraries(cmake-good ${HAYAI_LIBRARIES})
