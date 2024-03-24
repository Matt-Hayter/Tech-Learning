#include <string>
#include <vector>
#include <algorithm>    // std::reverse
#include <iostream>

int main() {
  std::string string_iterable = "abcdefg";
  //char char_array[] = "12345";
  //Reverse any iterable
  reverse(string_iterable.begin(), string_iterable.end());
  std::cout << string_iterable;
}