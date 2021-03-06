/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef LABELS_H
#define LABELS_H

#include <iostream>
#include <map>

class Labels {
  std::map<std::string, int> list_labels_;

 private:
  /* data */
 public:
  Labels() {}
  ~Labels() {}

  int operator[](std::string name);
  void push(std::string name, int line_position);
};

#endif  // LABELS_H