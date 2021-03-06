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

#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

#include "Registers.hpp"

/* Memory: Save and Load the Registers
 * Register Accumulator: Register 0 of Register Bank  */

class Memory {
 private:
  const int REGISTER_SIZE = 14;
  Registers register_bank_;

 public:
  Memory();
  ~Memory() {}

  int read(int id_register = 0);
  void write(int value, int id_register = 0);
  void reset();

  friend std::ostream& operator<<(std::ostream& os, const Memory& memory);
};

#endif  // MEMORY_H