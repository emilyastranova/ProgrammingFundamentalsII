#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;
int main () {

    string tempVar;
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

    ifstream myfile;
    myfile.open ("playerData.txt");
    string text;
    getline(myfile, name, ',');

    getline(myfile, tempVar, ',');
    singles = stoi(tempVar);
    getline(myfile, tempVar, ',');
    doubles = stoi(tempVar);
    getline(myfile, tempVar, ',');
    triples = stoi(tempVar);
    getline(myfile, tempVar, ',');
    plateAppearances = stoi(tempVar);
    getline(myfile, tempVar, ',');
    appearancesPerHR = stoi(tempVar);
    getline(myfile, tempVar, ',');
    battingAverage = stod(tempVar);
    getline(myfile, tempVar, ',');
    baseOnBalls = stoi(tempVar);
    getline(myfile, tempVar, ',');
    battingAverageInPlay = stod(tempVar);
    getline(myfile, tempVar, ',');
    walkToStrikeoutRatio = stod(tempVar);
    getline(myfile, tempVar);
    baseRuns = stoi(tempVar);

    cout << text;
    myfile.close();
    return 0;
}