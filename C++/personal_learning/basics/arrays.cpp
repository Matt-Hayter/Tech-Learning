#include <array>

using namespace std;

int main() {
  // Notes:
  // 1. Only use arrays vs vectors if size is known at compile time (not runtime)
  // 2. Performance slightly better than vectors & less memory (light wrapper on C-style array)
  // -> Use when size is known at compile time, and items are being changed (otherwise use tuple)


  // Declare  & Initialise array:

  array<int, 2> arr = {0, 1}; // Array of 0, 1
  array arr1 = {0, 1}; // From C++ 17, compiler can now do argument deduction.

  // Initialize array to default value (fill):

  array<array<bool, 5>, 5> valid_seqs;
    for(auto& row : valid_seqs) fill(row.begin(), row.end(), false);

  return 0;
}