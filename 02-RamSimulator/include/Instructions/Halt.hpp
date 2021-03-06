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

#ifndef HALT_H
#define HALT_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Labels.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Halt : public Instruction {
 private:
  /* data */
 public:
  Halt(/* args */) {}
  Halt(std::string name) : Instruction(name) {}
  ~Halt() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, Labels listLabel) {
    // std::cout << "Execute HALT" << std::endl;
    outTape.writeToFile();
    bool stateStop = 0;
    return stateStop;
  }
};
#endif  // HALT_H