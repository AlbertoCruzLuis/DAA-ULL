#ifndef WRITE_H
#define WRITE_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Write : public Instruction {
 private:
  /* data */
 public:
  Write(/* args */) {}
  Write(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Write() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute WRITE" << std::endl;
  }
};

#endif  // WRITE_H