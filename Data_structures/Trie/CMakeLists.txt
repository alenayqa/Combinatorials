cmake_minimum_required(VERSION 3.5.1)
project(trie_test)

# set(SOURCES src/Vertex.cpp src/Trie.cpp)

include_directories(headers)

# add_library (lib ${SOURCES})

add_executable(main main.cpp)
# target_link_libraries(main lib)