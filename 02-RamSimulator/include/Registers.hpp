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

#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <map>

class Registers {
 private:
  std::map<int, int> register_bank_;

 public:
  Registers(/* args */) {}
  ~Registers() {}

  void assign(int register_size);
  void push(int id, int value);
  int operator[](int id);
  void clear();

  friend std::ostream& operator<<(std::ostream& os, const Registers& registers);
};

#endif  // REGISTERS_H