#ifndef LOAD_H
#define LOAD_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Load : public Instruction {
 private:
  /* data */
 public:
  Load() {}
  Load(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Load() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute LOAD" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    if (addressing_mode_.get_mode() == INMEDIATE) {
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      memory.write(valueOfRegister);
    }
    programCounter.next_address();
  }
};
#endif  // LOAD_H