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
    // std::cout << "Execute LOAD" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    if (addressing_mode_.get_mode() == INMEDIATE) {
      memory.write(id_register);
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      memory.write(memory.read(valueOfRegister));
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      memory.write(valueOfRegister);
    }
    programCounter.next_address();
  }
};
#endif  // LOAD_H