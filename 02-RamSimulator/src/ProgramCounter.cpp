#include "ProgramCounter.hpp"

ProgramCounter::ProgramCounter() { current_address_ = 0; }

int ProgramCounter::get_current_address() { return current_address_; }

void ProgramCounter::set_address(int address) { current_address_ = address; }

void ProgramCounter::next_address() { current_address_++; }

void ProgramCounter::reset() { current_address_ = 0; }