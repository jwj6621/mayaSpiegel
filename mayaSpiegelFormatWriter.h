
#include <iostream>
#include <string>
#include <fstream>


#ifndef mayaSpiegelFormatWriter_h_
#define mayaSpiegelFormatWriter_h_

using namespace std;


class mayaSpiegelFormatWriter 
{

 public:
  static bool writeMSF( string inSimFile, string outDir);
 private:
  static void writeLine();
 
 
};

#endif
