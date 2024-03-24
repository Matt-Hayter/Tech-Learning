/*
Assignment 6, Shapes.
Calculates and prints the surface area as well as volume for a range of shapes.
Matt Hayter, last updated 23/04/2021
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <cmath>
#include <string>

//Abstract base class
class shape
{   
    public:
        virtual ~shape() {} //Virtual destructor
        virtual double find_area() = 0; //Pure virtual functions
        virtual double find_volume() = 0;
        virtual std::string get_name() const = 0;
};
//Abstract derived class
class two_D_shape: public shape
{
    public:
        virtual ~two_D_shape() {}
        //Additional pure virtual function used for finding the surface area of a prism
        virtual double find_perimeter() = 0;
};
//Abstract derived class
class three_D_shape : public shape
{
    public:
        virtual ~three_D_shape() {}
};
//Derived class
class rectangle : public two_D_shape
{
    protected:
        double length, width;
        std::string name;
    public:
        rectangle() : length{0}, width{0}, name{"nul"} {}
        rectangle(double len, double wid, std::string string) : length{len}, width{wid}, name{string} {}
        ~rectangle() {}
        double find_area() 
        {
            return length*width;
        }
        double find_volume() 
        {
            return 0;
        }
        std::string get_name() const
        {
            return name;
        }
        double find_perimeter()
        {
            return 2*(length + width);
        }
};
//Additional inheritance ('is_a')
class square : public rectangle
{
    //Square inherits protected rectangle members
    public:
        square() : rectangle{0, 0, "nul"} {}
        square(double len, std::string string) : rectangle{len, len, string} {}
        ~square() {}
};
//Derived class
class ellipse : public two_D_shape
{
    protected:
        double semi_minor_axis, semi_major_axis;
        std::string name;
    public:
        ellipse() : semi_major_axis{0}, semi_minor_axis{0}, name{"nul"} {}
        ellipse(double minor, double major, std::string string) : semi_minor_axis{minor},
            semi_major_axis{major}, name{string} {}
        ~ellipse() {}
        double find_area()
        {
            return M_PI*semi_minor_axis*semi_major_axis; 
        }
        double find_volume()
        {
            return 0;
        }
        std::string get_name() const
        {
            return name;
        }
        double find_perimeter()
        {
            //Approximation of the perimeter of an ellipse, if ever called upon
            double h = std::pow(semi_minor_axis - semi_major_axis, 2) / std::pow(semi_minor_axis + 
                semi_major_axis, 2);
            return M_PI*( semi_major_axis + semi_minor_axis)*(1 + h/4 + std::pow(h, 2)
                / 64 + std::pow(h, 3) / 256);
        }
};
//Additional inheritance ('is_a')
class circle : public ellipse
{
    public:
        circle() : ellipse{0, 0, "nul"} {}
        circle(double radius, std::string string) : ellipse{radius, radius, string} {}
        ~circle() {}
};
//Derived class
class cuboid : public three_D_shape
{
    protected:
        double length, width, height;
        std::string name;
    public:
        cuboid() : length{0}, width{0}, height{0}, name{"nul"} {}
        cuboid(double len, double wid, double high, std::string string) : length{len}, width{wid},
            height{high}, name{string} {}
        ~cuboid() {}
        double find_area()
        {
            return 2*length*width + 2*length*height + 2*width*height;
        }
        double find_volume()
        {
            return length*width*height;
        }
        std::string get_name() const
        {
            return name;
        }
};
//Additional inheritance ('is_a')
class cube : public cuboid
{
    public:
        cube() : cuboid{0, 0, 0, "nul"} {}
        cube(double len, std::string string) : cuboid{len, len, len, string} {}
        ~cube() {}   
};
//Derived class
class ellipsoid : public three_D_shape
{
    protected:
        double axis_1, axis_2, axis_3;
        std::string name;
    public:
        ellipsoid() : axis_1{0}, axis_2{0}, axis_3{0}, name{"nul"} {}
        ellipsoid(double ax1, double ax2, double ax3, std::string string) : axis_1{ax1}, axis_2{ax2},
            axis_3{ax3}, name{string} {}
        ~ellipsoid() {}
        double find_area()
        {
            return 4*M_PI*std::pow((std::pow(axis_1*axis_2, 1.6) + std::pow(axis_1*axis_3, 1.6) +
                std::pow(axis_2*axis_3, 1.6))/3, 1/1.6);
        }
        double find_volume()
        {
            return 4*M_PI*axis_1*axis_2*axis_3/3;
        }
        std::string get_name() const
        {
            return name;
        }
};
//Additional inheritance ('is_a')
class sphere : public ellipsoid
{
    public: 
        sphere() : ellipsoid{0, 0, 0, "nul"} {}
        sphere(double ax1, std::string string) : ellipsoid{ax1, ax1, ax1, string} {}
        ~sphere() {}
};
class prism : public three_D_shape
{
    protected:
        double depth;
        two_D_shape* surfaces; //Prism has_a 2D shape
        std::string name;
    public:
        prism() : depth{0} {}
        prism(double dep, two_D_shape* two_D_temp, std::string string) : 
            depth{dep}, surfaces{two_D_temp}, name{string} {}
        ~prism() {}
        double find_area()
        {
            //Calls upon perimeter and area function for a specified 2D shape
            return surfaces->find_perimeter()*depth + 2*surfaces->find_area();
        }
        double find_volume()
        {   
            return surfaces->find_area() * depth;
        }
        std::string get_name() const
        {
            return name;
        }
};
int main()
{
    std::vector<shape*> shape_vector; //Base class pointer
    shape_vector.push_back(new rectangle{3, 5, "rectangle"}); //Paramterised shapes added to vector
    shape_vector.push_back(new square{7, "square"});
    shape_vector.push_back(new ellipse{2, 3, "ellipse"});
    shape_vector.push_back(new circle{4, "circle"});
    shape_vector.push_back(new cuboid{5, 8, 2, "cuboid"});
    shape_vector.push_back(new cube{2, "cube"});
    shape_vector.push_back(new ellipsoid{3, 2, 1, "ellipsoid"});
    shape_vector.push_back(new sphere{4, "sphere"});
    //2D shape type for prism specified here, being a rectangle in this case
    two_D_shape *prism_surfaces = new rectangle{5, 4, "prism surfaces"};
    shape_vector.push_back(new prism{10, prism_surfaces, "rectangular prism"});
    std::cout << "There are " << shape_vector.size() << " shapes in total." << std::endl << '\n';
    std::cout << "* Printing each shapes area and volume " << std::endl << '\n';
    int shape_counter{};
    std::cout.precision(4);
    for(auto vector_iterator = shape_vector.begin(); vector_iterator < shape_vector.end(); vector_iterator ++) {
        shape_counter ++;
        std::cout << "Shape number " << shape_counter << ": " << std::endl;
        //Accessing a shapes member function using a pointer to a vector element that points to a
        //dynamically allocated derived class shape, which points to a base class shape.
        std::cout << "- Name: " << (*vector_iterator)->get_name() << std::endl;
        std::cout << "- Surface area: " << (*vector_iterator)->find_area() << std::endl;
        std::cout << "- Volume: " << (*vector_iterator)->find_volume() << std::endl;
        std::cout << '\n';
        //Delete dynamic memory now finished with it
        delete *vector_iterator;
        }
    delete prism_surfaces;
    shape_vector.clear();
}