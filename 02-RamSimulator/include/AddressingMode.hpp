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