#include <gtest/gtest.h>

#include <yak/preprocessor/preprocessor.hpp>

TEST(YakPreprocessor, CanReadSimpleFile) {
  auto code = yak::Preprocessor::ReadFile("yak/return_zero.yak");
  EXPECT_EQ(code, "func main() { return 0; }");
}

TEST(YakPreprocessor, CanHandleInclude) {
  auto code = yak::Preprocessor::ReadFile("yak/include.yak");
  EXPECT_EQ(code, "func add(int a, int b) { return a + b; } func main() { return add(1, 2); }");
}

TEST(YakPreprocessor, CanHandleMultipleIncludes) {
  auto code = yak::Preprocessor::ReadFile("yak/multiple_includes.yak");
  EXPECT_EQ(code, "func subtract(int a, int b) { return a - b; } func add(int a, int b) { return a + b; } func main() { return subtract(3, add(1, 2)); }");
}

TEST(YakPreprocessor, CanFormatWhitespace) {
  auto code = yak::Preprocessor::ReadFile("yak/extra_whitespace.yak");
  EXPECT_EQ(code, "func main() { int a = 1 + 4; }");
}
