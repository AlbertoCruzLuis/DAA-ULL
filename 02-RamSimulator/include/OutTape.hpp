#ifndef OUTTAPE_H
#define OUTTAPE_H

#include <fstream>
#include <iostream>
#include <vector>
class OutTape {
 private:
  std::vector<int> data_;
  std::fstream* file_;

 public:
  OutTape() {}
  OutTape(std::string nameFile);
  ~OutTape();

  std::vector<int> get_data();
  void add(int value);

  void writeToFile();

  friend std::ostream& operator<<(std::ostream& os, const OutTape& out_tape);
  friend std::ostream& operator<<(std::ostream& os, const OutTape* out_tape);
};

#endif  // OUTTAPE_H