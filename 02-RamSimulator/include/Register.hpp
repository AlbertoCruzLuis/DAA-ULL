#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>

class Register {
 private:
  int value_;

 public:
  Register() {}
  Register(int value);
  ~Register() {}

  int get_value() const;

  operator int() const;

  friend std::ostream& operator<<(std::ostream& os, const Register& c_register);
};

#endif  // REGISTER_H