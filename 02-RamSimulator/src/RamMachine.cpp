#include "RamMachine.hpp"

void RamMachine::startMachine(std::string ram_program, std::string in_tape,
                              std::string out_tape) {
  std::cout << "StartMachine" << std::endl;
  control_unit_.loadProgram(ram_program);
}

void RamMachine::showRegisterOfMemory() {}

void RamMachine::desensamblador() {}

void RamMachine::execute() {}

void RamMachine::showInputTape() {}

void RamMachine::showOutputTape() {}