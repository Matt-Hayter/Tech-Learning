// PL8/polymorphicvector.cpp
// Demonstrate how to use a vector of baseclass pointers to achieve polymorphism
// Niels Walet, Last modifiess 03/12/2019
#include<iostream>
#include<vector>
// Abstract base class (use as interface only). Abstract because base class contains a pure virual function and has no constrctor
class particle
{
public:
  //Virtual ensures correct function/destructor is called when being accessed with a base class pointer
  //If BASED CLASS destructor is not virtual, it will be called in preference over any derived constructor.
  virtual ~particle(){} // Need this! 
  // pure virtual function, must be implemented in derived classes. (pure syntax is = 0)
  // Declare what functions are common to all derived classes and list them as pure virual
  virtual void info()=0;
};
class electron : public particle
{
private:
  int charge;
public:
  electron() : charge{-1} {}
  ~electron() {std::cout<<"Electron destructor called"<<std::endl;}
  void info(){std::cout<<"electron: charge="<<charge<<"e"<<std::endl;} //Overriding function here
};
class ion : public particle
{
private:
  int charge,atomic_number;
public:
  // Note constructor short-hand!
  ion(double q, int Z) : charge(q),atomic_number(Z) {}
  ~ion() {std::cout<<"Ion destructor called"<<std::endl;}
  void info() //Overriding function here (same return and arguments for different classes)
  {
    std::cout<<"ion: charge="<<charge
         <<"e, atomic number="<<atomic_number<<std::endl;
  }
};
int main()
{
  // Each element in this vector will point to the location of a different shape.
  std::vector<particle*> particle_vector; //Base class pointer here.
  particle_vector.push_back(new ion{1,3});//Adding to vector of base class pointers
  particle_vector.push_back(new electron);
  particle_vector[0]->info();
  particle_vector[1]->info();
  std::cout<<"particle_vector has size "<<particle_vector.size()<<std::endl;
  for (auto particle_vectorit=particle_vector.begin();
       particle_vectorit<particle_vector.end();
       ++particle_vectorit) delete *particle_vectorit;
  particle_vector.clear();
  std::cout<<"particle_vector now has size "<<particle_vector.size()<<std::endl;
  return 0;
}