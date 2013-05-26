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
    this->sequenceA = sequenceA;
    this->sequenceB = sequenceB;
}

SwSingle::~SwSingle()// Destruktor
{
    this->sequenceA = "";
    this->sequenceB = "";
}

void SwSingle::printMatrix(){
    for(unsigned int i=0; i<this->sequenceB.length(); i++){
        if(i==0)cout<<"  ";
        cout<<this->sequenceB[i]<<" ";
    }
    cout<<endl;

    for(unsigned int i=0; i<this->matrix.size(); i++) {
        cout<<sequenceA[i]<<" ";
        for(unsigned int j=0; j<this->matrix[i].size(); j++) {
            cout<< this->matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// init matrix
void SwSingle::initMatrix(){
    /*for (unsigned int i = 0; i < this->sequenceA.size(); i++) {
        vector<int> row; // Create an empty row
        for (unsigned int j = 0; j < this->sequenceB.size(); j++) {
            row.push_back(0); // Add an element (column) to the row
        }
        matrix.push_back(row); // Add the row to the main vector
    }*/
}


void SwSingle::fillSwScoreMatrix(){
    int score = 1;
    for(unsigned int i=0; i<this->sequenceA.length(); i++){
        vector<int> row; // current row
        for(unsigned int j=0; j<this->sequenceB.length(); j++){
            score = scoreSwMatrixElement(this->sequenceA[i],this->sequenceB[j]);
            row.push_back(score);
        }
        matrix.push_back(row); // Add the row to the main vector
    }
}

int SwSingle::scoreSwMatrixElement(char charA,char charB){
  double score=0;
  if(charA==charB){
      if(score>=2){
          score+=1;
      }else{
          score=2;
      }
  }else{
      if(score>0){
          score-=1;
      }
  }
  return score;
}

double SwSingle::find_array_max(double array[],int length){

  double max = array[0];

  for(int i = 1; i<length; i++){
      if(array[i] > max){
           max = array[i];
      }
  }
  return max;
}

