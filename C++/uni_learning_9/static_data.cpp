// PL9/staticdata.cpp
// Example using static data members
// Memory allocated throughout lifetime of code
// Niels Walet, Last modified 03/02/2020
#include<iostream>
class my_class
{
private:
  int x{};
  //All objects of my_class class can share and edit this data as it is static
  //Data will not be deleted when object goes out of scope.
  static int n_objects; 
public:
  my_class(int x_in) : x{x_in} {n_objects++;}
  ~my_class() {n_objects--;}
  void show() {std::cout<<"x="<<x<<", n_objects="<<n_objects<<std::endl;}
};
//Memory allocated for duration of code here.
int my_class::n_objects{}; // define static data member outside class! Set to zero here.
void test() 
{
  
  my_class a3{3};
  a3.show();
  //a3 gows out of scope at the end of this function
}
int main()
{
  my_class a1{1};
  a1.show();
  my_class a2{2};
  a2.show();
  test();
  //a1 has n_objects = 2 as a3 has gone out of scope, reducing n_objects by one (in destructor)
  a1.show();
  return 0;
}
 
