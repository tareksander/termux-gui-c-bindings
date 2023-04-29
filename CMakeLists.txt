cmake_minimum_required(VERSION 3.18)
project(termux-gui-c-bindings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
find_package(SDL2)
include_directories(${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTOSRC PROTOHDR GUIProt0.proto)

include_directories(BEFORE SYSTEM include)


set(sources connection.cpp activity.cpp create.cpp view.cpp remote.cpp event.cpp notification.cpp webview.cpp hardwarebuffer.cpp)


list(TRANSFORM sources PREPEND "src/")

set(common connection.cpp bind.c)
list(TRANSFORM common PREPEND "src/common/")

add_custom_target(docs COMMAND doxygen)


add_library(termuxgui SHARED ${sources} ${common} ${PROTOSRC} ${PROTOHDR})
if(DEFINED ENV{SHARED_BUILD})
    target_link_libraries(termuxgui ${Protobuf_LIBRARIES} -ldl -landroid)
    target_compile_definitions(termuxgui PRIVATE SHARED_BUILD)
else()
    find_package(PkgConfig REQUIRED)
    find_package(utf8_range REQUIRED)
    pkg_check_modules(absl REQUIRED IMPORTED_TARGET absl_check absl_log absl_algorithm absl_base absl_bind_front absl_bits absl_btree absl_cleanup absl_cord absl_core_headers absl_debugging absl_die_if_null absl_dynamic_annotations absl_flags absl_flat_hash_map absl_flat_hash_set absl_function_ref absl_hash absl_layout absl_log_initialize absl_log_severity absl_memory absl_node_hash_map absl_node_hash_set absl_optional absl_span absl_status absl_statusor absl_strings absl_synchronization absl_time absl_type_traits absl_utility absl_variant)
    target_link_libraries(termuxgui libprotobuf.a PkgConfig::absl utf8_range utf8_validity -ldl -landroid)
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

add_executable(hello_reactivity_c EXCLUDE_FROM_ALL tutorial/c/hello_reactivity.c)
target_link_libraries(hello_reactivity_c termuxgui)

add_executable(hello_scrollview_c EXCLUDE_FROM_ALL tutorial/c/hello_scrollview.c)
target_link_libraries(hello_scrollview_c termuxgui)


add_executable(activity_events_c EXCLUDE_FROM_ALL tutorial/c/activity_events.c)
target_link_libraries(activity_events_c termuxgui)





add_executable(buffer_sdl_c EXCLUDE_FROM_ALL tutorial/c/buffer_sdl.c)
target_include_directories(buffer_sdl_c PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(buffer_sdl_c termuxgui ${SDL2_LIBRARIES})

add_executable(buffer_gl_c EXCLUDE_FROM_ALL tutorial/c/buffer_gl.c)
target_link_libraries(buffer_gl_c termuxgui -lEGL -lGLESv2)

add_executable(imageview_mpv_c EXCLUDE_FROM_ALL tutorial/c/imageview_mpv.c)
target_link_libraries(imageview_mpv_c termuxgui mpv)

add_executable(es2gears EXCLUDE_FROM_ALL demos/es2gears.c)
target_link_libraries(es2gears termuxgui -lEGL -lGLESv2 -lm)









