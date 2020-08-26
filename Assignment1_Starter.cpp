/*
 CS 1347 Summer 2020
 
 @author Your Name Here
 
 I started with Example 8-11 in the Malik textbook
 */
  


#include <iostream>
#include <iomanip>
    
using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const int MAGIC_NUMBER = 9;


void printMatrix(int matrix[][COLUMNS], int ROWS);

boolean isMagic(int matrix[][COLUMNS], int ROWS);

void fillMatrix(int matrix[][COLUMNS], int ROWS);

void initMatrix(int matrix[][COLUMNS], int ROWS); // Fills matrix with value -1

int main()
{

// run loop here
    
    
    return 0;
}

void printMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                 int numOfRows)
{
    int row, col;

    for (row = 0; row < numOfRows; row++)
    {
        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            cout << setw(5) << matrix[row][col] << " ";

        cout << endl;
    }
}

void initMatrix(int matrix[][COLUMNS], int ROWS)
{
    int row, col;
    for (row = 0; row < numOfRows; row++)
    {
        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            matrix[row][col] = -1;
    }
}
void fillMatrix(int matrix[][COLUMNS], int ROWS)
{
    initMatrix(matrix[][COLUMNS], ROWS);
    
    // Loop from 1 to 9
    // do while loop
    
    Row_Position = rand() % 3;  // Row_Position in the range 0 to 2
    Col_Position = rand() % 3;  // Col_Position in the range 0 to 2
   // http://www.cplusplus.com/reference/cstdlib/rand/ July 8, 2020
    
   // if position is -1, replace with loop varible, increment loop varible
   // else generate new random position
}

/*
void sumRows(int matrix[][NUMBER_OF_COLUMNS], int numOfRows)
{
    int row, col;
    int sum;

         //Sum of each individual row
    for (row = 0; row < numOfRows; row++)
    {
        sum = 0;

        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            sum = sum + matrix[row][col];

        cout << "Sum of row " << (row + 1) << " = " << sum
             << endl;
    }
}

void largestInRows(int matrix[][NUMBER_OF_COLUMNS], 
                   int numOfRows)
{
    int row, col;
    int largest;

         //Largest element in each row
    for (row = 0; row < numOfRows; row++)
    {
        largest = matrix[row][0]; //Assume that the first element
                                  //of the row is the largest.
        for (col = 1; col < NUMBER_OF_COLUMNS; col++)
            if (largest < matrix[row][col])
                largest = matrix[row][col];

        cout << "The largest element of row " << (row + 1) 
             << " = " << largest << endl;
    }
 

}
*/
