#ifndef JZERO_H
#define JZERO_H

#include "Instruction.hpp"

class Jzero : public Instruction {
 private:
  /* data */
 public:
  Jzero(/* args */) {}
  Jzero(std::string name, std::string value) : Instruction(name, value) {}
  ~Jzero() {}

  void execute() { std::cout << "Execute JZERO" << std::endl; }
};
#endif  // JZERO_H