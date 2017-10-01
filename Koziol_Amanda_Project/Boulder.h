//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino


#ifndef BOULDER_H_INCLUDED
#define BOULDER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Boulder{
	private:
		string storeOrHouse;
		string lifeStatus;
		string jumpOrFight;
		string flatOrMount;
		string houseOrStore;
		string timeSurvived;
	public:
		Boulder();
		string store(int Age);
		string house(string job, string lifeStatus);
		string sanitas(string job, string lifeStatus);
		int mountainChoice(int Age, string job, string lifeStatus);
		string getHouseOrStore();
		void setHouseOrStore(string houseOrStore);





};
#endif