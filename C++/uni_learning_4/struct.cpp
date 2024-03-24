// PL4/struct.cpp
// An example using a struct as a class
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<cmath>
struct particle
{
  std::string type;
  double mass;
  double momentum;
  double energy;
};
void print_data(const struct particle &p)
{
  std::cout.precision(3); // 2 significant figures
  std::cout<<"Particle: [type,m,p,E] = ["<<p.type<<","<< p.mass
       <<","<<p.momentum<<","<<p.energy<<"]"<<std::endl;
  return;
}
double gamma(const struct particle &p)
{
  return p.energy/p.mass;
}
int main()
{
  // Create 2 particles 
  particle electron;
  electron.type="electron";
  electron.mass=5.11e5;
  electron.momentum=1.e6;
  electron.energy=sqrt(electron.mass*electron.mass+electron.momentum*electron.momentum);
  particle proton;
  proton.type="proton";
  proton.mass=0.938e9;
  proton.momentum=3.e9;
  proton.energy=sqrt(proton.mass*proton.mass+proton.momentum*proton.momentum);
  // Print out details
  print_data(electron);
  print_data(proton);
  // Calculate Lorentz factors
  std::cout.precision(2);
  std::cout<<"Particle 1 has Lorentz factor gamma="
       <<gamma(electron)<<std::endl;
  std::cout<<"Particle 2 has Lorentz factor gamma="
       <<gamma(proton)<<std::endl;
  return 0;
}