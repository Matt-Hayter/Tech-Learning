// PL8/abstract.cpp
// The use of an abstract base class
// Niels Walet, last updated 04/12/2019
#include<iostream>
class particle
{
public:
  //Notice that there is no constructor here
  //Use base class to define declare virtual functions only (pure virtual functions)
  virtual ~particle(){} // Need this!
  virtual void info()=0; // pure virtual function   
};
class electron : public particle
{
private:
  int charge;
public:
  electron() : charge{-1} {}
  ~electron() {std::cout<<"Electron destructor called"<<std::endl;}
  void info(){std::cout<<"electron: charge="<<charge<<"e"<<std::endl;}  
};
class ion : public particle
{
private:
  int charge,atomic_number;
public:
  // Note constructor short-hand!
  ion(int q, int Z) : charge{q},atomic_number{Z} {}
  ~ion() {std::cout<<"Ion destructor called"<<std::endl;}
  void info(){std::cout<<"ion: charge="<<charge
               <<"e, atomic number="<<atomic_number<<std::endl;}
};