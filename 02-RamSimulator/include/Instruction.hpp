#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>

class Instruction {
 protected:
  std::string name_;
  std::string value_;

 public:
  Instruction() {}
  Instruction(std::string name, std::string value);
  virtual ~Instruction() {}

  virtual void execute() {}
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction& instruction);
  friend std::ostream& operator<<(std::ostream& os,
                                  const Instruction* instruction);
};

#endif  // INSTRUCTION_H