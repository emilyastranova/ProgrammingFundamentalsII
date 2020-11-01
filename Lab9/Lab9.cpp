
#include <iomanip>
#include <limits>
#include <iostream>

using namespace std;

int main() {
  int num1, num2;
  char opr;

  cout << "Enter two integers: ";
  
  while(true)
  {
    try
      {
        cin >> num1 >> num2;
        if(cin.fail())
          throw 1;
        else
          break;
      }
    catch(int x)
      {
        cin.clear();
        // The ignore function is the only way I could do this with C++
        // https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "System expected a number." << endl;
        cout << "Enter two integers: ";
      }
  }
  cout << endl;



  cout << "Enter operator: + (addition), - (subtraction),"
       << " * (multiplication), / (division): ";

  while(true)
  {
    try
      {
        cin >> opr;
        if(opr == '+' || opr == '-' || opr == '*' || opr == '/')
          break;
        else
          throw 1;
      }
    catch(int x)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "System expected an operation." << endl;
        cout << "Enter operator: + (addition), - (subtraction),"
             << " * (multiplication), / (division): ";
      }
  }
  cout << endl;

  cout << num1 << " " << opr << " " << num2 << " = ";

  switch (opr) {
    case '+':
      cout << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 - num2 << endl;
      break;
    case '*':
      cout << num1 * num2 << endl;
      break;
    case '/':
      try
      {
      if (num2 != 0)
        cout << num1 / num2 << endl;
      else
        throw 1;
      }
      catch(int n)
      {
        cout << "ERROR \nCannot divide by zero" << endl;
      }
      break;
    default:
      cout << "Illegal operation" << endl;
  }

  return 0;
}
