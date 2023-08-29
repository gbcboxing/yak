#include <gtest/gtest.h>

#include <yak/preprocessor/preprocessor.hpp>

TEST(YakPreprocessor, CanReadSimpleFile) {
  auto code = yak::Preprocessor::ReadFile("yak/return_zero.yak");
  EXPECT_EQ(code, "func main() {\n  return 0;\n}\n");
}
