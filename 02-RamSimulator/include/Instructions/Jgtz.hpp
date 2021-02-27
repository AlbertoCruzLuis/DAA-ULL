#ifndef JGTZ_H
#define JGTZ_H

#include "Instruction.hpp"

class Jgtz : public Instruction {
 private:
  /* data */
 public:
  Jgtz(/* args */) {}
  Jgtz(std::string name, std::string value) : Instruction(name, value) {}
  ~Jgtz() {}

  void execute() { std::cout << "Execute JGTZ" << std::endl; }
};
#endif  // JGTZ_H