/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: Sets and gets information for City objects
------------------------------------------*/
#include "City.h"
City::City()
{

}

City::City(std::string cityname, int pop, int inf)
{
  m_city = cityname;
  m_pop = pop;
  m_inf = inf;
}

std::string City::getCity()
{
  return(m_city);
}

int City::getPop()
{
  return(m_pop);
}

int City::getInf()
{
  return(m_inf);
}

void City::setCity(std::string cityname)
{
  m_city = cityname;
}

void City::setPop(int pop)
{
  m_pop = pop;
}

void City::setInf(int inf)
{
  m_inf = inf;
}

void City::incInf()
{
  m_inf++;
}

void City::levelOne()
{
  m_pop = m_pop * 0.9;
}

void City::levelTwo()
{
  m_pop = m_pop * 0.80;
}

void City::levelThree()
{
  m_pop = m_pop * 0.75;
}

bool City::operator ==(const std::string other)
{
  return(m_city == other);
}

bool City::operator <(const City& other)
{
  return(m_pop < other.m_pop);
}

bool City::operator >(const City& other)
{
  return(m_pop > other.m_pop);
}
