//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Denver.h"
using namespace std;




ofstream outputFile("Story.txt");
int timeSurvived1[10];

//Constructor
Denver::Denver()
{
	

	string continueOrLeave;
	cout << "As you are driving down 36, you hit abandoned cars, ";
	cout << "completley blocking your path. You are now faced with a decision.";
	cout << " Do you continue on foot down 36, or do you venture into the open space?" <<endl;
	cout << "Continue or Leave" <<endl;
	cin >> continueOrLeave;
	roadOrOpenSpace = continueOrLeave;
	timeSurvived1[0] = 52;

	//output file
	outputFile << "";
	outputFile << "As you travled down US 36, you hit abandoned cars that completley blocked the path.";
}

string Denver::getRoadOrOpen()
{
	return roadOrOpenSpace;
}
void Denver::setRoadOrOpen(string roadOrOpenSpace){
	roadOrOpen = roadOrOpenSpace;
}





//Staying on 36
void Denver::stayOnRoad(){
	cout << "You have made a bad decision." << endl;
	cout << "Just five minutes into your walk down 36, you are attacked by a hoard of zombies and you did not survive the fight." << endl;
	cout << "You are now a zombie." << endl;


}




//Person's chice to go into open space
string Denver::openSpace(string job)
{

	string lifeStatus = "";
	if(lifeStatus == "")
	{


		//Initial question after they chose to go to the open space
		cout << "You have been walking for almost an hour through the open space and you find a farm house." << endl;
		cout << "Do you take over the farm by killing all of them, or do you risk it and try to befriend them?" <<endl;
		cout << "Kill or Befriend" << endl;
		cin >> killOrFriend;
		timeSurvived1[1] = 1;

		//output file
		outputFile << "After walking through the open space, you find a house. ";


	
		if (killOrFriend == "Befriend")
		{
			string userFight;
			cout << "You form a great friendship with the owners of the house and stay there for four days until disaster strikes." << endl;
			cout << "The entire defensive line of the CU football team has become zombies";
			cout << " and is attacking the house. Do you stay and try to fight them off, or do you run away?" << endl;
			cout << "Run or Fight" << endl;
			cin >> userFight;
			runOrKill = userFight;

			//output file
			outputFile << "You befriended the owner of the house. Days later, the entire defensive line of the CU football team who were zombies, attacked the house. ";
			timeSurvived1[2] = 5;
		}

		if (killOrFriend == "Kill"){
			if (job == "Professor" || job == "Cop")
			{
				cout << "Durring the fight, you were shot in the stomach, and slowly blead to death." << endl;
				lifeStatus = "Dead";
			}
			else
			{
				string userFight;
				cout << "The entire defensive line of the CU football team has become zombies";
				cout << " and is attacking the house. Do you stay and try to fight them off, or do you run away?" << endl;
				cout << "Run or Fight" << endl;
				cin >> userFight;
				runOrKill = userFight;
			}
		}


		if(runOrKill == "Fight")
		{
			if(job == "Athlete" || job == "Cop")
			{
				cout << "Your choice to fight has backfired and you have been turned into a zombie." <<endl;
				
				lifeStatus = "Dead";

				//output file
				outputFile << "Your decision to fight the team was a bad choice, and you were killed. ";
			}	
			else
			{
				cout << "You were successful, but the house is now overrun with zombies, so you must continue to Denver." << endl;

				//output file
				outputFile << "You defeated the football team, but the house became overrun by zombies, so you were forced to continue to Denver";
			}
		}

		if(runOrKill == "Run")
		{
			if(job == "Student")
			{
				cout << "Right before you were hit by the buff bus, you had been ";
				cout << "lost in the Engineering building for two weeks, so your";
				cout <<" muscles are too weak to out run the zombies and you are killed." << endl;
				
				outputFile << "That week that you were lost within the Engineering building has come back to bite you. Your muscles were so weak, you were not able to outrun the zombies and you died.";
				lifeStatus = "Dead";
			}
		}		
		
	}
	return lifeStatus;
}



//Harry Potter Wand
string Denver::harryPotter(string lifeStatus)
{
	if(lifeStatus == "")
	{


		string spellChoice;
		cout << "As you were leaving, you found a wand. The house owner, who is now a zombie is walking towards you.";
		cout << " Do you use Stuptify or Wingardium Leviosa?" <<endl;
		cout << "Stuptify or Leviosa" << endl;
		cin >> spellChoice;

		if(spellChoice =="Leviosa")
		{
			cout << "You said it wrong! It's LeviOsa, not LevioSA. The zombie has gotten you and you are now dead." <<endl;
			lifeStatus = "Dead";
		}
		cout << lifeStatus <<endl;
	}
	return lifeStatus;


}


string Denver::suburbs(int Age, string lifeStatus)
{
	string carOrTruck;
	if(lifeStatus == "")
	{	
		timeSurvived1[3] = 7;


		cout << "You spend a week slowly heading towards Denver.";
		cout << " While in the suburbe, you break into abandoned houses and take what ever food you could find.";
		cout << " You have found the keys for both a car and a truck. Which do you take to help on your journey to Denver?" << endl;
		cout << "Car or Truck" << endl;
		cin >> carOrTruck;
	if(carOrTruck == "Car")
	{
		cout << "You have made it all the way to downtown Denver. ";
		cout << "Now you need to find other survivors." << endl;
		if(Age < 20 || Age > 30)
		{
			cout << "You get attacked as you enter the Pepsi Center by the remaining Denver Nuggets and die." << endl;
			lifeStatus = "dead";
		}
	}
	if(carOrTruck == "Truck")
	{
		cout << "After only an hour of driving, you run out of gas. While looking for more gas, you get attacked by zombies and die." << endl;
		lifeStatus = "Dead";
	}
	
	}
	return lifeStatus;
}
int Denver::winning(string lifeStatus)
{
	if(lifeStatus == "")
	{
		cout << "You have found the cure, and live a happy healthy life." << endl;
	}
	int sum = 0;
	for(int i = 0; i<10; i++)
	{
		sum = sum + timeSurvived1[i];
	}
	cout << "You lived " << sum << " days." <<endl;
	return sum;
}


