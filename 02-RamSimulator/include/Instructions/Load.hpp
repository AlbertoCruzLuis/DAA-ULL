#ifndef LOAD_H
#define LOAD_H

#include "Instruction.hpp"

class Load : public Instruction {
 private:
  /* data */
 public:
  Load() {}
  Load(std::string name, std::string value) : Instruction(name, value) {}
  ~Load() {}

  void execute() { std::cout << "Execute LOAD" << std::endl; }
};
#endif  // LOAD_H