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

#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "RamMachine.hpp"

class Menu {
 private:
  /* data */
 public:
  Menu(RamMachine ramMachine);
  ~Menu() {}

  void showOptions();
  void showHelp();
};

#endif  // MENU_H