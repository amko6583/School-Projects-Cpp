//Amanda Koziol
//Homework 7
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include <sstream>
#include "Quarterback.h"
using namespace std;
Quarterback::Quarterback(){

}

Quarterback::Quarterback(string data){
	int x = 0;							//Position in the string
	int y = 0;							//Number of commas
	string values = "";
	for(x; x < data.length(); x++)
	{
		if(data[x] != ',') 				//if the character in the string is not ,
		{
			values = values + data[x];	//Addes that character to the string values
		}
		else if (data[x] == ',')		//if the character is a comma
		{
			if (y ==0)
			{
				new_name = values;		//Takes the string up until the first comma
			}
			else if (y ==1)
			{
				completions = stoi(values);	//Converts the string after the first comma to an int
			}
			else if (y == 2)
			{
				attempts = stoi(values);
			}
			else if (y == 3)
			{
				yards = stoi(values);
			}
			else if (y == 4)
			{
				touchdowns_new = stoi(values);
			}
			y++;
			values = "";					//resets the string


		}
	}
}

//Finding and setting the quarterback name
string Quarterback::getName(){
	return new_name;
}
void Quarterback::setName(string new_name){
 	quarterbackName = new_name;			//Takes new_name and sets it as the quarterbackName
}

//Finding and setting completions
int Quarterback::getComp(){
	return completions;
}
void Quarterback::setComp(int completions){	
	passCompletions = completions;		//Sets the value from the input string to passCompletions
}


//Finding and setting attempts
int Quarterback::getAtt(){
	return attempts;						//Returns that value
}
void Quarterback::setAtt(int attempts){
	passAttempts = attempts;				//Sets the passAttempts value
}


//Finding and setting yards
int Quarterback::getYards(){			
	return yards;
}
void Quarterback::setYards(int yards){
	totalPassingYards = yards;			//Sets totalPassingYards
}


//Finding and setting touchdowns
int Quarterback::getTD(){

	return touchdowns_new;
}
void Quarterback::setTD(int touchdowns_new){
	touchdowns = touchdowns_new;					//Sets touchdowns
}

//Finding and setting interceptions
int Quarterback::getPick(){

	return picks;	
}
void Quarterback::setPick(int picks){
	interceptions = picks; 				//sets interceptions
}

//Adds when a pass is completed
void Quarterback::PassCompleted(int yards){
	passCompletions = passCompletions+1;			//adds one for the completion
	passAttempts = passAttempts+1;					//adds one for the pass attempt
	totalPassingYards = totalPassingYards + yards;	//adds the number of yards that they completed
}

//When a pass is attempted but not completed
void Quarterback::PassAttempted(){
	passAttempts = passAttempts + 1;
}

//When a pass is intercepted
void Quarterback::Interception(){
	interceptions = interceptions + 1;		//Adds one for interception
	passAttempts = passAttempts + 1;		//adds one to pass attemps

}

//When there is a touchdown
void Quarterback::touchdown(int yards){
	passAttempts = passAttempts + 1;
	passCompletions = passCompletions + 1;
	touchdowns = touchdowns + 1;
	yards = yards + 1;
}


//These functions are used to calculate passer ratings
float Quarterback::calcC(){
	C = (passCompletions / passAttempts - 0.30) * 5;
}
float Quarterback::calcY(){
	Y = (totalPassingYards / passAttempts - 3)*0.25;
}

float Quarterback::calcT(){
	T = touchdowns/passAttempts * 20;
}
float Quarterback::calcI(){
	I = 2.375 - (interceptions / passAttempts * 25);
}

//This function is used to calculate the passer rating
float Quarterback::PasserRating(){
	C = calcC();
	Y = calcY();
	T = calcT();
	I = calcI();

	//Corrects the values if they are negative or above 2.375
	if (C <0)
		C = 0;
	else if (C > 2.375)
		C = 2.375;
	if (Y <0)
		Y = 0;
	else if (Y > 2.375)
		Y = 2.375;
	if (T <0)
		T = 0;
	else if (T > 2.375)
		T = 2.375;
	if (I <0)
		I = 0;
	else if (I > 2.375)
		I = 2.375;
	float PasserRating = (C+Y+T+I)/6*100;		//Uses the calculated values to find passerRating
	return PasserRating;
}

//Determines what rating the quarterback recieves
string Quarterback::Evaluation(){
	string rating;
	PasserRatings = PasserRating();
	if (PasserRatings>95 )
		rating = "great";
	if (PasserRatings > 90 && PasserRatings <= 95)
		rating = "good";
	if (PasserRatings > 85 && PasserRatings <= 90)
		rating = "mediocre";
	if (PasserRatings <= 85)
		rating = "poor"	;

	return rating;

}
