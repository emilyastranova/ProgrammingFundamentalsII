#include "AlienType.h"
#include <iostream>

class MartianType: public AlienType
{
  protected:
    std::string speciesName;
    int legs;
    int eyes;
  public:
    MartianType(); // Default constructor
    MartianType(std::string speciesVar, int numLegs, int numEyes);
    
    void print(); // Overload from base class
};