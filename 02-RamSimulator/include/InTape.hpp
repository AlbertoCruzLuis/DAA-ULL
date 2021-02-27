#ifndef INTAPE_H
#define INTAPE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class InTape {
 private:
  std::vector<int> data_;
  std::fstream* file_;
  unsigned tape_position_;

 public:
  InTape() {}
  InTape(std::string nameFile);
  ~InTape();

  std::vector<int> get_data() const;

  void analyzeFile();
  void addData(std::string line);
  int read();

  friend std::ostream& operator<<(std::ostream& os, const InTape& in_tape);
  friend std::ostream& operator<<(std::ostream& os, const InTape* in_tape);
};

#endif  // INTAPE_H