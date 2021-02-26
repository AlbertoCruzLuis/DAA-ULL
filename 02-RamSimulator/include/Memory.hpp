#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

#include "Register.hpp"

/* Memory: Save and Load the Registers */

class Memory {
 private:
  std::vector<Register> register_bank_;

 public:
  Memory(/* args */) {}
  ~Memory() {}

  std::vector<Register> get_register_bank();
};

#endif  // MEMORY_H