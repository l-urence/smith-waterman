#ifndef SINGLE_H
#define SINGLE_H

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class SwSingle
{
    private:
        vector< vector<int> > matrix;
        string sequenceA;
        string sequenceB;
        int ind; //indel score
        int iMaxScore, jMaxScore;
        void printMatrix();
        void printAlignments(int seqALength, int seqBLength, char* a, char* b, int tick, int maxScore);
        const static int GAP_PANELTY = -1;
        const static int MISMATCH_PANELTY = -1;
        const static int MATCH_PANELTY = 2;

    public:
        SwSingle();
        int scoreSwMatrixElement(char charA,char charB);
        int findMaxScoreInArray(int array[],int length);
        int findMaxScoreAndPositionsInMatrix();
        void calculateAlignments();
        void setSequences(string a, string b);
        vector<int> getPositionsWithNumber(int value);
        vector<int> traceBackSeq(vector<int> start);
};

#endif // SINGLE_H
