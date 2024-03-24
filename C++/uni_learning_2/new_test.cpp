
#include <iostream>

int main()
{
  double* my_data = new double[5];

  for(int i{};i<5;i++)
    std::cin>>my_data[i];

  for(int i{};i<5;i++)
    std::cout<<my_data[i];

  delete[] my_data;

  return 0;
}