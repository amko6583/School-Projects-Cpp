//Amanda Koziol
//Homework 7
//Recitation 109
//TA Michael Luzzolino


#ifndef QUARTERBACK_H_INCLUDED
#define QUARTERBACK_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class Quarterback
{
	//Data Members

	private:
		string quarterbackName;
		int passCompletions;
		int passAttempts;
		int totalPassingYards;
		int touchdowns;
		int interceptions;
		int picks;
		float rating;
		string new_name;
		int attempts;
		int completions;
		int yards;
		int new_touchdowns;


	public:
		Quarterback();
		Quarterback(string data);

		//access methods
		string getName();
		void setName(string new_name);

		int getComp();
		void setComp(int completions);

		int getAtt();
		void setAtt(int attempts);

		int getYards();
		void setYards(int yards);

		int getTD();
		void setTD(int touchdowns_new);

		int getPick();
		void setPick(int picks);

		//Functions
		void PassCompleted(int yards);
		void PassAttempted();
		void Interception();
		void touchdown(int yards);
		float PasserRating();
		string Evaluation();


	private:
		
		float calcC();
		float calcY();
		float calcT();
		float calcI();

};
#endif // QUARTERBACK_H
