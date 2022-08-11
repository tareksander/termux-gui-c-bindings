cmake_minimum_required(VERSION 3.18)
project(termux-gui-c-bindings)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTOSRC PROTOHDR GUIProt0.proto)

include_directories(BEFORE SYSTEM include)


set(sources termuxgui_c.cpp impl/Connection.cpp)
list(TRANSFORM sources PREPEND "src/")

add_custom_target(docs COMMAND doxygen)


add_library(termuxgui STATIC ${sources} ${PROTOSRC} ${PROTOHDR})
target_link_libraries(termuxgui Protobuf_LIBRARIES)

install(TARGETS termuxgui LIBRARY)
install(DIRECTORY include/ DESTINATION TYPE INCLUDE)
