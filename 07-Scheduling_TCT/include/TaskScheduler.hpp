/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 07-Scheduling_TCT
|| @Info: https://en.wikipedia.org/wiki/Parallel_task_scheduling_problem
=======================================================================*/

#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include <iostream>
#include <vector>

#include "Algorithms/Algorithm.hpp"
#include "Solution.hpp"

class TaskScheduler {
 private:
  Algorithm* algorithm_;

 public:
  TaskScheduler(Algorithm* algorithm) { algorithm_ = algorithm; }
  ~TaskScheduler() {}

  Solution run(Graph& graph) { return algorithm_->execute(graph); }
};
#endif  // TASKSCHEDULER_H