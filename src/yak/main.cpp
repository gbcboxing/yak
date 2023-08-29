#include <iostream>

#include <args.hxx>

#include "preprocessor/preprocessor.hpp"

int main(int argc, char** argv) {
  args::ArgumentParser parser("yak - a lightweight, embeddable programming language.");
  
  /* List of arguments we accept: */
  args::Positional<std::string> file(parser, "[file]", "The input file");
  args::Flag help(parser, "help", "Display this help menu and exit", {'h', "help"});
  args::Flag version(parser, "version", "Display program version", {'v', "version"});

  /* Parse arguments and throw appropriate errors if malformed */
  try {
    parser.ParseCLI(argc, argv);
  }
  catch (const args::ParseError& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  /* -h, --help, or no arguments given */
  if (argc == 1 || help) {
    std::cout << parser;
    return 0;
  }

  /* -v, --version */
  if (version) {
    std::cout << "yak 0.1\n";
    return 0;
  }

  /* Ensure an input file given */
  if (!file) {
    std::cout << "No input file\n";
    return 1;
  }

  /* No other relevant flags given - interpret and run the file */
  /* Since no compile flags etc exist yet, just interpret and run the file regardless */
  auto code = yak::Preprocessor::ReadFile(file.Get());
  
}
