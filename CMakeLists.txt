cmake_minimum_required(VERSION 3.25)
project(yak)

add_executable(${PROJECT_NAME} src/yak/main.cpp)

if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
