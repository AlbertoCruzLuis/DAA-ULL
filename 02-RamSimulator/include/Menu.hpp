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