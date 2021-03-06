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

#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Instruction.hpp"
#include "Labels.hpp"

class FileParser {
 private:
  Labels list_label_;
  std::vector<Instruction*> list_instruction_;
  std::fstream file_;

 public:
  FileParser(std::string inFileName);
  ~FileParser() {}

  Labels get_list_label();
  std::vector<Instruction*> get_list_instructions();

  void analyzeFile();
  bool isComments(std::string line);
  bool isEmptyLine(std::string line);
  std::string findLabel(std::string line);
  Instruction findInstruction(std::string line);
  Instruction* validateOperation(Instruction instruction);
};

#endif  // FILEPARSER_H