#ifndef SINGLE_H
#define SINGLE_H

#include <string>
#include <vector>

using namespace std;

class Single
{
    private:
        int **matrix = 0;
        int rowsCount = 0;
        int columnsCount = 0;

    public:
        Single();
        Single(vector<string> sequenceVectorA, vector<string> sequenceVectorB);
        ~Single();
        void printMatrix();
        void initMatrix();
        int rateMatrixElement(char charA,char charB);
        double find_array_max(double array[],int length);
        void fillMatrix(std::string sequenceA, std::string sequenceB);

};

#endif // SINGLE_H
