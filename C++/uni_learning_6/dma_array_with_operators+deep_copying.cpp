// PL6/deep.cpp
// An example of a deep copy
// Niels Walet, last updated 23/02/2020
#include<iostream>
class dynamic_array
{
private:
  size_t size {};
  double *array {nullptr};
public:
  // Order functions are called upon will matter if variables are used in other member functions
  dynamic_array()
     {std::cout<<"Default constructor called"<<std::endl;}
  dynamic_array(size_t s); //Constructor uses s, and later function creates array and gives object 'size' property
  //With a destructor, you need a copy and assignment operator too (otherwise destructor gets called too often)
  ~dynamic_array(){std::cout<<"Destructor called"<<std::endl;}
  dynamic_array(dynamic_array&); //Copy constructor
  //Notice the reference to the object now needed for operator (as oppose to another type)
  dynamic_array& operator=(dynamic_array&);
  size_t length() const {return size;} //Equivalent of a get() function
  double & operator[](size_t i);
};

// Parameterized constructor implementation
dynamic_array::dynamic_array(size_t s)
{
  std::cout<<"Parameterized constructor called"<<std::endl;
  if(s<1)
    {
      std::cout<<"Error: trying to declare an array with size < 1"<<std::endl;
      throw("size not positive"); //Outputs a custom error is error occurs within indentation.
    }
  size = s;
  array = new double[size];
  for(size_t i{}; i<size; i++) {
    array[i] = 0;
    std::cout << array[i];
  }
}

// Copy constructor needed for deep copying
// Creates new object with the same properties as the previous (used instead of assignment if object is not yet initialised)
dynamic_array::dynamic_array(dynamic_array &arr)
{
  // Copy size and declare new array
  array=nullptr; size=arr.length();
  if(size>0)
    {
      array=new double[size];
      // Copy values into new array
      for(size_t i{};i<size;i++) array[i] = arr[i];
    }
}
// Creates assignment operator for deep copying
//reference used so that function can be overloaded without destroying the orginial
dynamic_array & dynamic_array::operator=(dynamic_array &arr) // member object is l.h. value, argument is r.h.
{
  // no self assignment
  //If array on rhs of assignment operator is the same as that on the left, return that on left (this) before copying.
  //Copy operator won't run if self same object is in question (no new initialisation of object in main())
  if(&arr == this) return *this; // why &arr needed instead of arr? >> As arr is an rvalue
  // First delete this object's array
  delete[] array; array=nullptr; size=0;
  // Now copy size and declare new array
  size=arr.length();
  if(size>0)
    {
      array=new double[size];
      // Copy values into new array
      for(size_t i{};i<size;i++) array[i] = arr[i];
    }
  // Points to the current ar
  return *this; //
}

// Overloaded element [] operator implementation
double & dynamic_array::operator[](size_t i)
{
  if(i<0 || i>=size)
    {
      std::cout<<"Error: trying to access array element out of bounds"<<std::endl;
      throw("Out of Bounds error");
    }
  return array[i];
}  
int main()
{
  std::cout<<"Declaring array a1 with parameterized constructor"<<std::endl;
  dynamic_array a1{2};
  std::cout<<"Length of a1 = "<<a1.length()<<std::endl;
  a1[0] = 0.5; // Overloaded operator means elements of a private array can be accessed from object using [] after object.
  a1[1] = 1.0;
  std::cout<<"a1[0] = "<<a1[0]<<std::endl;
  std::cout<<"a1[1] = "<<a1[1]<<std::endl;
  std::cout<<std::endl;
  //
  std::cout<<"Declaring array a2 with default constructor"<<std::endl;
  dynamic_array a2;
  std::cout<<"Length of a2 = "<<a2.length()<<std::endl;
  std::cout<<"Now copy values from a1 by assignment"<<std::endl;
  //Compiler auto creates operator= if not defined previously
  a2=a1; //deep copying. Gives a2 same type and data, but doesn't track a change in that data
  std::cout<<"Length of a2 = "<<a2.length()<<std::endl;
  std::cout<<"a2[0] = "<<a2[0]<<std::endl;
  std::cout<<"a2[1] = "<<a2[1]<<std::endl;
  std::cout<<std::endl;
  //
  std::cout<<"Declare array a3 and initialize"<<std::endl;
  dynamic_array a3=a1;
  std::cout<<"Length of a3 = "<<a3.length()<<std::endl;
  std::cout<<"a3[0] = "<<a3[0]<<std::endl;
  std::cout<<"a3[1] = "<<a3[1]<<std::endl;
  std::cout<<std::endl;
  //
  std::cout<<"Using other C++ way to declare and initialize"<<std::endl;
  dynamic_array a4{a1};
  std::cout<<"Length of a4 = "<<a4.length()<<std::endl;
  std::cout<<"a4[0] = "<<a4[0]<<std::endl;
  std::cout<<"a4[1] = "<<a4[1]<<std::endl;
  std::cout<<std::endl;
  // Showing a2-4 are all deep copies (values don't change with a1)
  a1[1] = -2.5;
  std::cout<<"a1[1] = "<<a1[1]<<std::endl;
  std::cout<<"a2[1] = "<<a2[1]<<std::endl;
  std::cout<<"a3[1] = "<<a3[1]<<std::endl;
  std::cout<<"a4[1] = "<<a4[1]<<std::endl;
  return 0;
}