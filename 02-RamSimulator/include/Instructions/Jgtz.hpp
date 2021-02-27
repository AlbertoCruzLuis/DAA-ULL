#ifndef JGTZ_H
#define JGTZ_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Jgtz : public Instruction {
 private:
  /* data */
 public:
  Jgtz(/* args */) {}
  Jgtz(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jgtz() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute JGTZ" << std::endl;
  }
};
#endif  // JGTZ_H