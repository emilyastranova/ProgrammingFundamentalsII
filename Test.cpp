#include <iostream>

using namespace std;

struct intStruct
{
    int int1 = 10;
    int int2 = 20;
};

int main()
{
    intStruct testStruck;
    cout << testStruck.int2;
    return 0;
}
