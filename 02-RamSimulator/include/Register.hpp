/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

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