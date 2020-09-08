#include <iostream>

// Written by Tyler Harrison

using namespace std;
class baseballPlayer
{
    public:
        int stat1;
        int stat2;
        baseballPlayer(int stat1p, int stat2p)
        {
            stat1 = stat1p;
            stat2 = stat2p;
        };
        int getStatistics()
        {
            return stat1;
        }
};

int main()
{
    baseballPlayer player = baseballPlayer(1, 2);
    int stats = player.getStatistics();
    cout << stats;
    return 0;
}
