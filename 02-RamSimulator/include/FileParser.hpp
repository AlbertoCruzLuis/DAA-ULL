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

#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Instruction.hpp"
#include "Instructions/Add.hpp"
#include "Instructions/Halt.hpp"
#include "Instructions/Jump.hpp"
#include "Instructions/Jzero.hpp"
#include "Instructions/Load.hpp"
#include "Instructions/Mult.hpp"
#include "Instructions/Read.hpp"
#include "Instructions/Store.hpp"
#include "Instructions/Sub.hpp"
#include "Instructions/Write.hpp"
#include "Label.hpp"

class FileParser {
 private:
  std::vector<std::string> formattedData_;
  std::vector<Label> list_label_;
  std::vector<Instruction*> list_instruction_;
  std::fstream file_;

 public:
  FileParser(std::string inFileName);
  ~FileParser() {}

  std::vector<Label> get_list_label();
  std::vector<Instruction*> get_list_instructions();

  void analyzeFile();
  bool isComments(std::string line);
  bool isEmptyLine(std::string line);
  std::string findLabel(std::string line);
  Instruction findInstruction(std::string line);
  Instruction* validateOperation(Instruction instruction);
};

#endif  // FILEPARSER_H