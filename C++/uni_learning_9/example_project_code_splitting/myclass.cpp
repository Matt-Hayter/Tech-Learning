// PL9/myclass.cpp
// implementation file for class definition
// Niels Walet, Last modified 03/12/2019


//House style: Same file name used for both header (.h file) (declaration) and implimentation
//As show() belongs to the myclass.h class definition file, both are named the same (myclass)

#include<iostream>
#include "myclass.h"
using namespace my_ns1; //Using my_ns1 namespace
//Function definition still used inside .cpp file as normal
void myclass::show()
{
  std::cout<<"x="<<x<<std::endl;
}