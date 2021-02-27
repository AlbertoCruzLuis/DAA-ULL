#ifndef WRITE_H
#define WRITE_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Write : public Instruction {
 private:
  /* data */
 public:
  Write(/* args */) {}
  Write(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Write() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute WRITE" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    std::cout << "ValueOfRegister -> " << valueOfRegister << std::endl;
    if (addressing_mode_.get_mode() == INMEDIATE) {
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      outTape.add(valueOfRegister);
    }
    programCounter.next_address();
  }
};

#endif  // WRITE_H