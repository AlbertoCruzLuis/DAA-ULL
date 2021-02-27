#ifndef ADD_H
#define ADD_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Add : public Instruction {
 private:
  /* data */
 public:
  Add() {}
  Add(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Add() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute ADD" << std::endl;
    if (addressing_mode_.get_mode() == INMEDIATE) {
      /* code */
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      /* code */
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      /* code */
    }
  }
};

#endif  // ADD_H