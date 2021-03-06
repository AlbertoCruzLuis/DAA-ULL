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

#ifndef JGTZ_H
#define JGTZ_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Jgtz : public Instruction {
 private:
  /* data */
 public:
  Jgtz(/* args */) {}
  Jgtz(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Jgtz() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    std::cout << "Execute JGTZ" << std::endl;
  }
};
#endif  // JGTZ_H