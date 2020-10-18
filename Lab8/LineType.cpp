#include <cmath>
#include <iomanip>
#include <iostream>

#include "LineType.h"

using namespace std;

ostream &operator << (ostream &out, const lineType &otherLine)
{
  otherLine.equation();
  return out;
}
istream & operator >> (istream &in, lineType &otherLine)
{
  double a; double b; double c;
  cout << "Input line coefficients: ";
  in >> a >> b >> c;
  otherLine.setLine(a,b,c);
  return in;
}

void lineType::operator=(const lineType &line)
{
  setLine(line.getXCoefficient(), line.getYCoefficient(), line.getCOnstantTerm());
}
void lineType::setLine(double a, double b, double c) {
  xCoeff = a;
  yCoeff = b;

  if (a == 0 && b == 0)
    constTerm = 0;
  else
    constTerm = c;
}

void lineType::equation() const {
  cout << xCoeff << "x ";

  if (yCoeff < 0)
    cout << "- ";
  else
    cout << "+ ";

  cout << fabs(yCoeff) << "y = " << constTerm << endl;
}

double lineType::getXCoefficient() const { return xCoeff; }

double lineType::getYCoefficient() const { return yCoeff; }

double lineType::getCOnstantTerm() const { return constTerm; }

void lineType::setXCoefficient(double coeff) { xCoeff = coeff; }

void lineType::setYCoefficient(double coeff) { yCoeff = coeff; }

void lineType::setConstantTerm(double c) { constTerm = c; }

double lineType::slope() const { return -xCoeff / yCoeff; }

bool lineType::operator+(){return verticalLine();}
bool lineType::verticalLine() const {
  if (yCoeff == 0)
    return true;
  else
    return false;
}

bool lineType::operator-(){return horizontalLine();}
bool lineType::horizontalLine() const {
  if (xCoeff == 0)
    return true;
  else
    return false;
}

bool lineType::operator==(const lineType &otherLine){return equalLines(otherLine);}
bool lineType::equalLines(lineType otherLine) const {
  // Note that lines such as 2x + 3y = 1 and 4x + 6y = 2
  // are also equal.

  double factor = 1;

  if (xCoeff != 0)
    factor = otherLine.xCoeff / xCoeff;
  else
    factor = otherLine.yCoeff / yCoeff;

  if (xCoeff * factor == otherLine.xCoeff &&
      yCoeff * factor == otherLine.yCoeff &&
      constTerm * factor == otherLine.constTerm)
    return true;
  else
    return false;
}

bool lineType::operator||(lineType otherLine){return parallel(otherLine);}
bool lineType::parallel(lineType otherLine) const {
  if (yCoeff == 0 && otherLine.yCoeff == 0)
    return true;
  else if ((yCoeff != 0 && otherLine.yCoeff == 0) ||
           (yCoeff == 0 && otherLine.yCoeff != 0))
    return false;
  else if ((xCoeff / yCoeff) == (otherLine.xCoeff / otherLine.yCoeff))
    return true;
  else
    return false;
}

bool lineType::operator&&(lineType otherLine){return perpendicular(otherLine);}
bool lineType::perpendicular(lineType otherLine) const {
  if (yCoeff != 0 && otherLine.yCoeff != 0) {
    if ((xCoeff / yCoeff) * (otherLine.xCoeff / otherLine.yCoeff) == -1.0)
      return true;
    else
      return false;
  } else if ((xCoeff == 0 && otherLine.yCoeff == 0) ||
             (yCoeff == 0 && otherLine.xCoeff == 0))
    return true;
  else
    return false;
}

void lineType::pointOfIntersection(lineType otherLine) {
  if (equalLines(otherLine))
    cout << "Both lines are equal. They have infinite "
         << "points of intersections." << endl;
  else if (parallel(otherLine))
    cout << "Lines do not intersect. No point intersection." << endl;
  else
    cout << "The point of intersection is: ("
         << (constTerm * otherLine.yCoeff - yCoeff * otherLine.constTerm) /
                (xCoeff * otherLine.yCoeff - yCoeff * otherLine.xCoeff)
         << ", "
         << (constTerm * otherLine.xCoeff - xCoeff * otherLine.constTerm) /
                (yCoeff * otherLine.xCoeff - xCoeff * otherLine.yCoeff)
         << ")" << endl;
}

lineType::lineType(double a, double b, double c) { setLine(a, b, c); }
