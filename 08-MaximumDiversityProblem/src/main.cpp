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

    // GRASP Experiment
    /*std::vector<int> size_solutions = {2, 3, 4, 5};
    std::vector<int> size_rcls = {2, 3};

    Experiment experiment(maximum_diversity, "grasp");
    std::cout << experiment << std::endl;
    for (auto&& size_solution : size_solutions) {
      for (auto&& rcl_size : size_rcls) {
        experiment.grasp(size_solution, new ExchangeExternalPoint(), rcl_size);
        experiment.show_table(std::cout);
      }
    }*/

    // Greedy Experiment
    /*std::vector<int> size_solutions = {5, 4};
    Experiment experiment_greedy(maximum_diversity, "greedy");
    std::cout << experiment_greedy << std::endl;
    for (auto&& size_solution : size_solutions) {
      experiment_greedy.greedy(size_solution);
      experiment_greedy.show_table(std::cout);
    }*/

    // Branch&Bound Experiment
    std::vector<int> size_solutions = {4};
    Experiment experiment(maximum_diversity, "branch_bound");
    Experiment experiment_greedy(maximum_diversity, "greedy");
    std::cout << experiment << std::endl;
    for (auto&& size_solution : size_solutions) {
      experiment_greedy.greedy(size_solution);
      experiment.branch_bound(size_solution, experiment_greedy.get_solution(),
                              1);
      experiment.show_table(std::cout);
    }

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }
  return 0;
}
