//Amanda Koziol
//Homework 7
//Recitation 109
//TA Michael Luzzolino

#ifndef BIKERACER_H_INCLUDED
#define BIKERACER_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

class Racer
{
public:
	Racer()
	//Data Members
	pirvate:
		float M;				//Mass of the biker
		float Mb;				//Mass of the bike
		float g = 9.81;         //Gravitation constant
    	float v;                //velocity in the m/s
   		float cr;				//Coefficient of resistance due to road
   		float cf;				//coefficient of resistance due to air
   		float k;				//Coefficient related to rider position
	//Methods
	public:
		Racer();
		int getBikeMass();
		void setBikeMass(int value);
		

		int getBikeCR();
		void setBikeCR(int value);

		int getRiderMass();
		void setRiderMass(int value);

		int getCDraft();
		void setCDraft(int value);

		int getK();
		void setK(int value);

		int getVelocity();
		void setVelocity(int value);

	//Equations
	private:
		float Power();
		float TotalEnergy(float distance);


};
#endif // BIKERACER_H