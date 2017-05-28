/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: Runs the menu, takes inFile, outputs quarantines, and helps track infection levels
------------------------------------------*/
#include "MedicalExecutive.h"

//***************************************************************************
//                                                                         //
//                                                                         //
//                             CONSTRUCTOR                                 //
//                                                                         //
//                                                                         //
//***************************************************************************

MedicalExecutive::MedicalExecutive(std::string filename)
{
  std::ifstream inFile;
  inFile.open(filename);

  if(inFile.is_open())
  {
    CityList = new LinkedList<City>;
    //QuarantineList = new LinkedList<City>;

    std::string line;
    while(std::getline(inFile, line))
    {
      std::string city, pop, inf;

      city = line.substr(0, line.find(",")); //Looks at each string as array of characters and copies till comma
      line = line.substr(line.find(",") + 1, line.length());
      pop = line.substr(0, line.find(","));
      inf = line.substr(line.find(",") + 1, line.length() - 1);

      City newCity(city, std::stoi(pop), std::stoi(inf));
      addToList(newCity);

    }
    std::cout << "End of file. Starting Program...\n";
  }
  inFile.close();


  QuarantineList = new LinkedList<City>;
}

//***************************************************************************
//                                                                         //
//                                                                         //
//                              DESTRUCTOR                                 //
//                                                                         //
//                                                                         //
//***************************************************************************

MedicalExecutive::~MedicalExecutive()
{
    delete CityList;
    delete QuarantineList;
}

//***************************************************************************
//                                                                         //
//                                                                         //
//                              ADD TO LIST                                //
//                                                                         //
//                                                                         //
//***************************************************************************

void MedicalExecutive::addToList(City newCity)
{
  int pos = 1;

  if(CityList->isEmpty())
  {
    CityList->addFront(newCity);
  }
  else if(CityList->getEntry(CityList->getLength()) > newCity)
  {
    CityList->addBack(newCity);
  }
  else
  {
    while(CityList->getEntry(pos) > newCity && pos < CityList->getLength())
    {
      pos++;
    }
    CityList->insert(pos, newCity);
  }
}


//***************************************************************************
//                                                                         //
//                                                                         //
//                          POPULATION TRACKER                             //
//                                                                         //
//                                                                         //
//***************************************************************************

void MedicalExecutive::popTracker()
{
  LinkedList<City>* tempList = new LinkedList<City>;

  while(!CityList->isEmpty())
  {
      City temp = CityList->getEntry(1);
      CityList->removeFront();

      int pos = 1;
      if(tempList->isEmpty())
      {
        tempList->addFront(temp);
      }
      else if(tempList->getEntry(tempList->getLength()) > temp)
      {
        tempList->addBack(temp);
      }
      else
      {
        while(tempList->getEntry(pos) > temp && pos < tempList->getLength())
        {
          pos++;
        }
        tempList->insert(pos, temp);
      }
  }
  delete CityList;
  CityList = tempList;

  LinkedList<City>* tempList2 = new LinkedList<City>;
  while(!QuarantineList->isEmpty())
  {
      City temp = QuarantineList->getEntry(1);
      QuarantineList->removeFront();

      int pos = 1;
      if(tempList2->isEmpty())
      {
        tempList2->addFront(temp);
      }
      else if(tempList2->getEntry(tempList2->getLength()) > temp)
      {
        tempList2->addBack(temp);
      }
      else
      {
        while(tempList2->getEntry(pos) > temp && pos < tempList2->getLength())
        {
          pos++;
        }
        tempList2->insert(pos, temp);
      }
  }
  delete QuarantineList;
  QuarantineList = tempList2;

}

//***************************************************************************
//                                                                         //
//                                                                         //
//                        INFECTION ALL TRACKER                            //
//                                                                         //
//                                                                         //
//***************************************************************************

void MedicalExecutive::allinfTracker()
{
  for(int i = 1; i < CityList->getLength(); i++)
  {

  if(CityList->getEntry(i).getInf() == 4)
    {
      std::cout << CityList->getEntry(i).getCity() << " has been placed in quarantine!\n";
      QuarantineList->addFront(CityList->getEntry(i));
      CityList->removeAt(i);
    }

    else if(CityList->getEntry(i).getInf() == 3)
    {

      City current = CityList->getEntry(i);
      std::string name = "New ";
      name+= current.getCity();
      int pop = current.getPop()*0.25;
      City temp(name,pop,0);
      current.levelThree();
      CityList->setEntry(i, current);
      addToList(temp);
    }

    else if(CityList->getEntry(i).getInf() == 2)
    {
      City current = CityList->getEntry(i);
      current.levelTwo();
      CityList->setEntry(i, current);
    }

    else if(CityList->getEntry(i).getInf() == 1)
    {
      City current = CityList->getEntry(i);
      current.levelOne();
      CityList->setEntry(i, current);
    }

  }

}

//***************************************************************************
//                                                                         //
//                                                                         //
//                       INFECTION SINGLE TRACKER                          //
//                                                                         //
//                                                                         //
//***************************************************************************

void MedicalExecutive::singleinfTracker(std::string name)
{
  for(int i = 1; i < CityList->getLength(); i++)
  {
    if(CityList->getEntry(i).getCity() == name)
    {
  if(CityList->getEntry(i).getInf() == 4)
    {
      std::cout << CityList->getEntry(i).getCity() << " has been placed in quarantine!\n";
      QuarantineList->addFront(CityList->getEntry(i));
      CityList->removeAt(i);
    }
    else if(CityList->getEntry(i).getInf() == 3)
    {

      City current = CityList->getEntry(i);
      std::string name = "New ";
      name+= current.getCity();
      int pop = current.getPop()*0.25;
      City temp(name,pop,0);
      current.levelThree();
      CityList->setEntry(i, current);
      addToList(temp);

    }
    else if(CityList->getEntry(i).getInf() == 2)
    {
      City current = CityList->getEntry(i);
      current.levelTwo();
      CityList->setEntry(i, current);
    }
    else if(CityList->getEntry(i).getInf() == 1)
    {
      City current = CityList->getEntry(i);
      current.levelOne();
      CityList->setEntry(i, current);
    }
    }
  }
}

//***************************************************************************
//                                                                         //
//                                                                         //
//                                RUN                                      //
//                                                                         //
//                                                                         //
//***************************************************************************

void MedicalExecutive::run()
{
  char choice = '\0';

  //*****************************************************************
  //                           MENU                                //
  //*****************************************************************
  do{
  std::cout << "Make a selection:\n";
  std::cout << "1) Increase infection level of all cities\n";
  std::cout << "2) Increase infection level of specific city\n";
  std::cout << "3) Print status of a specific city\n";
  std::cout << "4) Create quarantine log\n";
  std::cout << "5) Print all cities above infection level\n";
  std::cout << "6) Exit\n";
  std::cout << "Choice: ";
  std::cin >> choice;
  //*****************************************************************
  //                         VALID INPUT                           //
  //*****************************************************************
  while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6')
  {
    std::cin >> choice;
  }
  //*****************************************************************
  //                           CHOICES                             //
  //*****************************************************************
  // Choice 1
  if(choice == '1') //Increase infection of all cities
  {
    std::cout << "The infection level of all cities has been increased.\n";

    for(int i = 1; i <= CityList->getLength(); i++)
    {
      City current = CityList->getEntry(i);
      current.incInf();
      CityList->setEntry(i, current);
    }

    allinfTracker();
    popTracker();

    /*for(int i = 1; i <= CityList->getLength(); i++)     DEBUGGING
    {
      std::cout << CityList->getEntry(i).getCity() << ", " << CityList->getEntry(i).getPop() << ", "<< CityList->getEntry(i).getInf() << '\n';
    }*/
  }

  //Choice 2
  else if(choice == '2') //Increase infection of specific
  {
    std::cout << "Input city name: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    for(int i = 1; i <= CityList->getLength(); i++)
    {
      if(CityList->getEntry(i) == name)
      {
        City current = CityList->getEntry(i);
        current.incInf();
        CityList->setEntry(i, current);
      }
    }
    singleinfTracker(name);
    popTracker();

    /*for(int i = 1; i <= CityList->getLength(); i++)     DEBUGGING
    {
      std::cout << CityList->getEntry(i).getCity() << ", " << CityList->getEntry(i).getPop() << ", "<< CityList->getEntry(i).getInf() << '\n';
    }*/
  }

  //Choice 3
  else if(choice == '3') //Print status of specific city
  {
    std::string name;
    std::cout << "Input a city: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    for(int i = 1; i <= CityList->getLength(); i++)
    {
      if(CityList->getEntry(i) == name)
      {
        std::cout << CityList->getEntry(i).getCity() << ", ";
        std::cout << CityList->getEntry(i).getPop() << ", ";
        std::cout << CityList->getEntry(i).getInf() << '\n';
      }
    }
  }

  //Choice 4
  else if(choice == '4') //Create quarantine log
  {
    if(QuarantineList->isEmpty())
    {
      std::cout << "There are no Quarantined Cities.\n";
    }
    else
    {
      std::ofstream outfile;
      std::string file;
      std::cout << "Enter a name for quarantine log: ";
      std::cin >> file;
      outfile.open(file);

      while(!outfile.is_open())
      {
        std::cout << "Enter a valid file name: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> file;
        outfile.open(file);
      }

      for(int i = 1; i <= QuarantineList->getLength(); i ++)
      {
        outfile << QuarantineList->getEntry(i).getCity() << ", ";
        outfile << QuarantineList->getEntry(i).getPop() << ", ";
        outfile << QuarantineList->getEntry(i).getInf() << '\n';
      }

    outfile.close();
    }
  }

  //Choice 5
  else if(choice == '5') // Print all cities above an infection level
  {
    int inflvl = 0;
    std::cout << "Input infection level: ";
    std::cin >> inflvl;

    for(int i = 1; i <= CityList->getLength(); i++)
    {
      if(CityList->getEntry(i).getInf() > inflvl)
      {
        std::cout << CityList->getEntry(i).getCity() << ", ";
        std::cout << CityList->getEntry(i).getPop() << ", ";
        std::cout << CityList->getEntry(i).getInf() << '\n';
      }
    }

  }

//*****************************************************************
//                              EXIT                             //
//*****************************************************************
  std::cout<<'\n';
  }while(choice != '6');
  std::cout << "Goodbye!\n";
}









//Space
//*****************************************************************
