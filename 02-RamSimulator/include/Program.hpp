#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

#include "FileParser.hpp"
#include "Instruction.hpp"
#include "Label.hpp"

class Program {
 private:
  std::vector<Label> list_labels_;
  std::vector<Instruction*> list_instructions_;

 public:
  Program() {}
  Program(std::string program_name);
  ~Program() {}

  std::vector<Label> get_list_label();
  std::vector<Instruction*> get_list_instructions();
};

#endif  // PROGRAM_H