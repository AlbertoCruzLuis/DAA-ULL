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

#ifndef DIV_H
#define DIV_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Div : public Instruction {
 private:
  /* data */
 public:
  Div(/* args */) {}
  Div(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Div() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    std::cout << "Execute DIV" << std::endl;
  }
};

#endif  // DIV_H