
//#include <QtGui>
#include <CL/cl.h>
#include <iostream>
#include <string.h>
#include <fstream>
//#include "gui.h"
#include "filehandler.h"
#include "single.h"

using namespace std;

//! [main function]
int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

   // Gui gui;
   // gui.show();

      if(argc!=3){
      }

      char *filenameA = argv[1];
      char *filenameB = argv[2];
      string sequenceA, sequenceB;
      FileHandler *fileHandler = new FileHandler();

      ifstream streamOfSequenceA, streamOfSequenceB;

      streamOfSequenceA.open(filenameA);
      fileHandler->checkFile(! streamOfSequenceA,filenameA);
      sequenceA = fileHandler->readSequencesFromFile(streamOfSequenceA);

      streamOfSequenceB.open(filenameB);
      fileHandler->checkFile(! streamOfSequenceB,filenameB);
      sequenceB = fileHandler->readSequencesFromFile(streamOfSequenceB);


      Single *single = new Single(10,9);
    single->printMatrix();
    //qDebug("test");

    //return app.exec();
}

//! [main function]
