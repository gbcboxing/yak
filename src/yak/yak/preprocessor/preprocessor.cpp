#include "preprocessor.hpp"

#include <fstream>
#include <sstream>

namespace yak {
namespace Preprocessor {

std::string ReadFile(const std::string& path) {
  std::ifstream t(path);
  std::stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}

}
}
