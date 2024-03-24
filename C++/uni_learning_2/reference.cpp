// PL1/byreference3.cpp
// A problem with references
// Niels Walet, last updated 04/12/2019
#include <iostream> 
#include <string>

int main() 
{ 
  int a{1}; 
  int &b{a}; // b refers to a (so b will change if a changes) 
  std::cout<<a<<" "<<b<<std::endl; 
  a++; 
  std::cout<<a<<" "<<b<<std::endl;
  b++; 
  std::cout<<a<<" "<<b<<std::endl;
  return 0;
}