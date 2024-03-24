#include <limits>
#include <vector>

using namespace std;

int main() {
  // For overloaded constructors, using () not {}
  // {} can lead to unexpected behaviour
  vector<vector<int>> curr_mins(5,
        vector<int>(5, numeric_limits<int>::max()));
}