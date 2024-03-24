#include <string>

int main() {
  // Variable declared on stack
  std::string some_string{"hello"};

  // Pointer declared on stack, pointing to variables on stack
  std::string* stack_pointer = &some_string;
  
  // Pointer declared on stack, pointer to a new dynamically allocated variable on heap
  std::string* heap_pointer = new std::string{52};
  delete heap_pointer;

  return 0;
}