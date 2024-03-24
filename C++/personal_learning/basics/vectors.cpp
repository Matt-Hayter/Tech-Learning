#include <vector>

int main() {
  // Constrcutors:

  // Custom constructor: length of vector, default value
  std::vector<int> one_d_vector_a (5, 999);

  // Nested curly braces initialises with a vector of 5, 999
  std::vector<int> one_d_vector_b ({5, 999});

  // 2D vector filled with 999s
  std::vector<std::vector<int>> two_d_vector (5, std::vector<int> (7, 999));

  // Copy constructor to slice vector
  std::vector<int> sliced_vector = std::vector<int>(one_d_vector_a.begin()+3, one_d_vector_a.end());


  // Size

  // For using the .size() of a vector in comparisons/constructors, sometimes best to cast to int first, to avoid errors from implicit conversions.
  int N = two_d_vector.size(),
      M = two_d_vector[0].size();

  // Or can use dynamic cast, if stl functions that convert implicitly (eg. min/max) are not used extensively
  2 + (int)two_d_vector.size(); // Casting size_t to int



  // Insert/Extend

  // Extend one vector with another
  std::vector<int> temp_vector{1, 1, 1, 1};
  one_d_vector_a.insert(one_d_vector_a.end(), temp_vector.begin(), temp_vector.end());

  return 0;
}