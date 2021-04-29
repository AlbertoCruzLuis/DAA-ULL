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

#ifndef __COMMANDLINEARGUMENTS_H__
#define __COMMANDLINEARGUMENTS_H__

#include <getopt.h>

#include <fstream>
#include <iostream>
#include <vector>

class CommandLineArguments {
 private:
  std::vector<std::string> list_arguments_;
  std::string name_algorithm_;

 public:
  CommandLineArguments(int argc, char *argv[]);
  ~CommandLineArguments() {}

  std::vector<std::string> get_list_arguments();
  std::string get_name_algorithm();
  void set_name_algorithm(std::string name_algorithm);

  void usage();
};

#endif  // __COMMANDLINEARGUMENTS_H__