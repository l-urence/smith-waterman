#ifndef SINGLE_H
#define SINGLE_H

#include <string>
#include <vector>

using namespace std;

class SwSingle
{
    private:
        //int **matrix = 0; //dynamisches zweidimensionales array in C++ nervig, besser vectoren...
        vector< vector<int> > matrix;
        string sequenceA;
        string sequenceB;
        int ind;
        void printMatrix();
        void printAlignments(int tick);

    public:
        SwSingle();
        SwSingle(string sequenceVectorA, string sequenceVectorB);
        ~SwSingle();
        void initMatrix();
        int scoreSwMatrixElement(char charA,char charB);
        int findMaxElement(int array[],int length);
        void calculateAlignments();
};

#endif // SINGLE_H
