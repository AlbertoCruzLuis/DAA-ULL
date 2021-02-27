#include "OutTape.hpp"

OutTape::OutTape(std::string nameFile) {
  file_ = new std::fstream(nameFile, std::fstream::out);
}

OutTape::~OutTape() {}

std::vector<int> OutTape::get_data() { return data_; }

void OutTape::add(int value) { data_.push_back(value); }

void OutTape::writeToFile() {
  for (auto&& value : data_) {
    *file_ << value << " ";
  }
  file_->close();
}

std::ostream& operator<<(std::ostream& os, const OutTape* out_tape) {
  // Show Data
  return os;
}

std::ostream& operator<<(std::ostream& os, const OutTape& out_tape) {
  // Show Data
  return os;
}