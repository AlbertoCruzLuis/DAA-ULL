#ifndef HALT_H
#define HALT_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Halt : public Instruction {
 private:
  /* data */
 public:
  Halt(/* args */) {}
  Halt(std::string name) : Instruction(name) {}
  ~Halt() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute HALT" << std::endl;
    outTape.writeToFile();
    bool stateStop = 0;
    return stateStop;
  }
};
#endif  // HALT_H