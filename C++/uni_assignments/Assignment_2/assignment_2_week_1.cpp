/* 
Assignment 2, Week 1
Reads in users file and uses arrays with DMA to calculate the mean,
error on the mean, and standard deviation in coursework marks within file.
Indicates the location of and omits any empty or failed lines, informing
the user.
My save location:
C:\\Users\\Student\\Documents\\C++Code\\Assignments\\Assignment_2\\courselist.dat
Matt Hayter, last updated 05/03/2021.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <iterator>

double calculate_mean_of_marks(double*, const double); //Function protoypes for clear layout.
double calculate_std_of_marks(double*, const double, double);

int main()
{   
    std::string input_file_name;
    std::ifstream input_file;
    bool good_input;
    do {
        std::cout << "Input a file name for the coursework marks: " << std::endl;
        std::cin >> input_file_name;
        input_file.open(input_file_name);
        if(!input_file.good()) {
            std::cerr << "File could not be opened, check it's location. " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input_file.clear();
            input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            good_input = true;
        }
    } while (good_input != true);
    std::string input_data_line;
    int raw_file_length{};
    int faulty_file_lines{}; //Variable for number of blank or faaulty lines in file.
    while(!input_file.eof()) {
        getline(input_file, input_data_line);
        raw_file_length ++;
        if(input_data_line.empty()){
            faulty_file_lines ++; //Adds number of empty lines.
            std::cout << "Data line " << raw_file_length << " is empty and has been omitted. " << std::endl;
        }
        if(input_file.fail()) {
            faulty_file_lines ++; //Adds number of failed lines.
            std::cerr << "Data could not be successfully read from line " << raw_file_length << ". " << std::endl;
            input_file.clear();
            input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } 
    int trimmed_file_length = raw_file_length - faulty_file_lines;
    input_file.seekg(0); //Resets file pointer back to first line.
    std::string *input_data_array{new std::string[trimmed_file_length]};
    double *marks{new double[trimmed_file_length]};
    for(int i{}; i < trimmed_file_length; i++) { //Using trimmed file length together with i-- to omit faulty lines.
        getline(input_file, input_data_line, '\n');
        if(!input_data_line.empty() and !input_file.fail()) {
            input_data_array[i] = input_data_line;
            //Convert first 4 digits of string for each line to char and then to double.
            marks[i] = atof(input_data_line.substr(0,5).c_str());
        } else {
            i --; //Ensures all components of data and marks array are filled in the case of a faulty file line.
        }
    }   
    input_file.close();
    delete[] input_data_array;
    double mark_mean = calculate_mean_of_marks(marks, trimmed_file_length);
    double mark_standard_deviation = calculate_std_of_marks(marks, trimmed_file_length, mark_mean);
    double mark_mean_error = mark_standard_deviation/std::pow(trimmed_file_length, 0.5);
    delete[] marks;
    std::cout << "There are " << trimmed_file_length << " lines of data that have been used from this file. " << "\n" <<
        "The mean coursework mark is " << std::setprecision(3) << mark_mean << 
        " with an error of " << mark_mean_error << ".\n" << "The standard deviation in course marks is "
        << mark_standard_deviation << "." << std::endl;
    return 0;
}
double calculate_mean_of_marks(double *marks, const double number_of_marks)
{
    double sum;
    for(int i{}; i < number_of_marks; i++) {
        sum += marks[i];
    }
    double mean = sum/number_of_marks;
    return mean;
}
double calculate_std_of_marks(double *marks, const double number_of_marks, double mean)
{
    double difference_squared_sum{0};
    for(int i{}; i < number_of_marks; i++) {
        difference_squared_sum += std::pow(marks[i] - mean, 2);
    }
    double standard_deviation = std::pow((1/(number_of_marks - 1))*difference_squared_sum, 0.5);
    return standard_deviation;
}