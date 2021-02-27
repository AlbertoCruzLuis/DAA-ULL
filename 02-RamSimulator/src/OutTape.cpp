#include "OutTape.hpp"

OutTape::OutTape(std::string nameFile) {
  file_ = new std::fstream(nameFile, std::fstream::out);
  file_->close();
}

OutTape::~OutTape() {}

std::vector<int> OutTape::get_data() { return data_; }

std::ostream& operator<<(std::ostream& os, const OutTape* out_tape) {
  // Show Data
  return os;
}

std::ostream& operator<<(std::ostream& os, const OutTape& out_tape) {
  // Show Data
  return os;
}