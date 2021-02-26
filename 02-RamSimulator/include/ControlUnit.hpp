#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include <iostream>
#include <vector>

#include "FileParser.hpp"
#include "Instruction.hpp"
#include "Label.hpp"

/* ControlUnit: It is responsible for interpreting and processing the
 * instructions received from a program */

class ControlUnit {
 private:
  std::vector<Label> set_labels_;
  std::vector<Instruction> set_instructions_;

 public:
  ControlUnit();
  ~ControlUnit() {}

  void loadProgram(std::string program_name);
};

#endif  // CONTROL_UNIT_H