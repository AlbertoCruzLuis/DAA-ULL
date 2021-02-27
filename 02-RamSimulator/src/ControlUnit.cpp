#include "ControlUnit.hpp"

ControlUnit::ControlUnit() {}

void ControlUnit::loadProgram(std::string program_name) {
  program_ = Program(program_name);
}

void ControlUnit::executeProgram(bool state_machine) {
  program_counter_;
  // When program is halt or state_machine is 0 stop the machine
  while (state_machine) {
    int current_address = program_counter_.get_current_address();
    program_.get_list_instructions()[current_address]->execute();
    std::cout << "CurrentAddress: " << current_address << std::endl;
    std::cout << "CurrentInstruction: "
              << program_.get_list_instructions()[current_address] << std::endl;
    // Test for stop inifinit loop. Necesary Implementation the instructions.
    state_machine = 0;
  }
}