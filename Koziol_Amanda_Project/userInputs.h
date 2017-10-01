//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino


#ifndef USERINPUTS_H_INCLUDED
#define USERINPUTS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class userInputs
{
	private:
	string line;
	string userJobs;
	string userName;
	int userAges;
	string userGender;
	string Name;
	int Age;
	string previousJob;
	string Gender;

	public:
		userInputs();
		//Setting Initial Inputs
		string getUserJob();
		void setUserJob(string userJobs);

		int getUserAge();
		void setUserAge(int userAges);

		//Functions to decide which route to go
		string stayOrGo();

		string deadOrAlive();



};
#endif