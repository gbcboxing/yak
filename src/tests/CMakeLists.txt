cmake_minimum_required(VERSION 3.25)
project(yak_tests)

set(YAK_TESTS_SRC_MAIN_FILES
  test_main.cpp
  test_preprocessor.hpp
)
source_group("tests" FILES ${YAK_TESTS_SRC_MAIN_FILES})

add_executable(${PROJECT_NAME}
  ${YAK_TESTS_SRC_MAIN_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)
target_link_libraries(${PROJECT_NAME} PRIVATE yak)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
