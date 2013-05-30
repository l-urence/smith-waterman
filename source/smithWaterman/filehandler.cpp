#include "filehandler.h"

FileHandler::FileHandler()
{

}
void FileHandler::checkFile(int open, char filename[]){
  if (open) {
      cout << "Error: Can't open the file " << filename << endl;
      exit(1);
  }
}

vector<string> FileHandler::readSequencesFromFile(ifstream& f) {
  vector<string> sequenceVector;
  string seq;
  char line[5000];
    
  while (f.good()) {
      f.getline(line, 5000);
      
      if (line[0] == 0 || line[0]=='#') {
          continue;
      }

      seq = strToupper(line);
      sequenceVector.push_back(seq);
    }
    
  return sequenceVector;
}

string FileHandler::strToupper(char* str) {
    string strUpperCase = "";
    
    for (int i = 0; str[i] != 0; ++i) {
        int c = toupper(str[i]);
        strUpperCase.push_back(char(c));
    }
    
    return strUpperCase;
}

void FileHandler::printSequences(vector<string> vector) {
    for (std::vector<string>::const_iterator iterator = vector.begin(), end = vector.end(); iterator != end; ++iterator) {
        cout << "list element="<<*iterator<<endl;
    }
}