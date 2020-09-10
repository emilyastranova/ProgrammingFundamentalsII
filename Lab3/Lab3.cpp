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

    int textWidth = 47;

public:
    baseballPlayer(){};
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
        cout << endl;
    }
    void printStatsNumbered()
    {
        int x = 1;
        cout << "(" << x << ")  "; x++; printStat("Player Name: ", name);
        cout << "(" << x << ")  "; x++; printStat("1B - Single: ", singles);
        cout << "(" << x << ")  "; x++; printStat("2B - Double: ", doubles);
        cout << "(" << x << ")  "; x++; printStat("3B - Triple: ", triples);
        cout << "(" << x << ")  "; x++; printStat("AB - At bat: ", plateAppearances);
        cout << "(" << x << ")  "; x++; printStat("AB/HR - At bats per home run: ", appearancesPerHR);
        cout << "(" << x << ")  "; x++; printStat("BA - Batting average: ", battingAverage);
        cout << "(" << x << ")  "; x++; printStat("BB - Base on balls: ", baseOnBalls);
        cout << "(" << x << ")  "; x++; printStat("BABIP - Batting average on balls in play: ", battingAverageInPlay);
        cout << "(" << x << ") "; x++; printStat("BB/K - Walk-to-strikout ratio: ", walkToStrikeoutRatio);
        cout << "(" << x << ") "; x++; printStat("BsR - Base runs: ", baseRuns);
        cout << endl;
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
    }
    void printStat(string s, double i) // For longs
    {
        cout << setw(textWidth) << left << s << i << endl;
    }
    string getName(){return name;}

    void setName(string s){name = s;}
    void setSingles(int i){singles = i;}
    void setDoubles(int i){doubles = i;}
    void setTriples(int i){triples = i;}
    void setPlateAppearances(int i){plateAppearances = i;}
    void setAppearancesPerHR(int i){appearancesPerHR = i;}
    void setBattingAverage(double i){battingAverage = i;}
    void setBaseOnBalls(int i){baseOnBalls = i;}
    void setBattingAverageInPlay(double i){battingAverageInPlay = i;}
    void setWalkToStrikeoutRatio(double i){walkToStrikeoutRatio = i;}
    void setBaseRuns(int i){baseRuns = i;}
};

class baseballTeam
{
    baseballPlayer team[3];
    int teamSize = 3; // Used 
    public:
    bool isFilled = false; // Detects whether team is empty or not for menu selection
        baseballTeam(){}; // Default constructor
        baseballTeam(baseballPlayer * players) // Preload team with an array of players
        {
            for(int x = 0; x < teamSize; x++)
                team[x] = players[x];
            isFilled = true;
        };
        ~baseballTeam(){}; // Destructor
        void getUserInput() // Load in input from console
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
            for(int x = 0; x < teamSize; x++)
            {
                // Read in from user input
                cout << "Player #" << x+1 << endl << endl;
                cout << "Player Name: "; getline(cin, name);
                cout << "1B - Single: "; cin >> singles;
                cout << "2B - Double: "; cin >> doubles;
                cout << "3B - Triple: "; cin >> triples;
                cout << "AB - At bat: "; cin >> plateAppearances;
                cout << "AB/HR - At bats per home run: "; cin >> appearancesPerHR;
                cout << "BA - Batting average: "; cin >> battingAverage;
                cout << "BB - Base on balls: "; cin >> baseOnBalls;
                cout << "BABIP - Batting average on balls in play: "; cin >> battingAverageInPlay;
                cout << "BB/K - Walk-to-strikout ratio: "; cin >> walkToStrikeoutRatio;
                cout << "BsR - Base runs: "; cin >> baseRuns;
                cout << endl;
                cin.ignore();
                // Create new baseballPlayer
                baseballPlayer temp = baseballPlayer(name, singles, doubles, triples, plateAppearances, appearancesPerHR, battingAverage,baseOnBalls,
                                                    battingAverageInPlay,walkToStrikeoutRatio,baseRuns);
                // Add player to team array
                team[x] = temp;
            }
            isFilled = true;
        }

        void loadFromFile()
        {
            cout << "\nUnder construction\n" << endl;
        }

        void editPlayer()
        {
            int selection = 0;
            int stat = 0;
            cout << "\nWhich player would you like to edit?: \n" << endl;
            for(int x = 0; x < teamSize; x++)
            {
                cout << "(" << x+1 << ") " << team[x].getName() << endl;
            }
            cout << "\nInput selection: ";
            cin >> selection;

            baseballPlayer temp = team[selection-1];

            cout << "\nWhich of the following stats would you like to change?\n" << endl;
            temp.printStatsNumbered();
            cout << "Input selection: ";
            cin >> stat;
            cout << endl;

            string newStringVal;
            int newIntVal;
            double newDoubleVal;
            switch (stat)
            {
            case 1:
                cout << "Name: ";
                cin.ignore();
                getline(cin,newStringVal);
                temp.setName(newStringVal);
                break;

            case 2:
                cout << "1B - Single: ";
                cin >> newIntVal;
                temp.setSingles(newIntVal);
                break;
            case 3:
                cout << "2B - Double: ";
                cin >> newIntVal;
                temp.setDoubles(newIntVal);
                break;
            case 4:
                cout << "3B - Triple: ";
                cin >> newIntVal;
                temp.setTriples(newIntVal);
                break;
            case 5:
                cout << "AB - At bat: ";
                cin >> newIntVal;
                temp.setPlateAppearances(newIntVal);
                break;
            case 6:
                cout << "AB/HR - At bats per home run: ";
                cin >> newIntVal;
                temp.setAppearancesPerHR(newIntVal);
                break;
            case 7:
                cout << "BA - Batting average: ";
                cin >> newDoubleVal;
                temp.setBattingAverage(newDoubleVal);
                break;
            case 8:
                cout << "BB - Base on balls: ";
                cin >> newIntVal;
                temp.setBaseOnBalls(newIntVal);
                break;
            case 9:
                cout << "BABIP - Batting average on balls in play: ";
                cin >> newDoubleVal;
                temp.setBattingAverageInPlay(newDoubleVal);
                break;
            case 10:
                cout << "BB/K - Walk-to-strikout ratio: ";
                cin >> newDoubleVal;
                temp.setWalkToStrikeoutRatio(newDoubleVal);
                break;
            case 11:
                cout << "BsR - Base runs: ";
                cin >> newIntVal;
                temp.setBaseRuns(newIntVal);
                break;
            
            default:
                break;
            }
            cout << endl;
            temp.printStats();
            team[selection-1] = temp;
            cout << endl;
        }
        void printTeamStats()
        {
            for(int i = 0; i < teamSize; i++)
                team[i].printStats();
        }
};


void displayMenu(baseballTeam team)
{
    int selection;
    cout << "Menu:" << endl;
    cout << "--------------------------" << endl;
    cout << "(1) Input player names\n(2) Show player stats\n(3) Edit player stats\n(4) Load players from file\n(5) Exit program" << endl << endl;
    cout << "Input selection: ";
    cin >> selection;
    cin.ignore();

    if(selection > 1 && selection < 4 && !team.isFilled) // Check to make sure teams filled in before displaying and editing
    {
        cout << "\nInput the teams first\n" << endl;
        displayMenu(team);
    }

    switch (selection)
    {
    case 1:
        team.getUserInput();
        displayMenu(team);
        break;
    
    case 2:
        team.printTeamStats();
        displayMenu(team);
        break;

    case 3:
        team.editPlayer();
        displayMenu(team);
        break;

    case 4:
        team.loadFromFile();
        displayMenu(team);
        break;

    case 5:
        exit(0);
        break;
    
    default:
        cout << "Enter a valid menu selection" << endl;
        displayMenu(team);
        break;
    }
}

int main()
{
    //baseballPlayer(string namePar, int singlesPar, int doublesPar, int triplesPar, int plateAppPar,
    //int appearPerHRPar, long batAvgPar, int bOBPar, long batAvgInPlayPar, long walkToSOPar, int baseRunsPar)

     baseballPlayer players[3] = {baseballPlayer("Craig Biggio", 43, 6, 1, 123, 26, 0.211, 7, 0.350, 0.241, 14), 
                                  baseballPlayer("Feg Liggio", 42, 3, 1, 123, 26, 0.211, 7, 0.350, 0.241, 14),
                                  baseballPlayer("Tyler Harrison", 4, 6, 1, 123, 26, 0.211, 7, 0.350, 0.241, 14)};


    baseballTeam team = baseballTeam(players);
    displayMenu(team);
    return 0;
}
