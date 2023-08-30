#include <gtest/gtest.h>

#include <yak/preprocessor/preprocessor.hpp>
#include <yak/lexer/lexer.hpp>

bool CompareTokenLists(const std::vector<std::string>& a, const std::vector<std::string>& b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

TEST(YakLexer, CanTokenizeSimpleString) {
  auto code = "func main(){return 0;}";
  auto tokens = yak::Lexer::Tokenize(code);
  EXPECT_TRUE(CompareTokenLists(*tokens, { "func", "main", "(", ")", "{", "return", "0", ";", "}" }));
}
