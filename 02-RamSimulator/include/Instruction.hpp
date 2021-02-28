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

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <vector>

#include "AddressingMode.hpp"
#include "InTape.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Instruction {
 protected:
  const unsigned INMEDIATE = 1;
  const unsigned INDIRECT = 2;
  const unsigned DIRECT = 3;
  std::string name_;
  std::string value_;
  AddressingMode addressing_mode_;

 public:
  Instruction() {}
  Instruction(std::string name, char mode, std::string value);
  Instruction(std::string name);
  virtual ~Instruction() {}

  std::string get_name();
  std::string get_value();
  char get_mode();

  virtual bool execute(Memory& memory, ProgramCounter& programCounter,
                       InTape& inTape, OutTape& outTape,
                       std::vector<Label> list_label) {}
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction& instruction);
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction* instruction);
};

#endif  // INSTRUCTION_H