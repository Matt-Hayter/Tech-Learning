#include <vector>
#include <iostream>
#include <algorithm> // Required for min/max_element

using namespace std;

int main() {
  vector<int> res{5, 2};
  res.push_back(7); // Max
  res.push_back(1); // Min
  // Max/min_element functions require pointer to first up to end elements, which point to values to be compared (not further pointers etc.)
  vector<int>::iterator max_el = max_element(res.begin(), res.end()); // Returns iterator pointing to max val
  vector<int>::iterator min_el = min_element(res.begin(), res.end()); // Returns iterator pointing to min val

  cout << "min el: " << *min_el << "max el: " << *max_el;

  return 0;
}