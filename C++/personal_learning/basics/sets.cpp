#include <unordered_set>
#include <set>
#include <string>

int main() {
  // Unordered set: implemented as a hashset -> generally O(1) lookup times

  // set: implemented as a heap

  // Initialise set from iterable:
  std::string s = "abcdefffg";
  std::unordered_set<char> some_set(s.begin(), s.end());

  //Check if something's in set: retur true/false:
  some_set.count('a');
}