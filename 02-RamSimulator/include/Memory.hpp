#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

#include "Register.hpp"

/* Memory: Save and Load the Registers
 * Register Accumulator: Register 0 of Register Bank  */

class Memory {
 private:
  std::vector<Register> register_bank_;

 public:
  Memory();
  ~Memory() {}

  std::vector<Register> get_register_bank();
  Register read(int id_register = 0);
  void write(int value, int id_register = 0);

  friend std::ostream& operator<<(std::ostream& os, const Memory& memory);
};

#endif  // MEMORY_H