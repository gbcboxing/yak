cmake_minimum_required(VERSION 3.25)
project(yak)

set(YAK_SRC_EXCEPTIONS_FILES
  yak/exceptions/exceptions.hpp
)
source_group("src/yak/exceptions" FILES ${YAK_SRC_EXCEPTIONS_FILES})

set(YAK_SRC_PREPROCESSOR_FILES
  yak/preprocessor/preprocessor.hpp yak/preprocessor/preprocessor.cpp
  yak/preprocessor/trim_whitespace.hpp yak/preprocessor/trim_whitespace.cpp
)
source_group("src/yak/preprocessor" FILES ${YAK_SRC_PREPROCESSOR_FILES})

set(YAK_SRC_TOKENIZER_FILES
  yak/tokenizer/tokenizer.hpp yak/tokenizer/tokenizer.cpp
)
source_group("src/yak/tokenizer" FILES ${YAK_SRC_TOKENIZER_FILES})

add_library(${PROJECT_NAME}
  ${YAK_SRC_EXCEPTIONS_FILES}
  ${YAK_SRC_PREPROCESSOR_FILES}
  ${YAK_SRC_TOKENIZER_FILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC .)
