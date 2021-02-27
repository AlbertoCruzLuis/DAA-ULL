#ifndef HALT_H
#define HALT_H

#include "Instruction.hpp"

class Halt : public Instruction {
 private:
  /* data */
 public:
  Halt(/* args */) {}
  Halt(std::string name, std::string value) : Instruction(name, value) {}
  ~Halt() {}

  void execute() { std::cout << "Execute HALT" << std::endl; }
};
#endif  // HALT_H