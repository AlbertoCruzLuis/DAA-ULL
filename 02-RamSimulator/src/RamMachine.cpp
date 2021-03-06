#include "RamMachine.hpp"

void RamMachine::startMachine(std::string ram_program, std::string in_tape,
                              std::string out_tape) {
  std::cout << "StartMachine" << std::endl;
  control_unit_.loadProgram(ram_program);
  in_tape_ = InTape(in_tape);
  out_tape_ = OutTape(out_tape);
  state_ = 1;
}

void RamMachine::showRegisterOfMemory() { std::cout << memory_ << std::endl; }

void RamMachine::desensamblador() {}

void RamMachine::execute(bool mode_trace) {
  reset();
  // Execute Instructions
  control_unit_.executeProgram(state_, memory_, in_tape_, out_tape_,
                               mode_trace);
}

void RamMachine::showInputTape() { std::cout << in_tape_ << "\n"; }

void RamMachine::showOutputTape() { std::cout << out_tape_ << "\n"; }

void RamMachine::reset() {
  memory_.reset();
  in_tape_.reset();
  out_tape_.reset();
}