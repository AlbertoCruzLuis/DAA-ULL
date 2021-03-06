#include "Instruction.hpp"

Instruction::Instruction(std::string name, char mode, std::string value)
    : name_(name), addressing_mode_(mode), value_(value) {}

Instruction::Instruction(std::string name)
    : name_(name), addressing_mode_('\0'), value_("") {}

std::string Instruction::get_name() { return name_; }

std::string Instruction::get_value() { return value_; }

char Instruction::get_mode() { return addressing_mode_.get_symbol(); }

std::ostream& operator<<(std::ostream& os, const Instruction& instruction) {
  os << "Name: " << instruction.name_
     << " | AddressingMode: " << instruction.addressing_mode_;
  if (instruction.value_ != "") os << " | Value: " << instruction.value_;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Instruction* instruction) {
  os << "Name: " << instruction->name_
     << " | AddressingMode: " << instruction->addressing_mode_;
  if (instruction->value_ != "") os << " | Value: " << instruction->value_;
  return os;
}