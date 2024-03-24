#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

  // For simple delimeters (space or new line):

  istringstream pattern1("abc dawdn deidn eid nie di end"); // Pass string to string stream
  string word1;
  while(pattern1 >> word1) { // Extract chunks of stream, separated by " " or "\n" delimeters
    cout << word1 << endl;
  }

  // For other delimeters, use getline:
  istringstream pattern2("abc,dawdn,deidn,eid,nie,di,end"); // Pass string to string stream
  string word2;
  while(getline(pattern2, word2, ',')) {
    cout << word2 << endl;
  }

  return 0;
}
