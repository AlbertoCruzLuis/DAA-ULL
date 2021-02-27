#include "AddressingMode.hpp"

AddressingMode::AddressingMode() { mode_ = INMEDIATE; }

AddressingMode::AddressingMode(char symbol) {
  if (symbol == '=') {
    mode_ = INMEDIATE;
  } else if (symbol == '*') {
    mode_ = INDIRECT;
  } else {
    mode_ = DIRECT;
  }
}

char AddressingMode::get_symbol() {
  if (mode_ == INMEDIATE) return '=';
  if (mode_ == INDIRECT) return '*';
  return '\0';
}

unsigned AddressingMode::get_mode() { return mode_; }

std::ostream& operator<<(std::ostream& os, const AddressingMode& addr_mode) {
  if (addr_mode.mode_ == addr_mode.INMEDIATE) {
    os << "Inmediate";
  } else if (addr_mode.mode_ == addr_mode.INDIRECT) {
    os << "Indirect";
  } else if (addr_mode.mode_ == addr_mode.DIRECT) {
    os << "Direct";
  }

  return os;
}
