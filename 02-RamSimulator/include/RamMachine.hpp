#ifndef RAMMACHINE_H
#define RAMMACHINE_H

#include <iostream>

#include "ControlUnit.hpp"
#include "InTape.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"

class RamMachine {
 private:
  Memory memory_;
  ControlUnit control_unit_;
  InTape in_tape_;
  OutTape out_tape_;
  bool state_;  // State = 0 or Halt -> Stop the Machine | State = 1 Run

 public:
  RamMachine() {}
  ~RamMachine() {}

  void startMachine(std::string ram_program, std::string in_tape,
                    std::string out_tape);
  void showRegisterOfMemory();
  void desensamblador();  // Convert code to machine code
  void execute();
  void showInputTape();
  void showOutputTape();
};

#endif  // RAMMACHINE_H