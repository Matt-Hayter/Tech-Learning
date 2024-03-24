// PL7/multiple.cpp
// A Basic example of multiple inheritance
// Niels Walet, last updated 06/12/2019
#include<iostream>
class A {
//Use this
protected: //Member Access extended to derived classes, but still not accessible outside class
  double Ax;
public:
  A(const double Axin) : Ax{Axin} {}
  void show(){std::cout<<"Ax="<<Ax<<std::endl;}
};
class B {
protected:
  double Bx;
public:
  B(const double Bxin) : Bx{Bxin} {}
  void show(){std::cout<<"Bx="<<Bx<<std::endl;}
};
class C : public A, public B {  // Single derived class inheriting both base classes A and B
  double Cx;
public:
  C(const double Axin, const double Bxin, const double Cxin) :
    A{Axin}, B{Bxin}, Cx{Cxin} {} //Contain all inhertited classes here
  void show(){std::cout<<"Ax,Bx,Cx = "<<Ax<<" "<<Bx<<" "<<Cx<<std::endl;}
};
int main() 
{
  C my_object{0.1,0.2,0.3}; //Parameters in order listed in C's constructor
  my_object.show(); //Alternative to using << operator.
  return 0;
}