#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>

class Register {
 private:
  /* data */
 public:
  Register(/* args */) {}
  ~Register() {}

  friend std::ostream& operator<<(std::ostream& os, const Register& c_register);
};

#endif  // REGISTER_H