#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include <iostream>
#include <vector>

#include "Memory.hpp"
#include "Program.hpp"
#include "ProgramCounter.hpp"

/* ControlUnit: It is responsible for interpreting and processing the
 * instructions received from a program */

class ControlUnit {
 private:
  Program program_;
  ProgramCounter program_counter_;

 public:
  ControlUnit();
  ~ControlUnit() {}

  void loadProgram(std::string program_name);
  void executeProgram(bool state_machine, Memory &memory);
};

#endif  // CONTROL_UNIT_H