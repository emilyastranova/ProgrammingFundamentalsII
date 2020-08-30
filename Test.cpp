#include <iostream>
#include <algorithm>

using namespace std;

struct testStruct
{
    void changeX1(int &num)
    {
        num = 11;
    }
};

int main()
{
    testStruct tStruct;
    int x1 = 10;
    tStruct.changeX1(x1);
    cout << x1;
    return 0;
}

