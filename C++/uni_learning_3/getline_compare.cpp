#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "Please, enter your full name: ";
    std::cin >> name; //Takes input until a space is found
    std::cout << "Hello, " << name << "!\n";

    return 0;
}