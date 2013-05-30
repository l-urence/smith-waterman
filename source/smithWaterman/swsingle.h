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
        int ind;
        void printMatrix();
        void printAlignments(int tick);

    public:
        SwSingle();
        int scoreSwMatrixElement(char charA,char charB);
        int findMaxElement(int array[],int length);
        void calculateAlignments();
        void setSequences(string a, string b);
};

#endif // SINGLE_H