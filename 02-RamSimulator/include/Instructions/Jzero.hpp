#ifndef JZERO_H
#define JZERO_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Jzero : public Instruction {
 private:
  /* data */
 public:
  Jzero(/* args */) {}
  Jzero(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jzero() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute JZERO" << std::endl;
  }
};
#endif  // JZERO_H