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

#ifndef ADD_H
#define ADD_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Add : public Instruction {
 private:
  /* data */
 public:
  Add() {}
  Add(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Add() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    // std::cout << "Execute ADD" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    int result_add;
    if (addressing_mode_.get_mode() == INMEDIATE) {
      result_add = memory.read() + id_register;
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      result_add = memory.read() + memory.read(valueOfRegister);
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      result_add = memory.read() + valueOfRegister;
    }
    memory.write(result_add);
    programCounter.next_address();
  }
};

#endif  // ADD_H