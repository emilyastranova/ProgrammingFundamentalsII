#include <iostream>
#include <chrono>

using namespace std;

int main()
{

    for (int x = 1; x <= 5; x++)
    {
        cout << "\rTest " << x;
        _sleep(1000);
    }

    return 0;
}

