/*
A Class for Matrices
Allows user to enter two matrices, informing the user of various actions made.
Matt Hayter, last updated 16/04/2021
*Some slightly incorrect values
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

class matrix
{
    //Friend functions
    friend void operator >> (std::istream &, matrix &);
    friend std::ostream &operator << (std::ostream &, matrix &);
    private:
        int number_of_rows, number_of_columns, entered_elements, matrix_points;
        double *matrix_data;
    public:
        matrix() : number_of_rows{0}, number_of_columns{0}, entered_elements{0}, matrix_points{0},
            matrix_data{nullptr} {} //Default constructor
        matrix(int rows, int columns); //Paramaterised constructor
        ~matrix() 
        {   
            //delete[] matrix_data; //Destructor that clears dynamic memory after use
        }
        matrix(const matrix &); //Copy constructor
        matrix(matrix &&); //Move constructor
        matrix &operator = (matrix &); //Assignment operator
        matrix &operator = (matrix &&); //Move operator
        matrix operator + (matrix &); 
        matrix operator - (matrix &);
        matrix operator * (matrix &);
        matrix remove_row_i_column_j(int, int);
        double calculate_determinant();
        //Function to alter a matrices data
        void change_data()
        {
            for(int i{}; i < matrix_points; i++) {
                if(matrix_data[i] != 1) {
                    matrix_data[i] = 1;
                } else if (matrix_data[i] != 0) {
                    matrix_data[i] = 0;
                }
            }
        }
        //Returns a given matrix data point
        double get_index_value(int row, int column)
        {
            int matrix_index = column - 1 + (row - 1)*number_of_columns;
            return matrix_data[matrix_index];
        }
        int get_rows()
        {
            return number_of_rows;
        }
        int get_columns()
        {
            return number_of_columns;
        }
        int get_entered_elements()
        {
            return matrix_points;
        }
};
//Asks user to input the number of rows and validates input
int input_rows(size_t matrix_number)
{
    int rows;
    std::cout << "Matrix Number " << matrix_number + 1 << ": " << std::endl;
    std::cout << "- Enter the number of rows: ";
    std::cin >> rows;
    while(true) {
        if (!(rows > 0) || std::cin.peek() != '\n') {
            std::cout << "Invalid input, please enter an integer greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignores all the users input
            std::cout << "- Enter the number of rows: ";
            std::cin >> rows;
        } else {
            break;
        }
    }
    return rows;
}
//Asks user to input the number of columns and validates input
int input_columns()
{
    int columns;
    std::cout << "- Enter the number of columns: ";
    std::cin >> columns;
    while(true) {
        if (!(columns > 0) || std::cin.peek() != '\n') {
            std::cout << "Invalid input, please enter an integer greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "- Enter the number of columns: ";
            std::cin >> columns;
        } else {
            break;
        }
    }    
    return columns;
}
//Paramaterised constructor
matrix::matrix(int rows, int columns)
{
    number_of_rows = rows;
    number_of_columns = columns;
    entered_elements = 0;
    matrix_points = rows * columns;
    matrix_data = new double[matrix_points];
    for(int i{}; i < matrix_points; i++) {
        matrix_data[i] = 0;
    }
}
//Extracts each element from an istream
void operator >> (std::istream &input_stream, matrix &current_matrix)
{
    current_matrix.entered_elements ++; //Counts the number of entries the user has inputted
    input_stream >> current_matrix.matrix_data[current_matrix.entered_elements - 1];
}
//Formats matrix output
std::ostream &operator << (std::ostream &output_stream, matrix &current_matrix)
{   
    if(current_matrix.matrix_points == 0) {
        return output_stream;
    }
    for(int i{1}; i <= current_matrix.number_of_rows; i++) {
        std::cout << "( ";
        for(int j{1}; j <= current_matrix.number_of_columns; j++) {
            if(j > 1) {
                std::cout << "    ";
            }
            std::cout << std::setprecision(5) << current_matrix.get_index_value(i,j);
            if(j == current_matrix.number_of_columns) {
                std::cout << " )" << std::endl;
            }
        }
    }
    return output_stream;
}
//Copy constructor
matrix::matrix(const matrix &current_matrix)
{
    number_of_rows = current_matrix.number_of_rows;
    number_of_columns = current_matrix.number_of_columns;
    matrix_points = current_matrix.matrix_points;
    entered_elements = current_matrix.entered_elements;
    matrix_data = new double [matrix_points];
    for(int i{}; i < matrix_points; i++) {
        matrix_data[i] = current_matrix.matrix_data[i];
    }
}
//Assignment operator
matrix &matrix::operator = (matrix &current_matrix)
{
    //Protects against self-assignment
    if(this == &current_matrix) {
        return *this;
    }
    delete [] matrix_data;
    number_of_rows = current_matrix.number_of_rows;
    number_of_columns = current_matrix.number_of_columns;
    entered_elements = current_matrix.entered_elements;
    matrix_points = current_matrix.matrix_points;
    matrix_data = new double[matrix_points];
    for(int i{}; i < matrix_points; i++) {
        matrix_data[i] = current_matrix.matrix_data[i];
    }
    return *this;
}
//Move constructor, with a rvalue argument
matrix::matrix(matrix &&current_matrix)
{
    number_of_rows = current_matrix.number_of_rows;
    number_of_columns = current_matrix.number_of_columns;
    matrix_points = current_matrix.matrix_points;
    entered_elements = current_matrix.entered_elements;
    matrix_data = current_matrix.matrix_data;
    //Changing rvalue arguments data
    current_matrix.number_of_rows = 0;
    current_matrix.number_of_columns = 0;
    current_matrix.matrix_points = 0;
    current_matrix.entered_elements = 0;
    current_matrix.matrix_data = nullptr;
}
//Move operator
matrix &matrix::operator = (matrix &&current_matrix)
{   
    //Swapping values of right and left hand objects
    std::swap(number_of_rows, current_matrix.number_of_rows);
    std::swap(number_of_columns, current_matrix.number_of_columns);
    std::swap(matrix_points, current_matrix.matrix_points);
    std::swap(entered_elements, current_matrix.entered_elements);
    std::swap(matrix_data, current_matrix.matrix_data);
    return *this;
}
matrix matrix::operator + (matrix &current_matrix)
{   
    matrix sum;
    if(number_of_rows == current_matrix.number_of_rows && number_of_columns == current_matrix.number_of_columns) {
        sum.number_of_rows = number_of_rows;
        sum.number_of_columns = number_of_columns;
        sum.matrix_points = matrix_points;
        sum.entered_elements = entered_elements;
        delete [] sum.matrix_data;
        sum.matrix_data = new double[matrix_points];
        for(int i{}; i < entered_elements; i++) {
            sum.matrix_data[i] = matrix_data[i] + current_matrix.matrix_data[i];
        }
    } else {
        std::cout << "Matrices are not of the same dimensions and therefore cannot be summed" << std::endl;
    }
    return sum;
}

matrix matrix::operator - (matrix &current_matrix)
{   
    matrix difference;
    if(number_of_rows == current_matrix.number_of_rows && number_of_columns == current_matrix.number_of_columns) {
        difference.number_of_rows = number_of_rows;
        difference.number_of_columns = number_of_columns;
        difference.entered_elements = entered_elements;
        difference.matrix_points = matrix_points;
        delete [] difference.matrix_data;
        difference.matrix_data = new double[matrix_points];
        for(int i{}; i < entered_elements; i++) {
            difference.matrix_data[i] = matrix_data[i] - current_matrix.matrix_data[i];
        }
    } else {
        std::cout << "Matrices are not of the same dimensions and therefore cannot be subtracted." << std::endl;
    }
    return difference;
}

matrix matrix::operator * (matrix &current_matrix)
{
    int element_counter{};
    if(number_of_columns == current_matrix.number_of_rows) {
        matrix product{number_of_rows, current_matrix.number_of_columns};
        for(int i{1}; i <= product.number_of_rows; i++) {
            for(int j{1}; j <= product.number_of_columns; j++) {
                double element_sum{};
                //Summing all products of old matrices to form new matrix
                for(int z{1}; z <= number_of_columns; z++) {
                    element_sum += get_index_value(i, z) * current_matrix.get_index_value(z, j);
                }
                product.matrix_data[element_counter] = element_sum; //New matrix data assigned
                element_counter ++;
            }
        }
        return product;
   } else {
        std::cout << "The number of columns in the first matrix do not equal the number of rows in the " <<
            std::endl << "second, therefore these matrices could not be multiplied." << std::endl;
        matrix product;
        return product;
   }
}
matrix matrix::remove_row_i_column_j(int row, int column)
{
    matrix current_matrix{number_of_rows -1, number_of_columns -1};
    //Data from row and column specified will not make it through these loops, and will not be added to current_matrix
    for(int i{1}; i <= number_of_rows; i++) {
        if(i != row) {
            for(int j{1}; j <= number_of_columns; j++) {
                if(j != column) {
                    current_matrix.matrix_data[current_matrix.entered_elements] = get_index_value(i, j);
                    current_matrix.entered_elements ++;
                }
            }
        }
    }
    return current_matrix;
}
double matrix::calculate_determinant()
{   
    double determinant{};
    int sign{1};
    if(number_of_rows != number_of_columns) {
        std::cout << "Matrix columns does not equal matrix rows. Cannot calculate determinant. " << std::endl;
    } else if (number_of_rows == 2 && number_of_columns == 2) {
        determinant = get_index_value(1, 1)*get_index_value(2, 2) - get_index_value(2, 1)*get_index_value(1, 2);
    } else {
        for(int i{}; i <= number_of_columns; i++) {
            //Recursion of the calculate_determinant() function
            determinant += sign * remove_row_i_column_j(1, i).calculate_determinant() * get_index_value(1, i);
            sign =- sign; //Appropriate sign change for determinant components
        }
    }
    return determinant;
}

int main()
{   
    std::vector<matrix> matrix_vector;
    int rows, columns;
    //Loop for user entering matrix values
    for(int z{}; z < 2; z++) {
        rows = input_rows(z);
        columns = input_columns();
        matrix_vector.push_back(matrix{rows, columns});
        for(int i{1}; i <= matrix_vector[z].get_rows(); i++) {
            for(int j{1}; j <= matrix_vector[z].get_columns(); j++) {
                while(true) {
                    std::cout << "- Enter data for row " << i << ", column " << j << " of matrix: ";
                    std::cin >> matrix_vector[z]; //Overloaded istream operator
                    if(std::cin.fail()) {
                        std::cout << "Invalid input. Matrix element must be a number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }
            }
        }
        std::cout << '\n';
    }
    int matrix_number{};
    //Iteration to print each inputted matrix
    for (auto current_matrix = matrix_vector.begin(); current_matrix < matrix_vector.end(); current_matrix++) {
        matrix_number++;
        std::cout << "Matrix number " << matrix_number << ": ";
        std::cout << '\n';
        std::cout << *current_matrix;
    }
    //Series of print statements to demonstrate operations
    //Overloaded << operator used to print matrices
    std::cout << '\n';
    std::cout << "Matrix 1 + matrix 2: " << std::endl;
    matrix matrices_1_plus_2 = matrix_vector[0] + matrix_vector[1];
    std::cout << matrices_1_plus_2; 
    std::cout << '\n';
    std::cout << "Matrix 1 - matrix 2: " << std::endl;
    matrix matrices_1_minus_2 = matrix_vector[0] - matrix_vector[1];
    std::cout << matrices_1_minus_2;
    std::cout << '\n';
    std::cout << "Matrix 1 x Matrix 2: " << std::endl;
    matrix matrix_1_times_2 = matrix_vector[0] * matrix_vector[1];
    std::cout << matrix_1_times_2;
    std::cout << '\n';
    if(!(matrix_vector[0].get_entered_elements() == 1 && matrix_vector[1].get_entered_elements() == 1)) {
        std::cout << "* Calculating determinant of matrix 1 and 2 " << std::endl;
        std::cout << '\n';
        std::cout << "Determinant of matrix 1: " << std::setprecision(5) <<
        matrix_vector[0].calculate_determinant() << std::endl;
        std::cout << "Determinant of matrix 2: " << std::setprecision(5) <<
        matrix_vector[1].calculate_determinant() << std::endl;
        std::cout << '\n';
        std::cout << "* Removing row 1, column 1 from matrix 2: " << std::endl;
        std::cout << '\n';
        matrix removed_ij_matrix = matrix_vector[1].remove_row_i_column_j(1, 1); //Demonstration removing rows/columns
        std::cout << removed_ij_matrix;
        std::cout << '\n';
        std::cout << "* Copying matrix 1's data to matrix 3 " << std::endl;
        std::cout << '\n';
        matrix copied_matrix_3{matrix_vector[0]}; //Demonstrating deep copying
        std::cout << "Matrix 3: " << std::endl;
        std::cout << copied_matrix_3;
        std::cout << '\n';
        std::cout << "* Changing matrix 1's data " << std::endl;
        std::cout << '\n';
        matrix_vector[0].change_data();
        std::cout << "Matrix 1: " << std::endl;
        std::cout << matrix_vector[0];
        std::cout << '\n';
        std::cout << "Matrix 3's unchanged data (proof of deep copy): " << std::endl;
        std::cout << copied_matrix_3;
        std::cout << '\n';
        matrix matrix_4{std::move(matrix_vector[0])}; //Demonstrating move by assignment
        std::cout << "* Moving values from matrix 1 to matrix 4: " << std::endl;
        std::cout << '\n';
        std::cout << "Matrix 4: " << std::endl;
        std::cout << matrix_4;
        std::cout << '\n';
        std::cout << "Matrix 1: " << std::endl;
        std::cout << matrix_vector[0].get_entered_elements() << " data points." << std::endl;
        std::cout << '\n';
    } else {
        std::cout << "Values entered are not matrices, other matrix functons will not run." << std::endl;
    }
    
}