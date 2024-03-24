// PL7/galaxy.cpp
// The definition of a galaxy on top of the celestial object class
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
class celestial_object 
{
//Notice the public members for the base class
//Derived classes cannot access private member data
public:
  std::string name;
  double mass, distance, luminosity; //for compactness
public:
  celestial_object() : 
    name{"no-name"}, mass{}, distance{}, luminosity{} {}
  celestial_object(const std::string nm, const double l, const double m, const double d) :
    name{nm}, mass{m}, distance{d}, luminosity{l} {}
  ~celestial_object(){}
  std::string getname() const {return name;} 
  friend std::ostream& operator<<(std::ostream& , const celestial_object& );
};
class galaxy: public celestial_object { //Defines galaxy that is a derived class of celestial_object.
private:
  std::string hubble_type;
public:
  //Constructor for a derived class
  galaxy() : 
    celestial_object{}, hubble_type{"Sc"} {} //Derived classes need to include base class and members in constructor
  galaxy(const std::string nm, const double l, const double m, const double d,
     const std::string ht) :
    celestial_object{nm,l,m,d}, hubble_type{ht} {}
  ~galaxy(){}
  friend std::ostream& operator<<(std::ostream& , const galaxy& );
};
std::ostream& operator<<(std::ostream& o, const galaxy& gx)
//Can use .name for here as celestial object is public. 
//If name was private, could use public .getname() function.
{o <<" galaxy "<<gx.name <<": "<<std::endl
   <<" Hubble type "<<gx.hubble_type<<std::endl;
    return o;
}
//As this function requires a celestial object right hand argument, it is not called in main (with a galaxy)
std::ostream& operator<<(std::ostream& o, const celestial_object& co)
{o <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<std::endl;
    return o;
}
int main() {
  galaxy LMC{"Large Magellanic Cloud",-1,2e10,0.000875,"SBm"}; //5 inputs into constructor, in the order listed in the galaxy constuctor.
  //Only the << operator with a galaxy argument is called here, not also the base classes << operator
  std::cout << LMC;
  return 0;
}
 