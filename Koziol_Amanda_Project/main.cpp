//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino


#include <iostream>
#include <fstream>
#include <iomanip>
#include "userInputs.cpp"
#include "Denver.cpp"
#include "Boulder.cpp"

using namespace std;

int main()
{
	ofstream outputFile("Story.txt");
	outputFile << "One snowy day, you were walking through campus and got hit by the Buff Bus.";
	outputFile << " You have finally awoken from your coma after 50 days to realize that he hospital has been abandoned.";
	outputFile << " When you go to investigate, you discover that there are zombies walking the halls.";
	outputFile << " You have decided to stay in Boulder. Your first focus is to get food." << endl;
	//Initial Set Up
	string aliveOrDead = "";

	userInputs Inputs;
	string userJob = Inputs.getUserJob();
	int userAge = Inputs.getUserAge();
	string stay = Inputs.stayOrGo ();


	string lifeStatus = Inputs.deadOrAlive ();



	
	if(stay == "Go")
	{
		Denver denver;	
		outputFile << "You chose to go to Denver, but you hit traffic on 36. ";
		string roadOrOpenSpace = denver.getRoadOrOpen();
		if(roadOrOpenSpace == "Leave")
		{
			string aliveOrDead = "";
			aliveOrDead = denver.openSpace (userJob);
			if(aliveOrDead == "")
				outputFile << "You go into the open space. ";
			aliveOrDead = denver.harryPotter (aliveOrDead);
			if(aliveOrDead == "")
				outputFile << "As you left the house, you picked up a wand. ";
			aliveOrDead = denver.suburbs(userAge, aliveOrDead);	
			if(aliveOrDead == "")
			{
				outputFile << "You spend a week slowly heading towards Denver.";
				outputFile << " While in the suburbs, you break into abandoned houses and take what ever food you could find.";
				outputFile << " You have found the keys for a vehicle, but your choice backfired." << endl;
			}
			denver.winning(aliveOrDead);
		}

		if(roadOrOpenSpace == "Continue")
		{
			denver.stayOnRoad();
			outputFile << "After only five minutes walking on 36, you were attacked by zombies and killed.";
		}
	}

	if (stay == "Stay")
	{
		Boulder boulder;
		outputFile << "You chose to stay in Boulder." << endl; 
		string storeOrHouse = boulder.getHouseOrStore();
		if(storeOrHouse == "Store")
		{
			aliveOrDead = boulder.store(userAge);
			if(aliveOrDead == "")
				outputFile << "You chose to go to the store, but they were all out of food. " << endl;
		}


		aliveOrDead = boulder.house(userJob, aliveOrDead);
		
		if(aliveOrDead == "")
			{
				outputFile << "You were attacked while in the house, but you made it out alive. You made it to CrossFit Sanitas. " << endl;
			}
		aliveOrDead = boulder.sanitas(userJob, aliveOrDead);

		if(aliveOrDead == "")
		{
			outputFile << "You survived the explosion at Sprouts, and move into the mountains. " << endl;
		}
		
		int timeSurvived = boulder.mountainChoice(userAge, userJob, aliveOrDead);

		outputFile << "You lived for: " << timeSurvived << "days." << endl;


	}

	return 0;
}
	





