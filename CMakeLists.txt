cmake_minimum_required(VERSION 3.18)
project(termux-gui-c-bindings)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTOSRC PROTOHDR GUIProt0.proto)

include_directories(BEFORE SYSTEM include)


set(sources connection.cpp activity.cpp termuxgui_c.cpp view.cpp viewgroup.cpp textview.cpp)
list(TRANSFORM sources PREPEND "src/")

set(impl connection.cpp activity.cpp view.cpp viewgroup.cpp textview.cpp bind.c)
list(TRANSFORM impl PREPEND "src/impl/")

add_custom_target(docs COMMAND doxygen)


add_library(termuxgui STATIC ${sources} ${impl} ${PROTOSRC} ${PROTOHDR})
target_link_libraries(termuxgui ${Protobuf_LIBRARIES})

install(TARGETS termuxgui LIBRARY)
install(DIRECTORY include/ TYPE INCLUDE)


add_executable(hello_world_cpp EXCLUDE_FROM_ALL tutorial/cpp/hello_world.cpp)
target_link_libraries(hello_world_cpp termuxgui ${Protobuf_LIBRARIES})



