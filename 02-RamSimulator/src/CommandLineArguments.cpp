/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: December 2020
|| @University: ULL in Tenerife
|| @Name: commandlinearguments.cc
|| @Version: Practice 9 - RegularGrammarFromDFA
|| @Info: https://en.wikipedia.org/wiki/Context-free_grammar
=======================================================================*/

#include "CommandLineArguments.hpp"

/**
 * @brief Construct a new Command Line Arguments:: Command Line Arguments object
 *
 * @param argc
 * @param argv
 */
CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
  const char* const short_opts = "h";
  const option long_opts[] = {{"help", no_argument, nullptr, 'h'},
                              {nullptr, no_argument, nullptr, 0}};

  bool is_option = false;
  int opt;

  list_arguments_.push_back(argv[0]);

  while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) !=
         -1) {
    is_option = true;
    switch (opt) {
      case 'h':
        usage();
        throw false;

      case '?':
        std::cerr << "Unknown command line argument\n";

      default:
        std::cerr << argv[0] << " -h or --help\n";
        throw false;
    }
  }

  if (!is_option) {
    if (argc < 5) {
      std::cerr << argv[0] << " -h or --help\n";
      throw false;
    } else {
      for (int i = 1; i < argc; i++) {
        list_arguments_.push_back(argv[i]);
      }
    }
  }
}

/**
 * @brief Get list of all arguments
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> CommandLineArguments::get_list_arguments() {
  return list_arguments_;
}

/**
 * @brief Usage Manual
 *
 */
void CommandLineArguments::usage() {
  std::cerr << "USAGE\n";
  std::cerr << "SYNOPSIS\n";
  std::cerr << "\t" << list_arguments_[0]
            << " ram_program.ram input_tape.in output_tape.out debug\n";

  std::cerr << "DESCRIPTION\n";
  std::cerr << "\tRam Machine Simulator\n";

  std::cerr << "OPTIONS\n";
  std::cerr << "\t[-h][--help]            Help manual\n";
  std::cerr << "\t[debug]            Set 0 or 1 to enter or no in mode debug\n";
}