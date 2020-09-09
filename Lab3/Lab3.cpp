#include <iostream>
#include <iomanip>

// Written by Tyler Harrison
/*
    1B – Single: hits on which the batter reaches first base safely without the contribution of a fielding error
    2B – Double: hits on which the batter reaches second base safely without the contribution of a fielding error
    3B – Triple: hits on which the batter reaches third base safely without the contribution of a fielding error
    AB – At bat: plate appearances, not including bases on balls, being hit by pitch, sacrifices, interference, or obstruction
    AB/HR – At bats per home run: at bats divided by home runs
    BA – Batting average (also abbreviated AVG): hits divided by at bats (H/AB)
    BB – Base on balls (also called a "walk"): hitter not swinging at four pitches called out of the strike zone and awarded first base.
    BABIP – Batting average on balls in play: frequency at which a batter reaches a base after putting the ball in the field of play. Also a pitching category.
    BB/K – Walk-to-strikeout ratio: number of bases on balls divided by number of strikeouts
    BsR – Base runs: Another run estimator, like runs created
*/

using namespace std;
class baseballPlayer
{
    string name;
    int singles;
    int doubles;
    int triples;
    int plateAppearances;
    int appearancesPerHR;
    double battingAverage;
    int baseOnBalls;
    double battingAverageInPlay;
    double walkToStrikeoutRatio;
    int baseRuns;

    int textWidth = 45;

public:
    baseballPlayer(string namePar, int singlesPar, int doublesPar, int triplesPar, int plateAppPar, int appearPerHRPar,
                   double batAvgPar, int bOBPar, double batAvgInPlayPar, double walkToSOPar, int baseRunsPar)
    {
        name = namePar;
        singles = singlesPar;
        doubles = doublesPar;
        triples = triplesPar;
        plateAppearances = plateAppPar;
        appearancesPerHR = appearPerHRPar;
        battingAverage = batAvgPar;
        baseOnBalls = bOBPar;
        battingAverageInPlay = batAvgInPlayPar;
        walkToStrikeoutRatio = walkToSOPar;
        baseRuns = baseRunsPar;
    };
    ~baseballPlayer(){
        //cout << "Baseball player destructed";
        // I don't have any pointers to clean up
    };
    void printStats()
    {
        printStat("Player Name: ", name);
        printStat("1B - Single: ", singles);
        printStat("2B - Double: ", doubles);
        printStat("3B - Triple: ", triples);
        printStat("AB - At bat: ", plateAppearances);
        printStat("AB/HR - At bats per home run: ", appearancesPerHR);
        printStat("BA - Batting average: ", battingAverage);
        printStat("BB - Base on balls: ", baseOnBalls);
        printStat("BABIP - Batting average on balls in play: ", battingAverageInPlay);
        printStat("BB/K - Walk-to-strikout ratio: ", walkToStrikeoutRatio);
        printStat("BsR - Base runs: ", baseRuns);
    }
    void printStat(string s, string i) // For the name
    {
        cout << s << i << endl;
        cout << "--------------------------" << endl
             << endl;
    }
    void printStat(string s, int i) // For integers
    {
        cout << setw(textWidth) << left << s << i << endl;
        cout << "---------------------------------------------------" << endl;
    }
    void printStat(string s, double i) // For longs
    {
        cout << setw(textWidth) << left << s << i << endl;
        cout << "---------------------------------------------------" << endl;
    }
};

int main()
{
    //baseballPlayer(string namePar, int singlesPar, int doublesPar, int triplesPar, int plateAppPar,
    //int appearPerHRPar, long batAvgPar, int bOBPar, long batAvgInPlayPar, long walkToSOPar, int baseRunsPar)

    baseballPlayer player = baseballPlayer("Craig Biggio", 43, 6, 1, 123, 26, 0.211, 7, 0.350, 0.241, 14);
    player.printStats();
    return 0;
}
