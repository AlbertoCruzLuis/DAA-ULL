/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 06-LCS_DynamicProgramming
|| @Info: https://en.wikipedia.org/wiki/Dynamic_programming
=======================================================================*/

#include <iostream>

#include "LongestCommonSequence.hpp"

int main(int argc, char const *argv[]) {
  std::string sub_chain = "AGGTAB";
  std::string chain = "GXTXAYB";
  LongestCommonSequence lcs(sub_chain, chain);
  std::cout << lcs << "\n";
  return 0;
}
