#ifndef JUMP_H
#define JUMP_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Jump : public Instruction {
 private:
  /* data */
 public:
  Jump(/* args */) {}
  Jump(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jump() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute JUMP" << std::endl;
  }
};
#endif  // JUMP_H