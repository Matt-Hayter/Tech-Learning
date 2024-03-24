/*
A Class for Complex Numbers
Allows user to input complex numbers and validates. Performs various
calculations with these numbers and informs user of results.
Matt Hayter, last updated 19/03/2021
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <math.h>

class complex_number
{   
    //Access member data via non-member friend functions
    friend void operator >> (std::istream &, complex_number &);
    friend std::ostream &operator << (std::ostream &, const complex_number &);
    private:
        double real, imaginary;
    public:
        complex_number() : real{0}, imaginary{0} {}
        complex_number(double real_part, double imaginary_part) :
            real{real_part}, imaginary{imaginary_part} {}
        ~complex_number() {}
        double get_real_part() const
        {
            //Real part converted to string and length found
            //Length sets precision of cout, so when outputting components, full double is displayed
            std::string real_part_string{std::to_string(real)};
            std::cout.precision(real_part_string.length());
            return real;
        }
        double get_imaginary_part() const
        {   
            //Imaginary part converted to string and length found
            //Length sets precision of cout, so when outputting components, full double is displayed
            std::string imaginary_part_string{std::to_string(imaginary)};
            std::cout.precision(imaginary_part_string.length());
            return imaginary;
        }
        double calculate_modulus() const
        {
            double modulus;
            modulus = std::pow((std::pow(real, 2) + std::pow(imaginary, 2)), 0.5);
            return modulus;  
        }  
        complex_number operator + (const complex_number &number) const
        {
            complex_number complex_number_added{real + number.real,
                imaginary + number.imaginary};
            return complex_number_added;
        }
        complex_number operator - (const complex_number &number) const
        {
            complex_number complex_number_difference{real - number.real,
                imaginary - number.imaginary};
            return complex_number_difference;
        }
        //Larger member functions are written outside of class
        complex_number operator * (const complex_number &) const;
        complex_number operator / (const complex_number &) const;
        complex_number &get_complex_conjugate(complex_number &, const complex_number &);
        double calculate_argument() const;
};
double complex_number::calculate_argument() const
{
    double argument;
    //Assigns complex number a quadrant of an Argand diagram.
    //Ensures argument is taken anticlockwise from the +re axis
    if(real > 0 && imaginary > 0) {
        argument = atan(imaginary/real);
    } else if(real > 0 && imaginary < 0) {
        argument = 2*M_PI - atan(abs(imaginary/real));
    } else if(real < 0 && imaginary > 0) {
        argument = M_PI - atan(abs(imaginary/real));
    } else if(real < 0 && imaginary < 0) {
        argument = M_PI + atan(imaginary/real);
    } else if(real == 0 && imaginary > 0) {
        argument = M_PI_2;
    } else if(real == 0 && imaginary < 0) {
        argument = (3/2)*M_PI;
    } else {
        argument = 0;
    }
    return argument;
}
complex_number &complex_number::get_complex_conjugate(complex_number &complex_conjugate,
    const complex_number &current_complex_number)
{   
    //Alters complex_conjugate's member data accordingly and returns it
    real = current_complex_number.real;
    imaginary = -current_complex_number.imaginary;
    std::string imaginary_string{std::to_string(imaginary)};
    std::cout.precision(imaginary_string.length());
    return complex_conjugate;
}
complex_number complex_number::operator * (const complex_number &number) const
{
    complex_number product;
    product.real = real*number.real - imaginary*number.imaginary;
    product.imaginary = real*number.imaginary + imaginary*number.real;
    return product;
}
complex_number complex_number::operator / (const complex_number &number) const
{
    complex_number quotient;
    double denominator = std::pow(number.real, 2) + std::pow(number.imaginary, 2);
    quotient.real = (real*number.real + imaginary*number.imaginary)/denominator;
    quotient.imaginary = (-real*number.imaginary + imaginary*number.real)/denominator;
    return quotient;      
}
void operator >> (std::istream &input_stream, complex_number &current_complex_number)
{   
    char plus_or_minus, i;
    bool minus{false};
    //Extracts components from input stream, validating each part as it does so
    input_stream >> std::skipws >> current_complex_number.real >> plus_or_minus;
    if(plus_or_minus == '-') {
        //Sets minus to true, which can applied once imaginary part is read in
        minus = true;
    } else if(plus_or_minus == '+') {
    } else {
        //Sets the stream state to a failbit so user can re-enter
        input_stream.setstate(std::ios_base::failbit);
    }
    input_stream >> i;
    if(i != 'i') {
        //Sets the stream state to a failbit so user can re-enter
        input_stream.setstate(std::ios_base::failbit);
    }    
    input_stream >> current_complex_number.imaginary;
    if(minus == true) {
        current_complex_number.imaginary = -current_complex_number.imaginary;
    }
}
std::ostream &operator << (std::ostream &output_stream, const complex_number &current_complex_number)
{
    output_stream << current_complex_number.real;
    if(current_complex_number.imaginary >= 0) {
        output_stream << "+i";
    } else {
        output_stream << "-i";
    }
    output_stream << abs(current_complex_number.imaginary);
    return output_stream;
}
int main()
{   
    std::cout << "All complex numbers must be entered in the form a +/- ib. Example: 4.6 - i20" << std::endl;
    //Vector for user inputted complex numbers
    std::vector<complex_number> input_numbers(2);
    size_t complex_number_counter{};
    //Reads in and validates complex numbers with an iterator
    for(auto complex_number = input_numbers.begin(); complex_number < input_numbers.end(); complex_number ++) {
        complex_number_counter ++;
        std::cout << "Enter complex number " << complex_number_counter << ": ";
        while(true) {
            //Overloaded istream operator used here
            std::cin >> *complex_number;
            if(std::cin.fail()) {
                std::cout << "Invalid input, complex numbers must be entered in the form a +/- ib" << std::endl;
                std::cout << "Enter complex number " << complex_number_counter << ": ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    complex_number_counter = 0;
    //DMA for temporary complex conjugate storage
    complex_number *complex_conjugate{new complex_number};
    std::cout << '\n';
    //Overloaded ostream operator first used here
    std::cout << "For Complex numbers " << input_numbers[0] << ", " << input_numbers[1] << ": " << std::endl;
    //Outputs characteristic values for each inputted complex number
    for(auto complex_number = input_numbers.begin(); complex_number < input_numbers.end(); complex_number ++) {
        complex_number_counter ++;
        std::cout << '\n';
        std::cout << "Complex number " << complex_number_counter << ": " << std::endl;
        std::cout << "- Real part: " << complex_number->get_real_part() << '\n' <<
            "- Imaginary part: " << complex_number->get_imaginary_part() << std::endl;
        std::cout << std::setprecision(3) << "- Modulus: " << complex_number->calculate_modulus() <<
            '\n' << "- Argument: " << complex_number->calculate_argument() << '\n' << 
            "- Complex Conjugate: " << complex_conjugate->get_complex_conjugate(*complex_conjugate, *complex_number)
            << std::endl;
    } 
    delete complex_conjugate;
    std::cout.precision(3);
    //Demonstrates the use of overloaded operators to perform calculations with complex numbers
    std::cout << '\n' << "Performing some operations: " << std::endl;
    complex_number sum = input_numbers[0] + input_numbers[1];
    std::cout << "- Summed: " << sum << std::endl;
    complex_number difference = input_numbers[0] - input_numbers[1];
    std::cout << "- Difference (1-2): " << difference << std::endl;
    complex_number product = input_numbers[0]*input_numbers[1];
    std::cout << "- Product: " << product << std::endl;
    complex_number quotient = input_numbers[0]/input_numbers[1];
    std::cout << "- Quotient (1/2): " << quotient << std::endl;
}