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


void SwSingle::calculateAlignments(){

    long seqALength=this->sequenceA.length();
    long seqBLength=this->sequenceB.length();

    for(unsigned int i=0; i<this->sequenceA.length()+1; i++){
        vector<int> row; // current row
        for(unsigned int j=0; j<this->sequenceB.length()+1; j++){
            //score = scoreSwMatrixElement(this->sequenceA[i],this->sequenceB[j]);
            row.push_back(0);
        }
        matrix.push_back(row); // Add the row to the main vector
    }

    int temp[4];
    int I_i[seqALength+1][seqBLength+1],I_j[seqALength+1][seqBLength+1];     // Index matrices to remember the 'path' for backtracking

      // here comes the actual algorithm
    for(int i=1;i<=seqALength;i++){
        for(int j=1;j<=seqBLength;j++){
            temp[0] = matrix[i-1][j-1]+scoreSwMatrixElement(sequenceA[i-1],sequenceB[j-1]);
            temp[1] = matrix[i-1][j]-1;
            temp[2] = matrix[i][j-1]-1;
            temp[3] = 0.;
            matrix[i][j] = findMaxElement(temp,4);

            switch(ind){
              case 0:                                  // score in (i,j) stems from a match/mismatch
                I_i[i][j] = i-1;
                I_j[i][j] = j-1;
                break;
              case 1:                                  // score in (i,j) stems from a deletion in sequence A
                I_i[i][j] = i-1;
                I_j[i][j] = j;
                break;
              case 2:                                  // score in (i,j) stems from a deletion in sequence B
                I_i[i][j] = i;
                I_j[i][j] = j-1;
                break;
              case 3:                                  // (i,j) is the beginning of a subsequence
                I_i[i][j] = i;
                I_j[i][j] = j;
                break;
            }
        }
    }

    // search matrix for the maximal score
    double matrixMax = 0.;
    int iMax=0,jMax=0;
    for(int i=1;i<=seqALength;i++){
      for(int j=1;j<=seqBLength;j++){
        if(this->matrix[i][j]>matrixMax){
          matrixMax = matrix[i][j];
          iMax = i;
          jMax = j;
        }
      }
    }
    //cout<<matrixMax<<endl;

    // Backtracking from matrixMax
    int current_i=iMax,current_j=jMax;
    int next_i=I_i[current_i][current_j];
    int next_j=I_j[current_i][current_j];
    int tick=0;
    char consensus_a[seqALength+seqBLength+2],consensus_b[seqBLength+seqALength+2];

    while(((current_i!=next_i) || (current_j!=next_j)) && (next_j!=0) && (next_i!=0)){
    if(next_i==current_i)  consensus_a[tick] = '-';                  // deletion in A
    else                   consensus_a[tick] = this->sequenceA[current_i-1];   // match/mismatch in A

    if(next_j==current_j)  consensus_b[tick] = '-';                  // deletion in B
    else                   consensus_b[tick] = this->sequenceB[current_j-1];   // match/mismatch in B
    current_i = next_i;
    current_j = next_j;
    next_i = I_i[current_i][current_j];
    next_j = I_j[current_i][current_j];
    tick++;
    }

    // Output of the consensus motif to the console
    cout<<endl<<"***********************************************"<<endl;
    cout<<"The alignment of the sequences"<<endl<<endl;
    for(int i=0;i<seqALength;i++){cout<<this->sequenceA[i];}; cout<<"  and"<<endl;
    for(int i=0;i<seqBLength;i++){cout<<this->sequenceB[i];}; cout<<"  are:"<<endl<<endl;
;
    for(int i=tick-1;i>=0;i--){
        cout<<consensus_a[i];
    }
    cout<<endl;
    for(int i=tick-1;i>=0;i--){
        if(consensus_a[i]==consensus_b[i]){
            cout<<"|";
        }else{
            cout<<" ";
        }
    }
    cout<<endl;
    for(int j=tick-1;j>=0;j--){
        cout<<consensus_b[j];
    }
    cout<<endl;

    printMatrix();
}

int SwSingle::scoreSwMatrixElement(char charA,char charB){
  int score;
  if(charA==charB){
      score=2;
    }
  else{
      score=-1;
    }
  return score;
}

int SwSingle::findMaxElement(int array[],int length){
    int max = array[0];
    ind = 0;

    for(int i = 1; i<length; i++){
      if(array[i] > max){
        max = array[i];
        ind = i;
      }
    }
    return max;
}

void SwSingle::printMatrix(){
    for(unsigned i=0; i<this->sequenceB.length(); i++){
        if(i==0)cout<<"      ";
        cout<<this->sequenceB[i]<<"  ";
    }
    cout<<endl;

    for(unsigned int i=0; i<this->matrix.size(); i++) {
        if(i==0){
            cout<<"   ";
        }else{
            cout<<sequenceA[i-1]<<"  ";
        }
        for(unsigned int j=0; j<this->matrix[i].size(); j++) {
            cout<< this->matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

