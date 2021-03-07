/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef JZERO_H
#define JZERO_H

#include <vector>

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
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
               OutTape& outTape, Labels listLabel) {
    // std::cout << "Execute JZERO" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      throw "Error Addressing Mode. Addressing Mode for Jzero not Allowed";
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      int value_accumalator = memory.read();
      if (value_accumalator == 0) {
        // Jump to line of instruction what pointed label
        int positionToJump = listLabel[value_];
        programCounter.set_address(positionToJump);
      } else {
        programCounter.next_address();
      }
    }
  }
};
#endif  // JZERO_H