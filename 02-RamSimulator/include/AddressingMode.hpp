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

#ifndef ADDRESSINGMODE_H
#define ADDRESSINGMODE_H

#include <iostream>

class AddressingMode {
 private:
  const unsigned INMEDIATE = 1;
  const unsigned INDIRECT = 2;
  const unsigned DIRECT = 3;
  unsigned mode_;

 public:
  AddressingMode();
  AddressingMode(char symbol);
  ~AddressingMode() {}

  char get_symbol();
  unsigned get_mode();

  friend std::ostream& operator<<(std::ostream& os,
                                  const AddressingMode& addr_mode);
};

#endif  // ADDRESSINGMODE_H