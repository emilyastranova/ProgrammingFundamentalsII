
#include <iostream>

class AlienType
{
  protected:
    std::string speciesName;
    int legs;
    int eyes;
  public:
    AlienType(); // Default constructor for inheritance
    AlienType(std::string speciesVar, int numLegs, int numEyes);

    void print();
};