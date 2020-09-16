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
    if(name == "Twins")
        std::cout << "       .-\"\"\"\"-.        .-\"\"\"\"-.\n      /        \\      /        \\\n     /_        _\\    /_        _\\\n    // \\      / \\\\  // \\      / \\\\\n    |\\__\\    /__/|  |\\__\\    /__/|\n     \\    ||    /    \\    ||    /\n      \\        /      \\        /\n       \\  __  /        \\  __  / \n        '.__.'          '.__.'\n         |  |            |  |\n         |  |            |  |\n";
    std::cout << "Name: " << name << std::endl;
    std:: cout << "Number of Eyes: " << eyes << std::endl;
    std:: cout << "Number of Legs: " << legs << std::endl;
    std:: cout << std::endl;
}