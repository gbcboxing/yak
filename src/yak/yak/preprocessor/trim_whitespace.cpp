#include "trim_whitespace.hpp"

#include <algorithm>

namespace yak {
namespace Preprocessor {

const std::string kWhitespace = " \n\r\t\f\v";
 
std::string LTrim(const std::string& str) {
  size_t start = str.find_first_not_of(kWhitespace);
  return (start == std::string::npos) ? "" : str.substr(start);
}
 
std::string RTrim(const std::string& str) {
  size_t end = str.find_last_not_of(kWhitespace);
  return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string TrimWhitespace(const std::string& str) {
  return RTrim(LTrim(str));
}

}
}
