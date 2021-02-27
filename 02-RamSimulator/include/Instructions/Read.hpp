#ifndef READ_H
#define READ_H

#include "Instruction.hpp"
#include "Memory.hpp"

class Read : public Instruction {
 private:
  /* data */
 public:
  Read() {}
  Read(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Read() {}

  void execute(Memory memory, ProgramCounter programCounter) {
    std::cout << "Execute READ" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      // Error Addressing Deneged
    }
    if (addressing_mode_.get_mode() == DIRECT) {
      /* code */
    }
  }
};

#endif  // READ_H