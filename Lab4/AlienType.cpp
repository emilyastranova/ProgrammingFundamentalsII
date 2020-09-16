#include <iostream>
#include "AlienType.h"

AlienType::AlienType(){}

AlienType::AlienType(std::string nameVar, int numLegs, int numEyes)
{
    legs = numLegs; eyes = numEyes; name = nameVar;
}

void AlienType::print()
{
    std:: cout << "Alien" << "\n-------" << std::endl;
    std::cout << "Species: " << name << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}