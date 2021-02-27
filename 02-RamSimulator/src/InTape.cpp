#include "InTape.hpp"

InTape::InTape(std::string nameFile) {
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