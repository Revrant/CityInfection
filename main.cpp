/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/12/2017
File Summary: Validates user inputs a file
------------------------------------------*/
#include "MedicalExecutive.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    MedicalExecutive exec(argv[1]);
    exec.run();
  }
  return(0);
}
