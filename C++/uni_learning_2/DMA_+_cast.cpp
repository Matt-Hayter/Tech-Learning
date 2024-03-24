// PL1/dynamic.cpp
// Example of program using dynamic memory allocation
// Niels Walet, last updated 04/12/2019
#include<iostream>

int main()
{
  int number_of_values{};

  // Get number of values
  std::cout<<"Enter the number of values to enter: ";
  std::cin>>number_of_values;
  std::cout<<"You would like to enter "<<number_of_values<<" values"<<std::endl;

  // allocate memory for array of values

  double* values = new double[number_of_values];
  std::cout<<"Allocated memory for "<<number_of_values<<" doubles"<<std::endl;
  std::cout<<"Enter "<<number_of_values<<" doubles"<<std::endl;
  
  for(int i{};i<number_of_values;i++) //from, to, in steps of...
    std::cin>>values[i];
  std::cout<<"Here are your values: ";
  for(int i{};i<number_of_values;i++) 
    std::cout<<values[i]<<" ";
  std::cout<<std::endl;

  // Free memory
  delete[] values; //deleting an array
  std::cout<<"Freed memory"<<std::endl;
  return 0;
}