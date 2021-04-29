/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 07-Scheduling_TCT
|| @Info: https://en.wikipedia.org/wiki/Parallel_task_scheduling_problem
=======================================================================*/

#include "CommandLineArguments.hpp"

/**
 * @brief Construct a new Command Line Arguments:: Command Line Arguments object
 *
 * @param argc
 * @param argv
 */
CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
  const char* const short_opts = "ha:";
  const option long_opts[] = {{"help", no_argument, nullptr, 'h'},
                              {"algorithm", required_argument, nullptr, 'a'},
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

      case 'a': {
        std::string name_algorithm = optarg;
        set_name_algorithm(name_algorithm);
        break;
      }

      case '?':
        std::cerr << "Unknown command line argument\n";

      default:
        std::cerr << argv[0] << " -h or --help\n";
        throw false;
    }
  }

  if (!is_option) {
    if (argc < 2) {
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

std::string CommandLineArguments::get_name_algorithm() {
  return name_algorithm_;
}

void CommandLineArguments::set_name_algorithm(std::string name_algorithm) {
  name_algorithm_ = name_algorithm;
}

/**
 * @brief Usage Manual
 *
 */
void CommandLineArguments::usage() {
  std::cerr << "USAGE\n";
  std::cerr << "SYNOPSIS\n";
  std::cerr << "\t" << list_arguments_[0] << " input_problem.txt\n";

  std::cerr << "DESCRIPTION\n";
  std::cerr << "\tMaximum Diversity problem\n ";

  std::cerr << "OPTIONS\n";
  std::cerr << "\t[-h][--help]            Help manual\n";
}