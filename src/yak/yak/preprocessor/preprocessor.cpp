#include "preprocessor.hpp"

#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>

#include "yak/exceptions/exceptions.hpp"
#include "yak/preprocessor/trim_whitespace.hpp"

namespace yak {
namespace Preprocessor {

/* Read the file line by line, looking for preprocessor directives */
/* Execute any preprocessor directives we find */
/* Finally, apply some formatting to the output code string - trim or insert whitespace, etc. */
/* Last step is not really necessary, but it makes the strings easier for a human to grok */
std::string ReadFile(const std::string& path) {
  std::ifstream in_file(path);

  if (!in_file.is_open()) {
    throw yak::Exceptions::FileNotFoundException(path);
  }

  std::stringstream ss;

  /* For each line in the file, check if it's a preprocessor directive */
  /* If it is, execute it. */
  for (std::string line; std::getline(in_file, line);) {
    /* Trim whitespace so that we can check whether the line starts with #include or similar */
    line = yak::Preprocessor::TrimWhitespace(line);

    if (line.rfind("#include", 0) == 0) {
      /* #include - Make a recursive call to ReadFile and paste the result at the start of the output string */
      /* Multiple includes in one preprocessor directive are allowed */

      /* Use regex to grab the contents of any speech marks */
      auto rgx = std::regex("\"(.*?)\"");
      std::sregex_iterator current(line.begin(), line.end(), rgx);
      std::sregex_iterator end;

      /* For each string we find after #include: */
      while (current != end) {
        /* Remove leading and trailing quotes */
        std::smatch match = *current;
        std::string include_path = match.str();
        include_path.erase(0, 1);
        include_path.erase(include_path.size() - 1);

        /* Now that we have the include path, make it relative to the current directory */
        std::filesystem::path parent_dir = std::filesystem::path(path).parent_path();
        std::string file_contents = ReadFile(parent_dir.string() + "/" + include_path);

        /* Prepend the calculated string so far with the contents of the included file */
        const std::string &temp = ss.str();
        ss.seekp(0);
        ss << file_contents << temp;

        /* Go to the next include file */
        (void)*current++;
      }
    }
    else {
      /* If the line is not a preprocessor directive, append it to the output string */
      ss << line << " ";
    }
  }

  /* Clean up the formatting and make everything single-spaced */
  std::string result = ss.str();
  /* Add spaces around curly brackets */
  result = std::regex_replace(result, std::regex("\\}"), " } ");
  result = std::regex_replace(result, std::regex("\\{"), " { ");
  /* Remove all whitespace with single spaces */
  result = std::regex_replace(result, std::regex("\\s+"), " ");
  /* Trim all whitespace from the start and end of the string */
  result = yak::Preprocessor::TrimWhitespace(result);
  return result;
}

}
}
