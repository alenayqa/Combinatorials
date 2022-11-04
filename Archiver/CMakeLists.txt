cmake_minimum_required(VERSION 3.5.1)
project(archiver)

include_directories(include)

find_package(PkgConfig)
pkg_check_modules(YAMLCPP REQUIRED yaml-cpp>=0.5)
include_directories(${YAMLCPP_INCLUDE_DIRS})

add_executable(main main.cpp src/huffman_tree.cpp)

target_link_libraries(main ${YAMLCPP_LIBRARIES})