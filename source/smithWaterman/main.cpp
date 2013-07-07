#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "filehandler.h"
#include "swsingle.h"
//#include "cll.h"

/*
 *@author Laurence Bortfeld
 *@author Wojciech Konitzer
 *
 *OpenCL Tutorial:
 * "...code works for me on my Macbook Pro (with Geforce 9400M) running
 * Snow Leopard with the NVIDIA GPU SDK as well as
 * on the Ubuntu 10.4 workstations..."
http://enja.org/2010/07/20/adventures-in-opencl-part-1-5-cpp-bindings/

Compile command example:
g++ -o smithwaterman -L /opt/AMDAPP/lib/x86_64/ -I /opt/AMDAPP/include/ main.cpp swsingle.cpp filehandler.cpp cll.cpp util.cpp part1.cpp -lOpenCL

start program:
./smithwaterman seq1.txt seq2.txt
*/
// Use the right openCL header depending on the platform.
/*#ifdef __APPLE__
    #include "OpenCL/opencl.h"
#else
    #include "CL/cl.h"
#endif*/

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
    swSingle->setSequences("BANANE", "SANANA");
    swSingle->calculateAlignments();
    
   /* for(unsigned int i=0; i<sequenceVectorA.size(); i++){
        for(unsigned int j=0; j<sequenceVectorB.size(); j++){
            swSingle->setSequences(sequenceVectorA[i], sequenceVectorB[j]);
            swSingle->calculateAlignments();
        }
    }  */
    // Clean up
    delete swSingle;

    /**********  OpenCL implementation  ***********************************/
    printf("Hello, OpenCL\n");
    //initialize our CL object, this sets up the context
//    CL example;

    //load and build our CL program from the file //TODO: Add smithwaterman.cl
    //#include "part1.cl" //const char* kernel_source is defined in here
    //example.loadProgram(kernel_source);


    //initialize the kernel and send data from the CPU to the GPU
  //  example.popCorn();
    //execute the kernel
    //example.runKernel();
    //exit(0);*/


    return EXIT_SUCCESS;
}
