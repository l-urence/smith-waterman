
//#include <QtGui>
#include <CL/cl.h>
#include <iostream>
#include <string.h>
#include <fstream>
//#include "gui.h"
#include "filehandler.h"
#include "swsingle.h"

using namespace std;

//! [main function]
int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    // Gui gui;
    // gui.show();

    //check arguments
    if(argc!=3){
    }

    char *filenameA = argv[1];
    char *filenameB = argv[2];
    vector<string> sequenceVectorA, sequenceVectorB;
    FileHandler *fileHandler = new FileHandler();

    ifstream streamOfSequenceA, streamOfSequenceB;
    //open file a and fill vector a with sequences
    streamOfSequenceA.open(filenameA);
    fileHandler->checkFile(! streamOfSequenceA,filenameA);
    sequenceVectorA = fileHandler->readSequencesFromFile(streamOfSequenceA);
    //open file b and fill vector b with sequences
    streamOfSequenceB.open(filenameB);
    fileHandler->checkFile(! streamOfSequenceB,filenameB);
    sequenceVectorB = fileHandler->readSequencesFromFile(streamOfSequenceB);
    //print sequences
    fileHandler->printSequences(sequenceVectorA);
    fileHandler->printSequences(sequenceVectorB);
    //create a matrix every two sequences
    SwSingle *swSingle = new SwSingle(sequenceVectorA[0],sequenceVectorB[0]);
    //TODO... loop...
    swSingle->fillSwScoreMatrix(sequenceVectorA[0], sequenceVectorB[0]);
    //swSingle->printMatrix(sequenceVectorA[0], sequenceVectorB[0]);
    //qDebug("test");

    //return app.exec();
}

//! [main function]
