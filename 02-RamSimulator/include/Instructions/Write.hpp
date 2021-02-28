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
    // std::cout << "Execute WRITE" << std::endl;
    int id_register = std::stoi(value_);
    int valueOfRegister = memory.read(id_register);
    int dataToWrite;
    if (addressing_mode_.get_mode() == INMEDIATE) {
      dataToWrite = id_register;
    }
    if (addressing_mode_.get_mode() == INDIRECT) {
      dataToWrite = memory.read(valueOfRegister);
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      dataToWrite = valueOfRegister;
    }
    outTape.add(dataToWrite);
    programCounter.next_address();
  }
};

#endif  // WRITE_H