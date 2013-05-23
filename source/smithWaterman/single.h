#ifndef SINGLE_H
#define SINGLE_H

class Single
{
    private:
        int **matrix = 0;
        int rowsCount = 0;
        int columnsCount = 0;

    public:
        Single();
        Single(int rowsCount, int columnsCount);
        ~Single();
        void printMatrix();
        void initMatrix();

};

#endif // SINGLE_H
