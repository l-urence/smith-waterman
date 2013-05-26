#include "single.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Single::Single()
{
}

Single::Single(int rowsCount, int columnsCount) // Kostruktor

{
    matrix[rowsCount][columnsCount];
    initMatrix();
}

Single::~Single()// Destruktor
{
   matrix[0][0];
}

void Single::printMatrix()
{
    // loop for rows
    for (int i=0; i<rowsCount; i++)
    {
        //loop for columns
        for (int j=0; j<columnsCount; j++)
        {
            cout << matrix[i][j];
        }
        
        cout << "\n";
    }
}

void Single::initMatrix()
{
    for (int i=0;i<rowsCount;i++)
    {
        for(int j=0;j<columnsCount;j++)
        {
            matrix[rowsCount][columnsCount]=0.;
        }
    }
}

