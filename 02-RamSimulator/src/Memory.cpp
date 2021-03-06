#include "Memory.hpp"

Memory::Memory() { register_bank_.assign(REGISTER_SIZE); }

int Memory::read(int id_register) { return register_bank_[id_register]; }

void Memory::write(int value, int id_register) {
  register_bank_.push(id_register, value);
}

void Memory::reset() {
  register_bank_.clear();
  register_bank_.assign(REGISTER_SIZE);
}

std::ostream& operator<<(std::ostream& os, const Memory& memory) {
  os << memory.register_bank_;

  return os;
}
