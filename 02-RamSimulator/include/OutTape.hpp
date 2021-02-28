/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February / March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

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
  void reset();

  friend std::ostream& operator<<(std::ostream& os, const OutTape& out_tape);
  friend std::ostream& operator<<(std::ostream& os, const OutTape* out_tape);
};

#endif  // OUTTAPE_H