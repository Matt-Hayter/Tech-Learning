// extract to string
#include <iostream>
#include <string>

int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name); //Takes full input of user until delim is found (new line)
  std::cout << "Hello, " << name << "!\n"; //Print new line character to screen with /n

  return 0;
}
