#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

#include "FileParser.hpp"
#include "Instruction.hpp"
#include "Label.hpp"

class Program {
 private:
  std::vector<Label> list_label_;
  std::vector<Instruction> list_instruction_;

 public:
  Program(std::string program_name);
  ~Program() {}
};

#endif  // PROGRAM_H