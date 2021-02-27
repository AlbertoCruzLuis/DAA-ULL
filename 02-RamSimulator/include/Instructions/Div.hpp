#ifndef DIV_H
#define DIV_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Div : public Instruction {
 private:
  /* data */
 public:
  Div(/* args */) {}
  Div(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Div() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute DIV" << std::endl;
  }
};

#endif  // DIV_H