// PL3/cppstringstream.cpp
// Demonstration a string stream in the modern syntax
// String stream used so that strings can be written and other actions performed and not necessarily immediately printed out (for ostream).
// Without ostream, cout would be needed at the beginning of the output stream
// With ostream, stringstream can be attributed to variable (in this case output_stream) and then used later.
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<sstream> 
using namespace std;
int main() 
{
  //Integer identifier for a given file name
  ostringstream output_stream;
  output_stream << "FileData."; //Inputs "file_data" and file_index into string stream
  //Extracts string from stringstream and names it output_filename
  //Needs to be done as not all components in string stream are 'strings'
  string output_filename1{output_stream.str()};
  //Output_file_name has value 'FileData.123'
  std::cout << output_filename1 << std::endl;

  double random_number{239147};
  output_stream << "." << random_number;
  string output_filename2{output_stream.str()};
  cout << output_filename2 << std::endl;
  output_stream.str(""); //clear string stream buffer (memory).
  return 0;
}