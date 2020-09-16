
#include "JuperterianType.h"
#include <iostream>

JuperterianType::JuperterianType(std::string nameVar)
{
    name = nameVar; legs = 5; eyes = 1; // Allows user to pick species, but all martians have 2 legs and 3 eyes
}

void JuperterianType::print()
{
    std:: cout << "Juperterian" << "\n-------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}

