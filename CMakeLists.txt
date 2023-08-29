cmake_minimum_required(VERSION 3.25)
project(yak)

set(YAK_SRC_MAIN_FILES
  src/yak/main.cpp
)
source_group("src/yak" FILES ${YAK_SRC_MAIN_FILES})

set(YAK_SRC_PREPROCESSOR_FILES
  src/yak/preprocessor/preprocessor.hpp src/yak/preprocessor/preprocessor.cpp
)
source_group("src/yak/preprocessor" FILES ${YAK_SRC_PREPROCESSOR_FILES})

set(YAK_SRC_TOKENIZER_FILES
  src/yak/tokenizer/tokenizer.hpp src/yak/tokenizer/tokenizer.cpp
)
source_group("src/yak/tokenizer" FILES ${YAK_SRC_TOKENIZER_FILES})

add_executable(${PROJECT_NAME}
  ${YAK_SRC_MAIN_FILES}
  ${YAK_SRC_PREPROCESSOR_FILES}
  ${YAK_SRC_TOKENIZER_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE src/lib/args)

if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
