#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "filehandler.h"
#include "swsingle.h"

// Use the right openCL header depending on the platform.
#ifdef __APPLE__
    #include "OpenCL/opencl.h"
#else
    #include "CL/cl.h"
#endif

using namespace std;

int main(int argc, char *argv[]) {
    // Check number of given arguments. Mybe we use:
    // http://www.boost.org/doc/libs/1_53_0/doc/html/program_options.html
    if (argc != 3) {
        cout << "Not enough arguments" << endl;
        return EXIT_FAILURE;
    }

    char *filenameA = argv[1];
    char *filenameB = argv[2];
    vector<string> sequenceVectorA, sequenceVectorB;
    FileHandler *fileHandler = new FileHandler();
    ifstream streamOfSequenceA, streamOfSequenceB;
    
    //open file a and fill vector a with sequences
    streamOfSequenceA.open(filenameA);
    fileHandler->checkFile(! streamOfSequenceA, filenameA);
    sequenceVectorA = fileHandler->readSequencesFromFile(streamOfSequenceA);
    
    //open file b and fill vector b with sequences
    streamOfSequenceB.open(filenameB);
    fileHandler->checkFile(!streamOfSequenceB, filenameB);
    sequenceVectorB = fileHandler->readSequencesFromFile(streamOfSequenceB);

    SwSingle *swSingle = new SwSingle();
    for(unsigned int i=0; i<sequenceVectorA.size(); i++){
        for(unsigned int j=0; j<sequenceVectorB.size(); j++){
            swSingle->setSequences(sequenceVectorA[i], sequenceVectorB[j]);
            swSingle->calculateAlignments();
        }
    }
    
    // Clean up
    delete swSingle;
    
    return EXIT_SUCCESS;
}
