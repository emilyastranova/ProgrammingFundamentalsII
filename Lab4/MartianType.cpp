
#include "MartianType.h"
#include <iostream>

MartianType::MartianType(std::string nameVar)
{
    name = nameVar; legs = 2; eyes = 3; // Allows user to pick species, but all martians have 2 legs and 3 eyes
}

void MartianType::print()
{
    std:: cout << "Martian" << "\n-------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}

