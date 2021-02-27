#ifndef DIV_H
#define DIV_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Div : public Instruction {
 private:
  /* data */
 public:
  Div(/* args */) {}
  Div(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Div() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute DIV" << std::endl;
  }
};

#endif  // DIV_H