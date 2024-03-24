#include <string>

int main() {
  // As of c++20, can used std::format()
  std::string s = std::format("{1} to {0}", "a", "b");
  return 0;
}