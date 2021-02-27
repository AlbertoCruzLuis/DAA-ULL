#include "Program.hpp"

Program::Program(std::string program_name) {
  std::cout << "Program Analyze\n";
  FileParser fileParser(program_name);
  list_labels_ = fileParser.get_list_label();
  list_instructions_ = fileParser.get_list_instructions();
}

std::vector<Label> Program::get_list_label() { return list_labels_; }

std::vector<Instruction*> Program::get_list_instructions() {
  return list_instructions_;
}