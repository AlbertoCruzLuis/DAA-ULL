#include "Registers.hpp"

int Registers::operator[](int id) {
  std::cout << "ValueRegister: " << register_bank_[id] << std::endl;

  return register_bank_[id];
}

void Registers::assign(int register_size) {
  for (int id = 0; id < register_size; id++) {
    register_bank_.insert({id, -1});
  }
}

void Registers::push(int id, int value) { register_bank_[id] = value; }

void Registers::clear() { register_bank_.clear(); }

std::ostream& operator<<(std::ostream& os, const Registers& registers) {
  for (auto&& c_register : registers.register_bank_) {
    os << "Register [" << c_register.first << "]: " << c_register.second
       << "\n";
  }
  return os;
}