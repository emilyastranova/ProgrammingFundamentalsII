#ifndef JuperterianType_H
#define JuperterianType_H

#include "AlienType.h"
#include <iostream>

class JuperterianType : AlienType{
  public:
    JuperterianType(); // Default constructor
    JuperterianType(std::string nameVar);
    
    void print(); // Overload from base class
};

#endif