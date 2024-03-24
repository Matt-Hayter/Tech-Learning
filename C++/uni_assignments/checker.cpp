/*
Q's for instructors:
1. Is it best to minimise text in the main code and make use of functions instead? Say if 
    it's more efficient to include a piece of code in the main code (eg. only having to go through iterations
    once rather than twice) do I include it in the main code or not?
2. a 1 w 1 Couldn't figure out how to use DMA on ass 2 w 1 line 33 (input_data_line)
3. a 1 w 2 data_string_stream << "PHYS " << input_data_line.substr(5,'\n'); for some reason '\n' cuts line off after two letter of course name? line 65
4. Why is it best practice to use private object properties if we're still calling on get and set functions outside of class anyway?
5. Why hold function const and use set() within a class, see trialling_5 full_5.
*/

// ofstream constructor.
#include <fstream>      // std::ofstream
#include <iostream>

int main () {

  std::ofstream ofs;
  ofs.open("./test.txt");
  if(ofs.is_open()) {
      std::cout << "OPEN" << std::endl;
  } else if(ofs.fail()) {
      std::cout << "Failed" << std::endl;
  }

  ofs << "lorem ipsum";

  ofs.close();

  return 0;
}