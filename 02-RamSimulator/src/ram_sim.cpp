/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#include <iostream>

#include "CommandLineArguments.hpp"
#include "Menu.hpp"
#include "RamMachine.hpp"

int main(int argc, char* argv[]) {
  try {
    CommandLineArguments cmd_line(argc, argv);

    std::string program_name = argv[1];
    std::string in_tape_name = argv[2];
    std::string out_tape_name = argv[3];
    int debug_mode = atoi(argv[4]);

    RamMachine ramMachine;
    ramMachine.startMachine(program_name, in_tape_name, out_tape_name);

    if (debug_mode) Menu menu(ramMachine);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }
  return 0;
}
