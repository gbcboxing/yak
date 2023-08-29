#pragma once

#include <exception>
#include <string>
#include <sstream>

namespace yak {
namespace Exceptions {

struct FileNotFoundException : public std::exception {
  FileNotFoundException(const std::string& path) {
    std::stringstream ss;
    ss << "File not found: \"" << path << "\"";
    what_str = ss.str();
  }

  virtual const char* what() const noexcept override {
    return what_str.c_str();
  }

private:
  std::string what_str;
};

}
}
