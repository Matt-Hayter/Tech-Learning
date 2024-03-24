/* 
Assignment 2, Week 2
Reads in users file and prints full courselist either in alphabetical or numerical order,
along with the mean, error on the mean, and standard deviation in coursework marks. Gives
user the option to print the courselist for a particular year and gives corresponding statistics.
Removes empty or invalid data lines in file and informs the user. Validates user inputs.
Makes use of vectors and string streams.
My save location:
C:\\Users\\Student\\Documents\\C++Code\\Assignments\\Assignment_2\\courselist.dat
Matt Hayter, last updated 05/03/2021.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> select_course_year(std::vector<std::string> year_1_courses, std::vector<std::string>
                            year_2_courses, std::vector<std::string> year_3_courses, std::vector<std::string>
                            year_4_courses)
{   
    std::string year_selection;
    std::cout << '\n';
    std::cout << "What year? Enter a year, 1 to 4: ";
    std::cin >> year_selection;
    while(true) {
        if(year_selection == "1") {
            return year_1_courses;
            break;
        } else if(year_selection == "2") {
            return year_2_courses;
            break;
        } else if(year_selection == "3") {
            return year_3_courses;
            break;
        } else if(year_selection == "4") {
            return year_4_courses;
            break;
        } else {
            std::cout << '\n';
            std::cout << "Invalid input. Please enter a year as a single digit, 1 to 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> year_selection;          
        }
    }
}
int find_year_data_length(std::vector<std::string> &year_1_courses,std::vector<std::string> &year_2_courses,
        std::vector<std::string> &year_3_courses, std::vector<std::string> year_4_courses, std::vector<std::string>
        selected_year_courses, int year_1_data_length, int year_2_data_length, int year_3_data_length,
        int year_4_data_length)
{   
    if(selected_year_courses == year_1_courses) {
        return year_1_data_length;
    } else if(selected_year_courses == year_2_courses) {
        return year_2_data_length;
    } else if(selected_year_courses == year_3_courses) {
        return year_3_data_length;
    } else if(selected_year_courses == year_4_courses) {
        return year_4_data_length;
    } else {
        return 0;
    }
}
//Formulates vector containing only course marks, that can be used in other statistical functions. 
std::vector<double> select_course_marks_for_year(std::vector<std::string> year_1_input, std::vector<std::string>
                        year_2_input, std::vector<std::string> year_3_input, std::vector<std::string> year_4_input,
                        std::vector<std::string> selected_year_courses, std::vector<std::string> year_1_courses,
                        std::vector<std::string> year_2_courses, std::vector<std::string> year_3_courses,
                        std::vector<std::string> year_4_courses)
{   
    std::vector<double> year_marks;
    std::vector<double> error(year_1_courses.size(), 0);
    if(selected_year_courses == year_1_courses) {
        for(std::string i : year_1_input) {
            year_marks.push_back(atof(i.substr(0, 5).c_str())); //Converts string marks to char and then double.
        }
        return year_marks;
    } else if(selected_year_courses == year_2_courses) {
        for(std::string i : year_2_input) {
        year_marks.push_back(atof(i.substr(0, 5).c_str()));  
        }
        return year_marks;
    } else if(selected_year_courses == year_3_courses) {
        for(std::string i : year_3_input) {
        year_marks.push_back(atof(i.substr(0, 5).c_str()));  
        }
        return year_marks;
    } else if(selected_year_courses == year_4_courses) {
        for(std::string i : year_4_input) {
        year_marks.push_back(atof(i.substr(0, 5).c_str()));  
        }
        return year_marks;
    } else {
        return error;
    }
}
void order_courselist(std::vector<std::string> &input_data_vector)
{
    std::vector<std::string>::iterator vector_begin{input_data_vector.begin()};
    std::vector<std::string>::iterator vector_end{input_data_vector.end()};
    std::string ordering_choice;
    std::cout << '\n';
    std::cout << "Would you like the courses ordered alphabetically or by course code?" << '\n' <<
        "Type 'a' for alphabeticallly or 'c' for course code: ";
    std::cin >> ordering_choice;
    std::cout << '\n';
    while(true)
    {
        if(ordering_choice == "a" || ordering_choice == "A" || ordering_choice == "alphabetically") {
            //Lambda expression that orders vector lexicographically, in this case alphabetically.
            sort(vector_begin, vector_end, [](std::string const& a, std::string const& b) {
                return std::lexicographical_compare(std::begin(a) + 11, std::end(a), std::begin(b) + 11, std::end(b));
                });
            break;
        } else if(ordering_choice == "c" || ordering_choice == "C" || ordering_choice == "course code") {
            //Lambda expression that orders vector lexicographically, in this case by course code.
            sort(vector_begin, vector_end, [](std::string const& a, std::string const& b) {
                return std::lexicographical_compare(std::begin(a), std::end(a), std::begin(b), std::end(b));
                });
            break;
        } else {
            std::cout << "Invalid input. Please enter 'a' or 'c' for alphabetically/course code: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> ordering_choice;
            std::cout << '\n';
        }
    }
}
double calculate_mean_of_marks(std::vector<double> full_marks_vector, const double number_of_marks)
{   
    double sum;
    for(double i : full_marks_vector) { //Alternative to a for loop for conciseness.
        sum += i;
    }
    double mean = sum/number_of_marks;
    return mean;
}
double calculate_std_of_marks(std::vector<double> marks, const double number_of_marks, double mean)
{
    double difference_squared_sum;
    for(double i : marks) {
        difference_squared_sum += std::pow(i - mean, 2);
    }
    double standard_deviation = std::pow((1/(number_of_marks - 1))*difference_squared_sum, 0.5);
    return standard_deviation;
}
void print_vector_with_iterator(std::vector<std::string> input_data_vector)
{
    std::vector<std::string>::iterator vector_begin{input_data_vector.begin()};
    std::vector<std::string>::iterator vector_end{input_data_vector.end()};
    std::vector<std::string>::iterator vector_iterator;
        for(vector_iterator = vector_begin; vector_iterator < vector_end; vector_iterator ++) {
            std::cout << *vector_iterator << std::endl;
        }
}
int main()
{   
    std::string input_file_name;
    std::ifstream input_file;
    bool good_input;
    //Ensures there is a valid file upon user input.
    do {
        std::cout << "Input a file name for the coursework marks: ";
        std::cin >> input_file_name;
        input_file.open(input_file_name);
        if(!input_file.good()) {
            std::cerr << '\n' << "File could not be opened, check it's location. " << '\n' << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input_file.clear();
            input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            good_input = true;
        }
    } while(good_input != true);
    std::string input_data_line;
    std::vector<std::string> trimmed_input_data; //Vector with any faulty/empty file lines removed.
    std::vector<std::string> full_courselist_vector;
    std::vector<double> full_marks_vector;
    std::ostringstream data_string_stream;
    int raw_file_length{};
    std::cout << '\n';
    //Reads in file line by line and appends it to the relevent vectors.
    while(getline(input_file, input_data_line)) {
        raw_file_length ++;
        if(input_data_line.empty()){
            std::cout << "Data line " << raw_file_length << " is empty and has been omitted" << std::endl;
        } else if(input_file.fail()) {
            std::cerr << "Data could not be successfully read from line " << raw_file_length << ". " << std::endl;
            input_file.clear();
            input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            //Use string stream to alter format of data line.
            trimmed_input_data.push_back(input_data_line);
            data_string_stream << "PHYS " << input_data_line.substr(5, 5) << " " << input_data_line.substr(13, 1000);
            std::string new_data_line{data_string_stream.str()};
            full_courselist_vector.push_back(new_data_line);
            data_string_stream.str("");
            //Convert first 4 digits of string for each line to char and then to double for marks.
            full_marks_vector.push_back(atof(input_data_line.substr(0,5).c_str()));
        }
    }
    input_file.close();
    int data_entries = full_courselist_vector.size();
    std::string want_full_list;
    std::cout << '\n';
    std::cout << "Would you like the full courselist and corresponding statistics? Enter y/n: ";
    std::cin >> want_full_list;
    //Loop calls upon relevent functions to produce the full coursework list and statstics.
    while(true) {
        if(want_full_list == "y" or want_full_list == "yes" or want_full_list == "Y" or want_full_list == "Yes") {
            order_courselist(full_courselist_vector);
            print_vector_with_iterator(full_courselist_vector);
            double mark_mean = calculate_mean_of_marks(full_marks_vector, data_entries);
            double mark_standard_deviation = calculate_std_of_marks(full_marks_vector, data_entries, mark_mean);
            double mark_mean_error = mark_standard_deviation/std::pow(data_entries, 0.5);
            std::cout << '\n' << "Total number of courses within this file: "  << data_entries << '\n'
                << "Mean mark for all coursework: " << std::setprecision(3) << mark_mean << '\n'
                << "Standard error on mean mark: " << mark_mean_error << '\n'
                << "Standard deviation of total marks: " << mark_standard_deviation << std::endl;
            break;
        } else if(want_full_list == "n" or want_full_list == "no" or want_full_list == "N"
                    or want_full_list == "No") {
            std::cout << "Will not print full courselist. " << '\n';
            break;
        } else {
            std::cout << '\n';
            std::cout << "Invalid input. Please enter y or n for yes/no: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> want_full_list;
        }
    }
    //Declare courselist vectors for a given course year.
    std::vector<std::string> year_1_courses;
    std::vector<std::string> year_2_courses;
    std::vector<std::string> year_3_courses;
    std::vector<std::string> year_4_courses;
    //Declare vectors for course years including marks.
    std::vector<std::string> year_1_trimmed_input_data;
    std::vector<std::string> year_2_trimmed_input_data;
    std::vector<std::string> year_3_trimmed_input_data;
    std::vector<std::string> year_4_trimmed_input_data;
    int year_1_data_length{0};
    int year_2_data_length{0};
    int year_3_data_length{0};
    int year_4_data_length{0};
    //Create courselist vector for each course year and obtain length.
    for(std::string i : full_courselist_vector) {
        if(i.substr(5,1) == "1") {
            year_1_courses.push_back(i);
            year_1_data_length ++;
        } else if(i.substr(5,1) == "2") {
            year_2_courses.push_back(i);
            year_2_data_length ++;
        } else if(i.substr(5,1) == "3") {
            year_3_courses.push_back(i);
            year_3_data_length ++;
        } else if(i.substr(5,1) == "4") {
            year_4_courses.push_back(i);
            year_4_data_length ++;
        }
    }
    //Create course year vectors that include final marks.
    for(std::string i : trimmed_input_data) {
        if(i.substr(5, 1) == "1") {
            year_1_trimmed_input_data.push_back(i);
        } else if(i.substr(5, 1) == "2") {
            year_2_trimmed_input_data.push_back(i);
        } else if(i.substr(5, 1) == "3") {
            year_3_trimmed_input_data.push_back(i);
        } else if(i.substr(5, 1) == "4") {
            year_4_trimmed_input_data.push_back(i);
        }
    }
    std::string want_selected_list;
    std::cout << '\n';
    std::cout << "Would you like the courselist and corresponding statistics for a particular year? Enter y/n: ";
    std::cin >> want_selected_list;
    //Loop calls upon relevent functions to produce the coursework list and statstics of a given course year.
    while(true) {
        if(want_selected_list == "y" or want_selected_list == "yes" or want_selected_list == "Y"
            or want_selected_list == "Yes") {
            std::vector<std::string> selected_year_courses = select_course_year(year_1_courses, year_2_courses,
                                                                year_3_courses, year_4_courses);
            int year_data_length = find_year_data_length(year_1_courses, year_2_courses, year_3_courses,
                                                            year_4_courses, selected_year_courses, year_1_data_length,
                                                            year_2_data_length, year_3_data_length, year_4_data_length);
            std::vector<double> year_marks_vector = select_course_marks_for_year(year_1_trimmed_input_data,
                                                        year_2_trimmed_input_data, year_3_trimmed_input_data,
                                                        year_4_trimmed_input_data, selected_year_courses,
                                                        year_1_courses, year_2_courses, year_3_courses, year_4_courses);
            order_courselist(selected_year_courses);
            print_vector_with_iterator(selected_year_courses);
            double mark_mean = calculate_mean_of_marks(year_marks_vector, year_data_length);
            double mark_standard_deviation = calculate_std_of_marks(year_marks_vector, year_data_length, mark_mean);
            double mark_mean_error = mark_standard_deviation/std::pow(year_data_length, 0.5);
            std::cout << '\n' << "Number of courses within the selected year: "  << year_data_length << '\n'
                << "Mean mark for the selected year's coursework: " << std::setprecision(3) << mark_mean << '\n'
                << "Standard error on mean mark: " << mark_mean_error << '\n'
                << "Standard deviation of selected year's marks: " << mark_standard_deviation << std::endl;
            break;
        } else if (want_selected_list == "n" or want_selected_list == "no" or want_selected_list == "N"
            or want_selected_list == "No") {
            std::cout << "Will not print courselist for a particular year. " << '\n';
            break;
        } else {
            std::cout << '\n';
            std::cout << "Invalid input. Please enter y or n for yes/no: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> want_selected_list;
        }
    }
    return 0;
}