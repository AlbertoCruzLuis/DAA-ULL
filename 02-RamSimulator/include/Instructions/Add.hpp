#ifndef ADD_H
#define ADD_H

#include "Instruction.hpp"

class Add : public Instruction {
 private:
  /* data */
 public:
  Add(/* args */) {}
  Add(std::string name, std::string value) : Instruction(name, value) {}
  ~Add() {}

  void execute() { std::cout << "Execute ADD" << std::endl; }
};

#endif  // ADD_H