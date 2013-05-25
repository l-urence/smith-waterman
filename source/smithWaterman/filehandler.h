#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib> //required for exit(1)

using namespace std;

class FileHandler
{
public:
    FileHandler();
    void checkFile(int open, char filename[]);
    string readSequencesFromFile(ifstream& f);
};

#endif // FILEHANDLER_H