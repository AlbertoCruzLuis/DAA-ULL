#include "Memory.hpp"

Memory::Memory() {
  const int NUM_REGISTER = 14;
  register_bank_.resize(NUM_REGISTER);
}

Register Memory::read(int id_register) { return register_bank_[id_register]; }

void Memory::write(int value, int id_register) {
  register_bank_[id_register] = Register(value);
}

std::ostream& operator<<(std::ostream& os, const Memory& memory) {
  for (auto&& c_register : memory.register_bank_) {
    os << c_register << "\n";
  }

  return os;
}