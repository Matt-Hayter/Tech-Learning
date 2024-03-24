// PL3/vector3.cpp
// Demonstration of the vector container and the use of iterators
// Iterator is a special type of pointer to a vector element.
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<vector>
int main() 
{
  std::vector<double> vector_double; //Empty vector of type double.
  vector_double.push_back(4.5);
  vector_double.push_back(1.5); //Appends these components.
  vector_double.push_back(3.0); 
  std::cout << vector_double[0] << std::endl; //Standard way of accessing component.
  std::vector<double>::iterator vector_begin{vector_double.begin()}; //.begin() returns an iterator pointing to the first vector element.
  std::vector<double>::iterator vector_end{vector_double.end()}; //same as above for final element.
  std::vector<double>::iterator vector_iterator; //empty iterator
  for(vector_iterator=vector_begin;
      vector_iterator<vector_end; //Why not = here?
      ++vector_iterator)
    std::cout<<*vector_iterator<<std::endl; //Pointer used to access a given element of vector.
  return 0;
}

//Note: to use push_back in all cases (especially with dynamic memory in memba data), need a copy and assignment operator as well as a destructor