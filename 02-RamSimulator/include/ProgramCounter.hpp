/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February / March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#include <iostream>

class ProgramCounter {
 private:
  int current_address_;

 public:
  ProgramCounter();
  ~ProgramCounter() {}

  int get_current_address();
  void set_address(int address);
  void next_address();
  void reset();
};

#endif  // PROGRAMCOUNTER_H