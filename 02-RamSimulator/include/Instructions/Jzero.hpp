#ifndef JZERO_H
#define JZERO_H

#include <vector>

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Jzero : public Instruction {
 private:
  /* data */
 public:
  Jzero(/* args */) {}
  Jzero(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jzero() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute JZERO" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      // Error Addressing Deneged
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      int value_accumalator = memory.read();
      if (value_accumalator == 0) {
        // Jump to line of instruction what pointed label
        int positionToJump = findLabel(value_, listLabel).get_line_position();
        programCounter.set_address(positionToJump);
      } else {
        programCounter.next_address();
      }
    }
  }

  Label findLabel(std::string name, std::vector<Label> listLabel) {
    for (auto&& label : listLabel) {
      if (label.get_name() == name) {
        return label;
      }
    }
    throw "Error. This Label Not Exist";
  }
};
#endif  // JZERO_H