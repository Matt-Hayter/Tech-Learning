#include <iostream>

using namespace std;

/*

Question:

Three towers: A, B, C
Discs start at A, with largest at bottom, decreasing in size to top.
Want to get all discs from tower A to C, using B.
Can only move one disc at a time and no larger disc on smaller discs

Answer:

Recursive function, 2^n -1 moves
Move top n-1 to other tower, then base to target, then n-1 from other to target.
Call recursively for top n-1 discs -> works out.

Just think about logic for top layer, then logic works out for other layers.
*/

void solve_towers(int n, char from_tower, char to_tower, char via_tower) {
  if(n==0) return;
  solve_towers(n-1, from_tower, via_tower, to_tower);
  cout << "Moving from " << from_tower << " to " << to_tower << endl;
  solve_towers(n-1, via_tower, to_tower, from_tower);
}



int main() {
  solve_towers(2, 'A', 'C', 'B'); // Top layer: from A, to C, via B.
  solve_towers(4, 'A', 'C', 'B');

  return 0;
}