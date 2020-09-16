#include <stdio.h>
#include <iostream>

class Test
{
    public:
        int x;

        int getX() {
            return this->x;
        }
        void setX(int x) {
            this->x = x;
        }


};

int main()
{
    Test t;
    t.setX(10);
    std::cout << t.getX();
    return 0;
}
