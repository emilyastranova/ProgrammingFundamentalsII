#include <iostream>
#include "AlienType.h"

AlienType::AlienType(std::string speciesVar, int numLegs, int numEyes)
{
    legs = numLegs; eyes = numEyes; speciesName = speciesVar;
}

void AlienType::print()
{
    std:: cout << "Alien" << "\n-------" << std::endl;
    std::cout << "Species: " << speciesName << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}