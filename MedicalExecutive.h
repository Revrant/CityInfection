/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: medical Executive header files
------------------------------------------*/
#ifndef MEDICALEXECUTIVE_H
#define MEDICALEXECUTIVE_H
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "City.h"

class MedicalExecutive
{
private:
  std::string pop;
  std::string city;
  std::string inf;
  LinkedList<City>* CityList;
  LinkedList<City>* QuarantineList;
public:
  MedicalExecutive(std::string filename);
  ~MedicalExecutive();
  void cityHelper();
  void quarantineHelper();
  void addToList(City newCity);
  void run();
  void popTracker();
  void singleinfTracker(std::string name);
  void allinfTracker();
};
#endif
