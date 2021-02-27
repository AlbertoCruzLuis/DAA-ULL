#include "Instruction.hpp"

class Write : public Instruction {
 private:
  /* data */
 public:
  Write(/* args */) {}
  Write(std::string name, std::string value) : Instruction(name, value) {}
  ~Write() {}

  void execute() { std::cout << "Execute WRITE" << std::endl; }
};