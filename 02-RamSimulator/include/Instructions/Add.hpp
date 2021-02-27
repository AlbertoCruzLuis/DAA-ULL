#ifndef ADD_H
#define ADD_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Add : public Instruction {
 private:
  /* data */
 public:
  Add() {}
  Add(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Add() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute ADD" << std::endl;
    if (addressing_mode_.get_mode() == INMEDIATE) {
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
    }
    if (addressing_mode_.get_mode() == DIRECT) {
    }
    programCounter.next_address();
  }
};

#endif  // ADD_H