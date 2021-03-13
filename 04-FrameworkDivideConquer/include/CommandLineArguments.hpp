/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 04-FrameworkDivideConquer
|| @Info: https://es.wikipedia.org/wiki/Algoritmo_divide_y_vencer%C3%A1s
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

 public:
  CommandLineArguments(int argc, char *argv[]);
  ~CommandLineArguments() {}

  std::vector<std::string> get_list_arguments();

  void usage();
};

#endif  // __COMMANDLINEARGUMENTS_H__