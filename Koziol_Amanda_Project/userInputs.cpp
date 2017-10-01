//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include <iomanip>
#include "userInputs.h"
using namespace std;

ifstream myfile("InputOutputs.txt");


userInputs::userInputs()
{

	int index = 1;
	while (getline(myfile, line))
	{
		if(index%5 == 1)
		{
			cout << line << endl;
			cin >> userName;
		}
		if(index%5 == 2)
		{
			cout <<line<<endl;
			cin >> line;
			userAges = stoi(line);
		}
		if(index%5 == 3)
		{
			userJobs = "";
			cout << line << endl;
			cin >> line;
			while (userJobs == "")
			{
				if(line == "Doctor")
					userJobs = "Doctor";
				if(line == "Cop")
					userJobs = "Cop";
				if(line == "Professor")
					userJobs = "Professor";
				if(line == "Athlete")
					userJobs = "Athlete";
				if(line == "Student")
					userJobs = "Student";	
				if(userJobs == "")
					{
					cout << "Please enter a valid job: Doctor, Cop, Professor, Athlete, or Student" << endl;
					cin >> line;		
					}		
			}

		}
		
		index = index + 1;
	}
}
string userInputs::getUserJob(){
	return userJobs;
}

void userInputs::setUserJob(string userJobs){
	string userJob = userJobs;
}

int userInputs::getUserAge(){
	return userAges;
}

void userInputs::setUserAge(int userAges){
	int userAge = userAges;
}

string userInputs::stayOrGo(){
	string stayOrGo;
	ifstream myfile("finalOutput.txt");	
	string line;
	getline(myfile, line);
	cout <<line<<endl;
	cout << "After two days of looking for another survivor, you finally find someone who tells you that there is refuge in Denver." <<endl;
	
	//Choosing path of Denver or Boulder
	cout << "Do you stay in Boulder or go to Denver?" << endl;
	cout << "Stay or Go" <<endl;
	cin >> stayOrGo;

	return stayOrGo;

}

string userInputs::deadOrAlive(){
	string lifeStatus = "Alive";
	return lifeStatus;
}


