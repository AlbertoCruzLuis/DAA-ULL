#ifndef HALT_H
#define HALT_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Halt : public Instruction {
 private:
  /* data */
 public:
  Halt(/* args */) {}
  Halt(std::string name) : Instruction(name) {}
  ~Halt() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute HALT" << std::endl;
  }
};
#endif  // HALT_H