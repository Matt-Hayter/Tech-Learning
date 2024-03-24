#include <string>
#include <iostream>

using namespace std;

int sol1(string s) {
  int curr_removals = 0;
  for(char c : s) {

  }
  for(auto c_iter{s.rbegin()}; c_iter != s.rend(); c_iter++) {
    cout << *c_iter;
  }
  return curr_removals;
}



int main() {
  cout << sol1("AABAAAABBBBBABB") << endl; // 2
  cout << sol1("ABBBAABABABABAAAB") << endl; // 7
  cout << sol1("BBAAAA") << endl; // 2
  cout << sol1("BBBBBA") << endl; // 1
  cout << sol1("AABABABABABAAABB") << endl; // 5
}