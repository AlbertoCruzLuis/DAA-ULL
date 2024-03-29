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

#ifndef MULT_H
#define MULT_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Mult : public Instruction {
 private:
  /* data */
 public:
  Mult(/* args */) {}
  Mult(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Mult() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    // std::cout << "Execute MULT" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    int result_multiply;
    if (addressing_mode_.get_mode() == INMEDIATE) {
      result_multiply = memory.read() * id_register;
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      result_multiply = memory.read() * memory.read(valueOfRegister);
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      result_multiply = memory.read() * valueOfRegister;
    }
    memory.write(result_multiply);
    programCounter.next_address();
  }
};

#endif  // MULT_H