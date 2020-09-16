#ifndef JuperterianType_H
#define JuperterianType_H

#include "AlienType.h"
#include <iostream>

class JuperterianType : AlienType{
  protected:
    std::string name;
    int legs;
    int eyes;
  public:
    JuperterianType(); // Default constructor
    JuperterianType(std::string nameVar);
    
    void print(); // Overload from base class
};

#endif