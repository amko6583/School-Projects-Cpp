//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino


#ifndef DENVER_H_INCLUDED
#define DENVER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Denver{
	private:
		string runOrKill;
		string runOrKills;
		string roadOrOpenSpace;
		string killOrFriend;
		string roadOrOpen;
		int timeSurvived1[10];
	public:
		Denver();
		string getRoadOrOpen();
		void setRoadOrOpen(string roadOrOpenSpace);
		int timeSurvived();
		string getRunOrKill();
		void setRunOrKill(string runOrKills);
		void stayOnRoad();
		string openSpace(string job);
		string harryPotter(string lifeStatus);
	
		string suburbs(int Age, string lifeStatus);
		int winning(string lifeStatus);


};
#endif