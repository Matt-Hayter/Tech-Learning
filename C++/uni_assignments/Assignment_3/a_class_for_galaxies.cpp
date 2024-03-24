/*
A Class for Galaxies
Makes use of classes and objects to inform the user of various properties of galaxies. Manipulates
some of this data upon user request and adds satellite galaxies, informing the user whilst doing so.
Prints all properties of these galaxies.
Matt Hayter, last updated 11/03/2021
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>

class galaxy
{
    private:
        std::string hubble_type;
        double redshift, total_mass, stellar_mass_fraction;
        std::vector<galaxy> satellites;
    public:
        galaxy() : hubble_type{"Ghost"}, redshift{0}, total_mass{0}, stellar_mass_fraction{0} {} //Default constructor
        galaxy(std::string hubble_type_in, double redshift_in, double total_mass_in, //Parameterised constructor
                double stellar_mass_fraction_in) : hubble_type{hubble_type_in}, redshift{redshift_in},
                total_mass{total_mass_in}, stellar_mass_fraction{stellar_mass_fraction_in} {}
        ~galaxy() {}
        //Get function to access private data outside of class
        std::string get_type() const {return hubble_type;}
        void change_galaxy_type(std::string new_type) {hubble_type = new_type;}
        double calculate_stellar_mass() {return stellar_mass_fraction * total_mass;}
        //Prototypes so that functions can be defined after class
        void print_properties(size_t &, std::string, double);
        void add_satellite_galaxy(std::string, double, double, double);
        
};
//Prints properties of either a galaxy or satellite galaxy, depending on the object in question
void galaxy::print_properties(size_t &galaxy_choice, std::string galaxy_or_satellite, double stellar_mass)
{
    size_t satellite_number{};
    std::cout << galaxy_or_satellite << " " << galaxy_choice << "'s data: " << std::endl;
    //Only prints the # of satellites if object is a top level galaxy
    if(galaxy_or_satellite == "Galaxy") {
        std::cout << "-Number of satellites: " << satellites.size() << std::endl;
    }
    std::cout << "-Hubble type: " << hubble_type << std::setprecision(3) << ", Redshift: " << redshift
        << ", Total mass: " << total_mass << " kg, Stellar mass fraction: " << stellar_mass_fraction << std::endl;
    std::cout << "-Stellar mass: " << stellar_mass << std::setprecision(3) << " kg" << std::endl;
    //Accesses data for the satellites belonging to the galaxy in question
    if(satellites.size() != 0) {
        for(auto vector_iterator = satellites.begin(); vector_iterator < satellites.end(); vector_iterator ++) {
            satellite_number ++;
            stellar_mass = vector_iterator->calculate_stellar_mass();
            //Runs print function again, with a given satellite now being the primary object
            vector_iterator->print_properties(satellite_number, "Satellite", stellar_mass);
        }
    }
}
void galaxy::add_satellite_galaxy(std::string hubble_type, double redshift, double total_mass,
                double stellar_mass_fraction)
{
    galaxy satellite{hubble_type, redshift, total_mass, stellar_mass_fraction};
    satellites.push_back(satellite);
}
int main()
{   
    const double solar_mass{1.989e30};
    std::vector<galaxy> galaxies; 
    galaxies.push_back(galaxy{}); //Call on default galaxy constructor
    galaxies.push_back(galaxy{"E[0-7]", 4.576, 1.575e9, 0.032}); //Call on parameterised constructors
    galaxies.push_back(galaxy{"SB[a-c]", 2.854, 5.869e11, 0.043});
    galaxies.push_back(galaxy{"Irr", 7.237, 3.435e8, 0.017});
    //Inform the user of the choice of galaxies available
    std::cout << "There are "<< galaxies.size() << " galaxies in total" << '\n' <<
        "Galaxy 1 is the default and 2 - 4 are parameterised" << '\n' <<
        "Which galaxy's data would you like to proceed with? Enter 1 - 4: ";
    size_t user_galaxy_choice;
    //Reduce user galaxy input by one, for simplicity when accessing vector components
    size_t adapted_galaxy_choice;
    double stellar_mass;
    std::cin >> user_galaxy_choice;
    while(true) {
        //Check user input is valid before proceeding
        if(!std::cin.fail() && 1 <= user_galaxy_choice && user_galaxy_choice <= 4 && std::cin.peek() == '\n') {
            adapted_galaxy_choice = user_galaxy_choice - 1;
            std::cout << '\n';
            //Obtain stellar mass that is fed into the print function on the next line
            double stellar_mass = galaxies[adapted_galaxy_choice].calculate_stellar_mass();
            galaxies[adapted_galaxy_choice].print_properties(user_galaxy_choice, "Galaxy", stellar_mass);
            std::cout << '\n';
            //Change galaxy type and notify user
            std::cout << "* Changed galaxy "<< user_galaxy_choice << "'s Hubble type from " <<
                galaxies[adapted_galaxy_choice].get_type();
            galaxies[adapted_galaxy_choice].change_galaxy_type("S0"); //Galaxy type chosen here
            std::cout << " to " << galaxies[adapted_galaxy_choice].get_type() << " *" << std::endl;
            break;
        } else {
            std::cout << "Invalid input. Please enter a galaxy, 1 - 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> user_galaxy_choice;
        }
    }
    std::cout << '\n';
    //Add satellites to given galaxies
    galaxies[1].add_satellite_galaxy("Irr", 4.231, 1.385e8, 0.022);
    galaxies[3].add_satellite_galaxy("S[a-c]", 7.129, 1.989e7, 0.043);
    galaxies[3].add_satellite_galaxy("E[0-7]", 7.354, 1.123e7, 0.037);
    std::cout << "* Added satellites to galaxies *" << std::endl;
    std::cout << '\n';
    std::cout << "* Printing full galaxy list *" << std::endl;
    std::cout << '\n';
    size_t galaxy_number{};
    //Prints all updated data for galaxies
    for(auto vector_iterator = galaxies.begin(); vector_iterator < galaxies.end(); vector_iterator ++) {
        galaxy_number ++;
        //Pointers to galaxy objects being passed through a member functions
        double stellar_mass = vector_iterator->calculate_stellar_mass();
        vector_iterator->print_properties(galaxy_number, "Galaxy", stellar_mass);
        std::cout << '\n';
    }
    std::cout << '\n';
}