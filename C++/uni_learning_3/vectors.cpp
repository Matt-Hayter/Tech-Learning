// PL3/vector2.cpp
// Demonstration of the vector container.
// Vector is a smart (c++) array.
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<vector>
#include<string>
int main()
{
  const size_t n_a{5}; //type able to represent the size of an something in bytes. Seems similar to integers.
  std::vector<double> a(n_a); //length 5 vector of type double named a.
  std::vector<double> b;  // empty vector (stores doubles)
  std::vector<int> c(3,1); //length 3 vector of integers, with all elements 1
  std::vector<std::string> names(3); //vector with 3 strings
  std::vector<std::vector<double> > dd(3); //vector containing 3 empty double vectors
  dd[0]=a;// set the first element of dd to the vector a
  if(!(a.empty())) std::cout<<"a is not empty"<<std::endl; //Empty means it has not been allocated a size, see b above.
  //To be empty the vector must have no elements, not just storing no values within elements.
  if(b.empty()) std::cout<<"b is empty"<<std::endl;
  std::cout<<"a has size: "<<a.size()<<std::endl; //Find size of a vector (length or #elements).
  std::cout<<"b has size: "<<b.size()<<std::endl; //.size does not include #charcters etc. in an element.
  std::cout<<"c has size: "<<c.size()<<std::endl;
  std::cout<<"names has size: "<<names.size()<<std::endl;
  std::cout<<"dd has size: "<<names.size()<<std::endl; //.size does not count elements of vectors within a vector.
  names[0] = "Vector"; //Filling a vector of the correct size.
  names[1] = "of";
  names[2] = "strings";
  for(size_t i{}; i<names.size(); ++i)
    std::cout << "names[" << i << "] = " << names[i] << std::endl;
  b.push_back(1.5); //Append element to vector of value 1.5, increasing the vectors size
  b.push_back(3.0);
  b.push_back(4.5);
  std::cout<<"b now has size "<<b.size()<<std::endl;
  for(size_t i{}; i<b.size(); ++i) 
    std::cout<<"b[" << i << "] = "<<b[i]<<std::endl;
  b.pop_back();  //Removes element from end of vector.
  std::cout<<"b now has size "<<b.size()<<std::endl;
  for(size_t i{}; i<b.size(); ++i) 
    std::cout<<"b[" << i << "] = "<<b[i]<<std::endl;
  b.clear(); //Removes all elements from vector.
  if(b.empty()) std::cout<<"b is now empty"<<std::endl;
  return 0;
}