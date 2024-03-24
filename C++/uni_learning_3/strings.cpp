#include<iostream>
#include<string>
using std::string;
int main() 
{
  // Strings are also char arrays, but wrapped with extra functionality (eg .size())
  string my_first_string{"Hello, world!"};
  std::cout<<my_first_string<<std::endl;
  //length
  std::cout << "Length of string = "<<my_first_string.length()<<std::endl;
  //individual character
  std::cout<<"2nd character in string is "<<my_first_string[1]<<std::endl;
  //Better for indiv. character
  std::cout<<"The 3rd letter of the string is "<<my_first_string.at(2)<<std::endl;
  string input_string;
  std::cout<<"Enter a phrase: "; 

  getline(std::cin,input_string);
  std::cout << input_string << std::endl;
  string my_second_string{" C++ rocks!"};
  // match
  if(my_first_string == my_second_string) 
    std::cout<<"Strings match!"<<std::endl;
  //join
  string joined_string{my_first_string + my_second_string};
  std::cout<<"Joined string: "<<joined_string<<std::endl;
  //append
  my_first_string +=  my_second_string;
  std::cout<<"Appended string: "<<my_first_string<<std::endl;
  // extract
  const size_t first{18};
  const size_t last{22};
  string a_word = joined_string.substr(first,last-first+1); //from, length up to (hence the +1).
  std::cout<<"Extracting characters "<<first<<"-"<<last<<" from joined string: "<<a_word<<std::endl;
  return 0;
}