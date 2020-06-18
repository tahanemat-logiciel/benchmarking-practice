cmake_minimum_required(VERSION 3.11)

project(myproject VERSION 1.0.0)

find_path(CELERO_INCLUDE_DIR celero.h PATH_SUFFIXES celero)

find_library(CELERO_LIBRARY NAMES libcelero.so)

set(CELERO_LIBRARIES ${CELERO_LIBRARY})

set(CELERO_INCLUDE_DIRS ${CELERO_INCLUDE_DIR})

#include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIB_libtbb_FOUND to TRUE
# if all listed variables are TRUE
#find_package_handle_standard_args(TBB DEFAULT_MSG TBB_LIBRARIES TBB_INCLUDE_DIR)

mark_as_advanced(CELERO_INCLUDE_DIR CELERO_LIBRARIES)

add_executable(cmake-good main.cpp)

target_link_libraries(cmake-good ${CELERO_LIBRARIES})
