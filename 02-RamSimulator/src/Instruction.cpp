#include "Instruction.hpp"

Instruction::Instruction(std::string name, std::string value)
    : name_(name), value_(value) {}

std::ostream& operator<<(std::ostream& os, const Instruction& instruction) {
  os << "Name: " << instruction.name_ << "Value: " << instruction.value_;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Instruction* instruction) {
  os << "NamePointer: " << instruction->name_
     << "Value: " << instruction->value_;
  return os;
}