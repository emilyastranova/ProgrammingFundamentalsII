#include <iomanip>
#include <iostream>

using namespace std;

class invalidDay{
  public:
    string message;
    invalidDay()
    {
      message = "Invalid day";
    }

    string what(){
      return message;
    }
};

class invalidMonth{
  public:
    string message;
    invalidMonth()
    {
      message = "Invalid month";
    }

    string what(){
      return message;
    }
};

class invalidYear{
  public:
    string message;
    invalidYear()
    {
      message = "Invalid year";
    }

    string what(){
      return message;
    }
};

// I used this in Fundamentals I lab
int leap (int year)
{
    //if (year % 400 == 0 || year & 100 != 0 && year % 4 == 0)
    if (year % 4 == 0) // If year is a multiple of 4
    {
        if (year % 100 == 0) // If divisible by 100, then must be also divisible by 400
        { 
            if(year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else // Otherwise, just a regular leap year
            return 1;   
    }
    else
        return 0;  
}

int main() {
 
  cout << "Input a date in this format: mm-dd-yyyy" << endl;
  cout << "Input: ";

  string mm,dd,yy;
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  try
  {
    getline(std::cin, mm,'-');
    getline(std::cin, dd, '-');
    cin >> yy;

    if(leap(stoi(yy)))
      daysInMonth[1] = 29;
    
    if(stoi(mm) > 12 || stoi(mm) < 1)
      throw invalidMonth();
    if(stoi(dd) < 1 || stoi(dd) > daysInMonth[stoi(mm)-1])
      throw invalidDay();

    if(stoi(yy) > 9999 || stoi(yy) < 1)
      throw invalidYear();

    if(mm == "01")
      mm = "January";
    if(mm == "02")
      mm = "February";
    if(mm == "03")
      mm = "March";
    if(mm == "04")
      mm = "April";
    if(mm == "05")
      mm = "May";
    if(mm == "06")
      mm = "June";
    if(mm == "07")
      mm = "July";
    if(mm == "08")
      mm = "August";
    if(mm == "09")
      mm = "September";
    if(mm == "10")
      mm = "October";
    if(mm == "11")
      mm = "November";
    if(mm == "12")
      mm = "December";
    cout << mm << " " << dd << ", " << yy << endl;
  }
  catch (invalidMonth m){cout << m.what();}
  catch(invalidDay d){cout << d.what();}
  catch(invalidYear y){cout << y.what();}
}


