/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: City header file
------------------------------------------*/
#ifndef CITY_H
#define CITY_H
#include <string>
#include <iostream>
class City
{
private:
  std::string m_city;
  int m_pop;
  int m_inf;
public:
  City();
  City(std::string city, int pop, int inf);
  std::string getCity();
  int getPop();
  int getInf();
  void setCity(std::string cityname);
  void setPop(int pop);
  void setInf(int inf);
  void incInf();
  void levelOne();
  void levelTwo();
  void levelThree();
  bool operator ==(const std::string other);
  bool operator <(const City& other);
  bool operator >(const City& other);
};
#endif
