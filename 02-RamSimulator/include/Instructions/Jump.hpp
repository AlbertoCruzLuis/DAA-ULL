/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February / March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef JUMP_H
#define JUMP_H

#include <vector>

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "Program.hpp"
#include "ProgramCounter.hpp"

class Jump : public Instruction {
 private:
  /* data */
 public:
  Jump(/* args */) {}
  Jump(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jump() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    std::cout << "Execute JUMP" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      // Error Addressing Deneged
    }
    // Indirect mode working only when the register what pointed is valid
    if (addressing_mode_.get_mode() == DIRECT) {
      // Browse the Label what pointed Instruction in listLabel

      int positionToJump = findLabel(value_, listLabel).get_line_position();
      programCounter.set_address(positionToJump);
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
#endif  // JUMP_H