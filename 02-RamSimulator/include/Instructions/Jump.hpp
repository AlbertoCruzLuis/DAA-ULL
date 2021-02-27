#ifndef JUMP_H
#define JUMP_H

#include "Instruction.hpp"

class Jump : public Instruction {
 private:
  /* data */
 public:
  Jump(/* args */) {}
  Jump(std::string name, std::string value) : Instruction(name, value) {}
  ~Jump() {}

  void execute() { std::cout << "Execute JUMP" << std::endl; }
};
#endif  // JUMP_H