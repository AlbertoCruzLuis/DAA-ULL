#include "LongestCommonSequence.hpp"

#include <algorithm>

LongestCommonSequence::LongestCommonSequence(std::string sub_chain,
                                             std::string chain) {
  int rows = sub_chain.length();
  int cols = chain.length();
  hash_table_.resize(rows + 1);
  execute(sub_chain, chain, rows, cols);
}

void LongestCommonSequence::execute(std::string sub_chain, std::string chain,
                                    int rows, int cols) {
  std::string value_memo;
  for (size_t i = 0; i <= rows; i++) {
    for (size_t j = 0; j <= cols; j++) {
      if (i == 0 || j == 0) {
        hash_table_[i][j] = "";
      } else if (hash_table_[i - 1].count(j - 1) > 0) {
        if (sub_chain[i - 1] == chain[j - 1]) {
          hash_table_[i][j] = hash_table_[i - 1][j - 1] + sub_chain[i - 1];
        } else {
          hash_table_[i][j] =
              std::max(hash_table_[i - 1][j], hash_table_[i][j - 1]);
        }
      }
    }
  }
}

std::ostream& operator<<(std::ostream& os, const LongestCommonSequence& lcs) {
  int last_row = lcs.hash_table_[0].size() - 1;
  int last_col = lcs.hash_table_.size() - 1;
  os << "Longest Common Sequence is "
     << lcs.hash_table_[last_col].rbegin()->second << "\n";
  os << "Length of LCS is "
     << lcs.hash_table_[last_col].rbegin()->second.length();
  return os;
}