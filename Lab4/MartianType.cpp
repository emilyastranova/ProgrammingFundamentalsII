#include "MartianType.h"
#include<iostream>

MartianType::MartianType(std::string speciesVar, int numLegs, int numEyes)
{
    legs = numLegs; eyes = numEyes; speciesName = speciesVar;
}

void MartianType::print()
{
    std:: cout << "Martian" << "\n-------" << std::endl;
    std::cout << "Species: " << speciesName << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}

