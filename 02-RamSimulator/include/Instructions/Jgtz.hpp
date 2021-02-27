#ifndef JGTZ_H
#define JGTZ_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Jgtz : public Instruction {
 private:
  /* data */
 public:
  Jgtz(/* args */) {}
  Jgtz(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jgtz() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute JGTZ" << std::endl;
  }
};
#endif  // JGTZ_H