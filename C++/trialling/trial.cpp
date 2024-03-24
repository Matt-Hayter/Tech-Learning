#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <cmath>
#include <array>
#include <deque>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;




int main() {

  // Template arguments must be *compile time constants* (not runtime):

  // Can have this:
  array<array<bool, 4>, 4> valid_seqsa;
  // Or this, *if size is declared outside of a function*
  const size_t size1{5};
  array<array<bool, size1>, size1> valid_seqsb; // WRONG
  // Can't have this:
  size_t size2{5};
  // array<array<bool, size2>, size2> valid_seqsc; // WRONG

}