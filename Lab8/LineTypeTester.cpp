
// Main program

#include <iostream>

#include "LineType.h"

using namespace std;

int main() {
  lineType line1;
  cin >> line1;

  // I didn't do cin for all of them because
  // I wanted to make it easier to grade
  // This was faster for you to run and test
  lineType line2(3, 5, 7);
  lineType line3(2, 3, -2);
  lineType line4(3, -2, 1);
  lineType line5(2, 0, 3);   // vertical line
  lineType line6(0, -1, 2);  // horizontal line
  lineType line7(4, 6, 8);

  cout << "line1: ";
  cout << line1;
  cout << endl;

  if (!+line1)
    cout << "The slope of line1: " << line1.slope() << endl;
  else
    cout << "line1 is a vertial line. Its slope is undefined." << endl;

  cout << "line2: ";
  cout << line2;
  cout << endl;

  cout << "line3: ";
  cout << line3;
  cout << endl;

  cout << "line4: ";
  cout << line4;
  cout << endl;

  cout << "line5: ";
  cout << line5;
  cout << endl;

  cout << "line6: ";
  cout << line6;
  cout << endl;

  cout << "line7: ";
  cout << line7;
  cout << endl;

  if (line1 || line2)
    cout << "line1 and line2 are parallel." << endl;
  else
    cout << "line1 and line2 are not parallel." << endl;

  line1.pointOfIntersection(line2);

  if (line1 || line3)
    cout << "line1 and line3 are parallel." << endl;
  else
    cout << "line1 and line3 are not parallel." << endl;

  if (line1 && line4)
    cout << "line1 and line4 are perpendicular." << endl;
  else
    cout << "line1 and line4 are not perpendicular." << endl;

  if (+line5)
    cout << "line5 is a vertical line." << endl;
  else
    cout << "line5 is not a vertical line." << endl;

  if (-line6)
    cout << "line6 is a horizontal line." << endl;
  else
    cout << "line6 is not a horizontal line." << endl;

  line5.pointOfIntersection(line6);

  if (line1 == line7)
    cout << "line1 and line 7 are equal." << endl;
  else
    cout << "line1 and line 7 are not equal." << endl;

  line1.pointOfIntersection(line7);

  return 0;
}