#include "filehandler.h"

FileHandler::FileHandler()
{

}
void FileHandler::checkFile(int open, char filename[]){

  if (open){
      cout << "Error: Can't open the file "<<filename<<endl;
      exit(1);
  }else{
      cout<<"Opened file "<<filename<<endl;
  }
}

string FileHandler::readSequencesFromFile(ifstream& f)
{
  // overflows.
  string seq;
  char line[5000];
  while( f.good() )
    {
      f.getline(line,5000);
            cout << "Line:" << line << endl; //test output
      if( line[0] == 0 || line[0]=='#' )
    continue;
      for(int i = 0; line[i] != 0; ++i)
    {
      int c = toupper(line[i]);
      //if( c != 'A' && c != 'G' && c != 'C' && c != 'T' )
      //  continue;
      cout << "Character " << i << ": " << char(c)<<"\n"; //test output
      seq.push_back(char(c));
    }
    }
  return seq;
}


