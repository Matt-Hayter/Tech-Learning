// PL9/namespaceright.cpp
// User defined namespaces and resolution
// Niels Walet, Last modified 03/12/2019
#include<iostream>
//Can give classes the same name using namespace
//Namespace provides a scope for which variables, functions and classes are defined
namespace my_ns1 {
  //Can also declare variables with the same name
  const double ab{1.5};
  class my_class
  {
  private:
    int x;
  public:
    my_class() : x{} {} 
    my_class(int xx) : x{xx} {}
    ~my_class(){}
    void show(){std::cout<<"x="<<x<<std::endl;}
  };
}
namespace my_ns2
{
  const double ab{2.5};
  class my_class
  {
  private:
    int x,y;
  public:
    my_class() : x{},y{} {}
    my_class(int xx, int yy) : x{xx},y{yy} {}
    ~my_class(){}
    void show(){std::cout<<"x="<<x<<", y="<<y<<std::endl;}
  };
}
int main()
{
  //Good for when using multiple namespaces

  //Both are called myclass, my_ns1 namespace tells the compiler the scope.
  my_ns1::my_class c1{1}; // utilizes my_class from myns1
  c1.show();
  my_ns2::my_class c2{1,2}; // now different my_class from myns2
  c2.show();
  return 0;
}
 