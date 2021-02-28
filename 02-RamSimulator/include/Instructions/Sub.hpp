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

#ifndef SUB_H
#define SUB_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Sub : public Instruction {
 private:
  /* data */
 public:
  Sub() {}
  Sub(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Sub() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    // std::cout << "Execute SUB" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    int result_sub;
    if (addressing_mode_.get_mode() == INMEDIATE) {
      result_sub = memory.read() - id_register;
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      result_sub = memory.read() - memory.read(valueOfRegister);
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      result_sub = memory.read() - valueOfRegister;
    }
    memory.write(result_sub);
    programCounter.next_address();
  }
};

#endif  // SUB_H