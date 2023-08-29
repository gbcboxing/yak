cmake_minimum_required(VERSION 3.25)
project(yak_tests)

set(YAK_TESTS_SRC_MAIN_FILES
  test_main.cpp
  test_preprocessor.hpp
)
source_group("tests" FILES ${YAK_TESTS_SRC_MAIN_FILES})

set(YAK_TESTS_YAK_SOURCE_CODE_FILES
  yak/add.yak
  yak/extra_whitespace.yak
  yak/include.yak
  yak/multiple_includes.yak
  yak/return_zero.yak
  yak/subtract.yak
)
source_group("tests/yak" FILES ${YAK_TESTS_YAK_SOURCE_CODE_FILES})

add_executable(${PROJECT_NAME}
  ${YAK_TESTS_SRC_MAIN_FILES}
  ${YAK_TESTS_YAK_SOURCE_CODE_FILES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)
target_link_libraries(${PROJECT_NAME} PRIVATE yak)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

if(APPLE)
  set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_GENERATE_SCHEME TRUE XCODE_SCHEME_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
  set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
