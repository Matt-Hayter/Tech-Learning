// PL5/classfull.cpp
// A fully functioning class for 3-vectors
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
class vector3
{
  //friend functons defined at beginning.
  friend vector3 operator+(double scalar, const vector3 &v);
  friend std::ostream & operator<<(std::ostream &os, const vector3 &v);
private:
// Good practice to define private object properties, which can only be changed by feeding into class.
  double x,y,z;
public:
  vector3() : x{}, y{}, z{} {}
  // This must create a vector (without std::vector)
  vector3(double xin, double yin, double zin) : x{xin}, y{yin}, z{zin} {}
  ~vector3(){std::cout<<"Destroying vector"<<std::endl;} 
  // Access functions to set and get vector components
  // set and get functions used so that object properties can be re-defined if function variables are held constant.
  // Also used so properties can be accessed outside of function
  void set_x(double xin) {x=xin;}
  void set_y(double yin) {y=yin;}
  void set_z(double zin) {z=zin;}
  double get_x() const {return x;}
  double get_y() const {return y;}
  double get_z() const {return z;}
  // Function to calculate dot product of two vectors
  double dot_product(const vector3 &v) const // const on end guarentees member data is not modified.
  {
    // left x, y and z refer to current object's (b's) properties.
    // .x, .y and .z parts refer to the properties of object v (passed into function)
    return (x*v.x+y*v.y+z*v.z); //v.x accesses property x of object
  }
  // Function to overload + operator (addition of two vectors)
  vector3 operator+(const vector3 &v) const
  {
    vector3 temp{x+v.x,y+v.y,z+v.z};
    return temp;
  }
  // Another one for (right) adding a scalar
  // Function is overloaded here (same name but different argument/return)
  // Want a new object to be returned, hence function type
  vector3 operator+(const double scalar) const
  {
    vector3 temp{x+scalar,y+scalar,z+scalar};
    return temp;
  }
  // Want the current object to be changed and increased, hence the type void
  void operator+=(const double scalar) 
  {
    // Changes properties of member object (as this is within class)
    x+=scalar; y+=scalar; z+=scalar;
  }
  void operator+=(const vector3 &v) 
  {
    x+=v.x; y+=v.y; z+=v.z;
  }
}; // End of class
// Friend function (not members but have access to member data)
// Non-member function to left-add scalar to vector
// Require vector as argument
vector3 operator+(double scalar, const vector3 &v) //Reference to vector needed as oustide of class.
{
  vector3 temp{scalar+v.x,scalar+v.y,scalar+v.z};
  return temp;
}
// Friend function (not members but have access to member data)
// Require vector as argument
// Non-member function to overload ostream (e.g., cout) for vector3. Hence argument required output stream type (beginning of << stream)
// returns a reference to an ostream, so that << in main can be given value of stream os.
// If operator << is used and argument is not a vector, compiler will generate a standard << operator.
std::ostream & operator<<(std::ostream &os, const vector3 &v) //Left and right arguments
  {
    // Adds these components to output stream os
    os<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
    return os;
  }
// Main program
int main()
{
  vector3 a;
  vector3 b{1,2,3};
  vector3 c{-1,-2,-3};
  // Print vectors 
  // Works as cout<<a, cout<<b etc.
  std::cout <<a<<" "<<b<<" "<<c<<std::endl;
  // Add a scalar to each vector component
  double s{-1.5};
  // Can be done as operator functions are defined above, one being the += operator with a double argument
  // variable after sign defined as argument, and one before as member object.
  b+=s; // equivalent to b.operator+=(s);
  std::cout << b <<std::endl;
  // Dot product using member function of vector3
  double dp=b.dot_product(c);
  std::cout<<"Dot product b.c = "<<dp<<std::endl;
  // Can be done as operator functions are defined above, one being the + operator with vector arguments.
  // variable after sign defined as argument, and one before as member object.
  vector3 e=b+c; // Define an object e with no defined properties
  std::cout << e<<std::endl;
  // Can be done as operator functions are defined above, one being the += operator with a vector argument
  // variable after sign defined as argument, and one before as member object.
  b+=c;
  std::cout << b << std::endl;
  std::cout << b.get_x() << std::endl;
  return 0;
}