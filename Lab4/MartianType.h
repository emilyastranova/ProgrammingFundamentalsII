#ifndef MARTIANTYPE_H
#define MARTIANTYPE_H

#include "AlienType.h"
#include <iostream>

class MartianType : AlienType{

  public:
    MartianType(); // Default constructor
    MartianType(std::string nameVar);
    
    void print(); // Overload from base class
};

#endif