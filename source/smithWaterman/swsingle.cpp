#include "swsingle.h"

using namespace std;

SwSingle::SwSingle() {}

void SwSingle::calculateAlignments() {
    this->matrix.clear(); // TODO: check if matrix get clean recursively.
    long seqALength = this->sequenceA.length();
    long seqBLength = this->sequenceB.length();

    for (unsigned int i=0; i<this->sequenceA.length()+1; i++) {
        vector<int> row; // current row
        
        for(unsigned int j=0; j<this->sequenceB.length()+1; j++) {
            row.push_back(0);
        }
        
        matrix.push_back(row); // Add the row to the main vector
    }

    int tempArray[4];
    
    // Index matrices to remember the 'path' for backtracking
    int I_i[seqALength+1][seqBLength+1], I_j[seqALength+1][seqBLength+1];

    // here comes the actual algorithm
    for (int i=1; i <= seqALength; i++) {
        for (int j=1; j <= seqBLength; j++) {
            tempArray[0] = matrix[i-1][j-1] + scoreSwMatrixElement(sequenceA[i-1],sequenceB[j-1]);
            tempArray[1] = matrix[i-1][j] + this->GAP_PANELTY;
            tempArray[2] = matrix[i][j-1] + this->GAP_PANELTY;
            tempArray[3] = 0;
            matrix[i][j] = findMaxScoreInArray(tempArray, 4);

            switch (ind) {
                case 0: // score in (i,j) stems from a match/mismatch
                    I_i[i][j] = i-1;
                    I_j[i][j] = j-1;
                    break;
                case 1: // score in (i,j) stems from a deletion in sequence A
                    I_i[i][j] = i-1;
                    I_j[i][j] = j;
                    break;
                case 2: // score in (i,j) stems from a deletion in sequence B
                    I_i[i][j] = i;
                    I_j[i][j] = j-1;
                    break;
                case 3: // (i,j) is the beginning of a subsequence
                    I_i[i][j] = i;
                    I_j[i][j] = j;
                    break;
            }
        }
    }

    // search matrix for the maximal score
    int maxScore = findMaxScoreAndPositionsInMatrix();

    // Backtracking from matrixMax
    int current_i = this->iMaxScore,current_j=this->jMaxScore;
    int next_i = I_i[current_i][current_j];
    int next_j = I_j[current_i][current_j];
    int tick = 0;
    char consensus_a[seqALength + seqBLength + 2], consensus_b[seqBLength + seqALength + 2];

    while(((current_i!=next_i) || (current_j!=next_j)) && (next_j!=0) && (next_i!=0)) {

        if (next_i == current_i) {
            // deletion in A
            consensus_a[tick] = '-';
        } else {
            // match/mismatch in A
            consensus_a[tick] = this->sequenceA[current_i-1];
        }

        if (next_j==current_j) {
            // deletion in B
            consensus_b[tick] = '-';
        } else {
            // match/mismatch in B
            consensus_b[tick] = this->sequenceB[current_j-1];
        }
        current_i = next_i;
        current_j = next_j;
        next_i = I_i[current_i][current_j];
        next_j = I_j[current_i][current_j];
        tick++;
    }

    printMatrix();
    printAlignments(seqALength, seqBLength, consensus_a, consensus_b, tick, maxScore);
}

void SwSingle::printMatrix() {
    cout << endl << "Result Matrix:" << endl;
    for (unsigned i=0; i < this->sequenceB.length(); i++) {
        if (i == 0) {
            cout << "      ";
        }

        cout << this->sequenceB[i] << "  ";
    }

    cout << endl;

    for (unsigned int i=0; i < this->matrix.size(); i++) {
        if (i == 0) {
            cout << "   ";
        } else {
            cout << sequenceA[i-1] << "  ";
        }

        for (unsigned int j=0; j<this->matrix[i].size(); j++) {
            cout << this->matrix[i][j] << "  ";
        }

        cout << endl;
    }
}

void SwSingle::printAlignments(int seqALength, int seqBLength, char* a, char* b, int tick, int maxScore){
    cout<<"The alignment of the sequences"<<endl<<endl;

    for (int i=0; i < seqALength; i++) {
        cout<<this->sequenceA[i];
    }
    cout << "  and" << endl;

    for (int i=0; i < seqBLength; i++) {
        cout << this->sequenceB[i];
    }
    cout << "  is:" << endl << endl;

    if(tick == 0){
        cout<<"No alignment available."<<endl;
    }else{
        for (int i=tick-1; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;

        for (int i=tick-1; i >= 0; i--) {
            if (a[i] == b[i]) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << endl;

        for (int j=tick-1; j >= 0; j--) {
            cout << b[j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Gap Panelty: " << this->GAP_PANELTY << endl;
    cout << "Mismatch Panelty: " << this->MISMATCH_PANELTY << endl;
    cout<< "Match Panelty: " << this->MATCH_PANELTY << endl;

    vector<int> topValues = getPositionsWithNumber(maxScore);
    cout << "Maximum score: " << maxScore << endl;
    cout << "Found at " << topValues.size() << " position(s)" << endl;
    cout << "***********************************************" << endl;
}

int SwSingle::scoreSwMatrixElement(char charA, char charB) {
  int score;
  if (charA == charB) {
      score=this->MATCH_PANELTY;
  } else {
      score=this->MISMATCH_PANELTY;
  }

  return score;
}

int SwSingle:: findMaxScoreAndPositionsInMatrix(){
    int maxScore = 0;
    for (unsigned int i = 1; i < this->matrix.size(); i++) {
        for (unsigned int j = 1; j < this->matrix[i].size(); j++) {
            if(this->matrix[i][j] > maxScore){
                maxScore = this->matrix[i][j];
                this->iMaxScore = i;
                this->jMaxScore = j;
            }
        }
    }
  return maxScore;
}

int SwSingle::findMaxScoreInArray(int array[], int length) {
    int maxScore = array[0];
    ind = 0;

    for (int i = 1; i < length; i++) {
        if (array[i] > maxScore) {
            maxScore = array[i];
            ind = i;
        }
    }
    return maxScore;
}

vector<int> SwSingle::getPositionsWithNumber(int value){
  vector<int> results;

  for (unsigned int i=0; i<this->matrix.size(); i++) {
      for(unsigned int j=0; j<matrix[i].size(); j++) {
          if (matrix[i][j] == value) {
              results.push_back(matrix[i][j]);
          }
      }
  }
  return results;

}

void SwSingle::setSequences(string a, string b) {
    this->sequenceA = a;
    this->sequenceB = b;
}
