#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Instruction.hpp"
#include "Instructions/Load.hpp"
#include "Instructions/Read.hpp"
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

  void analyzeFile();
  bool isComments(std::string line);
  bool isEmptyLine(std::string line);
  std::string findLabel(std::string line);
  std::pair<std::string, std::string> findInstruction(std::string line);
  Instruction* validateOperation(std::string name, std::string value);
};

#endif  // FILEPARSER_H