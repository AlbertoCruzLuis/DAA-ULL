#ifndef READ_H
#define READ_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Read : public Instruction {
 private:
  /* data */
 public:
  Read() {}
  Read(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Read() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute READ" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      // Error Addressing Deneged
    }
    // Indirect mode working only when the register what pointed is valid
    if (addressing_mode_.get_mode() == DIRECT) {
      int valueToInsert = inTape.read();
      std::cout << "VAlueToInsert ->" << valueToInsert << std::endl;
      int id_register = stoi(value_);
      memory.read();
      memory.write(valueToInsert, id_register);
    }
    programCounter.next_address();
  }
};

#endif  // READ_H