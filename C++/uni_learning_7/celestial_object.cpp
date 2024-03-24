#include<iostream>
#include<string>
using namespace std;
class celestial_object {
private:
  string name;
  double mass, distance, luminosity; // for compactness
public:
  celestial_object() : 
    name("no-name"), luminosity(0), mass(1e12), distance(0) {}
  celestial_object(const string nm, const double l, const double m, const double d) :
    name(nm), luminosity(l), mass(m), distance(d){}
  ~celestial_object(){}
  string celestial_object_name() {return name;}
  friend ostream& operator<<(ostream& , const celestial_object& );
};
ostream& operator<<(ostream& o, const celestial_object& co)
{o <<" object "<<co.name <<": "<<endl
   <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<endl;
    return o;}
int main() {
  celestial_object LMC("Large Magellanic Cloud",-1,2e10,0.000875);
  cout <<LMC;
  return 0;
}