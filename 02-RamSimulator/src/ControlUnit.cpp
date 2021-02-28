#include "ControlUnit.hpp"

ControlUnit::ControlUnit() {}

void ControlUnit::loadProgram(std::string program_name) {
  program_ = Program(program_name);
}

void ControlUnit::executeProgram(bool state_machine, Memory &memory,
                                 InTape &inTape, OutTape &outTape) {
  program_counter_.reset();
  // When program is halt or state_machine is 0 stop the machine
  while (state_machine) {
    int current_address = program_counter_.get_current_address();
    Instruction *current_instruction =
        program_.get_list_instructions()[current_address];
    state_machine = current_instruction->execute(
        memory, program_counter_, inTape, outTape, program_.get_list_label());
    std::cout << "CurrentAddress: " << current_address << std::endl;
    std::cout << program_.get_list_instructions()[current_address] << std::endl;
  }
}