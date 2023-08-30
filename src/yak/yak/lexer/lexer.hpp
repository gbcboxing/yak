#pragma once

#include <memory>
#include <string>
#include <vector>

namespace yak {
namespace Lexer {

std::shared_ptr<std::vector<std::string>> Tokenize(const std::string& code);

}
}
