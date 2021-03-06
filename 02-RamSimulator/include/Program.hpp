/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

#include "FileParser.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"

class Program {
 private:
  Labels list_labels_;
  std::vector<Instruction*> list_instructions_;

 public:
  Program() {}
  Program(std::string program_name);
  ~Program() {}

  Labels get_list_label();
  std::vector<Instruction*> get_list_instructions();

  // Method: How memory is assign to this program
};

#endif  // PROGRAM_H