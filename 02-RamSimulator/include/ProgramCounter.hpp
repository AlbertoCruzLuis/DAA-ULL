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
};

#endif  // PROGRAMCOUNTER_H