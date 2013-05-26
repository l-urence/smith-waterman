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

    public:
        SwSingle();
        SwSingle(string sequenceVectorA, string sequenceVectorB);
        ~SwSingle();
        void printMatrix(string sequenceA, string sequence);
        void initMatrix(string sequenceA, string sequenceB);
        int scoreSwMatrixElement(char charA,char charB);
        double find_array_max(double array[],int length);
        void fillSwScoreMatrix(std::string sequenceA, std::string sequenceB);
};

#endif // SINGLE_H
