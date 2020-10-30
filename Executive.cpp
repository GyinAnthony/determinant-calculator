#include <fstream>
#include <iostream>
#include <string>
#include "Executive.h"
#include "Matrix.h"



Executive::Executive()
{
}

void Executive::run(std::string filename)
{
  int count = 0;
  double n = 0;
  std::ifstream inFile(filename);
  while(inFile >>n)
  {
    count ++;
    Matrix M(inFile,n);
    std::cout << count << ". Matrix 1: "; 
    std::cout << M.det() << std::endl;
  }
}
Executive::~Executive()
{

}
