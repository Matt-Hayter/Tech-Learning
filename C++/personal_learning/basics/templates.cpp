 #include <array>

 using namespace std;
 
 int main() {
  // Template arguments must be compile time constants (not runtime)
  // Can have this:
  array<array<bool, 4>, 4> valid_seqs;
  // Can't have this:
  const size_t size{5};
  array<array<bool, size>, size> valid_seqs; // WRONG

 }