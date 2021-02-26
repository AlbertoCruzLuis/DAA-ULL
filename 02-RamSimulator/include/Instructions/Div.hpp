#ifndef DIV_H
#define DIV_H

#include "Instruction.hpp"

class Div : public Instruction {
 private:
  /* data */
 public:
  Div(/* args */) {}
  Div(std::string name, std::string value) : Instruction(name, value) {}
  ~Div() {}

  void execute() { std::cout << "Execute DIV" << std::endl; }
};

#endif  // DIV_H