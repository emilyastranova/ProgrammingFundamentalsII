/*
 CS 1347 Fall 2020
 
 @author Tyler Harrison
 
 I started with Example 8-11 in the Malik textbook
 */
  

#include <iostream>
#include <iomanip>
    
using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const int MAGIC_NUMBER = 9;
bool isMagic;
int magicNumber = 15;
int magicSquares = 0;
int magicSquare[ROWS][COLUMNS];

void printMatrix(int matrix[][COLUMNS]);
void fillMatrix(int matrix[][COLUMNS]);
void sumRows(int matrix[][COLUMNS]);
void sumColumns(int matrix[][COLUMNS]);
void sumDiag(int matrix[][COLUMNS]);
void checkIfMagic(int matrix[][COLUMNS]);
void initMatrix(int matrix[][COLUMNS]); // Fills matrix with value -1

int main()
{
    int amountOfTimes;
    cout << "How many times would you like to check for a magic square: ";
    cin >> amountOfTimes;
    cout << endl;

    srand(time(0)); // Used to generate a random number every compilation. Source: https://stackoverflow.com/questions/9421463/rand-generating-same-number-upon-compilation
    for(int x = 0; x < amountOfTimes; x++)
    {
        initMatrix(magicSquare);
        fillMatrix(magicSquare);
        //printMatrix(magicSquare);
        checkIfMagic(magicSquare);
    }
    cout << "Program ran " << amountOfTimes << " times" << endl;
    cout << "Magic squares found: " << magicSquares;
    return 0;
}

void printMatrix(int matrix[][COLUMNS])
{
    int row, col;
    //cout << endl;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLUMNS; col++)
            cout << setw(5) << matrix[row][col] << " ";

        cout << endl;
    }
    cout << endl;
}

void initMatrix(int matrix[][COLUMNS])
{
    int row, col;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLUMNS; col++)
            matrix[row][col] = -1;
    }
}
void fillMatrix(int matrix[][COLUMNS])
{

    int Row_Position = rand() % ROWS;  // Row_Position in the range 0 to 2
    int Col_Position = rand() % ROWS;  // Col_Position in the range 0 to 2

    // Loop from 1 to 9
    for (int x = 1; x < 10; x++)
    {
        // do while loop
        // if position is -1, replace with loop varible, increment loop varible
        // else generate new random position
        while (matrix[Row_Position][Col_Position] != -1)
        {
            Row_Position = rand() % 3;  // Row_Position in the range 0 to 2
            Col_Position = rand() % 3;  // Col_Position in the range 0 to 2
        }
        matrix[Row_Position][Col_Position] = x;
    }
   // http://www.cplusplus.com/reference/cstdlib/rand/ July 8, 2020
}


void sumRows(int matrix[][COLUMNS])
{
    int row, col;
    int sum;

    //Sum of each individual row
    for (row = 0; row < ROWS; row++)
    {
        sum = 0;

        for (col = 0; col < COLUMNS; col++)
            sum = sum + matrix[row][col];

        //cout << "Sum of row " << (row + 1) << " = " << sum
        //     << endl;
        if(sum != 15)
            isMagic = false;
    }
    //cout << endl;
}
void sumColumns(int matrix[][COLUMNS])
{
    int row, col;
    int sum;

    //Sum of each individual row
    for (row = 0; row < ROWS; row++)
    for (col = 0; col < COLUMNS; col++)
    {
        sum = 0;

        for (row = 0; row < ROWS; row++)
            sum = sum + matrix[row][col];

        //cout << "Sum of column " << (col + 1) << " = " << sum
        //     << endl;
        if(sum != 15)
            isMagic = false;
    }
    //cout << endl;
}
void sumDiag(int matrix[][COLUMNS])
{
    int sum = 0;
    // Sum of diagonal 1
    sum += matrix[0][0] + matrix[1][1] + matrix[2][2];
    //cout << "Sum of diag 1: " << sum << endl;
    if(sum != 15)
        isMagic = false;
    // Sum of Diagonal 2
    sum = 0;
    sum += matrix[0][2] + matrix[1][1] + matrix[2][0];
    //cout << "Sum of diag 2: " << sum;
    if(sum != 15)
        isMagic = false;
}
void checkIfMagic(int matrix[][COLUMNS])
{
    isMagic = true;
    sumRows(matrix);
    sumColumns(matrix);
    sumDiag(matrix);
    if(isMagic)
    {
        magicSquares++;
        printMatrix(matrix);
    }
}
