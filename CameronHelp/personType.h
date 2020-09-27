#include <string>
#include <iostream>
using namespace std;

class personType
{
public:
   personType(){};
   personType(string first, string last)
    {
       firstName = first; lastName = last;
    }
    void print(){cout<<firstName<<" f "<<lastName;}
    void setName(string first, string last) {firstName= first; lastName=last;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}

 private:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};