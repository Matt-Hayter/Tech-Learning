// PL9/myproject.cpp
// Main code in this file
// Niels Walet, Last modified 03/12/2019

// These are header files (#include), of which compiler will search for code
// Header files are for class definitions and function declarations
#include <iostream>//#include iostream file from standard library
// Now this header file should be included in every .cpp file that makes up program
#include "myclass.h"//Notice .h for our own header file

// Code continues as if header code is written in this file
int main()
{
  my_ns1::myclass c1(1); // namespace from "myclass.h" file
  c1.show();
  return 0;
}