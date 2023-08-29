cmake_minimum_required(VERSION 3.25)
project(yak_runtime)

set(YAK_SRC_MAIN_FILES
  src/yak/main.cpp
)
source_group("src/yak" FILES ${YAK_SRC_MAIN_FILES})

add_executable(${PROJECT_NAME}
  ${YAK_SRC_MAIN_FILES}
)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "yak")

add_subdirectory(src/yak)

target_include_directories(${PROJECT_NAME} PRIVATE src/lib/args)
target_link_libraries(${PROJECT_NAME} PRIVATE yak)

enable_testing()
add_subdirectory(src/lib/googletest)
add_subdirectory(src/tests)

if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
