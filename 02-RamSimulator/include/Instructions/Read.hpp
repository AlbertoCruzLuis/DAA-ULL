#ifndef READ_H
#define READ_H

#include "Instruction.hpp"

class Read : public Instruction {
 private:
  /* data */
 public:
  Read() {}
  Read(std::string name, std::string value) : Instruction(name, value) {}
  ~Read() {}

  void execute() { std::cout << "Execute READ" << std::endl; }
};

#endif  // READ_H