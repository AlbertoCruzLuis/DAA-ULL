#ifndef LOAD_H
#define LOAD_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Load : public Instruction {
 private:
  /* data */
 public:
  Load() {}
  Load(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Load() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute LOAD" << std::endl;
  }
};
#endif  // LOAD_H