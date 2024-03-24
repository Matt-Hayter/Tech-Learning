// PL9/twonum2.cpp
// Define a class template to hold a pair of numbers
// Similar to vector<...>, where vector is a class template and vector<...> created a template class for a vector of doubles.
// Niels Walet, Last modified 03/12/2019

#include<iostream>

// template class definition
template <class T> class pair_of_numbers {
private:
  T x,y;
public:
  pair_of_numbers() : x{},y{} {}
  pair_of_numbers(T xx, T yy) : x{xx},y{yy} {}
  // In this case, also want functions to return the same generic data type
  // These are effectively template functions?
  T add() {return x+y;}
  T sub() {return x-y;}
};
int main()
{
  int x{1};
  int y{2};
  double a{-1.5};
  double b{-2.5};
  // Use class template for object representing pair of integers
  pair_of_numbers<int> ip{x,y};
  std::cout<<"x+y="<<ip.add()<<std::endl;
  std::cout<<"x-y="<<ip.sub()<<std::endl;
  // Now for a pair of doubles
  pair_of_numbers<double> dp{a,b};
  std::cout<<"a+b="<<dp.add()<<std::endl;
  std::cout<<"a-b="<<dp.sub()<<std::endl;
  return 0;
}