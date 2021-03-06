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

#ifndef STORE_H
#define STORE_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Store : public Instruction {
 private:
  /* data */
 public:
  Store(/* args */) {}
  Store(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Store() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    // std::cout << "Execute STORE" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    if (addressing_mode_.get_mode() == INMEDIATE) {
      throw "Error Addressing Mode. Addressing Mode not Allowed";
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      memory.write(memory.read(), valueOfRegister);
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      memory.write(memory.read(), id_register);
    }
    programCounter.next_address();
  }
};
#endif  // STORE_H