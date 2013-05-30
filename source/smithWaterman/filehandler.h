#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib> //required for exit(1)
#include <vector>

using namespace std;

class FileHandler {
    public:
        FileHandler();
        void checkFile(int open, char filename[]);
        vector<string> readSequencesFromFile(ifstream& f);
        string strToupper(char* str);
        void printSequences(vector<string> vector);
};

#endif // FILEHANDLER_H