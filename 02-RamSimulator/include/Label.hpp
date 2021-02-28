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

#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include <vector>

class Label {
 private:
  std::string name_;
  int line_position_;

 public:
  Label(std::string name, int line_position);
  ~Label() {}

  std::string get_name();
  int get_line_position();
};

#endif  // LABEL_H