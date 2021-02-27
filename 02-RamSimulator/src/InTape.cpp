#include "InTape.hpp"

InTape::InTape(std::string nameFile) {
  std::cout << "Create InTape" << std::endl;
  tape_position_ = 0;
  file_ = new std::fstream(nameFile, std::fstream::in | std::fstream::out);
  analyzeFile();
  file_->close();
}

InTape::~InTape() {}

std::vector<int> InTape::get_data() const { return data_; }

void InTape::analyzeFile() {
  std::string line;
  while (getline(*file_, line)) {
    addData(line);
  }
}

void InTape::addData(std::string line) {
  std::istringstream iss(line);
  int num;
  while (iss >> num) {
    data_.push_back(num);
  }
}

int InTape::read() {
  int value = 0;
  if (tape_position_ < data_.size()) {
    value = data_[tape_position_];
    tape_position_++;
  }
  return value;
}

std::ostream& operator<<(std::ostream& os, const InTape* in_tape) {
  for (auto&& element : in_tape->get_data()) {
    os << element << " - ";
  }
  os << "\n";
  return os;
}

std::ostream& operator<<(std::ostream& os, const InTape& in_tape) {
  for (auto&& element : in_tape.get_data()) {
    os << element << " - ";
  }
  os << "\n";
  return os;
}