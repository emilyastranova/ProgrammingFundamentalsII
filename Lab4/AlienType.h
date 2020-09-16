#ifndef ALIENTYPE_H
#define ALIENTYPE_H

#include <iostream>

class AlienType
{
  protected:
    std::string name;
    int legs;
    int eyes;
  public:
    AlienType(); // Default constructor for inheritance
    AlienType(std::string name, int numLegs, int numEyes);

    void print();
};

#endif