#include "swsingle.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

SwSingle::SwSingle()
{
}

SwSingle::SwSingle(string sequenceA, string sequenceB) // Kostruktor
{
    initMatrix(sequenceA, sequenceB);
}

SwSingle::~SwSingle()// Destruktor
{

}

void SwSingle::printMatrix(string sequenceA, string sequenceB){
    // loop for rows
    for(int i=0; i<sequenceA.size(); i++) {
        //loop for columns
        for(int j=0; j<sequenceB.size(); j++) {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
}

// init matrix
void SwSingle::initMatrix(string sequenceA, string sequenceB){
      for(int i=0;i<sequenceA.size();i++){
           for(int j=0;j<sequenceB.size();j++){
             matrix.push_back(std::vector<int> (0, 0));
           }
      }

}

void SwSingle::fillSwScoreMatrix(string sequenceA, string sequenceB){
    int match = 1;
    int mismatch = 0;
    int gap = 0;

    /*for(int i=0; i<sequenceA.length(); i++){
        for(int j=0; j<sequenceB.length(); j++){
            if(sequenceA[i]==sequenceB[j]){
                //match += 1;
                //matrix[i][j]=match;
            }
        }
    }*/
}

int SwSingle::scoreSwMatrixElement(char charA,char charB){
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

double SwSingle::find_array_max(double array[],int length){

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

