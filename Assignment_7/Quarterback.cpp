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
				string new_name = values;		//Takes the string up until the first comma
			}
			else if (y ==1)
			{
				int completions = stoi(values);	//Converts the string after the first comma to an int
			}
			else if (y == 2)
			{
				int attempts = stoi(values);
			}
			else if (y == 3)
			{
				int yards = stoi(values);
			}
			else if (y == 4)
			{
				int new_touchdowns = stoi(values);
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

	return new_touchdowns;
}
void Quarterback::setTD(int new_touchdowns){
	touchdowns = new_touchdowns;					//Sets touchdowns
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
	float C = (passCompletions / passAttempts - 0.30) * 5;
}
float Quarterback::calcY(){
	float Y = (totalPassingYards / passAttempts - 3)*0.25;
}

float Quarterback::calcT(){
	float T = touchdowns/passAttempts * 20;
}
float Quarterback::calcI(){
	float I = 2.375 - (interceptions / passAttempts * 25);
}

//This function is used to calculate the passer rating
float Quarterback::PasserRating(){
	float C = calcC();
	float Y = calcY();
	float T = calcT();
	float I = calcI();

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
	float rating = (C+Y+T+I)/6*100;		//Uses the calculated values to find passerRating
	return rating;
}

//Determines what rating the quarterback recieves
string Quarterback::Evaluation(){
	string eval;
	if (rating>95 )
		eval = "great";
	if (rating > 90 && rating <= 95)
		eval = "good";
	if (rating > 85 && rating <= 90)
		eval = "mediocre";
	if (rating <= 85)
		eval = "poor"	;

	return eval;

}
