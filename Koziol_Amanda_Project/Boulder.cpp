//Amanda Koziol
//Project 1
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include <iomanip>
#include "boulder.h"
using namespace std;

string lifeStatus;
int timeSurvived[10];
string houseOrStore;

Boulder::Boulder()
{

	timeSurvived[0] = 52;
	cout << "You have decided to stay in Boulder. Your first focus is to get food." << endl;
	cout << "Do you risk going to the grocery store, or raid houses?" << endl;
	cout << "Store or House" << endl;
	cin >> storeOrHouse;
	houseOrStore = storeOrHouse;
}

string Boulder::getHouseOrStore(){
	return houseOrStore;
}

void Boulder::setHouseOrStore(string houseOrStore){
	storeOrHouse = houseOrStore;
}

string Boulder::store(int Age)
{
	if(Age > 60)
	{
		cout << "You were attacked by hungry fraternity boys while entering and you have died." << endl;
		lifeStatus = "Dead";
		ifstream myfile("Story.txt");
		ofstream outputFile("Story.txt");
		outputFile << " You were attacked by hungry fraternity boys while entering and you have died.";
	}
	else
	{
		cout << "The store has been completley emptied out, so you are forced to raid houses." << endl;
		timeSurvived[1] = 1;
	}
	
	return lifeStatus;
}

string Boulder::house(string job, string lifeStatus)
{
	if(lifeStatus == "")
	{

		cout << "You have found some food, but while in the house, zombies corner you while on the second floor." << endl;
		cout << "Do you fight the zombie, or do you jump out of the window?" << endl;
		cout << "Fight or Jump" << endl;
		cin >> jumpOrFight;
		if(jumpOrFight == "Jump")
		{
			if(job == "Cop" || job == "Doctor")
			{
				cout << "Your when you jumped out of the window, you broke your leg.";
				cout << "As you yelled out in pain, zombies approached you, and attacks before you could limp away and you were killed." << endl;
				lifeStatus = "Dead";
			}
		}
		if(jumpOrFight == "Fight")
		{
			if(job == "Professor" || job == "Student")
			{
				cout << "In the heat of battle, you did not notice that there was a zombie in the closet.";
				cout << "It came out of the closet and killed you." << endl;
				lifeStatus = "Dead";
			}
		}
	}
	//cout << lifeStatus << endl;
	timeSurvived[1] = 1;
	return lifeStatus;
}


string Boulder::sanitas(string job, string lifeStatus)
{
	if(lifeStatus == "")
	{


		cout << "With your food in tow, you must find a place to stay in. ";
		cout << "You decide on CrossFit Sanitas." << endl;
		cout << "You stay there for three weeks, getting food from Larkburger and Tokyo Joes. ";
		timeSurvived[2] = 21;
		if(job == "Doctor" || job == "Professor" || job == "Athlete")
		{
			cout << "You were working out, and right when you get the barbell above your head, Sprout explodes. ";
			cout << "The shock wave from the explosion causes you to drop the barbell on your head and you are killed instantly." << endl;
			lifeStatus = "Dead";
		}
	
		
	}
	return lifeStatus;
}


int Boulder::mountainChoice(int Age, string job, string lifeStatus)
{	
	if(lifeStatus == "")
	{


		string flatironsOrMountains;
		cout << "Sprouts suddenly explodes while you are sleeping.";
		cout << "The explosion destroys Sanitas. This makes you realize that the only safe place is to be in the mountains." << endl;
		cout << "Now you have to choose, do you stay in the flatirons and re enter Boulder for food and supplies, or do you go deep into the mountains?" << endl;
		cout << "Flatirons or Mountains" << endl;
		cin >> flatironsOrMountains;
		if(flatironsOrMountains == "Flatirons" )
		{
			cout << "You survive for five weeks in the flatirons, but when you go back into Boulder to get more supplies, you run into Ralphie.";
			cout << " Without the proper care of her handlers, she charges towards you. You get gored and die from internal bleeding." << endl;
			lifeStatus = "Dead";
			timeSurvived[3] = 35;
		}

		if(flatironsOrMountains == "Mountains")
		{
			string pickOrContinue;
			cout << "On your way into the mountains, you see a boot sitting in the middle of the trail.";
			cout << "Do you pick it up, or continue?" << endl;
			cout << "Pick or Continue" << endl;
			cin >> pickOrContinue;
			if(pickOrContinue == "Pick")
			{
				cout << "To your suprise, the boot was a portkey. You are transported to Hogwarts, which has avoided the zombies." << endl;
				cout << "You seek shelter there, and you live a long, happy life." << endl;
				cout << "Congratulations!!!" << endl;
				timeSurvived[4] = 5;
			}
			if(pickOrContinue == "Continue")
			{
				cout << "You continue into the mountains. You found a spot right near the tree line. ";
				cout << "From here you can see if anyone is approaching. This allows you to live there for the rest of your life." << endl;

			}
		}

		
	}
	int sum = 0;
	for(int i = 0; i<19; i++)
	{
		sum = sum + timeSurvived[i];
	}
	cout <<"You lived: " << sum << " Days" << endl;
	return sum;
}


