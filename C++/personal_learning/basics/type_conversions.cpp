#include <string>

using namespace std;

int main() {

  // string/char array -> int:

  // stoi works for array of chars and string objects
  char c[] = "1111"; 
  int char_int_conversion = stoi(c);
  string s{"771"};
  int string_int_conversion = stoi(s);

  // char -> int:

  char c1 = '1';
  // Implicit cast converts to ASCII (ord() in Python)
  int converted_int = (int)c1 - 48; // 48 is the ASCII value for '0'. Subtracting this gives the integer value we're after (1)

  // char -> string:

  char c2 = 'A';
  string str(1, c2);
  string str2(1, 'A'); // or

  // int -> string
  int a = 1234;
  string string_from_int = to_string(a);
}