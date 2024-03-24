// PL9/functiontemplate.cpp
// Demonstration of function templates, used when function is do be overloaded with a different variable type.
// Unlike prev. seen overloading, this allows a generic datatype to use the same function, which can be specified later in code.
// Niels Walet, Last modified 04/12/2019
#include<iostream>
//T is a generic template parameter here
//After ...> remainder of function is the same as a usual function, but returning and feeding in type "T"
template <class T> T maxval(T a, T b) //Usually T = c_type, it's arbitrary
{
  //? Used for true/false tests returning an lvalue
  //test ? iftrue::iffalse
  return (a > b) ? a : b;
}
int main()
{
  double x1{1}; double x2{1.5};
  //Instance of function created here (double)
  std::cout<<"Maximum value (doubles) = "<< maxval<double>(x1,x2)<<std::endl;
  int i1{1}; int i2{-1};
  //Another istance of function (int)
  std::cout<<"Maximum value (ints) = "<< maxval<int>(i1,i2)<<std::endl;
  return 0;
}