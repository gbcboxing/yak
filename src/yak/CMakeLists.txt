cmake_minimum_required(VERSION 3.25)
project(yak)

set(YAK_SRC_PREPROCESSOR_FILES
  preprocessor/preprocessor.hpp preprocessor/preprocessor.cpp
)
source_group("src/yak/preprocessor" FILES ${YAK_SRC_PREPROCESSOR_FILES})

set(YAK_SRC_TOKENIZER_FILES
  tokenizer/tokenizer.hpp tokenizer/tokenizer.cpp
)
source_group("src/yak/tokenizer" FILES ${YAK_SRC_TOKENIZER_FILES})

add_library(${PROJECT_NAME}
  ${YAK_SRC_PREPROCESSOR_FILES}
  ${YAK_SRC_TOKENIZER_FILES}
)
