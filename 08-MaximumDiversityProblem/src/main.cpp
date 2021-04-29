/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 08-MaximumDiversityProblem
|| @Info: http://grafo.etsii.urjc.es/optsicom/mdp/
=======================================================================*/

#include <iostream>

#include "Algorithms/Greedy.hpp"
#include "CommandLineArguments.hpp"
#include "Problem.hpp"
#include "Strategy.hpp"

int main(int argc, char* argv[]) {
  try {
    CommandLineArguments cmd_line(argc, argv);

    std::string file_name = cmd_line.get_list_arguments()[1];
    Problem maximum_diversity(file_name);

    int size_solution = 5;

    Strategy strategy(new Greedy(size_solution));
    std::cout << strategy.run(maximum_diversity);

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }
  return 0;
}
