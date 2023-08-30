#include "lexer.hpp"

#include <functional>

namespace yak {
namespace Lexer {

/* Helper function - read through the string until we reach a character that matches a given condition */
/* Examples - read until whitespace, read until next double quote */
/* Condition is defined using a lambda that takes in a char and returns a bool */
void ReadUntil(const std::string& str, int& i, std::function<bool(char)> func) {
  ++i;
  while (i < str.length() && !func(str[i])) {
    ++i;
  }
  --i;
}

/* Given an input string, tokenize it into a list of strings */
/* No checks are made about whether the tokens make sense in context, */
/* At this point we just want to take a string representing the code and */
/* output a list of strings representing each token in the input string */
std::shared_ptr<std::vector<std::string>> Tokenize(const std::string& code) {
  auto tokens = std::make_shared<std::vector<std::string>>();
  
  /* Keep track of the start of the current token */
  for (int i = 0; i < code.size(); ++i) {
    char c = code[i];
    
    /* Skip any whitespace */
    if (std::isspace(c)) {
      continue;
    }
    /* Numeric literals - float, int, double, etc */
    else if (std::isdigit(c)) {
      int start = i;
      ReadUntil(code, i, [](char c){ return !std::isdigit(c); });
      tokens->push_back(code.substr(start, i + 1 - start));
    }
    /* Identifiers - function names, variable names, etc */
    else if (std::isalpha(c)) {
      int start = i;
      ReadUntil(code, i, [](char c){ return !std::isalnum(c); });
      tokens->push_back(code.substr(start, i + 1 - start));
    }
    else if (c == '{') {
      tokens->push_back("{");
    }
    else if (c == '}') {
      tokens->push_back("}");
    }
    else if (c == '(') {
      tokens->push_back("(");
    }
    else if (c == ')') {
      tokens->push_back(")");
    }
    else if (c == ';') {
      tokens->push_back(";");
    }
  }
  
  return tokens;
}

}
}
