#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>

#include "AddressingMode.hpp"
#include "Memory.hpp"
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

  virtual void execute(Memory memory, ProgramCounter programCounter) {}
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction& instruction);
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction* instruction);
};

#endif  // INSTRUCTION_H