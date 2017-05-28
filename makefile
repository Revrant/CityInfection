CityInfection: main.o MedicalExecutive.o City.o
	g++ -g -std=c++11 -Wall main.o MedicalExecutive.o City.o -o CityInfection
main.o: main.cpp LinkedList.h Node.h City.h MedicalExecutive.h
	g++ -g -std=c++11 -Wall -c main.cpp
MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp
	g++ -g -std=c++11 -Wall -c MedicalExecutive.cpp
City.o: City.h City.cpp
	g++ -g -std=c++11 -Wall -c City.cpp
clean:
	rm *.o CityInfection
