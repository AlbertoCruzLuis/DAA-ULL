#include "Memory.hpp"

Memory::Memory() { register_bank_.assign(NUM_REGISTER, Register(-1)); }

Register Memory::read(int id_register) { return register_bank_[id_register]; }

void Memory::write(int value, int id_register) {
  register_bank_[id_register] = Register(value);
}

void Memory::reset() {
  register_bank_.clear();
  register_bank_.assign(NUM_REGISTER, Register(-1));
}

std::ostream& operator<<(std::ostream& os, const Memory& memory) {
  for (auto&& c_register : memory.register_bank_) {
    os << c_register << "\n";
  }

  return os;
}
