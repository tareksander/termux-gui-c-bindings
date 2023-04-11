cmake_minimum_required(VERSION 3.18)
project(termux-gui-c-bindings)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
find_package(SDL2)
include_directories(${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTOSRC PROTOHDR GUIProt0.proto)

include_directories(BEFORE SYSTEM include)


set(sources connection.cpp activity.cpp create.cpp view.cpp remote.cpp event.cpp)
list(TRANSFORM sources PREPEND "src/")

set(common connection.cpp bind.c)
list(TRANSFORM common PREPEND "src/common/")

add_custom_target(docs COMMAND doxygen)


add_library(termuxgui SHARED ${sources} ${common} ${PROTOSRC} ${PROTOHDR})
if(DEFINED ENV{SHARED_BUILD})
    target_link_libraries(termuxgui ${Protobuf_LIBRARIES})
    target_compile_definitions(termuxgui PRIVATE SHARED_BUILD)
else()
    target_link_libraries(termuxgui libprotobuf.a)
    target_link_options(termuxgui PRIVATE -Wl,--exclude-libs,ALL)
endif()


install(TARGETS termuxgui LIBRARY)
install(DIRECTORY include/ TYPE INCLUDE)



add_executable(hello_world_c EXCLUDE_FROM_ALL tutorial/c/hello_world.c)
target_link_libraries(hello_world_c termuxgui)

add_executable(hello_activity_c EXCLUDE_FROM_ALL tutorial/c/hello_activity.c)
target_link_libraries(hello_activity_c termuxgui)

add_executable(hello_textview_c EXCLUDE_FROM_ALL tutorial/c/hello_textview.c)
target_link_libraries(hello_textview_c termuxgui)

add_executable(buffer_sdl_c EXCLUDE_FROM_ALL tutorial/c/buffer_sdl.c)
target_include_directories(buffer_sdl_c PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(buffer_sdl_c termuxgui ${SDL2_LIBRARIES})

add_executable(imageview_mpv_c EXCLUDE_FROM_ALL tutorial/c/imageview_mpv.c)
target_link_libraries(imageview_mpv_c termuxgui mpv)











