#include "Register.hpp"

Register::Register(int value) : value_(value) {}

int Register::get_value() const { return value_; }

std::ostream& operator<<(std::ostream& os, const Register& c_register) {
  os << "Value of Register: " << c_register.get_value();
  return os;
}