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

set(YAK_SRC_LEXER_FILES
  yak/lexer/lexer.hpp yak/lexer/lexer.cpp
  yak/lexer/token.hpp yak/lexer/token.cpp
)
source_group("src/yak/lexer" FILES ${YAK_SRC_LEXER_FILES})

add_library(${PROJECT_NAME}
  ${YAK_SRC_EXCEPTIONS_FILES}
  ${YAK_SRC_LEXER_FILES}
  ${YAK_SRC_PREPROCESSOR_FILES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC .)
