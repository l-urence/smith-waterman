#include "single.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Single::Single()
{
}

Single::Single(vector<string> sequenceVectorA, vector<string> sequenceVectorB) // Kostruktor

{
    matrix[rowsCount][columnsCount];
    initMatrix();
}

Single::~Single()// Destruktor
{
   matrix[0][0];
}

void Single::printMatrix(){
    // loop for rows
    for(int i=0; i<rowsCount; i++) {
        //loop for columns
        for(int j=0; j<columnsCount; j++) {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
}

void Single::initMatrix(){
      for(int i=0;i<rowsCount;i++){
        for(int j=0;j<columnsCount;j++){
          matrix[rowsCount][columnsCount]=0.;
        }
      }
}

void Single::fillMatrix(string sequenceA, string sequenceB){

    for(int i=0;i<rowsCount;i++){
        for(int j=0;j<columnsCount;j++){
          matrix[rowsCount][columnsCount]=0.;
        }
      }
}

int Single::rateMatrixElement(char charA,char charB){

  double result;
  if(charA==charB){
      result=1;
    }
  else{
      if(result>0){
        result=-1;
      }
    }
  return result;
}

double Single::find_array_max(double array[],int length){

  double max = array[0];
  int ind = 0;

  for(int i = 1; i<length; i++){
      if(array[i] > max){
    max = array[i];
    ind = i;
      }
  }
  return max;
}

