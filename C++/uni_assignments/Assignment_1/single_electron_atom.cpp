/* single_electron_atom.cpp
calculates the photon energies from electronic transitions
in a single electron atom.
Matt Hayter, last updated 18/02/2021 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <new>
#include <cmath>

int user_input_data_and_validate(std::string ask_user)
{   
    bool finished_validating{0};
    int  input_data;
    while(finished_validating == false){
        finished_validating = true;
        std::cout << ask_user;
        std::cin >> input_data;
        if(input_data < 1 and not std::cin.fail()){
            std::cout << "Value entered must be equal or greater than one. ";
            finished_validating = false;
            }
        if(std::cin.fail() or std::cin.peek() != '\n'){ //cin.peek() finds following character in stream without consuming it.
            std::cout << "Value entered must be an integer. ";
            finished_validating = false;
            }
        if(std::cin.fail() and (input_data > 2147483646 or input_data < - 2147483646)){
            std::cout << "Value entered is too large. ";
            finished_validating = false;
            }
        if(finished_validating == false){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } //Ignores all user input digits.
    }
    return input_data;
}
std::string determine_units(std::string units)
{
    std::string *units_input{new std::string}; //DMA for user inputted string of unknown size.
    std::cout << "Would you like the photon energy in J or eV? ";
    std::cin >> *units_input;
    while (true){ 
        if(*units_input == "J" or *units_input == "Joules" or *units_input == "joules" or *units_input == "j"){
            delete units_input; //End DMA now string size is known.
            units = "J";
            break;
        }else if(*units_input == "eV" or *units_input == "ev" or *units_input == "Electron Volts"
                    or *units_input == "electron volts" or *units_input == "EV"){
            delete units_input; //End DMA now string size is known.
            units = "eV";
            break;
        }else{  
            std::cout << "Incorrect unints chosen, input is case sensitive. Please enter J or eV: ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> *units_input;
        }
    }
    return units;
}
double calculate_transition_energy_and_return_levels(int Z, int n_i, int n_j, std::string units)
{
    double transition_energy;
    double energy_of_initial_level;
    double energy_of_final_level;
    if(units == "eV"){
        transition_energy = 13.6*std::pow(Z, 2)*(1/std::pow(n_j, 2)-1/std::pow(n_i, 2));
        energy_of_initial_level = 13.6*std::pow(Z, 2)*(-1/std::pow(n_i, 2));
        energy_of_final_level = 13.6*std::pow(Z, 2)*(-1/std::pow(n_j, 2));
    }else{
        transition_energy = 1.6*std::pow(10, -19)*13.6*std::pow(Z, 2)*(1/std::pow(n_j, 2)-1/std::pow(n_i, 2));
        energy_of_initial_level = 1.6*std::pow(10, -19)*13.6*std::pow(Z, 2)*(-1/std::pow(n_i, 2));
        energy_of_final_level = 1.6*std::pow(10, -19)*13.6*std::pow(Z, 2)*(-1/std::pow(n_j, 2));
    }
    std::cout << "An electron transitions from an energy level of " << std::setprecision(2) << std::scientific << 
                energy_of_initial_level << " " << units << " to an energy level of " << energy_of_final_level <<
                " " << units << "." << std::endl;
    return transition_energy;
}
bool ask_user_to_repeat_and_validate(bool repeat)
{
    std::string *user_input_repeat{new std::string};//DMA for user inputted string of unknown size.
    bool valid_repeat_entered{};   
    while(valid_repeat_entered == false){
        std::cout << "Would you like to repeat this this process? Enter y/n: ";
        std::cin >> *user_input_repeat;
        if(*user_input_repeat == "n"){
            repeat = false;
            std::cout << "Will not repeat process. ";
            valid_repeat_entered = true;
        }else if(*user_input_repeat == "y"){
            std::cout << "Repeating process. ";
            valid_repeat_entered = true;
        }else{
            std::cout << "Input invalid. ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    delete user_input_repeat;
    return repeat;
}
int main()
{
    std::string ask_user_1{"Enter an atomic number for a single electron atom: "};
    std::string ask_user_2{"Enter the initial principal quantum number: "};
    std::string ask_user_3{"Enter the final principal quantum number: "};
    bool repeat{true};
    while(repeat == true){
        int atomic_number = user_input_data_and_validate(ask_user_1);
        int initial_quantum_number = user_input_data_and_validate(ask_user_2);
        int final_quantum_number = user_input_data_and_validate(ask_user_3);
        std::string units;
        if (initial_quantum_number != final_quantum_number){ //Removes reqest for user to input units if energy is zero.
            units = determine_units(units);
        }else{
            units = "J";
        }
        double transition_energy = calculate_transition_energy_and_return_levels(atomic_number, initial_quantum_number,
                                    final_quantum_number, units);
        std::string output_statement;
        if(transition_energy < 0){
            output_statement = "A photon is absorbed with an energy of ";
            transition_energy = -transition_energy; //Alters physical process depending on user data inputs, ensuring positive energy.
        }else if(transition_energy > 0){
            output_statement = "A photon is emmitted with an energy of "; 
        }else{
            output_statement = "There is no photon emitted, transition energy is ";
            transition_energy = 0; 
        }
        std::cout << output_statement << std::setprecision(2) << std::scientific << transition_energy << " " << units << "." << std::endl;
        repeat = ask_user_to_repeat_and_validate(repeat);
    }
    return 0;
}