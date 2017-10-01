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

	//Data Members
	private:
		float M;				//Mass of the biker
		float Mb;				//Mass of the bike
		float g = 9.81;         //Gravitation constant
    	float v;                //velocity in the m/s
    	float velocity;
   		float cr1;				//Coefficient of resistance due to road
   		float CDraft;
   		float cf;				//coefficient of resistance due to air
   		float k;
   		float Power1;
   		float K;				//Coefficient related to rider position
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
	public:
		float Power();
		float TotalEnergy(float distance);


};
#endif // BIKERACER_H