#ifndef INTAPE_H
#define INTAPE_H

#include <fstream>
#include <sstream>
#include <vector>

class InTape {
 private:
  std::vector<int> data_;
  std::fstream* file_;

 public:
  InTape() {}
  InTape(std::string nameFile);
  ~InTape();

  std::vector<int> get_data() const;

  void analyzeFile();
  void addData(std::string line);

  friend std::ostream& operator<<(std::ostream& os, const InTape& in_tape);
  friend std::ostream& operator<<(std::ostream& os, const InTape* in_tape);
};

#endif  // INTAPE_H