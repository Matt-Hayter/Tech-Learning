#include <array>

int main() {
  // Fill iterable with given value:

  std::array<std::array<bool, 5>, 5> valid_seqs;
    for(auto& row : valid_seqs) std::fill(row.begin(), row.end(), false);
}