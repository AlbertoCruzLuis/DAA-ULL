/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: December 2020
|| @University: ULL in Tenerife
|| @Name: commandlinearguments.h
|| @Version: Practice 9 - RegularGrammarFromDFA
|| @Info: https://en.wikipedia.org/wiki/Context-free_grammar
=======================================================================*/

#ifndef __COMMANDLINEARGUMENTS_H__
#define __COMMANDLINEARGUMENTS_H__

#include <getopt.h>

/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February / March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

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