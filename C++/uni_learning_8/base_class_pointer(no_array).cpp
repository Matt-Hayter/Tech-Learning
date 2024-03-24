// PL8/baseclasspointer3.cpp
// Demonstrates the use of a baseclass pointer
// Niels Walet, Last modified 03/12/2019
#include<iostream>
using namespace std;
class particle
{
protected:
  double charge;
public:
  particle(double q) : charge{q}{} 
  virtual void info(){std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
};
 
class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q}, atomic_number{Z}{}
  void info(){
    std::cout<<"ion: charge="<<charge
         <<"e, atomic number="<<atomic_number<<std::endl;
  }
};
int main()
{
  particle particle_1{1}; // proton
  ion ion_1{2,2}; // helium nucleus
  particle_1.info();
  ion_1.info();
  //Base class pointers can also point to derived classes of base class.
  //Allows all derived classes to be accessed with singular pointer
  particle *particle_pointer; // pointer to base class, particle 
  //Similar to iterators pointing to a vector of objects! Just no vector so syntax is different.
  //syntax =& used for a pointer to an object of type previously specified
  particle_pointer=&particle_1; // pointer to object particle_1
  particle_pointer->info();// pointer to an object used, so -> used to access member function (like when iterating)
  //Notice that a particle pointer can poin to an ion
  particle_pointer=&ion_1; // point to ion_1 (allowed!)
  particle_pointer->info();
  return 0;
}