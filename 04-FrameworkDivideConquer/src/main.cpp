/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 04-FrameworkDivideConquer
|| @Info: https://es.wikipedia.org/wiki/Algoritmo_divide_y_vencer%C3%A1s
=======================================================================*/

#include <sstream>
#include <vector>

#include "CommandLineArguments.hpp"
#include "Framework.h"
#include "MergeSortProblem.h"
#include "MergeSortSolution.h"
#include "QuickSortProblem.h"
#include "QuickSortSolution.h"

int main(int argc, char* argv[]) {
  try {
    CommandLineArguments cmd_line(argc, argv);

    std::vector<int> array;
    std::string array_in_format_string = cmd_line.get_list_arguments()[1];
    std::stringstream string_to_parser(array_in_format_string);

    char bracketsAndCommas;
    int number;
    string_to_parser >> bracketsAndCommas;
    while (string_to_parser >> number) {
      array.push_back(number);
      string_to_parser >> bracketsAndCommas;
    }

    Framework framework;
    Problema* problem = new QuickSortProblem(array);
    Solucion* solution = new QuickSortSolution();

    framework.divideyVenceras(problem, solution);
    solution->resolver();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }

  return 0;
}