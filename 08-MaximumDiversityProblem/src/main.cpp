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

#include "CommandLineArguments.hpp"
#include "Experiment.hpp"
#include "LocalSearch.hpp"
#include "NeighbourAlgorithms/ExchangeExternalPoint.hpp"
#include "Problem.hpp"

int main(int argc, char* argv[]) {
  try {
    CommandLineArguments cmd_line(argc, argv);

    std::string file_name = cmd_line.get_list_arguments()[1];
    Problem maximum_diversity(file_name);

    std::vector<int> size_solutions = {2, 3, 4, 5};
    Experiment experiment(maximum_diversity, "greedy");
    std::cout << experiment << std::endl;
    for (auto&& size_solution : size_solutions) {
      experiment.greedy(size_solution);
      experiment.show_table(std::cout);
    }

    LocalSearch local_search(new ExchangeExternalPoint());
    std::cout << local_search.execute(experiment.get_solution());

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }
  return 0;
}
